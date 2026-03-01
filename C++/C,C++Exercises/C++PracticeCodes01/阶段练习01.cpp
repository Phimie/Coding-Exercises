/*
阶段练习01:
目标:

1.递减运算符重载              √
2.左移运算符重载              √
3.加号运算符重载              √
4.类做友元                    √
5.全局函数做友元              √
6.常函数                      √
7.常对象                      √
8.this指针                    √
9.静态成员函数&静态成员变量   √
10.类对象作为类成员           √
11.初始化列表                 √
12.深拷贝和浅拷贝             √
13.拷贝构造函数               √
14.构析函数                   √
15.new分配内存                √
16.指针+引用                  √
17.赋值运算符重载             √
18.关系运算符重载             √
19.函数调用运算符重载         √
20.匿名函数调用               √
*/

#include <iostream>
#include <string>

// MyPrint类
class MyAdd
{
public:
    int operator()(int num1, int num2) // 函数调用运算符重载
    {
        return num1 + num2;
    }

public:
private:
};

// 手机类
class Phone
{
public:
    Phone() : brand(" ")
    {
    }

    bool operator==(const Phone &p) const
    {
        if (brand == p.brand)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

public:
    std::string brand;
};

// 学生类
class Student
{

    friend class Teacher;                                                  // 类做友元
    friend void test02();                                                  // 全局函数做友元
    friend std::ostream &operator<<(std::ostream &cout, const Student &s); // 重置左移运算符函数做友元

public:
    Student() // 默认构造函数
        : m_age(0),
          m_ID(""),
          m_Name(""),
          m_height(nullptr),
          m_Phone(nullptr) // 默认构造函数也要初始化所有值!
    {
        std::cout << "默认构造函数调用" << std::endl;
    }
    Student(int age, std::string ID, std::string name, int height)
        : m_age(18), m_ID("0"), m_Name("张三"), m_height(nullptr), m_Phone(nullptr)
    // 有参构造函数,初始化列表,指针初始化为空指针
    {
        this->m_height = new int(height);
        this->m_age = age;
        this->m_ID = ID;
        this->m_Name = name;
        std::cout << "对象 " << this->m_Name << " 创建成功!" << "年龄:" << this->m_age << ",学号:" << this->m_ID << ",身高:" << *this->m_height << std::endl;
    }
    ~Student() // 析构函数
    {
        if (m_height != NULL)
        {
            delete m_height;
            m_height = NULL;
        }
        delete m_Phone;
        std::cout << "对象 " << this->m_Name << " 关闭!" << std::endl;
    }

    Student(const Student &s) // 自定义拷贝构造函数,实现深拷贝
    {
        this->m_height = new int(*s.m_height);
        this->m_age = s.m_age;
        this->m_ID = s.m_ID;
        this->m_Name = s.m_Name;
        std::cout << "对象 " << this->m_Name << " 拷贝成功!" << "年龄:" << this->m_age << ",学号:" << this->m_ID << ",身高:" << *this->m_height << std::endl;
    }

public:
    Student &operator--() // 前置递减运算符,因为是单目运算符,所以不需要额外参数
    {
        this->m_age--;
        return *this;
    }

    Student operator--(int)   // 后置递减运算符,参数列表加上int表后置
    {                         // 后置递减运算符的返回值不应该是一个引用,因为需要返回的是一个副本
        Student temp = *this; // 先记录当前数据   //注意:这里调用了拷贝构造函数
        --(*this);            // 调用前置改变自身
        return temp;
    }

    Student &operator+(Student &s) // 加号运算符重载
    {
        this->m_age = this->m_age + s.m_age;
        return *this;
    }

    bool operator==(const Student &s) const
    {
        // 比较基本类型成员
        if (m_age != s.m_age || m_ID != s.m_ID || m_Name != s.m_Name)
            return false;

        // 比较m_height指针指向的值
        if (m_height == nullptr && s.m_height == nullptr)
        {
        }
        else if (m_height == nullptr || s.m_height == nullptr)
        {
            // 一个为空，另一个非空，不相等
            return false;
        }
        else
        {
            if (*m_height != *s.m_height)
                return false;
        }

        // 比较m_Phone指针指向的对象
        if (m_Phone == nullptr && s.m_Phone == nullptr)
        {
        }
        else if (m_Phone == nullptr || s.m_Phone == nullptr)
        {
            return false;
        }
        else
        {
            // 使用Phone类的operator==比较
            if (!(*m_Phone == *s.m_Phone))
                return false;
        }

        return true;
    }
    Student &operator=(Student &s) // 赋值运算符重载
    {
        if (this == &s) // 处理自赋值问题,即s1 = s1;
        {
            return *this;
        }

        if (m_height != NULL) // 确保待赋值数据为空
        {
            delete m_height;
            m_height = NULL;
        }
        if (m_Phone != NULL)
        {
            delete m_Phone;
            m_Phone = NULL;
        }

        if (s.m_height == NULL) // 确保源数据不为空
        {
            m_height = NULL;
        }
        else
        {
            m_height = new int(*s.m_height);
        }
        if (s.m_Phone == NULL)
        {
            m_Phone = NULL;
        }
        else
        {
            m_Phone = new Phone(*s.m_Phone);
        }

        m_age = s.m_age;
        m_ID = s.m_ID;
        m_Name = s.m_Name;

        return *this;
    }

public:
    class Score // 子类
    {
    public:
    public:
    private:
        int m_Math;
        int m_English;
        int m_Chinese;
    };

public:
    void AddPhone(const std::string &brand) // 使用const +引用,保证安全性
    {
        m_Phone = new Phone();
        this->m_Phone->brand = brand; // 指针使用对象的话要用 -> 符号,->等同于(*Phone).brand
    }

