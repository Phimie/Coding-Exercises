using System;
namespace LearningGeneric
{
    //泛型是一种允许在定义类、接口、方法等时使用占位符来表示类型的编程技术。
    //通过使用泛型，我们可以创建可重用的代码，避免重复编写相似的代码，并且在编译时提供类型安全检查。
    class Test<T>
    {
        public T value { get; set; }

    }
    interface ITest<T>
    {
        public T value { get; set; }
    }

    class Test2 : ITest<string>
    {
        public string value { get; set; }
    }

    class Test3
    {
        //泛型函数,可以在函数定义中使用类型参数，使得函数能够接受不同类型的参数并返回相应类型的结果。
        public void Print<T>(T value)
        {
            Console.WriteLine(value);
        }
    }
    class Test3<T>
    {
        public K Print<K>(K value)
        {
            Console.WriteLine(value);
            return value;
        }
    }

    //使用泛型优化ArrayList
    //可以一定程度上避免装箱和拆箱操作，提高性能,装箱和拆箱的缺点是会产生额外的内存分配和垃圾回收开销，尤其是在频繁使用值类型时。通过使用泛型，我们可以直接操作值类型而不需要装箱，从而提高性能。
    class ArrayList<T>
    {
        private T[] items;
        private int count;

        public ArrayList()
        {
            items = new T[4];
            count = 0;
        }

        public void Add(T item)
        {
            if (count == items.Length)
            {
                Array.Resize(ref items, items.Length * 2);
            }
            items[count++] = item;
        }

        public T Get(int index)
        {
            if (index < 0 || index >= count)
            {
                throw new IndexOutOfRangeException();
            }
            return items[index];
        }

        public int Count => count;
    }

    //泛型约束,可以使用where关键字来指定类型参数必须满足的约束条件。例如，可以要求类型参数必须是某个类的子类，或者必须实现某个接口。
    //泛型约束一共存在6种:
    //1. where T : class  // T必须是引用类型
    //2. where T : struct  // T必须是值类型
    //3. where T : new()  // T必须具有无参数的构造函数
    //4. where T : <base class name>  // T必须是指定基类的子类
    //5. where T : <interface name>  // T必须实现指定的接口
    //6. where T : K  // 另一个泛型类型本身或者派生类型

    class Test4<T> where T : struct
    {
        public T value { get; set; }
    }
    //多个泛型字母约束
    class Test5<T, K> where T : class where K : struct // T必须是引用类型，K必须是值类型
    {
        public T referenceTypeValue { get; set; }
        public K valueTypeValue { get; set; }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Test<int> test = new Test<int>();
            test.value = 10;
            Console.WriteLine(test.value);

            Test2 test2 = new Test2();
            test2.value = "Hello";
            Console.WriteLine(test2.value);
            Test3 test3 = new Test3();
            test3.Print("Hello World");
            Test3<int> test4 = new Test3<int>();
            test4.Print(100);
            Test3<string> test5 = new Test3<string>();
            test5.Print("Hello Generic");
            Test4<int> test6 = new Test4<int>();
            //泛型约束
            test6.value = 20;
            Console.WriteLine(test6.value);//Test4<string> test7 = new Test4<string>(); //编译错误，因为string不是值类型


        }
    }
}