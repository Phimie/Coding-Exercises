using System;
using System.Collections;
namespace LearningStack
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Stack"); //先进后出
            Stack stack = new Stack();

            //增(压栈)
            //stack是object类型的集合，可以存储任意类型的数据
            stack.Push(1);
            stack.Push("C#");
            stack.Push(3.14);
            stack.Push(true);

            //取(弹栈)
            stack.Pop();
            Console.WriteLine(stack.Pop());

            //查
            Console.WriteLine(stack.Peek());
            if (stack.Contains("C#"))  //Contains方法用于检查Stack中是否存在指定的元素，如果存在则返回true，否则返回false。
            {
                Console.WriteLine("存在C#");
            }

            //遍历
            //方法1 使用foreach循环直接遍历Stack集合,Stack会按照先进后出的顺序返回元素
            foreach (var item in stack)
            {
                Console.WriteLine(item);
            }
            //方法2 使用ToArray方法将Stack转换为数组，然后遍历数组。
            object[] array = stack.ToArray(); //将Stack转换为数组
            foreach (var item in array)
            {
                Console.WriteLine(item);
            }

            //方法3 循环弹栈
            while (stack.Count > 0)
            {
                Console.WriteLine(stack.Pop());
            }



            Console.WriteLine("按任意键继续...");
            Console.ReadKey();
        }
    }
}