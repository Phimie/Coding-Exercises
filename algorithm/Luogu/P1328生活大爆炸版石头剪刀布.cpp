#include <iostream>
// 定义胜负矩阵,避免复杂条件判断
int compare(int a, int b)
{
    int data[5][5] = {
        {0, -1, 1, 1, -1},
        {1, 0, -1, 1, -1},
        {-1, 1, 0, -1, 1},
        {-1, -1, 1, 0, 1},
        {1, 1, -1, -1, 0}};
    return data[a][b];
}

int main()
{
    int n, Ta, Tb, Tac, Tbc, ScoreA, ScoreB;
    std::cin >> n >> Ta >> Tb;
    int A[Ta], B[Tb];
    for (int k = 0; k < Ta; k++)
    {
        std::cin >> A[k];
    }
    for (int j = 0; j < Tb; j++)
    {
        std::cin >> B[j];
    }
    for (int i = 0; i < n; i++)
    {
        Tac = i % Ta;
        Tbc = i % Tb;
        if (compare(A[Tac], B[Tbc]) == 1)
        {
            ScoreA++;
        }
        else if (compare(A[Tac], B[Tbc]) == -1)
        {
            ScoreB++;
        }
        else
        {
            continue;
        }
    }

    std::cout << ScoreA << ' ' << ScoreB;
    return 0;
}