    std::string getPhone()
    {
        return m_Phone->brand;
    }

    std::string getName()
    {
        return m_Name;
    }

    void test() const // 常函数
    {
        std::cout << m_Name << "类中常函数调用" << std::endl;
    }

    static std::string getSchool() // 静态成员函数只能访问静态成员变量
    {
        return School;
    }

public:
    static std::string School; // 静态成员函数

private:
    std::string m_Name;
    std::string m_ID;
    int m_age;
    int *m_height;
    Phone *m_Phone;
};

// 教师类
class Teacher
{
public:
    Teacher() : m_Name(""), m_age(0), m_ID("")
    {
    }

public:
    void test()
    {
        std::cout << "Teacher类是Student类的友元,所以可以访问Student的私有成员" << std::endl;
        Student s1;
        std::cout << "s1的姓名是:" << s1.m_Name << std::endl;
    }

private:
    std::string m_Name;
    std::string m_ID;
    int m_age;
};

// 重载左移运算符
std::ostream &operator<<(std::ostream &cout, const Student &s) // 传入的应该是一个常量引用,一是避免不必要的拷贝,二是允许传入临时对象
{
    std::cout << s.m_age;
    return cout;
}

std::string Student::School = "希望小学"; // 静态成员变量只能在类外声明

void test01()
{
    Student s1(18, "01", "张三", 160);
    Student s2(20, "02", "李四", 170);
    std::cout << "--s2 = " << --s2 << std::endl;
    std::cout << "s2-- = " << s2-- << std::endl; // 这里返回的是临时对象,所以会造成对象 李四 关闭两次的假象;
    std::cout << "s2 = " << s2 << std::endl;
}

void test02() // 全局函数
{
    Student s1(30, "01", "张三", 180);
    std::cout << "作为Student的友元,我可以访问它的私有成员\"身高\":" << *s1.m_height << std::endl;
}

void test03()
{
    Student s1(30, "01", "李四", 190);
    s1.AddPhone("IQOO 12");
    std::cout << s1.getName() << "使用的手机是:" << s1.getPhone() << std::endl;
}

void test04()
{
    const Student s1(30, "01", "王五", 150); // 常对象
    s1.test();                               // 常对象只能使用常函数

    Teacher t1;
    t1.test();
}

void test05()
{
    Student s1(30, "01", "王五", 150);
    Student s2 = s1;
    std::cout << "s1的学校是:" << s1.getSchool() << std::endl;
    std::cout << "s2的学校是:" << s2.getSchool() << std::endl;
}

void test06()
{
    Student s1(30, "01", "王五", 150);
    Student s2(20, "02", "张三", 170);
    Student s3(10, "03", "李四", 190);
    std::cout << "初始时s1为:" << s1 << std::endl;
    s1 = s2 = s3;

    std::cout << "赋值过后s1为:" << s1 << std::endl;
}

void test07()
{
    Student s1(30, "01", "王五", 150);
    Student s2(20, "02", "张三", 170);
    Student s3(10, "03", "李四", 190);
    s1 = s3;
    if (s1 == s2)
    {
        std::cout << "s1 和 s2 相等" << std::endl;
    }
    else
    {
        std::cout << "s1 和 s2 不相等" << std::endl;
    }
    if (s1 == s3)
    {
        std::cout << "s1 和 s3 相等" << std::endl;
    }
    else
    {
        std::cout << "s1 和 s3 不相等" << std::endl;
    }
}

void test08()
{
    std::cout << "num1+num2=" << MyAdd()(100, 200) << std::endl;
}

int main()
{
    std::cout << "测试一:" << std::endl;
    test01();
    std::cout << std::endl;

    std::cout << "测试二:" << std::endl;
    test02();
    std::cout << std::endl;

    std::cout << "测试三:" << std::endl;
    test03();
    std::cout << std::endl;

    std::cout << "测试四:" << std::endl;
    test04();
    std::cout << std::endl;

    std::cout << "测试五:" << std::endl;
    test05();
    std::cout << std::endl;

    std::cout << "测试六:" << std::endl;
    test06();
    std::cout << std::endl;

    std::cout << "测试七:" << std::endl;
    test07();
    std::cout << std::endl;

    std::cout << "测试八:" << std::endl;
    test08();
    std::cout << std::endl;

    system("pause");
    return 0;
}

// 2025/6/1