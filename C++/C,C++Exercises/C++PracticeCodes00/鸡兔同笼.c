#include<stdio.h>

int main()
{
    int tou;
    int jiao;
    printf("请输入头的数量:");
    scanf ("%d",&tou);
    printf("请输入脚的数量:");
    scanf("%d",&jiao);
    int y = jiao/2 - tou;
    int x = tou - y;
    printf ("鸡有%d只，兔有%d只\n",x,y);
    return 0;
}

