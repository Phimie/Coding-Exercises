using System;
using System.Text;
namespace Test
{
    class Program
    {
        static void Main(string[] args)
        {
            //string 本质是 char[] 数组
            Console.WriteLine("字符串的基本操作");
            string str1 = "abc";
            Console.WriteLine(str1[0]);
            char[] arr = str1.ToCharArray();
            Console.WriteLine(arr[1]);
            for (int i = 0; i < str1.Length; i++)  //.Length 是 string 的属性
            {
                Console.Write(arr[i]);
            }
            Console.WriteLine();

            //字符串拼接
            Console.WriteLine("\n字符串拼接");
            string str2 = "def";
            string str3 = str1 + str2;  //字符串拼接
            string str4 = string.Concat(str1, str2);  //Concat 是 string 的静态方法，字符串拼接
            string str5 = string.Format("{0}{1}", str1, str2);  //Format 是 string 的静态方法，字符串格式化
            Console.WriteLine(str3);
            Console.WriteLine(str4);
            Console.WriteLine(str5);

            //正向查找字符位置
            Console.WriteLine("\n正向查找字符位置");
            string str6 = "hello world";
            int index1 = str6.IndexOf('o');  //IndexOf 是 string 的方法，返回字符在字符串中第一次出现的位置
            Console.WriteLine(index1);

            //反向查找字符位置
            Console.WriteLine("\n反向查找字符位置");
            int index2 = str6.LastIndexOf('o');  //LastIndexOf 是 string 的方法，返回字符在字符串中最后一次出现的位置
            Console.WriteLine(index2);

            //移除指定位置后的字符
            Console.WriteLine("\n移除指定位置后的字符");
            string str7 = str6.Remove(5);  //Remove 是 string 的方法，移除指定位置后的所有字符
            Console.WriteLine(str7);
            string str8 = str6.Remove(5, 1);  //Remove 是 string 的方法，移除指定位置后的指定数量的字符
            Console.WriteLine(str8);

            //替换指定字符
            Console.WriteLine("\n替换指定字符");
            string str9 = str6.Replace('o', 'x');  //Replace 是 string 的方法，替换指定字符
            Console.WriteLine(str9);

            //大小写转换
            Console.WriteLine("\n大小写转换");
            string str10 = str6.ToUpper();  //ToUpper 是 string 的方法，将字符串转换为大写
            string str11 = str6.ToLower();  //ToLower 是 string 的方法，将字符串转换为小写
            Console.WriteLine(str10);
            Console.WriteLine(str11);

            //字符串截取
            Console.WriteLine("\n字符串截取");
            string str12 = str6.Substring(0, 5);  //Substring 是 string 的方法，截取字符串，参数1：起始位置，参数2：截取长度
            Console.WriteLine(str12);

            //字符串分割
            Console.WriteLine("\n字符串分割");
            string[] arr2 = str6.Split(' ');  //Split 是 string 的方法，分割字符串，参数：分割符
            foreach (string s in arr2)
            {
                Console.WriteLine(s);
            }

            //string是特殊的引用类型，具有值类型的特性
            //如果每次重新赋值或者拼接时,会分配新的内存空间,效率较低
            //如果需要频繁修改字符串,建议使用StringBuilder类,效率较高
            Console.WriteLine("\n使用StringBuilder类");
            StringBuilder sb = new StringBuilder("123123123");  //StringBuilder 是 System.Text 命名空间下的类，提供了可变字符串的功能
            sb.Append("456");  //Append 是 StringBuilder 的方法，用于在字符串末尾追加内容
            Console.WriteLine(sb.ToString());  //ToString 是 StringBuilder 的方法，将 StringBuilder 转换为 string
            //获得容量
            Console.WriteLine(sb.Capacity);  //Capacity 是 StringBuilder 的属性，表示 StringBuilder 的容量


            Console.WriteLine("\n按任意键继续");
            Console.ReadKey(true);
        }
    }
}