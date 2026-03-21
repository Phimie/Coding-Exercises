using System;
namespace FlyingChess
{

    #region 状态相关
    enum E_WindowState{
        start,
        playing,
        gameover
    }

    enum E_GameState{
        gamming,
        win,
        lose

    }

    enum E_ChoiceIndex{
        Choice1,
        Choice2,
        Choice3
    }
    #endregion

    #region 地图相关
    enum E_Grid_Type{
        normal,
        boom,
        pause,
        tunnel
    }

    struct Vector2
    {
        public int x;
        public int y;

        public Vector2(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
    }

    struct Grid{
        public E_Grid_Type type;
        public Vector2 pos;

        public Grid(int x, int y, E_Grid_Type type){
            pos.x = x;
            pos.y = y;
            this.type = type;
        }

        public void Draw()
        {
            Console.SetCursorPosition(pos.x, pos.y);
            switch(type)
            {
                case E_Grid_Type.normal:
                    Console.ForegroundColor = ConsoleColor.White;
                    Console.Write("□");
                    break;
                case E_Grid_Type.boom:
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.Write("●");
                    break;
                case E_Grid_Type.pause:
                    Console.ForegroundColor = ConsoleColor.Blue;
                    Console.Write("停");
                    break;
                case E_Grid_Type.tunnel:
                    Console.ForegroundColor = ConsoleColor.Yellow;
                    Console.Write("★");
                    break;
            }
        }
    }

    struct Map
    {
        public Grid[] grids;

        public Map(int x, int y, int num)
        {
            grids = new Grid[num];

            int indexX = 0;
            int indexY = 0;
            int stepNum = 2;

            Random r = new Random();
            int randomNum;
            for (int i = 0; i < num; i++)
            {
                randomNum = r.Next(0,101);

                if (randomNum < 85 || i == 0 || i == num - 1)
                {
                    grids[i].type = E_Grid_Type.normal;
                }
                else if (randomNum >= 85 && randomNum < 90)
                {
                    grids[i].type = E_Grid_Type.boom;
                }
                else if (randomNum >= 90 && randomNum < 95)
                {
                    grids[i].type = E_Grid_Type.pause;
                }else{
                    grids[i].type = E_Grid_Type.tunnel;
                }

                grids[i].pos = new Vector2(x, y);

                if (indexX == 10){
                    y += 1;
                    ++indexY;
                    if (indexY == 2){
                        indexX = 0;
                        indexY = 0;
                        stepNum = -stepNum;
                    }
                }else{
                    x += stepNum;
                    ++indexX;
                }


            }
        }

        public void Draw(){
            for (int i = 0 ; i < grids.Length; i++){
                grids[i].Draw();
            }
        }
    }
    #endregion

    #region 玩家相关

        enum E_PlayerType
        {
            player,
            computer,
        }

        struct Player
        {
            public E_PlayerType type;
            public int nowIndex;
            public bool isPause;
            public Player(int index, E_PlayerType type)
            {
                nowIndex = index;
                this.type = type;
                isPause = false;
            }

            public void Draw(Map mapInfo)
            {
                Grid grid = mapInfo.grids[nowIndex];

                Console.SetCursorPosition(grid.pos.x, grid.pos.y);

                switch (type)
                {
                    case E_PlayerType.player:
                        Console.ForegroundColor = ConsoleColor.Cyan;
                        Console.Write("我");
                        break;
                    case E_PlayerType.computer:
                        Console.ForegroundColor = ConsoleColor.Magenta;
                        Console.Write("PC");
                        break;
                }
            }
        }

    #endregion



    class Program{
        #region 局部方法

        static void ClearInfo(){
            Console.SetCursorPosition(2, 24);
            Console.Write("                                        ");
            Console.SetCursorPosition(2, 25);
            Console.Write("                                        ");
            Console.SetCursorPosition(2, 26);
            Console.Write("                                        ");
            Console.SetCursorPosition(2, 27);
            Console.Write("                                        ");
        }



