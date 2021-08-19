#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"

int Student::count_students = 0;

Student::Student()
{
	count_students++;
	courses = new course[6];
}

Student::Student(string name, string age, string nationalId, string email, int id, float gpa, course * courses, int grad_year):Person(name,age,nationalId,email),GPA(gpa),expected_graduation_year(grad_year),id(id)
{
	count_students++;
	this ->courses = new course[6];
	this->courses = courses;
}

int Student::no_of_students()
{
	return count_students;
}

int Student::get_Id()
{
	return id;
}

float Student::get_GPA()
{
	return GPA;
}

course * Student::get_cources()
{
	return courses;
}

int Student::how_long_to_graduate()
{
	time_t now = time(0);
	tm *pointer_time_struct= localtime(&now);
	return ( (this->expected_graduation_year) - ( 1900 + (pointer_time_struct->tm_year) ) );
}

int Student::get_expected_graduation_year()
{
	return expected_graduation_year;
}

string Student::get_Password() 
{
	return pass;
}

void Student::set_Id(int id)
{
	this->id = id;
}

void Student::set_GPA(float gpa)
{
	this->GPA = gpa;
}

void Student::set_courses(course * courses)
{
	this->courses = courses;
}

void Student::set_pass(string pass)
{
	this->pass = pass;
}

void Student::set_expected_graduation_year(int year)
{
	this->expected_graduation_year = year;
}

Student::~Student()
{
	count_students--;
}
