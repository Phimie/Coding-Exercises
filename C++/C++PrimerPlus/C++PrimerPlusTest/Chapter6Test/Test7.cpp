#include <iostream>
#include <cctype>
#include <string>

int main() {
    std::string word;
    int vowel_count = 0, consonant_count = 0, other_count = 0;

    std::cout << "请输入单词（输入q结束）：" << std::endl;

    while (true) {
        std::cin >> word;
        if (word == "q") {
            break;
        }

        char first_char = tolower(word[0]);

        if (isalpha(first_char)) {
            if (first_char == 'a' || first_char == 'e' || first_char == 'i' || first_char == 'o' || first_char == 'u') {
                ++vowel_count;
            } else {
                ++consonant_count;
            }
        } else {
            ++other_count;
        }
    }

    std::cout << "以元音打头的单词数量：" << vowel_count << std::endl;
    std::cout << "以辅音打头的单词数量：" << consonant_count << std::endl;
    std::cout << "不属于这两类的单词数量：" << other_count << std::endl;

    return 0;
}
