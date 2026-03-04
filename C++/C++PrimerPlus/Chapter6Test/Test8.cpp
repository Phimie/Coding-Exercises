#include <iostream>
#include <fstream>

int main() {
    std::string filename;
    std::cout << "请输入要检查的文件名：";
    std::cin >> filename;

    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "无法打开文件或该文件不存在：" << filename << std::endl;
        return 1;
    }

    int char_count = 0;
    char ch;
    while (infile.get(ch)) {
        ++char_count;
    }

    infile.close();

    std::cout << "文件 " << filename << " 中包含的字符数为：" << char_count << std::endl;

    return 0;
}
