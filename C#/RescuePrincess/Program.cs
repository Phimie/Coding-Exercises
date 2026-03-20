using System;
class Program{
    static void Main(string[] args)
    {
        #region 初始化
        Console.BackgroundColor = ConsoleColor.White;
        Console.Clear();
        Console.ForegroundColor = ConsoleColor.Blue;
        Console.CursorVisible = false;
        int WindowSize_x = 50,WindowSize_y= 30;
        Console.SetWindowSize(WindowSize_x,WindowSize_y);
        Console.SetBufferSize(WindowSize_x,WindowSize_y);
        int Selfx = 2,Selfy = 1,SelfAtkMin = 8,SelfAtkMax = 12,SelfHp = 100;
        int bossX = 24,bossY = 15,bossAtkMin = 7,bossAtkMax = 13,bossHp = 100;
        int nowWindowID = 1;
        bool isFight = false;
        #endregion

        #region 主循环
        while(true)
        {
            switch(nowWindowID)
            {
                #region 开始窗口
                case 1:
                    Console.Clear();
                    Console.SetCursorPosition(WindowSize_x / 2 - 7, 5);
                    Console.Write("RescuePrincess");
                    int nowChoiceIndex = 0;
                    while (true)
                    {
                        bool isExitWhile = false;
                        Console.SetCursorPosition(WindowSize_x/2 - 4, 10);
                        Console.ForegroundColor = nowChoiceIndex == 0 ? ConsoleColor.Red : ConsoleColor.Black;
                        Console.Write("开始游戏");
                        Console.SetCursorPosition(WindowSize_x/2 - 4, 12);
                        Console.ForegroundColor = nowChoiceIndex == 1 ? ConsoleColor.Red : ConsoleColor.Black;
                        Console.Write("退出游戏");                        
                        char input = Console.ReadKey(true).KeyChar;
                        switch (input)
                        {
                            case 'W': case 'w':
                                nowChoiceIndex = 0;
                                break;
                            case 'S': case 's':
                                nowChoiceIndex = 1;
                                break;
                            case ' ':
                                if (nowChoiceIndex == 0){
                                    nowWindowID = 2;
                                    isExitWhile = true;
                                }else{
                                    Environment.Exit(0);
                                }
                                break;
                        }
                        if(isExitWhile){
                            Console.Clear();
                            break;
                        }
                    }
                    break;
                #endregion
                
                #region 游戏窗口
                case 2:
                    //边界
                    Console.ForegroundColor = ConsoleColor.Red;
                    for (int i = 1 ; i < WindowSize_y; i++){
                        if (i == 1 || i == 24 || i == 29)
                            Console.Write("■■■■■■■■■■■■■■■■■■■■■■■■■");
                        else
                            Console.Write("■                                              ■");
                    }

                    while (true)
                    {
                        //绘制boss
                        if (bossHp > 0){
                            Console.SetCursorPosition(bossX,bossY);
                            Console.ForegroundColor = ConsoleColor.Green;
                            Console.Write("■");
                        }
                        //绘制主角
                        Console.SetCursorPosition(Selfx,Selfy);
                        Console.ForegroundColor = ConsoleColor.Blue;
                        Console.Write("■");

                        char key = Console.ReadKey(true).KeyChar;

                        //战斗相关
                        if (isFight && key == ' ')
                        {
                                Random r = new Random();
                                int atk = r.Next(SelfAtkMin, SelfAtkMax);
                                bossHp -= atk;
                                Console.ForegroundColor = ConsoleColor.Green;
                                Console.SetCursorPosition(2,WindowSize_y - 4);
                                Console.Write("                                              ");
                                Console.SetCursorPosition(2,WindowSize_y - 4);
                                Console.Write("你对boss造成了{0}点伤害, boss剩余血量为{1}", atk, bossHp);
                                atk = r.Next(bossAtkMin, bossAtkMax);
                                SelfHp -= atk;
                                Console.ForegroundColor = ConsoleColor.Blue;
                                Console.SetCursorPosition(2, WindowSize_y - 3);
                                Console.Write("                                         ");
                                Console.SetCursorPosition(2, WindowSize_y - 3);
                                Console.Write("boss对你造成了{0}点伤害, 你的剩余血量为{1}", atk, SelfHp);
                                if (bossHp <= 0 || SelfHp <= 0)
                                {
                                    for (int i = 3 ; i <= 5 ; i++){
                                        Console.SetCursorPosition(2, WindowSize_y - i);
                                        Console.Write("                                         ");
                                    }
                                    Console.SetCursorPosition(2,WindowSize_y - 5);
                                    Console.ForegroundColor = ConsoleColor.Red;
                                    if (bossHp < SelfHp){
                                        Console.Write("恭喜你胜利了!");
                                        Console.SetCursorPosition(bossX,bossY);
                                        Console.Write("  ");
                                    }
                                    else {
                                        Console.Write("你失败了!");
                                    }
                                    isFight = false;
                                }
                        }
                        //移动相关
                        else
                        {
                            //擦除
                            Console.SetCursorPosition(Selfx,Selfy);
                            Console.Write("  ");
                            switch (key)
                            {
                                case 'W':case 'w':
                                    Selfy -= 1;
                                    if (Selfy < 1)
                                        Selfy = 1;
                                    else if (Selfx == bossX && Selfy == bossY && bossHp > 0)
                                        ++Selfy;
                                    break;
                                case 'A':case 'a':
                                    Selfx -= 2;
                                    if (Selfx < 2)
                                        Selfx = 2;
                                    else if (Selfx == bossX && Selfy == bossY && bossHp > 0)
                                        Selfx += 2;
                                    break;
                                case 'S':case 's':
                                    Selfy += 1;
                                    if (Selfy > Console.BufferHeight - 8)
                                        Selfy = Console.BufferHeight - 8;
                                    else if (Selfx == bossX && Selfy == bossY && bossHp > 0)
                                        --Selfy;
                                    break;
                                case 'D':case 'd':
                                    Selfx += 2;
                                    if (Selfx > Console.BufferWidth - 4)
                                        Selfx = Console.BufferWidth - 4;
                                    else if (Selfx == bossX && Selfy == bossY && bossHp > 0)
                                        Selfx -= 2;
                                    break;
                                case ' ':
                                    if ((Selfx == bossX && Selfy == bossY - 1 || Selfx == bossX && Selfy == bossY + 1 || Selfx == bossX - 2 && Selfy == bossY || Selfx == bossX + 2 && Selfy == bossY) && bossHp > 0)
                                    {
                                        isFight = true;
                                        Console.SetCursorPosition(2,WindowSize_y - 5);
                                        Console.ForegroundColor = ConsoleColor.Black;
                                        Console.Write("开始和boss战斗了,按空格继续");
                                        Console.SetCursorPosition(2,WindowSize_y - 4);
                                        Console.Write("玩家当前血量为{0}",SelfHp);
                                        Console.SetCursorPosition(2,WindowSize_y - 3);
                                        Console.Write("boss当前血量为{0}",bossHp);
                                    }
                                    break;
                            }
                        }
                        
                    }
                    break;
                #endregion
                #region 结束窗口
                case 3:
                    break;
                #endregion
            }
            #endregion
        }
    }
}