/*
4��Daphne��10%�ĵ���Ͷ����100��Ԫ��Ҳ����˵��ÿһ���������Ͷ�ʶ��10%��
��ÿ��10��Ԫ����Ϣ = 0.10��ԭʼ����Cleo��5%�ĸ���Ͷ����100��Ԫ��
Ҳ����˵����Ϣ�ǵ�ǰ��������õ���Ϣ����5%��?����Ϣ = 0.05����ǰ���Cleo�ڵ�һ��Ͷ��100��Ԫ��ӯ����5%���õ���105��Ԫ��
��һ���ӯ����105��Ԫ��5%����5.25��Ԫ���������ơ�
���дһ�����򣬼���������Cleo��Ͷ�ʼ�ֵ���ܳ���Daphne��Ͷ�ʼ�ֵ������ʾ��ʱ�����˵�Ͷ�ʼ�ֵ��
*/


#include <iostream>

int main() {
    double daphne_investment = 100.0;
    double cleo_investment = 100.0;
    int years = 0;

    while (cleo_investment <= daphne_investment) {
        daphne_investment += 10;
        cleo_investment += cleo_investment * 0.05;
        years++;
    }

    std::cout << "���� " << years << " �꣬Cleo��Ͷ�ʼ�ֵ����Daphne��Ͷ�ʼ�ֵ��" << std::endl;
    std::cout << "��ʱ��Daphne��Ͷ�ʼ�ֵΪ: $" << daphne_investment << std::endl;
    std::cout << "��ʱ��Cleo��Ͷ�ʼ�ֵΪ: $" << cleo_investment << std::endl;

    return 0;
}
