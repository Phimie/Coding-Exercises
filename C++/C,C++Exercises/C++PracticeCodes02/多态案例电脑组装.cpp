#include <iostream>
#include <string>

class CPU
{
public:
    virtual void calculate() = 0; // 抽象计算函数

private:
};

class GPU
{
public:
    virtual void display() = 0; // 抽象显示函数
private:
};

class Memory
{
public:
    virtual void storage() = 0; // 抽象存储函数
private:
};

class Computer
{
public:
    Computer(CPU *cpu, GPU *gpu, Memory *memory)
    {
        m_cpu = cpu;
        m_gpu = gpu;
        m_mem = memory;
    }

    void work()
    {
        m_cpu->calculate();
        m_gpu->display();
        m_mem->storage();
    }
    // 因为所有零件都要走Computer的析构函数,所以可以在这里释放3个电脑零件
    ~Computer()
    {
        if (m_cpu != NULL)
        {
            delete m_cpu;
            m_cpu = NULL;
        }
        if (m_gpu != NULL)
        {
            delete m_gpu;
            m_gpu = NULL;
        }
        if (m_mem != NULL)
        {
            delete m_mem;
            m_mem = NULL;
        }
    }

private:
    CPU *m_cpu; // CPU的零件指针
    GPU *m_gpu;
    Memory *m_mem;
};

class IntelCPU : public CPU
{
public:
    void calculate()
    {
        std::cout << "Intel的CPU开始计算了" << std::endl;
    }

private:
};

class IntelGPU : public GPU
{
public:
    void display()
    {
        std::cout << "Intel的GPU开始显示了" << std::endl;
    }

private:
};

class IntelMemory : public Memory
{
public:
    void storage()
    {
        std::cout << "Intel的Memory开始存储了" << std::endl;
    }

private:
};

class AMDCPU : public CPU
{
public:
    void calculate()
    {
        std::cout << "AMD的CPU开始计算了" << std::endl;
    }

private:
};

class AMDGPU : public GPU
{
public:
    void display()
    {
        std::cout << "AMD的GPU开始显示了" << std::endl;
    }

private:
};

class AMDMemory : public Memory
{
public:
    void storage()
    {
        std::cout << "AMD的Memory开始存储了" << std::endl;
    }

private:
};

void test01()
{
    // 第一台电脑零件
    CPU *IntelCPU1 = new IntelCPU;
    GPU *IntelGPU1 = new IntelGPU;
    Memory *IntelMemory1 = new IntelMemory;

    // 创建第一台电脑
    std::cout << "第一台电脑开始工作:" << std::endl;
    Computer *computer1 = new Computer(IntelCPU1, IntelGPU1, IntelMemory1);
    computer1->work();
    delete computer1;
    std::cout << "________________________________________" << std::endl;
    std::cout << "第二台电脑开始工作:" << std::endl;
    Computer *computer2 = new Computer(new AMDCPU, new AMDGPU, new AMDMemory);
    computer2->work();
    delete computer2;
    std::cout << "________________________________________" << std::endl;
    std::cout << "第三台电脑开始工作:" << std::endl;
    Computer *computer3 = new Computer(new IntelCPU, new AMDGPU, new IntelMemory);
    computer3->work();
    delete computer3;
}

int main()
{
    test01();
    return 0;
}
