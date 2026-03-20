#include <stdio.h>
int main() {
    int num;
    int sum = 0;
    int number;
    while (1) {
        printf("请输入想累加的数字的数量:\n");
        scanf_s("%d", &num);
        if (num > 0) {break;}
        else {printf("请输入一个正整数\n");
}
    }
    printf("请输入 %d 个数字:\n", num);
    for (int i = 0; i < num; i++) {
        scanf_s("%d", &number);
        sum += number;
    }
    printf("这 %d 个数字的和为: %d\n", num, sum);
    return 0;
}


