#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct donor {
    string name;
    double amount;
};

int main() {
    ifstream in_file("donors.txt");
    if (!in_file) {
        cerr << "无法打开文件！" << endl;
        return 1;
    }

    int num_donors;
    in_file >> num_donors;

    vector<donor> donors(num_donors);

    for (int i = 0; i < num_donors; ++i) {
        in_file.ignore();
        getline(in_file, donors[i].name);
        in_file >> donors[i].amount;
    }

    in_file.close();

    cout << "Grand Patrons:" << endl;
    bool has_grand_patrons = false;
    for (const auto& donor : donors) {
        if (donor.amount > 10000) {
            cout << donor.name << ": " << donor.amount << endl;
            has_grand_patrons = true;
        }
    }
    if (!has_grand_patrons) {
        cout << "none" << endl;
    }

    cout << "Patrons:" << endl;
    bool has_patrons = false;
    for (const auto& donor : donors) {
        if (donor.amount <= 10000) {
            cout << donor.name << ": " << donor.amount << endl;
            has_patrons = true;
        }
    }
    if (!has_patrons) {
        cout << "none" << endl;
    }

    return 0;
}
