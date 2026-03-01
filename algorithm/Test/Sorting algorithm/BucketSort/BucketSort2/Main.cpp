#include <iostream>
int main()
{
    int Bucket[101] = {0};
    int n = 0;
    int num = 0;
    std::cout << "要输入几个数字:";
    std::cin >> n;
    std::cout << std::endl;
    std::cout << "请输入" << n << "个数字(0-100):";

    for (int i = 0; i < n; i++)
    {
        std::cin >> num;
        Bucket[num]++;
    }
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < Bucket[i]; j++)
        {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}