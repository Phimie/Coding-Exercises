#include <iostream>
#include <cctype>
#include <string>

int main() {
    std::string word;
    int vowel_count = 0, consonant_count = 0, other_count = 0;

    std::cout << "�����뵥�ʣ�����q��������" << std::endl;

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

    std::cout << "��Ԫ����ͷ�ĵ���������" << vowel_count << std::endl;
    std::cout << "�Ը�����ͷ�ĵ���������" << consonant_count << std::endl;
    std::cout << "������������ĵ���������" << other_count << std::endl;

    return 0;
}
