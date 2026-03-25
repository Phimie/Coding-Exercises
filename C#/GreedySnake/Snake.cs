using System;
namespace GreedySnake
{
    enum E_MoveDirection
    {
        Up,
        Down,
        Left,
        Right
    }
    class Snake : IDraw
    {
        public SnakeBody[] snakeBodies;
        public int nowSnakeLength;

        private Position lastTailPos;

        E_MoveDirection moveDirection;
        public Snake(int x, int y)
        {
            snakeBodies = new SnakeBody[200];
            snakeBodies[0] = new SnakeBody(x, y, E_SnakeBodyType.Head);
            nowSnakeLength = 1;
            moveDirection = E_MoveDirection.Right;

        }
        public void Draw()
        {
            for (int i = 0; i < nowSnakeLength; i++)
            {
                snakeBodies[i].Draw();
            }
        }

        public void Move()
        {
            lastTailPos = snakeBodies[nowSnakeLength - 1].pos;
            Console.SetCursorPosition(lastTailPos.x, lastTailPos.y);
            Console.Write("  ");

            for (int i = nowSnakeLength - 1; i > 0; i--)
            {
                snakeBodies[i].pos = snakeBodies[i - 1].pos;
            }

            switch (moveDirection)
            {
                case E_MoveDirection.Up:
                    --snakeBodies[0].pos.y;
                    break;
                case E_MoveDirection.Down:
                    ++snakeBodies[0].pos.y;
                    break;
                case E_MoveDirection.Left:
                    snakeBodies[0].pos.x -= 2;
                    break;
                case E_MoveDirection.Right:
                    snakeBodies[0].pos.x += 2;
                    break;
            }

        }

        public void ChangeDirection(E_MoveDirection newDirection)
        {
            if ((nowSnakeLength > 1) && (
                (moveDirection == E_MoveDirection.Up && newDirection == E_MoveDirection.Down) ||
                (moveDirection == E_MoveDirection.Down && newDirection == E_MoveDirection.Up) ||
                (moveDirection == E_MoveDirection.Left && newDirection == E_MoveDirection.Right) ||
                (moveDirection == E_MoveDirection.Right && newDirection == E_MoveDirection.Left)))
            {
                return;
            }
            moveDirection = newDirection;
        }

        public bool CheckEnd(Map map)
        {
            for (int i = 0; i < map.mapWalls.Length; i++)
            {
                if (snakeBodies[0].pos == map.mapWalls[i].pos)
                {
                    return true;
                }
            }
            for (int i = 1; i < nowSnakeLength; i++)
            {
                if (snakeBodies[0].pos == snakeBodies[i].pos)
                {
                    return true;
                }
            }
            return false;
        }

        public bool CheckSamePos(Position pos)
        {
            for (int i = 0; i < nowSnakeLength; i++)
            {
                if (snakeBodies[i].pos == pos)
                {
                    return true;
                }
            }
            return false;
        }

        public void CheckEatFood(Food food)
        {
            if (snakeBodies[0].pos == food.pos)
            {
                food.RandomPosition(this);
                AddBody();
            }
        }

        public void AddBody()
        {
            snakeBodies[nowSnakeLength] = new SnakeBody(lastTailPos.x, lastTailPos.y, E_SnakeBodyType.Body);
            nowSnakeLength++;
        }


    }
}