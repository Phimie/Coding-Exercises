#include <iostream>
#include <string.h>
struct Student_information{
	std::string Stu_name;
	int Stu_score;
};

void Change_Stu_score(Student_information *ptr);

int main(){
	Student_information Stu1 = {"libai",60};
	std::cout << "now the stu1's name is " << Stu1.Stu_name << " ,and the score is "<<Stu1.Stu_score<<std::endl;
	Change_Stu_score(&Stu1);
	return 0;
}

void Change_Stu_score(Student_information *ptr){
	ptr -> Stu_name = "dufu";
	ptr -> Stu_score = 100;
	std::cout <<"Change over!" << std::endl <<"now the stu1's name is " << ptr -> Stu_name << " ,and the score is "<<ptr -> Stu_score<<std::endl;
}
