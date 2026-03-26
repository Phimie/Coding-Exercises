using System;
using System.Collections;
namespace LearningAdvanced
{
    class Program
    {
        //ArrayList
        static void Main(string[] args)
        {
            //增
            ArrayList array = new ArrayList();
            array.Add(1);
            array.Add("123");
            array.Add(true);
            array.Add(new object());
            ArrayList array2 = new ArrayList();
            array2.Add(1);
            array2.Add(2);
            array.AddRange(array2); //增加一个范围,即array2

            array.Insert(1, "1234");

            //删
            array.Remove(1);//移除指定元素
            array.RemoveAt(0);//移除指定位置的元素,参数是索引
            array2.Clear(); //清空

            //查
            Console.WriteLine(array[0]);
            if (array.Contains("2345"))  //查找元素,返回bool
            {
                Console.WriteLine("存在");
            }

            int index = array.IndexOf(true);  //查找元素,返回索引
            Console.WriteLine(index);
            index = array.LastIndexOf(true);  //从后查找,返回索引
            Console.WriteLine(index);

            //遍历
            Console.WriteLine(array.Count); //通过Count来获取长度而不是Length
            Console.WriteLine(array.Capacity); //通过Capacity来获取容量

            foreach (object item in array)
            {
                Console.Write(item);
                Console.Write(',');
            }

            //装箱拆箱  
            //ArrayList本质上就是一个object数组,所以什么都可以装,所以存在装箱拆箱
            int i = 1;
            array[0] = i; //装箱
            i = (int)array[0]; //拆箱

            Console.WriteLine();
            Console.WriteLine("请按任意键继续");
            Console.ReadKey(true);
        }

    }
}