        static int RandomMove(int w, int h, ref Player p, ref Player otherP, Map map)
        {
            //擦除之前的内容
            ClearInfo();
            Console.ForegroundColor = p.type == E_PlayerType.player ? ConsoleColor.Cyan : ConsoleColor.Magenta;

            if (p.isPause)
            {
                Console.SetCursorPosition(2, 25);
                Console.Write("处于暂停该点,{0}需要暂停一回合", p.type == E_PlayerType.player ? "你" : "电脑");
                Console.SetCursorPosition(2,26);
                Console.Write("请按任意键,让{0}开始扔骰子", p.type == E_PlayerType.player ? "电脑" : "你");
                p.isPause = false;
                return 0;
            }


            Random r = new Random();
            int randomNum = r.Next(1,7);
            p.nowIndex += randomNum;

            //打印扔的点数
            Console.SetCursorPosition(2,24);
            Console.Write("{0}扔出的点数为:{1}", p.type == E_PlayerType.player ? "你" : "电脑", randomNum);

            if ( p.nowIndex >= map.grids.Length - 1 )
            {
                p.nowIndex = map.grids.Length - 1;
                Console.SetCursorPosition(2, 25);
                if (p.type == E_PlayerType.player){
                    Console.Write("恭喜你率先到达了终点");
                    Console.SetCursorPosition(2, 26);
                    Console.Write("请按任意键结束游戏");
                    return 1;
                }else{
                    Console.Write("很遗憾,电脑率先到达了终点");
                    Console.SetCursorPosition(2, 26);
                    Console.Write("请按任意键结束游戏");
                    return 2;
                }
            }
            else{
                Grid grid = map.grids[p.nowIndex];

                switch (grid.type)
                {
                    case E_Grid_Type.normal:
                        Console.SetCursorPosition(2,25);
                        Console.Write("{0}到了一个安全位置", p.type == E_PlayerType.player ? "你" : "电脑");
                        Console.SetCursorPosition(2,27);
                        Console.Write("请按任意键,让{0}开始扔骰子", p.type == E_PlayerType.player ? "电脑" : "你");
                        break;
                    case E_Grid_Type.boom:
                        p.nowIndex -= 5;

                        if (p.nowIndex < 0)
                        {
                            p.nowIndex= 0;
                        }
                        Console.SetCursorPosition(2,25);
                        Console.Write("{0}踩到了炸弹,退后5格", p.type == E_PlayerType.player ? "你" : "电脑");

                        break;
                    case  E_Grid_Type.pause:
                        p.isPause = true;
                        Console.SetCursorPosition(2,26);
                        Console.Write("{0}到达了暂停点,需要暂停一回合", p.type == E_PlayerType.player ? "你" : "电脑");
                        Console.SetCursorPosition(2,27);
                        Console.Write("请按任意键,让{0}开始扔骰子", p.type == E_PlayerType.player ? "电脑" : "你");
                        break;
                    case E_Grid_Type.tunnel:
                        Console.SetCursorPosition(2,25);
                        Console.Write("{0}踩到了时空隧道", p.type == E_PlayerType.player ? "你" : "电脑");
                        Console.SetCursorPosition(2,27);
                        Console.Write("请按任意键,让{0}开始扔骰子", p.type == E_PlayerType.player ? "电脑" : "你");
                        randomNum = r.Next(1, 91);
                        if (randomNum < 30){
                            p.nowIndex -= 5;
                            if (p.nowIndex < 0)
                            {
                                p.nowIndex = 0;
                            }
                            Console.SetCursorPosition(2,26);
                            Console.Write("触发倒退5格");
                        }
                        else if ( randomNum <= 60 )
                        {
                            p.isPause = true;
                            Console.SetCursorPosition(2,26);
                            Console.Write("触发暂停1回合");
                        }
                        else
                        {
                            int temp = p.nowIndex;
                            p.nowIndex = otherP.nowIndex;
                            otherP.nowIndex = temp;
                            Console.SetCursorPosition(2,26);
                            Console.Write("触发双方交换位置");
                        }

                        Console.SetCursorPosition(2,27);
                        Console.Write("请按任意键,让{0}开始扔骰子", p.type == E_PlayerType.player ? "电脑" : "你");
                        break;
                }


            }

            return 0;
        }

        static void DrawPlayer(Player player, Player computer, Map map){
            if (player.nowIndex == computer.nowIndex)
            {
                Grid grid = map.grids[player.nowIndex];
                Console.SetCursorPosition(grid.pos.x, grid.pos.y);
                Console.ForegroundColor = ConsoleColor.Green;
                Console.Write("◆");
            }
            else{
                player.Draw(map);
                computer.Draw(map);
            }
        }


