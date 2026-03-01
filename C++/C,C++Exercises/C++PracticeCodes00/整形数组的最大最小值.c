#include<stdio.h>
int main(){
    int i,max,min;
    int a[10]={1,-6,6,9,2,5,88,4,7,10};
    max=min=a[0];
    for (i=0;i<10;i++){
        if (a[i]>max){max=a[i];}
        if (a[i]<min){min=a[i];}
    }
    printf("最大是%d,最小是%d",max,min);
    return 0;
}
