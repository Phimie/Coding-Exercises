using System;
namespace LearningOOP
{
    class GameObject
    {
        public int a;
        public GameObject(int a)
        {
            this.a = a;
        }
    }

    enum E_SexType
    {
        Man,
        Woman,
        none,
    }

    struct Position
    {

    }

    class Pet
    {

    }

    class Person
    {
        //成员变量
        private string name = "无姓名";  //与结构体不同,类里面,成员变量是可以直接初始化的
        public int age;

        private int money;
        E_SexType sex;
        Person girlFriend;   //与结构体不同,类里面可以声明同名变量
        Person[] normalFriend;
        Position pos;      //类里面可以声明任意变量类型,甚至也可以是结构体
        Pet pet;

        //成员属性  //对成员变量有保护作用
        public string Name
        {
            get
            {
                return name;        //代表这个属性可以获取的内容
            }
            set
            {
                name = value; //value关键字 用于表示 外部传入的值
            }
        }

        public int Money
        {
            private get   //将get设置为privat,将成员属性设置为只能修改不能获取
            {
                return money - 5;
            }
            set
            {
                if (value < 0)
                {
                    value = 0;
                    Console.WriteLine("钱不能少于0,强制设置为0");
                }
                money = value + 5;  //可以对成员进行加密操作
            }
        }

        public float Height  //自动成员属性 没有对应的成员变量  用于快速创建一个只得不改或者只改不得的成员变量
        {
            get;
            private set;
        }



        //成员方法
        public Person() : this("默认名字")  //调用无参构造函数之前先调用一个string参数的构造函数
        {

        }

        public Person(string name)  //构造函数重载
        {
            this.name = name;
            Console.WriteLine("调用了this(name)");
        }
        public Person(string name, int age, E_SexType sex) : this(name)  //:this() 可以在没有参数传入的时候默认调用无参构造函数
        {
            this.name = name + "Test";
            this.age = age;
            this.sex = sex;

        }
        public void Speak(string str)
        {
            Console.WriteLine("{0}说{1}", name, str);
        }

        public void Info()
        {
            Console.WriteLine("{0},{1},{2}", name, age, sex);
        }


        ~Person()    //当引用类型的堆内存被回收时,会自动调用该函数
        {
            Console.WriteLine("析构函数调用");
        }
    }

    class Student
    {
        private string name;
        private int age;
        private Student[] friends;

        private int[,] array;

        static public void Speak()   //静态成员长期存储在堆中,所以可以不用实例化对象直接调用
        {
            Console.WriteLine("Student类静态成员方法测试");
        }

        public const float PI = 3.14159f; //常量是特殊的静态成员,也可以不用实例化对象直接调用

        public Student this[int index]  //索引器:可以让对象可以像数组一样通过索引访问其中元素,使程序看起来更直观
        {
            get
            {
                if (friends == null || friends.Length - 1 < index)  //索引器里面是可以写逻辑的
                {
                    return null;
                }

                return friends[index];
            }
            set
            {
                if (friends == null)
                {
                    friends = new Student[] { value };
                }
                else if (index > friends.Length - 1)
                {
                    friends[friends.Length - 1] = value;
                }
                friends[index] = value;
            }
        }

        public int this[int i, int j]  //索引器重载
        {
            get
            {
                return array[i, j];
            }
            set
            {
                array[i, j] = value;
            }
        }


        public Student()
        {
            friends = new Student[10];
        }
        public Student(string name, int age) : this()
        {
            this.name = name;
            this.age = age;
        }
        public void Info()
        {
            Console.WriteLine("{0},{1},{2}", name, age, friends);
        }
    }
    //静态类 : 常用于将一些静态成员写在静态类中,表现为一个工具类,因为是工具类,所以静态类不能被实例化
    //比如 console就是一个静态类
    static class Print
    {
        public static int test = 0; //静态成员变量

        static Print() //静态构造函数不能使用访问修饰符,不能有参数,只会在第一次使用静态类的时候自动调用一次
        {
            Console.WriteLine("触发静态类中的静态构造函数的自动调用");
        }


        public static void Write(string text)
        {
            Console.Write(text);
        }
        public static void WriteLine(string text)
        {
            Console.WriteLine(text);
        }
    }

    class Tools
    {
        //普通类中的静态构造函数在使用的时候只会自动调用一次
        static Tools()  //静态构造函数和普通构造函数可以同时存在,
        {

        }
        public Tools()  //普通构造函数
        {

        }
    }

    class Program
    {
        static void Main(string[] agrs)
        {
            //测试普通封装和类型
            GameObject A = new GameObject(2);
            GameObject B = A;
            B = null;
            Console.WriteLine(A.a); //与结构体不同,类是引用类型,B=null使栈上存的地址置为null,不影响A;

            //测试构造析构,GC
            Person p1 = new Person("张三", 10, E_SexType.Man);
            p1.Speak("你好");
            p1.Info();
            p1 = null;

            GC.Collect();  //手动触发垃圾回收GC的方法

            //测试成员属性
            Person p2 = new Person();
            p2.Name = "测试成员属性";
            Console.WriteLine(p2.Name);


            //测试索引器
            Student s1 = new Student();
            s1[0] = new Student("李四同学", 11);
            s1[0].Info();

            //测试静态成员
            Student.Speak();
            Console.WriteLine(Student.PI);

            //测试静态类
            Print.Write("测试静态类");
            Print.WriteLine("测试静态类");



            Console.WriteLine("请按任意键继续");
            Console.ReadKey(true);
        }
    }
}