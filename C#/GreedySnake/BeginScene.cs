using System;
namespace GreedySnake
{
    class BeginScene : BeginOrEndBaseScene
    {
        public BeginScene()
        {
            strTitle = "贪吃蛇";
            strOne = "开始游戏";
        }
        public override void EnterSpaceDoSomething()
        {
            switch (nowSelectIndex)
            {
                case 0:
                    Game.ChangeScene(E_SceneType.Game);
                    break;
                case 1:
                    Environment.Exit(0);
                    break;
            }
        }
    }
}