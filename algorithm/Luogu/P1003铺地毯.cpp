#include <iostream>
#include <vector>

struct frame
{
    int a, b, g, k;
};

int main()
{
    int n = 0;
    std::cin >> n;
    std::vector<frame> carpets(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> carpets[i].a >> carpets[i].b >> carpets[i].g >> carpets[i].k;
    }
    int x, y = -1;
    std::cin >> x >> y;
    for (int i = n - 1; i >= 0; i--)
    {
        if (x >= carpets[i].a && x <= carpets[i].a + carpets[i].g && y >= carpets[i].b && y <= carpets[i].b + carpets[i].k)
        {
            std::cout << i + 1;
            return 0;
        }
    }
    std::cout << -1;
    return 0;
}