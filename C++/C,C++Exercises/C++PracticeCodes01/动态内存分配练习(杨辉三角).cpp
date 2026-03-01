//动态内存分配练习(杨辉三角)

#include<stdio.h>
#include<stdlib.h>

void CreatTriangle(int n);

int main (){
	int rows;
	printf("请输入行数:");
	scanf("%d",&rows);   		//输入行数
	CreatTriangle(rows);
	return 0;
}

void CreatTriangle(int n){
	
	int **triangle = (int **)malloc(n * sizeof(int));
	if (triangle == NULL){
		printf("内存分配失败\n");
		return;
	}
	
	//检测内存分配
	for(int i=0;i<n;i++){
		triangle[i] = (int *)malloc((i+1)*sizeof(int));
		if(triangle[i] == NULL){
			printf("内存分配失败\n");
			for(int j=0;j<i;j++){
				free (triangle[j]); 
			}
			free (triangle);
		}
	}
	
	//计算杨辉三角
	for (int i = 0;i<n;i++){
		triangle[i][0]=triangle[i][i]=1;
		for (int j = 1;j<i;j++){
			triangle [i][j] = triangle [i-1][j-1] +triangle[i-1][j];
		}
	}
	//打印杨辉三角
	for (int i =0;i<n;i++){
		
		//打印空格
		for (int k = 0; k < n - i - 1; k++) {
            printf(" ");
        }
        //打印数字
		for (int j=0;j<=i;j++){
			printf("%d ",triangle[i][j]);
		}
		printf("\n");
	}
	
	// 释放内存
	for (int i = 0; i < n; i++){
	    free(triangle[i]);
	}
	free(triangle);
}
