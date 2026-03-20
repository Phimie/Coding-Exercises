using System;

class Program
{
    static void Main(string[] args){
        #region 基础Test
        //io
        Console.WriteLine("Hello, World!");
        Console.Write("nihao");
        /*
        Console.Read();
        Console.ReadLine();
        Console.ReadKey(); //读取任意按键并跳过
        */
        char key = Console.ReadKey(false).KeyChar; //读取输入的按键,ReadKey接收参数true则不会把输入的内容输出在控制台

        //变量
        int i = 0,j = 0;
        string qwer = "123";
        const float PI = 3.1415926f; //C#默认所有小数常量为double,必须加f明确是float类型才能赋值给float PI;
        long l = i;  //隐式转换,long类型>int类型,所以可以自动进行隐式转换
        j = (short)l; //利用()来进行显示转换
        j = int.Parse(qwer); //利用: 类型.Parse(string) 的方法来处理string的显示转换
        qwer = j.ToString(); //利用: 变量.ToString() 的方法来将其它类型转换成string
        Console.WriteLine("1234" + 1 + true); //进行字符串拼接时,会自动调用tostring来全部转换成string
        string str1 = string.Format("你好{0},你好{1}","1","2"); //利用string.Format进行更灵活的字符串拼接

        //异常捕获
        try{
            qwer = "qwer";
            j = int.Parse(qwer);
            Console.WriteLine("没问题");
        }catch{
            Console.WriteLine("出错了");
        }finally{
            Console.WriteLine("最终执行");
        }

        //控制台
        Console.BackgroundColor = ConsoleColor.White; //修改背景颜色,必须clear()才能显现;
        Console.Clear();
        Console.SetWindowSize(50,25);
        Console.SetBufferSize(50,100); //缓冲区尺寸(接收参数(x,y)
        Console.SetCursorPosition(17,5); //设置光标位置 (视觉上1y = 2x)
        Console.CursorVisible = false; //设置光标的可见性;
        Console.ForegroundColor = ConsoleColor.Red; //修改字体颜色
        Console.WriteLine("输入任意键继续");
        Console.ReadKey();
        Environment.Exit(0); //关闭控制台
        #endregion
    }
}

