#include <iostream>
int main()
{
    int L, R;
    int count = 0;
    std::cin >> L >> R;
    for (int i = L; i <= R; i++)
    {
        int num = i;
        while (num > 0)
        {
            if (num % 10 == 2)
            {
                count++;
            }
            num /= 10;
        }
    }
    std::cout << count << std::endl;
    return 0;
}
