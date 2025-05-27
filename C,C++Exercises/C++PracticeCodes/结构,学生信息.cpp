#include <iostream>
#include <string>
#include <limits>

struct Student {
    std::string Name;
    double Height;
    double Weight;
    int ID;
};

int main() {
    int Students_number;
    std::cout << "Please enter the number of students: ";
    std::cin >> Students_number;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Student *Students[Students_number];
    for (int i = 0; i < Students_number; i++) {
        Students[i] = new Student(); //��ÿ��ָ�������Ҫ���ڴ�
    }

    for (int j = 0; j < Students_number; j++) {
        std::cout << "\nPlease enter the " << (j + 1) << " student's name: ";
        std::getline(std::cin, Students[j]->Name);    
        
		//std::getline �Ὣ���з������������Ƴ�,���Բ���Ҫ�ٵ���std::cin.ignore()
		
        std::cout << "\nPlease enter the " << (j + 1) << " student's height: ";
        std::cin >> Students[j]->Height;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        //std::numeric_limits<����>::max()��һ��limits���еĺ���,���ڷ������͵����ֵ
        //std::streamsize�����������Ĵ�С
        
        std::cout << "\nPlease enter the " << (j + 1) << " student's weight: ";
        std::cin >> Students[j]->Weight;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nPlease enter the " << (j + 1) << " student's ID: ";
        std::cin >> Students[j]->ID;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    for (int i = 0; i < Students_number; i++) {
        std::cout << "\nThe " << (i + 1) << " student's name is: " << Students[i]->Name
                  << "\nThe " << (i + 1) << " student's height is: " << Students[i]->Height
                  << "\nThe " << (i + 1) << " student's weight is: " << Students[i]->Weight
                  << "\nThe " << (i + 1) << " student's ID is: " << Students[i]->ID;
    }

    for (int i = 0; i < Students_number; i++) {
        delete[] Students[i];  //һ�������ͷ��ڴ�
    }
    return 0;
}

