using System;
namespace LearningOOP_part1
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

    class Test
    {
        //普通类中的静态构造函数在使用的时候只会自动调用一次
        static Test()  //静态构造函数和普通构造函数可以同时存在,
        {

        }
        public Test()  //普通构造函数
        {

        }
    }

    static class Tools  //拓展方法必须写在静态类中
    {
        public static void SpeakValue(this int value)  //拓展方法:可以在不修改原有类的基础上,为原有类添加新的方法,第一个参数必须使用this关键字修饰,并且参数类型(value)就是要拓展的类
        {
            Console.WriteLine("为int类型拓展方法测试,传入的值是{0}", value);
        }

        public static void SpeakValue(this string value, string name)  //拓展方法重载
        {
            Console.WriteLine("为string类型拓展方法测试,传入的值是{0},名字是{1}", value, name);
        }

        public static void Func3(this MyClass myClass)  //为自定义类拓展方法测试
        {
            Console.WriteLine("为MyClass类拓展方法测试,成员变量a的值是{0}", myClass.a);
        }

        public static void Func2(this MyClass myClass) //如果拓展方法和原有类中的方法重名,调用时会优先调用原有类中的方法,只有当原有类中没有这个方法时才会调用拓展方法
        {
            Console.WriteLine("这是拓展方法Func2");
        }
    }

    partial class MyClass
    {
        public int a = 10;
        public void Func1()
        {
            Console.WriteLine("MyClass的Func1方法");
        }
        public void Func2()
        {
            Console.WriteLine("MyClass的Func2方法");
        }

        class MyClassInner  //内部类,只能被外部类访问,不能被外部类实例化,只能被外部类的成员方法访问
        {

        }
    }

    partial class MyClass  //分部类,可以将一个类分成多个部分,分别写在不同的文件中,编译时会将这些部分合并成一个完整的类
    {
        public void Func4()
        {
            Console.WriteLine("MyClass的Func4方法");
        }
    }

    class Point
    {
        private int x;
        private int y;

        public Point()
        {

        }

        public Point(int x, int y) : this()
        {
            this.x = x;
            this.y = y;
        }

        public static Point operator +(Point p1, Point p2)  //运算符重载:可以让自定义类的对象使用运算符进行运算,需要使用operator关键字重载对应的运算符
        {
            Point result = new Point();
            result.x = p1.x + p2.x;
            result.y = p1.y + p2.y;
            return result;
        }

        public void Info()
        {
            Console.WriteLine("Point的坐标是({0},{1})", x, y);
        }
    }

    class Father //子类可以继承父类的成员变量和成员方法,但是不能继承父类的构造函数和析构函数
    {
        public string name;

        protected int age;  //protected修饰的成员只能被子类访问,不能被外部访问
        public Father(string name)
        {
            this.name = name;
        }
        public void Speak()
        {
            Console.WriteLine("我是父类,我的名字是{0}", name);
        }
    }

    class Son : Father
    {
        public Son(string name) : base(name)  //子类的构造函数需要调用父类的构造函数,使用base关键字调用
        {

        }
        public void SonSpeak()
        {
            Console.WriteLine("我是子类,我的名字是{0}", name);
        }
    }

    class Monster
    {
        protected int hp;
    }

    class Boss : Monster
    {
        public void Skill()
        {
            Console.WriteLine("boss释放技能");
        }
    }

    class Goblin : Monster
    {
        public void Attack()
        {
            Console.WriteLine("goblin攻击");
        }
    }

    //密封类:被sealed修饰的类,不能被继承,但是可以被实例化,通常用于一些工具类或者一些不需要被继承的类
    sealed class NotHaveSon
    {

    }

    //测试多态
    class Animal
    {
        public string name;

        public Animal(string name)
        {
            this.name = name;
        }
        public virtual void Speak()  //虚函数:使用virtual关键字修饰的方法可以被子类重写,实现多态
        {
            Console.WriteLine("动物叫");
        }
    }

    class Dog : Animal
    {

        public Dog(string name) : base(name)
        {
        }

        public override void Speak()  //使用override关键字修饰的方法是对父类方法的重写,实现多态
        {
            base.Speak();  //通过base保留调用父类的Speak方法
            Console.WriteLine("狗叫");
        }
    }

    //抽象类
    abstract class Thing  //被abstract修饰的类,不能被实例化,只能被继承,通常用于一些需要被继承的类,比如动物类,植物类等
    {
        public abstract void DoSomething();  //抽象方法:没有方法体,需要在子类中重写,实现多态
    }

    class Book : Thing
    {
        public override void DoSomething()  //重写抽象方法,实现多态
        {
            Console.WriteLine("书籍可以被阅读");
        }
    }

    //接口
    interface IShape  //接口:定义了一组方法,但是没有方法体,需要在实现类中实现,通常用于一些需要被实现的类,比如圆形类,矩形类等
    {
        void Draw();  //接口中的方法默认是public abstract的,所以不需要使用abstract关键字修饰
        string Name //接口中的属性
        {
            get;
            set;
        }

        int this[int index]  //接口中的索引器
        {
            get;
            set;
        }

        event Action OnDraw;  //接口中的事件
    }

    class Shape { }

    class Circle : Shape, IShape  //一个类可以实现多个接口,需要使用逗号分隔
    {
        public string Name { get; set; }

        public int this[int index]
        {
            get
            {
                return 0;
            }
            set
            {

            }
        }

        public event Action OnDraw;

        public void Draw()
        {
            Console.WriteLine("画一个圆");
            OnDraw?.Invoke();  //触发事件
        }
    }

    class Program
    {
        static void Main(string[] agrs)
        {
            //测试普通封装和类型
            Console.WriteLine("--------- 开始测试普通封装和类型 ---------\n");
            GameObject A = new GameObject(2);
            GameObject B = A;
            B = null;
            Console.WriteLine(A.a); //与结构体不同,类是引用类型,B=null使栈上存的地址置为null,不影响A;
            Console.WriteLine("\n--------- 结束测试普通封装和类型 ---------\n");

            //测试构造析构,GC
            Console.WriteLine("--------- 开始测试构造析构,GC ---------\n");
            Person p1 = new Person("张三", 10, E_SexType.Man);
            p1.Speak("你好");
            p1.Info();
            p1 = null;
            Console.WriteLine("\n--------- 结束测试构造析构,GC ---------\n");

            GC.Collect();  //手动触发垃圾回收GC的方法

            //测试成员属性
            Console.WriteLine("--------- 开始测试成员属性 ---------\n");
            Person p2 = new Person();
            p2.Name = "测试成员属性";
            Console.WriteLine(p2.Name);
            Console.WriteLine("\n--------- 结束测试成员属性 ---------\n");

            //测试索引器
            Console.WriteLine("--------- 开始测试索引器 ---------\n");
            Student s1 = new Student();
            s1[0] = new Student("李四同学", 11);
            s1[0].Info();
            Console.WriteLine("\n--------- 结束测试索引器 ---------\n");

            //测试静态成员
            Console.WriteLine("--------- 开始测试静态成员 ---------\n");
            Student.Speak();
            Console.WriteLine(Student.PI);
            Console.WriteLine("\n--------- 结束测试静态成员 ---------\n");

            //测试静态类
            Console.WriteLine("--------- 开始测试静态类 ---------\n");
            Print.Write("测试静态类");
            Print.WriteLine("测试静态类");
            Console.WriteLine("\n--------- 结束测试静态类 ---------\n");

            //测试拓展方法
            Console.WriteLine("--------- 开始测试拓展方法 ---------\n");
            int n = 10;
            n.SpeakValue(); //为int类型拓展方法测试,传入的值是10
            string str = "测试";
            str.SpeakValue("张三"); //为string类型拓展方法测试,传入的值是测试,名字是张三
            MyClass myClass = new MyClass();
            myClass.Func3();  //为MyClass类拓展方法测试,成员变量a的值是10
            myClass.Func2();  //调用时会优先调用原有类中的方法,只有当原有类中没有这个方法时才会调用拓展方法,所以输出的是MyClass的Func2方法
            Console.WriteLine("\n--------- 结束测试拓展方法 ---------\n");


            //测试运算符重载
            Console.WriteLine("--------- 开始测试运算符重载 ---------\n");
            Point point1 = new Point(1, 2);
            Point point2 = new Point(3, 4);
            Point point3 = point1 + point2;  //运算符重载后,可以直接使用+运算符对Point类的对象进行运算
            point3.Info();
            Console.WriteLine("\n--------- 结束测试运算符重载 ---------\n");

            //测试基本继承
            Console.WriteLine("--------- 开始测试基本继承 ---------\n");
            Son son1 = new Son("儿子");
            son1.SonSpeak();

            Console.WriteLine("\n--------- 结束测试基本继承 ---------\n");

            //测试里氏替换原则,is as, object
            Console.WriteLine("--------- 测试里氏替换原则,is as, object ---------\n");
            Father son2 = new Son("测试"); //用父类容器 装载子类对象
            if (son2 is Son)  //is关键字 用于判断一个对象是否是某个类型的实例,如果是返回true,否则返回false
            {
                (son2 as Son).SonSpeak();  //将父类对象转换为子类对象,调用子类方法   //as关键字 用于将一个对象转换为某个类型的实例,如果转换成功返回该类型的对象,否则返回null
            }


            Random random = new Random();
            int randomNum;
            Monster[] monsters = new Monster[10];
            for (int i = 0; i < monsters.Length; i++)
            {
                randomNum = random.Next(0, 4);
                if (randomNum == 0)
                {
                    monsters[i] = new Boss();
                }
                else
                {
                    monsters[i] = new Goblin();
                }
            }
            for (int i = 0; i < monsters.Length; i++)
            {
                if (monsters[i] is Boss)
                {
                    (monsters[i] as Boss).Skill();
                }
                else if (monsters[i] is Goblin)
                {
                    (monsters[i] as Goblin).Attack();
                }
            }

            object obj = new Son("测试");  //object是所有类的父类,所以可以用object类型的变量来接收任何类型的对象,但是只能调用object类中的方法,如果要调用子类的方法,需要先将object类型的变量转换为子类类型
            if (obj is Son)
            {
                (obj as Son).SonSpeak();
            }


            Console.WriteLine("--------- 结束测试里氏替换原则,is as, object ---------\n");

            //测试多态
            Console.WriteLine("--------- 测试多态vob,抽象函数,接口 ---------\n");
            Animal animal = new Dog("旺财");
            animal.Speak();  //调用的是Dog类重写的Speak方法,实现了多态

            Thing book = new Book();
            book.DoSomething();

            IShape circle = new Circle();
            circle.Draw();

            Console.WriteLine("\n--------- 结束测试多态vob,抽象函数,接口 ---------\n");




            Console.WriteLine("请按任意键继续");
            Console.ReadKey(true);
        }
    }
}
