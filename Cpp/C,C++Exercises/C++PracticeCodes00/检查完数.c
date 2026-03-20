#include <stdio.h>
int main()
{
    int i,j,num,n;
    printf("需要检查多少以内的完数:");
    scanf ("%d",&n);
    for (i=1;i<n;i++){
        num=0;
        for (j=1;j<=i/2;j++){
            if (i%j==0){
                num+=j;
                }
        }
        if (num==i){
            printf("%d是完数\n",i);
                }
    }
    return 0;
}