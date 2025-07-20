#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    bool first = true;
    bool zero = true;

    for (int i = n; i >= 0; --i)
    {
        int c;
        std::cin >> c;
        if (!c)
            continue;
        zero = false;

        if (!first)
        {
            std::cout << (c > 0 ? '+' : '-');
            if (c < 0)
                c = -c;
        }
        else if (c < 0)
        {
            std::cout << '-';
            c = -c;
        }
        first = false;

        if (c != 1 || !i)
            std::cout << c;
        if (i)
        {
            std::cout << 'x';
            if (i > 1)
                std::cout << '^' << i;
        }
    }
    if (zero)
        std::cout << 0;

    return 0;
}