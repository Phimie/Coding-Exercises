using System;
namespace GreedySnake
{
    class Food : GameObject
    {
        public Food(int x, int y)
        {
            pos = new Position(x, y);
        }
        public override void Draw()
        {
            Console.SetCursorPosition(pos.x, pos.y);
            Console.ForegroundColor = ConsoleColor.Cyan;
            Console.Write("食");
        }
    }
}