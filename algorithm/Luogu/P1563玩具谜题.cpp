#include <iostream>
#include <vector>
#include <string>
int main()
{
    int n, m, RoL, step, index = 0;
    std::cin >> n >> m;
    std::vector<std::string> person(n);
    std::vector<int> direction(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> direction[i] >> person[i];
    }
    for (int i = 0; i < m; i++)
    {
        std::cin >> RoL >> step;
        if (index < 0)
            index = index % n + n;
        if (RoL == 1 && direction[index % n] == 0 || RoL == 0 && direction[index % n] == 1)
            index += step;
        else
            index -= step;
    }
    if (index < 0)
        index = index % n + n;
    std::cout << person[index % n];
}