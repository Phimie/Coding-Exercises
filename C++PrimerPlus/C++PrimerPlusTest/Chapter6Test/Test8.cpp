#include <iostream>
#include <fstream>

int main() {
    std::string filename;
    std::cout << "������Ҫ�����ļ�����";
    std::cin >> filename;

    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "�޷����ļ�����ļ������ڣ�" << filename << std::endl;
        return 1;
    }

    int char_count = 0;
    char ch;
    while (infile.get(ch)) {
        ++char_count;
    }

    infile.close();

    std::cout << "�ļ� " << filename << " �а������ַ���Ϊ��" << char_count << std::endl;

    return 0;
}
