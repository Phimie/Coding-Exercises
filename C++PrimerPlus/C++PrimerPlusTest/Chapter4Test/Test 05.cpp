/*
�ṹCandyBar����3����Ա����һ����Ա�洢���ǿ��Ʒ�ƣ��ڶ�����Ա�洢�ǿ��������������С����?��
��������Ա�洢���ǿ�Ŀ�·�ﺬ����������?��
���дһ��������������ṹ������һ����Ϊsnack��CandyBar������
�������Ա�ֱ��ʼ��Ϊ��Mocha Munch��?��2.3��350����ʼ��Ӧ������snackʱ���С�
��󣬳�����ʾsnack���������ݡ�
*/



#include  <iostream>
#include <string>
int main (){
	struct CandyBar {
		std::string brand;
		double weight;
		int calorie;
	};
	CandyBar snack = {
		"Mocha Munch",
		2.3,
		350
	};
	std::cout <<"brand:"<< snack.brand <<"\n"<<"calores: "<<snack.calorie<<"\n"<<"weight: "<<snack.weight<<std::endl;
	return 0;
}
