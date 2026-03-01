#include <iostream>
#include <cctype>

int main() {
    char ch;
    while ((ch = getchar()) != '@') {
        if (isdigit(ch)) {
            continue;
        } else if (isupper(ch)) {
            putchar(tolower(ch));
        } else if (islower(ch)) {
            putchar(toupper(ch));
        } else {
            putchar(ch);
        }
    }
    return 0;
}
