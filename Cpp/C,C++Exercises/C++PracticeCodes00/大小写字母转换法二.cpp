#include <iostream>
int main() {
	char input_string[100];
	std::cin >> input_string;
	for (int i = 0; i < strlen(input_string); i++) {
		if (input_string[i] <= 'Z' && input_string[i]>='A') {
			input_string[i] = (int)input_string[i] + ('a'-'A');
		}
	}
	std::cout << input_string;
	return 0;
}
