#pragma once
#ifndef STUDENT_H_
#define STUDENT_H_
#include "person.h"
#include <set>
class Student :public Person
{
private:
	float GPA;
	int id;
	set <string> courses;
public:
	Student(string n, float gpa, int ID);
	void set_gpa(float gpa);
	void set_ID(int ID);
	void set_Course(string course);
	float get_gpa();
	int get_ID();
	void get_Courses();
	void Display_student();
};
#endif // !1



