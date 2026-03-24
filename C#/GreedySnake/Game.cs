using System;
namespace GreedySnake
{
    enum E_SceneType
    {
        Begin,
        Game,
        End
    }
    class Game
    {
        public const int w = 80;
        public const int h = 20;
        public static ISceneUpdate nowScene;

        public Game()
        {
            Console.CursorVisible = false;
            Console.SetWindowSize(w, h);
            Console.SetBufferSize(w, h);

            ChangeScene(E_SceneType.Begin);
        }

        public void Start()
        {
            while (true)
            {
                if (nowScene != null)
                {
                    nowScene.Update();
                }
            }
        }

        public static void ChangeScene(E_SceneType type)
        {
            Console.Clear();
            switch (type)
            {
                case E_SceneType.Begin:
                    nowScene = new BeginScene();
                    break;
                case E_SceneType.Game:
                    nowScene = new GameScene();
                    break;
                case E_SceneType.End:

                    break;
            }
        }

    }
}