// 分别利用普通写法和多态技术实现计算器
#include <iostream>
#include <string>

// 普通写法
class Calculator
{
public:
    int getResult(std::string oper)
    {
        if (oper == "+")
        {
            return m_Num1 + m_Num2;
        }
        else if (oper == "-")
        {
            return m_Num1 - m_Num2;
        }
        else if (oper == "*")
        {
            return m_Num1 * m_Num2;
        }
        // 如果想扩展新的功能,需要修改源码
        // 在真实的开发中,提倡开闭原则
        // 开闭原则:对扩展进行开发,对修改进行关闭
    }

    int m_Num1;
    int m_Num2;

private:
};

void test01()
{
    Calculator c;
    c.m_Num1 = 10;
    c.m_Num2 = 10;

    std::cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << std::endl;
    std::cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << std::endl;
    std::cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << std::endl;
}

// 利用多态实现计算器
/*
多态好处:
1.组织结构清晰
2.可读性强
3.对于前期和后期扩展以及维护性高
*/

// 实现计算器抽象类,当类中有了纯虚函数,这个类也成为抽象类

/*
抽象类特点:
1.无法实例化对象
2.子类必须重写抽象类中的纯虚函数,否则也属于抽象类
*/
class AbstractCalculator
{
public:
    virtual int getResult() = 0; // 纯虚函数的写法
    // 只要有一个纯虚函数,这个类成为抽象类,无法实例化对象

    int m_Num1;
    int m_Num2;
};

// 实现计算器加法类
class AddCalculator : public AbstractCalculator
{
public:
    int getResult() // 抽象类的子类  必须要重写父类中的纯虚函数,否则也属于抽象类
    {
        return m_Num1 + m_Num2;
    }
};

// 实现计算器减法类
class SubCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 - m_Num2;
    }
};

// 实现计算机乘法类
class MulCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 * m_Num2;
    }
};

// 实现计算机除法类
class DivCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 / m_Num2;
    }
};

void test02()
{
    // 多态使用条件
    // 父类指针或者引用指向子类对象

    // 加法计算
    AbstractCalculator *abc = new AddCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 20;
    std::cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << std::endl;
    // 用完后记得销毁
    delete abc;

    // 减法运算
    abc = new SubCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 20;
    std::cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << std::endl;
    delete abc;

    // 乘法运算
    abc = new MulCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 20;
    std::cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << std::endl;
    delete abc;

    // 除法运算
    abc = new DivCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 20;
    std::cout << abc->m_Num1 << " / " << abc->m_Num2 << " = " << abc->getResult() << std::endl;
    delete abc;
}

int main()
{
    std::cout << "测试一" << std::endl;
    test01();
    std::cout << std::endl;

    std::cout << "测试二" << std::endl;
    test02();
    std::cout << std::endl;

    system("pause");
    return 0;
}