using System;
namespace GreedySnake
{
    class Map : IDraw
    {
        public MapWall[] mapWalls;
        public Map()
        {
            mapWalls = new MapWall[Game.w + (Game.h - 3) * 2];
            int index = 0;
            for (int i = 0; i < Game.w; i += 2)
            {
                mapWalls[index++] = new MapWall(i, 0);
                mapWalls[index++] = new MapWall(i, Game.h - 2);
            }
            for (int i = 1; i < Game.h - 2; i++)
            {
                mapWalls[index++] = new MapWall(0, i);
                mapWalls[index++] = new MapWall(Game.w - 2, i);
            }

        }

        public void Draw()
        {
            for (int i = 0; i < mapWalls.Length; i++)
            {
                mapWalls[i].Draw();
            }
        }

    }
}
