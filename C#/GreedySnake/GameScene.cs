using System;
namespace GreedySnake
{
    class GameScene : ISceneUpdate
    {
        Map map;
        Snake snake;

        Food food;

        int updateSpeed = 0;

        int tick = 15000;
        public GameScene()
        {
            map = new Map();
            snake = new Snake(40, 10);
            food = new Food(snake);
        }
        public void Update()
        {
            updateSpeed++;
            if (updateSpeed % tick == 0)
            {
                map.Draw();
                snake.Move();
                snake.Draw();
                food.Draw();
                snake.CheckEatFood(food);
                updateSpeed = 0;
            }

            if (snake.CheckEnd(map))
            {
                Game.ChangeScene(E_SceneType.End);
            }

            if (Console.KeyAvailable)  //.KeyAvailable属性：获取一个值，该值指示是否在输入流中有按键可供读取。
            {
                switch (Console.ReadKey(true).Key)
                {
                    case ConsoleKey.W:
                        snake.ChangeDirection(E_MoveDirection.Up);
                        break;
                    case ConsoleKey.S:
                        snake.ChangeDirection(E_MoveDirection.Down);
                        break;
                    case ConsoleKey.A:
                        snake.ChangeDirection(E_MoveDirection.Left);
                        break;
                    case ConsoleKey.D:
                        snake.ChangeDirection(E_MoveDirection.Right);
                        break;
                    case ConsoleKey.Spacebar:
                        if (tick == 15000)
                            tick = 5000;
                        else
                            tick = 15000;
                        break;
                }
            }



        }
    }
}