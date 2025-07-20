#include <iostream>
#include <vector>
#include <string>

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> person(n);
    std::vector<bool> direction(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> direction[i] >> person[i];
    }
}