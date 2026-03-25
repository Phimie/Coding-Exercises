using System;
namespace GreedySnake
{
    class EndScene : BeginOrEndBaseScene
    {
        public EndScene()
        {
            strTitle = "游戏结束";
            strOne = "回到主界面";
        }
        public override void EnterSpaceDoSomething()
        {
            switch (nowSelectIndex)
            {
                case 0:
                    Game.ChangeScene(E_SceneType.Begin);
                    break;
                case 1:
                    Environment.Exit(0);
                    break;
            }
        }
    }
}