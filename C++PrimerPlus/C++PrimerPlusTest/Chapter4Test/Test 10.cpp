/*
��дһ���������û���������40���ܵĳɼ��������Ը�⣬Ҳ�����û�����40���ܵĳɼ���?��
����ʾ������ƽ���ɼ�����ʹ��һ��array�������洢���ݣ������������֧��array�࣬��ʹ�����飩?��
*/
#include <iostream>
#include <vector> //�Ҵ�����vector
int main() {
    std::vector<double> times;
    double time;
    int count = 0;
    std::cout << "����������40���ܵĳɼ�����λ���룩��" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cin >> time;
        times.push_back(time);
        ++count;
    }
    double sum;
    for (double t : times) {
        sum += t;
    }
    double averageTime = sum / count;
    std::cout << "�ܹ������� " << count << " �γɼ���" << std::endl;
    std::cout << "ƽ���ɼ��ǣ�" << averageTime << " �롣" << std::endl;
    return 0;
}
