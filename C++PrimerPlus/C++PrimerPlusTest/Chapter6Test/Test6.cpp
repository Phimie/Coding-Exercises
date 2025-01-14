#include <iostream>
#include <string>
#include <vector>

struct donor {
    std::string donor_name;
    double donation_amount;
};

int main() {
    int num_donors;
    std::cout << "�������������Ŀ��";
    std::cin >> num_donors;

    std::vector<donor> donors(num_donors);

    for (int i = 0; i < num_donors; ++i) {
        std::cout << "������� " << i + 1 << " �������ߵ�������";
        std::cin.ignore();
        std::getline(std::cin, donors[i].donor_name);
        std::cout << "������� " << i + 1 << " �������ߵĿ��";
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
