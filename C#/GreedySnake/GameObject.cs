using System;
namespace GreedySnake
{
    struct Position
    {
        public int x;
        public int y;
        public Position(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
        public static bool operator ==(Position pos1, Position pos2)
        {
            return pos1.x == pos2.x && pos1.y == pos2.y;
        }
        public static bool operator !=(Position pos1, Position pos2)
        {
            return !(pos1 == pos2);
        }
    }
    abstract class GameObject : IDraw
    {
        public Position pos;
        public abstract void Draw();
    }
}