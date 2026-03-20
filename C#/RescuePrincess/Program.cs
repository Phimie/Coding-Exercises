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
        int Selfx = 2,Selfy = 1,SelfAtkMin = 2,SelfAtkMax = 5,SelfHp = 100,SelfEnergy = 100,SelfSpecialAtkMin = 4,SelfSpecialAtkMax = 7,SelfResotreHPMin = 1,SelfResotreHPMax = 3;
        int bossX = 24,bossY = 15,bossAtkMin = 3,bossAtkMax = 4,bossHp = 100;
        int princessX = 14,princessY = 12;
        int nowWindowID = 1;
        bool isFight = false,isWin = false,isGameover = false,isChatting = false;
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
                                    Selfx = 2;Selfy = 1;SelfHp = 100;SelfEnergy = 100;
                                    bossHp = 100;
                                    isFight = false;isWin = false;isGameover = false;
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
                    for (int i = 24 ; i < 29 ; i++){
                        Console.SetCursorPosition(32,i);
                        Console.Write("■");
                    }
                    //绘制教程
                    Console.SetCursorPosition(2,WindowSize_y - 6);
                    Console.ForegroundColor = ConsoleColor.Black;
                    Console.Write("wasd移动  按空格键交互");

                    //绘制主角血量
                    Console.SetCursorPosition(34,WindowSize_y - 6);
                    Console.ForegroundColor = ConsoleColor.Blue;
                    Console.Write("玩家血量:{0}  ",SelfHp);

                    //绘制主角能量
                    Console.SetCursorPosition(34,WindowSize_y - 5);
                    Console.ForegroundColor = ConsoleColor.Blue;
                    Console.Write("玩家能量:{0}  ",SelfEnergy);


                    while (true)
                    {
                        //绘制boss
                        if (bossHp > 0){
                            Console.SetCursorPosition(bossX,bossY);
                            Console.ForegroundColor = ConsoleColor.Green;
                            Console.Write("■");
                        }
                        //绘制公主
                        else if (bossHp <= 0){
                            Console.SetCursorPosition(princessX,princessY);
                            Console.ForegroundColor = ConsoleColor.Red;
                            Console.Write("■");
                        }
                        //绘制主角
                        Console.SetCursorPosition(Selfx,Selfy);
                        Console.ForegroundColor = ConsoleColor.Blue;
                        Console.Write("■");

                        char key = Console.ReadKey(true).KeyChar;
                        int nowFightChoiceIndex = 0,nowChatChoiceIndex = 0;

                        //绘制主角血量
                        Console.SetCursorPosition(34,WindowSize_y - 6);
                        Console.ForegroundColor = ConsoleColor.Blue;
                        Console.Write("玩家血量:{0}  ",SelfHp);

                        //绘制主角能量
                        Console.SetCursorPosition(34,WindowSize_y - 5);
                        Console.ForegroundColor = ConsoleColor.Blue;
                        Console.Write("玩家能量:{0}  ",SelfEnergy);

                        //移动相关
                        //擦除
                        Console.SetCursorPosition(Selfx,Selfy);
                        Console.Write("  ");
                        switch (key)
                        {
                            case 'W':case 'w':
                                Selfy -= 1;
                                if (Selfy < 1)
                                    Selfy = 1;
                                else if ((Selfx == bossX && Selfy == bossY && bossHp > 0)||(Selfx == princessX && Selfy == princessY && bossHp < 0))
                                    ++Selfy;
                                break;
                            case 'A':case 'a':
                                Selfx -= 2;
                                if (Selfx < 2)
                                    Selfx = 2;
                                else if ((Selfx == bossX && Selfy == bossY && bossHp > 0)||(Selfx == princessX && Selfy == princessY && bossHp < 0))
                                    Selfx += 2;
                                break;
                            case 'S':case 's':
                                Selfy += 1;
                                if (Selfy > Console.BufferHeight - 8)
                                    Selfy = Console.BufferHeight - 8;
                                else if ((Selfx == bossX && Selfy == bossY && bossHp > 0)||(Selfx == princessX && Selfy == princessY && bossHp < 0))
                                    --Selfy;
                                break;
                            case 'D':case 'd':
                                Selfx += 2;
                                if (Selfx > Console.BufferWidth - 4)
                                    Selfx = Console.BufferWidth - 4;
                                else if ((Selfx == bossX && Selfy == bossY && bossHp > 0)||(Selfx == princessX && Selfy == princessY && bossHp < 0))
                                    Selfx -= 2;
                                break;
                            case ' ':
                                //与boss交互
                                if ((Selfx == bossX && Selfy == bossY - 1 || Selfx == bossX && Selfy == bossY + 1 || Selfx == bossX - 2 && Selfy == bossY || Selfx == bossX + 2 && Selfy == bossY) && bossHp > 0)
                                {
                                    Console.ForegroundColor = ConsoleColor.Blue;
                                    Console.SetCursorPosition(2,WindowSize_y - 6);
                                    Console.Write("                           ");
                                    Console.SetCursorPosition(2,WindowSize_y - 6);
                                    Console.Write("开始战斗!");
                                    isFight = true;
                                }
                                //与公主交互
                                else if ((Selfx == princessX && Selfy == princessY - 1 || Selfx == princessX && Selfy == princessY + 1 || Selfx == princessX - 2 && Selfy == princessY || Selfx == princessX + 2 && Selfy == princessY) && bossHp <= 0){
                                    isChatting = true;
                                }
                                break;
                        }

                        #region 公主交互相关
                            while(isChatting){
                                //保持玩家绘制
                                Console.SetCursorPosition(Selfx,Selfy);
                                Console.ForegroundColor = ConsoleColor.Blue;
                                Console.Write("■");

                                
                                Console.SetCursorPosition(2, WindowSize_y - 5);
                                Console.ForegroundColor = nowChatChoiceIndex == 0 ? ConsoleColor.Red : ConsoleColor.Black;
                                Console.Write("  你还好吗");
                                Console.SetCursorPosition(2, WindowSize_y - 4);
                                Console.ForegroundColor = nowChatChoiceIndex == 1 ? ConsoleColor.Red : ConsoleColor.Black;
                                Console.Write("  我来晚了");
                                Console.SetCursorPosition(2, WindowSize_y - 3);
                                Console.ForegroundColor = nowChatChoiceIndex == 2 ? ConsoleColor.Red : ConsoleColor.Black;
                                Console.Write("  离开这里");
                                Console.SetCursorPosition(2, WindowSize_y - (5 - nowChatChoiceIndex));
                                Console.Write("▲");
                                char input1 = Console.ReadKey(true).KeyChar;
                                switch (input1)
                                {
                                    case ' ':
                                        switch (nowChatChoiceIndex)
                                        {
                                            case 0:
                                                Console.SetCursorPosition(2, WindowSize_y - 6);
                                                Console.Write("                           ");
                                                Console.SetCursorPosition(2, WindowSize_y - 6);
                                                Console.ForegroundColor = ConsoleColor.Green;
                                                Console.Write("公主: 我还活着");
                                                break;
                                            case 1:
                                                Console.SetCursorPosition(2, WindowSize_y - 6);
                                                Console.Write("                           ");
                                                Console.SetCursorPosition(2, WindowSize_y - 6);
                                                Console.ForegroundColor = ConsoleColor.Green;
                                                Console.Write("公主: 快带我离开这");
                                                break;
                                            case 2:
                                                isChatting = false;
                                                Console.Clear();
                                                isWin = true;
                                                nowWindowID = 3;
                                                break;
                                        }
                                        break;
                                    case 'w': case 'W':
                                        nowChatChoiceIndex--;
                                        if (nowChatChoiceIndex < 0){
                                            nowChatChoiceIndex= 0;
                                        }
                                        break;
                                    case 's': case 'S':
                                        nowChatChoiceIndex++;
                                        if (nowChatChoiceIndex > 2){
                                            nowChatChoiceIndex = 2;
                                        }
                                        break;
                                }
                            }
                        #endregion

                        #region 战斗相关
                        while(isFight)
                        {
                            //战斗中保持绘制更新信息
                            Console.SetCursorPosition(Selfx,Selfy);
                            Console.ForegroundColor = ConsoleColor.Blue;
                            Console.Write("■");
                            Console.SetCursorPosition(34,WindowSize_y - 6);
                            Console.ForegroundColor = ConsoleColor.Blue;
                            Console.Write("玩家血量:{0}  ",SelfHp);
                            Console.SetCursorPosition(34,WindowSize_y - 5);
                            Console.ForegroundColor = ConsoleColor.Blue;
                            Console.Write("玩家能量:{0}  ",SelfEnergy);
                            //仅在战斗中绘制boss血量
                            Console.SetCursorPosition(34,WindowSize_y - 3);
                            Console.ForegroundColor = ConsoleColor.Red;
                            Console.Write("boss血量:{0}  ",bossHp);


                            Console.SetCursorPosition(2, WindowSize_y - 5);
                            Console.ForegroundColor = nowFightChoiceIndex == 0 ? ConsoleColor.Red : ConsoleColor.Black;
                            Console.Write("  使出普通攻击(A:2~5) ");
                            Console.SetCursorPosition(2, WindowSize_y - 4);
                            Console.ForegroundColor = nowFightChoiceIndex == 1 ? ConsoleColor.Red : ConsoleColor.Black;
                            Console.Write("  使出特殊攻击(A:4~7 E:20) ");
                            Console.SetCursorPosition(2, WindowSize_y - 3);
                            Console.ForegroundColor = nowFightChoiceIndex == 2 ? ConsoleColor.Red : ConsoleColor.Black;
                            Console.Write("  使出休养调息(R:10)");
                            Console.SetCursorPosition(2, WindowSize_y - (5 - nowFightChoiceIndex));
                            Console.Write("▲");
                            Random r = new Random();
                            char input = Console.ReadKey(true).KeyChar;
                            switch (input)
                            {
                                case ' ':
                                    switch (nowFightChoiceIndex)
                                    {
                                        case 0:
                                            int NormalAtk = r.Next(SelfAtkMin, SelfAtkMax);
                                            bossHp -= NormalAtk;
                                            Console.ForegroundColor = ConsoleColor.Green;
                                            Console.SetCursorPosition(2,WindowSize_y - 6);
                                            Console.Write("                           ");
                                            Console.SetCursorPosition(2,WindowSize_y - 6);
                                            Console.Write("你造成了{0} 点伤害", NormalAtk);
                                            int bossAtk = r.Next(bossAtkMin, bossAtkMax);
                                            SelfHp -= bossAtk;
                                            if (bossHp <= 0 || SelfHp <= 0)
                                            {
                                                for (int i = 3 ; i <= 5 ; i++){
                                                    Console.SetCursorPosition(2, WindowSize_y - i);
                                                    Console.Write("                           ");
                                                }

                                                if (bossHp < SelfHp){
                                                    Console.SetCursorPosition(2,WindowSize_y - 6);
                                                    Console.ForegroundColor = ConsoleColor.Red;
                                                    Console.Write("恭喜你打败了boss!");
                                                    //立即更新血量
                                                    Console.SetCursorPosition(34,WindowSize_y - 6);
                                                    Console.ForegroundColor = ConsoleColor.Blue;
                                                    Console.Write("玩家血量:{0}  ",SelfHp);
                                                    Console.SetCursorPosition(34,WindowSize_y - 5);
                                                    Console.ForegroundColor = ConsoleColor.Blue;
                                                    Console.Write("玩家能量:{0}  ",SelfEnergy);
                                                    Console.SetCursorPosition(34,WindowSize_y - 3);
                                                    Console.ForegroundColor = ConsoleColor.Red;
                                                    Console.Write("boss血量:{0}  ",bossHp);
                                                    Console.SetCursorPosition(bossX,bossY);
                                                    Console.Write("  ");
                                                }
                                                else {
                                                    isGameover = true;
                                                    Console.Clear();
                                                    nowWindowID = 3;
                                                }
                                                isFight = false;
                                            }
                                            break;
                                        case 1:
                                            if (SelfEnergy >= 20){
                                                int SpecialAtk = r.Next(SelfSpecialAtkMin, SelfSpecialAtkMax);
                                                bossHp -= SpecialAtk;
                                                Console.ForegroundColor = ConsoleColor.Green;
                                                Console.SetCursorPosition(2,WindowSize_y - 6);
                                                Console.Write("                           ");
                                                Console.SetCursorPosition(2,WindowSize_y - 6);
                                                Console.Write("重击造成了{0} 点伤害", SpecialAtk);
                                                bossAtk = r.Next(bossAtkMin, bossAtkMax);
                                                SelfEnergy -= 20;
                                                SelfHp -= bossAtk;
                                                if (bossHp <= 0 || SelfHp <= 0)
                                                {
                                                    for (int i = 3 ; i <= 5 ; i++){
                                                        Console.SetCursorPosition(2, WindowSize_y - i);
                                                        Console.Write("                             ");
                                                    }

                                                    if (bossHp < SelfHp){
                                                        Console.SetCursorPosition(2,WindowSize_y - 6);
                                                        Console.ForegroundColor = ConsoleColor.Red;
                                                        Console.Write("恭喜你打败了boss!  ");
                                                        //立即更新血量
                                                        Console.SetCursorPosition(34,WindowSize_y - 6);
                                                        Console.ForegroundColor = ConsoleColor.Blue;
                                                        Console.Write("玩家血量:{0}  ",SelfHp);
                                                        Console.SetCursorPosition(34,WindowSize_y - 5);
                                                        Console.ForegroundColor = ConsoleColor.Blue;
                                                        Console.Write("玩家能量:{0}  ",SelfEnergy);
                                                        Console.SetCursorPosition(34,WindowSize_y - 3);
                                                        Console.ForegroundColor = ConsoleColor.Red;
                                                        Console.Write("boss血量:{0}  ",bossHp);
                                                        Console.SetCursorPosition(bossX,bossY);
                                                        Console.Write("  ");
                                                    }
                                                    else {
                                                        isGameover = true;
                                                        Console.Clear();
                                                        nowWindowID = 3;
                                                    }
                                                    isFight = false;
                                                }
                                            }else{
                                                Console.ForegroundColor = ConsoleColor.Green;
                                                Console.SetCursorPosition(2,WindowSize_y - 6);
                                                Console.Write("                           ");
                                                Console.SetCursorPosition(2,WindowSize_y - 6);
                                                Console.Write("你的能量不足! ");
                                            }
                                            break;
                                        case 2:
                                            int RestoreHp = r.Next(SelfResotreHPMin, SelfResotreHPMax);
                                            Console.ForegroundColor = ConsoleColor.Green;
                                            Console.SetCursorPosition(2,WindowSize_y - 6);
                                            Console.Write("                           ");
                                            Console.SetCursorPosition(2,WindowSize_y - 6);
                                            Console.Write("你恢复了{0}点血量,10点能量", RestoreHp);
                                            bossAtk = r.Next(bossAtkMin, bossAtkMax);
                                            SelfHp -= bossAtk;
                                            SelfEnergy += 10;
                                            if (SelfHp <= 0)
                                            {
                                                for (int i = 3 ; i <= 5 ; i++){
                                                    Console.SetCursorPosition(2, WindowSize_y - i);
                                                    Console.Write("                           ");
                                                }
                                                Console.SetCursorPosition(2,WindowSize_y - 6);
                                                Console.ForegroundColor = ConsoleColor.Red;
                                                isGameover = true;
                                                Console.Clear();
                                                nowWindowID = 3;
                                                isFight = false;
                                            }else{
                                                SelfHp += RestoreHp;
                                            }
                                            break;
                                    }
                                    break;
                                case 'w': case 'W':
                                    nowFightChoiceIndex--;
                                    if (nowFightChoiceIndex < 0){
                                        nowFightChoiceIndex = 0;
                                    }
                                    break;
                                case 's': case 'S':
                                    nowFightChoiceIndex++;
                                    if (nowFightChoiceIndex > 2){
                                        nowFightChoiceIndex = 2;
                                    }
                                    break;
                            }
                        }
                        #endregion
                        
                        if (isWin || isGameover){
                            break;
                        }
                    }
                    break;
                #endregion
                #region 结束窗口
                case 3:
                    if (isWin){
                        Console.SetCursorPosition(WindowSize_x/2 - 5,5);
                        Console.ForegroundColor = ConsoleColor.Red;
                        Console.Write("你胜利了!");
                    }
                    if (isGameover){
                        Console.SetCursorPosition(WindowSize_x/2 - 5,5);
                        Console.ForegroundColor = ConsoleColor.Green;
                        Console.Write("你失败了!");
                    }

                    nowChoiceIndex = 0;
                    while(true){
                        bool isExitWhile = false;
                        Console.SetCursorPosition(WindowSize_x/2 - 6, 10);
                        Console.ForegroundColor = nowChoiceIndex == 0 ? ConsoleColor.Red : ConsoleColor.Black;
                        Console.Write("回到开始界面");
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
                                    nowWindowID = 1;
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
            }
            #endregion
        }
    }
}