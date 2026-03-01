#include<stdio.h>
int main(){
    long long x,y,r,n,k=0;
    printf("请输入两个正整数:");
    scanf("%lld",&x);scanf("%lld",&y);
    n=x*y;
    if (y>x){k=y;y=x;x=k;}
    while (1){
        r = x%y;
        if (r==0){
            printf("%lld为最大公因数\n",y);
            printf("%lld为最小公倍数",n/y);
            break;
        }else{x=y;y=r;}
    }
    return 0;
}