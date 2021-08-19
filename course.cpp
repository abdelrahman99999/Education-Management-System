#include "course.h"


course::course()
{
	this->Instructors_of_course = new Instructor[3];
}

course::course(string course_name, string course_code, string grade, int course_hours, Instructor * Instructors_of_course):course_name( course_name), course_code( course_code), grade( grade), course_hours( course_hours)
{
	this->Instructors_of_course = new Instructor[3];
	this->Instructors_of_course = Instructors_of_course;
}

string course::get_course_name()
{
	return course_name;
}

string course::get_course_code()
{
	return course_code;
}

string course::get_course_grade()
{
	return grade;
}

int course::get_course_hours()
{
	return course_hours;
}

Instructor * course::get_Instructors_of_course()
{
	return Instructors_of_course;
}



course::~course()
{
}
