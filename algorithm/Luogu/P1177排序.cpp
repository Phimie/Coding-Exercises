#include <iostream>
#include <algorithm>

int a[100005];

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    std::sort(a, a + n);
    for (int i = 0; i < n; ++i)
    {
        std::cout << a[i];
        if (i != n - 1)
            std::cout << ' ';
    }
    std::cout << std::endl;
    return 0;
}