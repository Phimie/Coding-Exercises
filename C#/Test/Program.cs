using System;

class Program
{
    static void Main(string[] args){
        #region 基础Test
        //io
        Console.WriteLine("Hello, World!");
        Console.Write("nihao");
        Console.Read();
        Console.ReadLine();
        Console.ReadKey();

        //变量
        int i = 0,j = 0;
        string qwer = "123";
        const float PI = 3.1415926f; //C#默认所有小数常量为double,必须加f明确是float类型才能赋值给float PI;
        long l = i;  //隐式转换,long类型>int类型,所以可以自动进行隐式转换
        j = (short)l; //利用()来进行显示转换
        j = int.Parse(qwer); //利用: 类型.Parse(string) 的方法来处理string的显示转换
        qwer = j.ToString(); //利用: 变量.ToString() 的方法来将其它类型转换成string
        Console.WriteLine("1234" + 1 + true); //进行字符串拼接时,会自动调用tostring来全部转换成string

        //异常捕获
        try{

        }catch{

        }finally{
            
        }
        #endregion
    }
}