        static void PrintInfo(int x,int y,string info){
            Console.SetCursorPosition(x,y);
            Console.Write(info);
        }

        static void PrintInfo(int x, int y, string info, string color)
        {
            Console.SetCursorPosition(x, y);
            switch (color)
            {
                case "Black":
                    Console.ForegroundColor = ConsoleColor.Black;
                    break;
                case "DarkBlue":
                    Console.ForegroundColor = ConsoleColor.DarkBlue;
                    break;
                case "DarkGreen":
                    Console.ForegroundColor = ConsoleColor.DarkGreen;
                    break;
                case "DarkCyan":
                    Console.ForegroundColor = ConsoleColor.DarkCyan;
                    break;
                case "DarkRed":
                    Console.ForegroundColor = ConsoleColor.DarkRed;
                    break;
                case "DarkMagenta":
                    Console.ForegroundColor = ConsoleColor.DarkMagenta;
                    break;
                case "DarkYellow":
                    Console.ForegroundColor = ConsoleColor.DarkYellow;
                    break;                
                case "Gray":
                    Console.ForegroundColor = ConsoleColor.Gray;
                    break;
                case "DarkGray":
                    Console.ForegroundColor = ConsoleColor.DarkGray;
                    break;
                case "Blue":
                    Console.ForegroundColor = ConsoleColor.Blue;
                    break;
                case "Green":
                    Console.ForegroundColor = ConsoleColor.Green;
                    break;
                case "Cyan":
                    Console.ForegroundColor = ConsoleColor.Cyan;
                    break;
                case "Red":
                    Console.ForegroundColor = ConsoleColor.Red;
                    break;
                case "Magenta":
                    Console.ForegroundColor = ConsoleColor.Magenta;
                    break;
                case "Yellow":
                    Console.ForegroundColor = ConsoleColor.Yellow;
                    break;
                case "White":
                    Console.ForegroundColor = ConsoleColor.White;
                    break;
            }
            Console.Write(info);
            Console.ResetColor();
        }




        #endregion






