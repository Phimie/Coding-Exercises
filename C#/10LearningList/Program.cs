using System;
using System.Collections.Generic;
namespace LearningList
{
    class Program
    {
        static void Main(string[] args)
        {

            // List<T> 是一个泛型集合类，可以存储任意类型的数据
            // 对比ArrayList，List<T> 是类型安全的，性能更好
            // 避免了装箱和拆箱的开销
            // 现代C# 开发中，推荐使用 List<T> 而不是 ArrayList
            List<int> list = new List<int>();
            List<string> list2 = new List<string>();
            List<bool> list3 = new List<bool>();

            //增
            list.Add(1);
            list.Add(2);
            list.Add(3);
            list2.Add("hello");
            list2.Add("world");
            list.AddRange(new int[] { 4, 5, 6 });
            //删
            list.Remove(2);
            list.RemoveAt(0);

            //改
            list[0] = 10;

            //查
            int index = list.IndexOf(3);
            int count = list.Count;

            //遍历
            foreach (int item in list)
            {
                Console.WriteLine(item);
            }


            Console.WriteLine("请按任意键继续...");
            Console.ReadKey();
        }
    }
}