#include <iostream>
#include <string>
#include <vector>

struct donor {
    std::string donor_name;
    double donation_amount;
};

int main() {
    int num_donors;
    std::cout << "请输入捐献者数目：";
    std::cin >> num_donors;

    std::vector<donor> donors(num_donors);

    for (int i = 0; i < num_donors; ++i) {
        std::cout << "请输入第 " << i + 1 << " 个捐献者的姓名：";
        std::cin.ignore();
        std::getline(std::cin, donors[i].donor_name);
        std::cout << "请输入第 " << i + 1 << " 个捐献者的款项：";
        std::cin >> donors[i].donation_amount;
    }

    bool has_grand_patrons = false;
    bool has_patrons = false;

    std::cout << "\nGrand Patrons:" << std::endl;
    for (const auto& donor : donors) {
        if (donor.donation_amount > 10000) {
            std::cout << donor.donor_name << ": " << donor.donation_amount << std::endl;
            has_grand_patrons = true;
        }
    }
    if (!has_grand_patrons) {
        std::cout << "none" << std::endl;
    }

    std::cout << "\nPatrons:" << std::endl;
    for (const auto& donor : donors) {
        if (donor.donation_amount <= 10000) {
            std::cout << donor.donor_name << ": " << donor.donation_amount << std::endl;
            has_patrons = true;
        }
    }
    if (!has_patrons) {
        std::cout << "none" << std::endl;
    }

    return 0;
}
