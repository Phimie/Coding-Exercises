/*
分别使用函数实现下列功能:
(1)输入n个学生n门课程的成绩
(2)计算每个学生的平均分
(3)计算每门课程的平均分
*/

#include<iostream>
double student_grade[100][100], student_grade_average[100], course_average_grade[100];int number_students, number_of_student_grades;
int grade_input();
int student_average();
int course_average();
int main() {
	std::cout << "Please enter the number of students: ";
	std::cin >> number_students;
	std::cout << "Please enter the number of student grades: ";
	std::cin >> number_of_student_grades;
	grade_input();
	student_average();
	std::cout << std::endl;
	for (int i = 0; i < number_students; i++) {
		std::cout << "Student " << i+1 << "'s average grade is " << student_grade_average[i] << std::endl;
	}
	course_average();
	std::cout << std::endl;
	for (int j = 0; j < number_of_student_grades; j++) {
		std::cout << "The average grade for Course " << j + 1 << " is " << course_average_grade[j] << std::endl;
	}
}
int grade_input() {
	for (int i = 0; i < number_students; i++) {
		for (int j = 0; j < number_of_student_grades; j++) {
			std::cout << "Please enter the " << j+1 << " grade of student " << i+1 << ": ";
			std::cin >> student_grade[i][j];
		}
	}
	return 0;
}
int student_average() {
	for (int i = 0; i < number_students; i++) {
		double sum = 0;
		for (int j = 0; j < number_of_student_grades; j++) {
			sum += student_grade[i][j];
		}
		student_grade_average[i] = sum / number_of_student_grades;
	}
	return 0;
}
int course_average() {
	for (int i = 0; i < number_of_student_grades; i++) {
		double sum = 0;
		for (int j = 0; j < number_students;j++) {
			sum += student_grade[j][i];
		}
		course_average_grade[i] = sum / number_students;
	}
	return 0;
}


