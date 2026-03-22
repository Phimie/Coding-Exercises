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
        string name = "无姓名";  //与结构体不同,类里面,成员变量是可以直接初始化的
        int age;
        E_SexType sex;
        Person girlFriend;   //与结构体不同,类里面可以声明同名变量
        Person[] normalFriend;
        Position pos;      //类里面可以声明任意变量类型,甚至也可以是结构体
        Pet pet;


    }

    class Program
    {
        static void Main(string[] agrs)
        {
            GameObject A = new GameObject(2);
            GameObject B = A;
            B = null;
            Console.WriteLine(A.a); //与结构体不同,类是引用类型,B=null使栈上存的地址置为null,不影响A;

            Person p1 = new Person();



            Console.WriteLine("请按任意键继续");
            Console.ReadKey(true);
        }
    }
}