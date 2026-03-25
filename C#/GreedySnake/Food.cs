using System;
namespace GreedySnake
{
    class Food : GameObject
    {
        public Food(Snake snake)
        {
            RandomPosition(snake);
        }
        public override void Draw()
        {
            Console.SetCursorPosition(pos.x, pos.y);
            Console.ForegroundColor = ConsoleColor.Cyan;
            Console.Write("食");
        }

        public void RandomPosition(Snake snake)
        {
            Random random = new Random();
            this.pos.x = random.Next(4, Game.w - 4) / 2 * 2;
            this.pos.y = random.Next(1, Game.h - 4);
            Position newPos = new Position(this.pos.x, this.pos.y);

            if (snake.CheckSamePos(newPos))
            {
                RandomPosition(snake);
            }

        }
    }
}