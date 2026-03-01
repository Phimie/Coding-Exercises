#include <iostream>
void minmax (int a[],int len,int *max,int *min);
int main(){
	int a[] = {1,2,3,4,5,6,7,8,9,0,100,20,213,12,53,3435,-2};
	int max,min;
	minmax(a,sizeof(a)/sizeof(a[0]),&max,&min);
	std::cout<<"min: "<<min <<"\nmax: "<<max<<std::endl;
	return 0;
}
void minmax (int a[],int len,int *max, int *min){
	*min = *max = a[0];
	for (int i=0;i<len;i++){
		if (a[i]<*min){
			*min = a[i];
		}
		if (a[i]>*max){
			*max = a[i];
		}
	}
}
