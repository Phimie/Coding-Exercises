#include <iostream>
#include <array>

int main() {
    std::array<double, 10> donations;
    double num;
    int count = 0;
    double sum = 0.0;

    std::cout << "���������10��donationֵ����������ֽ�������" << std::endl;
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

        std::cout << "�����donationֵ��ƽ��ֵΪ��" << average << std::endl;
        std::cout << "�������� " << jisuan << " �����ִ���ƽ��ֵ" << std::endl;
    } else {
        std::cout << "δ������Ч��donationֵ" << std::endl;
    }

    return 0;
}
