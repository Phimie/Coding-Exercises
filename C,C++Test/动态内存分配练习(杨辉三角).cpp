//��̬�ڴ������ϰ(�������)

#include<stdio.h>
#include<stdlib.h>

void CreatTriangle(int n);

int main (){
	int rows;
	printf("����������:");
	scanf("%d",&rows);   		//��������
	CreatTriangle(rows);
	return 0;
}

void CreatTriangle(int n){
	
	int **triangle = (int **)malloc(n * sizeof(int));
	if (triangle == NULL){
		printf("�ڴ����ʧ��\n");
		return;
	}
	
	//����ڴ����
	for(int i=0;i<n;i++){
		triangle[i] = (int *)malloc((i+1)*sizeof(int));
		if(triangle[i] == NULL){
			printf("�ڴ����ʧ��\n");
			for(int j=0;j<i;j++){
				free (triangle[j]); 
			}
			free (triangle);
		}
	}
	
	//�����������
	for (int i = 0;i<n;i++){
		triangle[i][0]=triangle[i][i]=1;
		for (int j = 1;j<i;j++){
			triangle [i][j] = triangle [i-1][j-1] +triangle[i-1][j];
		}
	}
	//��ӡ�������
	for (int i =0;i<n;i++){
		
		//��ӡ�ո�
		for (int k = 0; k < n - i - 1; k++) {
            printf(" ");
        }
        //��ӡ����
		for (int j=0;j<=i;j++){
			printf("%d ",triangle[i][j]);
		}
		printf("\n");
	}
	
	// �ͷ��ڴ�
	for (int i = 0; i < n; i++){
	    free(triangle[i]);
	}
	free(triangle);
}
