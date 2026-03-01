#include <iostream>

class Student
{
public:
    void showClassName()
    {
        std::cout << "this is Student class" << std::endl;
    }

    void showStudentAge()
    {
        if (this == NULL)
        {
            return; // 这段代码提高的程序的健壮性
        }

        std::cout << "age = " << m_Age << std::endl;
    }

    int m_Age;
};

void test01()
{
    Student *s1 = NULL;

    s1->showClassName();

    s1->showStudentAge();
    //  如果输入以上代码,将会报错,因为传入的指针是为NULL;导致this没法指向m_Age;所以报错
}

int main()
{
    return 0;
}