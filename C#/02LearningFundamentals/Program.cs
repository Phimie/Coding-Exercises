using System;
namespace LearningBasics
{
    //枚举
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

    //结构体
    struct Car
    {
        int battery;   //结构体中声明的变量不能直接初始化
        string color;     //默认private
        string name;

        public Car(int battery, string color, string name)
        {
            this.battery = battery;
            this.color = color;
            this.name = name;
        }

        public void info()
        {   //修改为public
            Console.WriteLine("电池容量:{0},颜色:{1},型号名字:{2}", battery, color, name);
        }

    }




    class Program
    {
        //默认参数
        static void GetMoney(int money = 10)
        {
            Console.WriteLine("今天得到了{0}块钱", money);
        }

        //函数重载,注意:函数重载必须放在类级别中
        static void GetMoney(int money1, int money2)
        {
            Console.WriteLine("今天得到了两次钱,一次是{0},第二次是{1}", money1, money2);
        }

        static void Main(string[] args)
        {
            #region 枚举
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
            #endregion

            #region 数组
            int[] arr1 = new int[8] { 1, 2, 3, 4, 5, 6, 7, 8 }; //确定数组大小
            int[] arr2 = new int[] { 1, 2, 3, 4, 5, 5 }; //根据初始化内容确定数组大小
            int[] arr3 = { 1, 2, 3, 4, 5, 6, 7 }; //同上
            Console.WriteLine(arr1.Length); //获取数组长度
            Console.WriteLine(arr2[2]); //根据索引返回值

            int[,] arr4 = new int[2, 2] { { 1, 2 }, { 3, 4 } };  //二维数组声明
            int[,] arr5 = { { 5, 6 }, { 7, 8 } };
            Console.WriteLine(arr4.Length);
            Console.WriteLine(arr4.GetLength(0));  //行  //通过.GetLength()方法来得到行和列的长度
            Console.WriteLine(arr4.GetLength(1));  //列

            int[] a = new int[] { 10 };
            int[] b = a;
            b[0] = 20;
            Console.WriteLine(a[0]); //数组是引用类型,变量存储的是数据在内存中的地址;

            string str1 = "123";
            string str2 = str1;
            str2 = "321";
            Console.WriteLine(str1); //string是特殊的引用类型,它具备值类型的特征
            Console.WriteLine(str2);
            #endregion


            #region 函数
            //函数基础语法
            static void SayHello(string name)
            {
                Console.WriteLine("Hello,{0}", name);
                //return; 返回类型是void可以省略return;
            }
            SayHello(str1);

            //ref和out
            int value = 5;
            static void ChangeValue_ref(ref int value)
            {  //通过ref传入引用值
                value = 3;
            }
            static void ChangeValue_out(out int value)
            {
                value = 3;
            }
            ChangeValue_ref(ref value);   //ref和out的区别:
            ChangeValue_out(out value);   //1.ref传入的变量必须初始化 out不用
            Console.WriteLine(value);     //2.out传入的变量必须在内部复制 ref不用

            //变长参数
            static void PrintAll(params string[] items)
            { //变长参数关键字params
                foreach (string item in items)
                {          //枚举型for循环
                    Console.WriteLine(item);
                }
            }
            PrintAll("苹果", "香蕉", "栗子");

            GetMoney();
            GetMoney(100);
            GetMoney(2, 3);

            #endregion


            #region 结构体
            Car car1 = new Car(12, "Red", "婴儿车");
            car1.info();


            #endregion

            Console.WriteLine("按任意键继续");
            Console.ReadKey(true);
        }
    }
}
