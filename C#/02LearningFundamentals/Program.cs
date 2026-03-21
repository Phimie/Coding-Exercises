using System;
namespace LearningBasics
{
    enum E_playerType  //默认为int
    {
        Player1,       //默认为0
        Player2,      //默认为1
        Player3
    }

    enum E_MonsterType
    {
        Boss,
        Normal
    }

    class Program
        {
            static void Main(string[] args)
            {
                //枚举
                E_playerType playerType = E_playerType.Player1;  //声明枚举变量

                switch (playerType)   //枚举和switch常搭配使用
                {
                    case E_playerType.Player1:
                        break;
                    case E_playerType.Player2:
                        break;
                    case E_playerType.Player3:
                        break;
                }

                //数组
                int[] arr1 = new int[8] {1,2,3,4,5,6,7,8}; //确定数组大小
                int[] arr2 = new int[] {1,2,3,4,5,5}; //根据初始化内容确定数组大小
                int[] arr3 = {1,2,3,4,5,6,7}; //同上
                Console.WriteLine(arr1.Length); //获取数组长度
                Console.WriteLine(arr2[2]); //根据索引返回值

                int[,] arr4 = new int[2,2] {{1,2},{3,4}};  //二维数组声明
                int[,] arr5 = {{5,6},{7,8}};
                Console.WriteLine(arr4.Length);
                Console.WriteLine(arr4.GetLength(0));  //行  //通过.GetLength()方法来得到行和列的长度
                Console.WriteLine(arr4.GetLength(1));  //列






                Console.WriteLine("按任意键继续");
                Console.ReadKey(true);
            }
        }
}

      