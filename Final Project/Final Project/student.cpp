#include "student.h"
#include<iostream>

Student::Student(string n, float gpa, int ID) {
	GPA = gpa;
	id = ID;
	name = n;
}
void Student::set_gpa(float gpa) {
	GPA = gpa;
}
void Student::set_ID(int ID) {
	id = ID;
}
void Student::set_Course(string course) {
	courses.insert(course);
}
float Student::get_gpa() {
	return GPA;
}
int Student::get_ID() {
	return id;
}
void Student::get_Courses() {
	cout << name << "'s courses:" << endl;
	for (string c : courses) {
		cout << c<<endl;
	}
}
void Student::Display_student() {
	cout << "Name:  " << this->get_name() << endl;;
	cout << "Gpa:  " << this->get_gpa() << endl;;
	cout << "ID:  " << this->get_ID() << endl;;
	

}