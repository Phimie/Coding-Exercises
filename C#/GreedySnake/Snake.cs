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
        SnakeBody[] snakeBodies;
        int nowSnakeLength;

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
            SnakeBody lastBody = snakeBodies[nowSnakeLength - 1];
            Console.SetCursorPosition(lastBody.pos.x, lastBody.pos.y);
            Console.Write("  ");

            switch (moveDirection)
            {
                case E_MoveDirection.Up:
                    snakeBodies[0].pos.y--;
                    break;
                case E_MoveDirection.Down:
                    snakeBodies[0].pos.y++;
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


    }
}