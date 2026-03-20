/*
4．Daphne以10%的单利投资了100美元。也就是说，每一年的利润都是投资额的10%，
即每年10美元：利息 = 0.10×原始存款而Cleo以5%的复利投资了100美元。
也就是说，利息是当前存款（包括获得的利息）的5%，?：利息 = 0.05×当前存款Cleo在第一年投资100美元的盈利是5%—得到了105美元。
下一年的盈利是105美元的5%—即5.25美元，依此类推。
请编写一个程序，计算多少年后，Cleo的投资价值才能超过Daphne的投资价值，并显示此时两个人的投资价值。
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

    std::cout << "经过 " << years << " 年，Cleo的投资价值超过Daphne的投资价值。" << std::endl;
    std::cout << "此时，Daphne的投资价值为: $" << daphne_investment << std::endl;
    std::cout << "此时，Cleo的投资价值为: $" << cleo_investment << std::endl;

    return 0;
}
