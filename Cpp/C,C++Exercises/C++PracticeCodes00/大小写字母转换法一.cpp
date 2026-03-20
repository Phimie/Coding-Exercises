#include <iostream>
#include <cstdio>

int main() {
    char change[26][2] = {{'A', 'a'}, {'B', 'b'}, {'C', 'c'}, {'D', 'd'},{'E','e'},{'F','f'},{'G','g'},{'H','h'},{'I','i'},{'J','j'},{'K','k'},{'L','l'},{'M','m'},{'N','n'},{'O','o'},{'P','p'},{'Q','q'},{'R','r'},{'S','s'},{'T','t'},{'U','u'},{'V','v'},{'W','w'},{'X','x'},{'Y','y'},{'Z','z'}};
    char input[100];
    scanf("%99s", input);
    int len=strlen(input);
    for (int i=0;i<len;i++){
        for (int j=0;j<26;j++){
            if (input[i]==change[j][0]){
                input[i]=change[j][1];
            }
        }
    }
    printf("%s",input);
    return 0;
}