        static void Main(string[] args)
        {
            #region 初始化
            Console.BackgroundColor = ConsoleColor.Black;
            Console.Clear();
            Console.ForegroundColor = ConsoleColor.Blue;
            Console.CursorVisible = false;
            int WindowSize_x = 50,WindowSize_y= 30;
            Console.SetWindowSize(WindowSize_x,WindowSize_y);
            Console.SetBufferSize(WindowSize_x,WindowSize_y);
            E_WindowState WindowState = E_WindowState.start;
            E_GameState GameState = E_GameState.gamming;
            #endregion

            #region 主循环
            while(true)
            {
                switch(WindowState)
                {
                    #region 开始窗口
                    case E_WindowState.start:
                        Console.Clear();
                        Console.SetCursorPosition(WindowSize_x / 2 - 3, 5);
                        Console.ForegroundColor = ConsoleColor.Blue;
                        Console.Write("飞行棋");
                        E_ChoiceIndex StartE_ChoiceIndex = E_ChoiceIndex.Choice1;
                        while (true)
                        {
                            bool isExitWhile = false;
                            Console.ForegroundColor = StartE_ChoiceIndex == E_ChoiceIndex.Choice1 ? ConsoleColor.Red : ConsoleColor.White;
                            PrintInfo(WindowSize_x/2 - 4, 10,"开始游戏");
                            Console.SetCursorPosition(WindowSize_x/2 - 4, 12);
                            Console.ForegroundColor = StartE_ChoiceIndex == E_ChoiceIndex.Choice2 ? ConsoleColor.Red : ConsoleColor.White;
                            Console.Write("退出游戏");                        
                            char input = Console.ReadKey(true).KeyChar;
                            switch (input)
                            {
                                case 'W': case 'w':
                                    StartE_ChoiceIndex = E_ChoiceIndex.Choice1;
                                    break;
                                case 'S': case 's':
                                    StartE_ChoiceIndex = E_ChoiceIndex.Choice2;
                                    break;
                                case ' ':
                                    if (StartE_ChoiceIndex == E_ChoiceIndex.Choice1){
                                        GameState = E_GameState.gamming;
                                        WindowState = E_WindowState.playing;
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
                    case E_WindowState.playing:
                        while (GameState == E_GameState.gamming)
                        {
                            //绘制边界
                            Console.ForegroundColor = ConsoleColor.Red;
                            for (int i = 1 ; i < WindowSize_y; i++){
                                if (i == 1 || i == 19 || i == 24 || i == 29)
                                    Console.Write("■■■■■■■■■■■■■■■■■■■■■■■■■");
                                else
                                    Console.Write("■                                              ■");
                            }
                            //绘制教程
                            PrintInfo(2,19,"□:普通格子","White");
                            PrintInfo(2,20,"停:暂停,一回合不动    ","Blue");
                            PrintInfo(24,20,"●:炸弹,倒退5格","Red");
                            PrintInfo(2,21,"★:时空隧道,随机倒退,暂停,换位置","Yellow");
                            PrintInfo(2,22,"我:玩家   ","Cyan");
                            PrintInfo(12,22,"PC:电脑   ","Magenta");
                            PrintInfo(22,22,"◆:玩家电脑重合 ","Green");
                            
                            Map map = new Map(14, 3, 80);
                            Player player = new Player(0, E_PlayerType.player);
                            Player computer = new  Player(0,E_PlayerType.computer);
                            map.Draw();
                            DrawPlayer(player,computer,map);

                            int isGameOver = 0;
                            while (true)
                            {
                                Console.ReadKey(true);
                                isGameOver = RandomMove(WindowSize_x,WindowSize_y,ref player, ref computer, map);
                                map.Draw();
                                DrawPlayer(player, computer, map);
                                if (isGameOver != 0)
                                {
                                    Console.ReadKey(true);
                                    if (isGameOver == 1){
                                        GameState = E_GameState.win;
                                    }else{
                                        GameState = E_GameState.lose;
                                    }
                                    WindowState = E_WindowState.gameover;
                                    Console.Clear();
                                    break;
                                }

                                Console.ReadKey(true);
                                isGameOver = RandomMove(WindowSize_x,WindowSize_y,ref computer, ref player, map);
                                map.Draw();
                                DrawPlayer(player, computer, map);
                                if (isGameOver != 0)
                                {
                                    Console.ReadKey(true);
                                    if (isGameOver == 1){
                                        GameState = E_GameState.win;
                                    }else{
                                        GameState = E_GameState.lose;
                                    }
                                    WindowState = E_WindowState.gameover;
                                    Console.Clear();
                                    break;
                                }
                            }
                        }

                        break;
                    #endregion

                    #region 结束窗口
                    case E_WindowState.gameover:
                        E_ChoiceIndex OverE_ChoiceIndex = E_ChoiceIndex.Choice1;
                        if (GameState == E_GameState.win){
                            Console.SetCursorPosition(WindowSize_x/2 - 5,5);
                            Console.ForegroundColor = ConsoleColor.Red;
                            Console.Write("你胜利了!");
                        }
                        if (GameState == E_GameState.lose){
                            Console.SetCursorPosition(WindowSize_x/2 - 5,5);
                            Console.ForegroundColor = ConsoleColor.Green;
                            Console.Write("你失败了!");
                        }
                        while(true){
                            bool isExitWhile = false; 
                            Console.ForegroundColor = OverE_ChoiceIndex == E_ChoiceIndex.Choice1 ? ConsoleColor.Red : ConsoleColor.White;
                            PrintInfo(WindowSize_x/2 - 6, 10,"回到开始界面");
                            Console.ForegroundColor = OverE_ChoiceIndex == E_ChoiceIndex.Choice2 ? ConsoleColor.Red : ConsoleColor.White;
                            PrintInfo(WindowSize_x/2 - 4, 12, "退出游戏");
                            char input = Console.ReadKey(true).KeyChar;
                            switch (input)
                            {
                                case 'W': case 'w':
                                    OverE_ChoiceIndex = E_ChoiceIndex.Choice1;
                                    break;
                                case 'S': case 's':
                                    OverE_ChoiceIndex = E_ChoiceIndex.Choice2;
                                    break;
                                case ' ':
                                    if (OverE_ChoiceIndex == E_ChoiceIndex.Choice1){
                                        WindowState = E_WindowState.start;
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
}
