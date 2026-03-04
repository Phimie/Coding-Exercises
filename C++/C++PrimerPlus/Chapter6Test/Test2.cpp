#include <iostream>
#include <array>

int main() {
    std::array<double, 10> donations;
    double num;
    int count = 0;
    double sum = 0.0;

    std::cout << "请输入最多10个donation值（输入非数字结束）：" << std::endl;
    while (count < 10 && std::cin >> num) {
        donations[count++] = num;
        sum += num;
    }

    if (count > 0) {
        double average = sum / count;
        int jisuan = 0;
        for (int i = 0; i < count; ++i) {
            if (donations[i] > average) {
                ++jisuan;
            }
        }

        std::cout << "输入的donation值的平均值为：" << average << std::endl;
        std::cout << "数组中有 " << jisuan << " 个数字大于平均值" << std::endl;
    } else {
        std::cout << "未输入有效的donation值" << std::endl;
    }

    return 0;
}
