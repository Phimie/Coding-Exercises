using System;
using System.Net.Security;
namespace GreedySnake
{
    abstract class BeginOrEndBaseScene : ISceneUpdate
    {
        protected int nowSelectIndex = 0;
        protected string strTitle;
        protected string strOne;

        public abstract void EnterSpaceDoSomething();
        public void Update()
        {
            Console.ForegroundColor = ConsoleColor.Green;
            Console.SetCursorPosition(Game.w / 2 - strTitle.Length, 5);
            Console.Write(strTitle);

            Console.SetCursorPosition(Game.w / 2 - strOne.Length, 8);
            Console.ForegroundColor = nowSelectIndex == 0 ? ConsoleColor.Red : ConsoleColor.White;
            Console.Write(strOne);
            Console.SetCursorPosition(Game.w / 2 - 4, 10);
            Console.ForegroundColor = nowSelectIndex == 1 ? ConsoleColor.Red : ConsoleColor.White;
            Console.Write("结束游戏");

            switch (Console.ReadKey(true).Key)
            {
                case ConsoleKey.W:
                    --nowSelectIndex;
                    if (nowSelectIndex < 0)
                    {
                        nowSelectIndex = 0;
                    }
                    break;
                case ConsoleKey.S:
                    ++nowSelectIndex;
                    if (nowSelectIndex > 1)
                    {
                        nowSelectIndex = 1;
                    }
                    break;
                case ConsoleKey.Spacebar:
                    EnterSpaceDoSomething();
                    break;
            }
        }
    }
}