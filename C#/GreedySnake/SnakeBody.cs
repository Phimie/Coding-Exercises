using System;
namespace GreedySnake
{
    enum E_SnakeBodyType
    {
        Head,
        Body,
    }
    class SnakeBody : GameObject
    {

        private E_SnakeBodyType bodyType;

        public SnakeBody(int x, int y, E_SnakeBodyType bodyType)
        {
            this.pos = new Position(x, y);
            this.bodyType = bodyType;
        }

        public override void Draw()
        {
            Console.SetCursorPosition(pos.x, pos.y);
            Console.ForegroundColor = bodyType == E_SnakeBodyType.Head ? ConsoleColor.Yellow : ConsoleColor.Green;
            Console.Write(bodyType == E_SnakeBodyType.Head ? "●" : "■");
        }
    }
}