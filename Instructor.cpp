#include "Instructor.h"

int Instructor::count_Instructors= 0;

Instructor::Instructor() 
{
	count_Instructors++;
}

Instructor::Instructor(string name, string age, string nationalId,string email,string office_hours):Person(name,age,nationalId,email), office_hours(office_hours)
{
	count_Instructors++;
}

int Instructor::no_of_Instructors()
{
	return count_Instructors;
}




string Instructor::get_office_hours()
{
	return office_hours;
}

void Instructor::set_office_hours(string off_hours)
{
	this->office_hours = off_hours;
}

Instructor::~Instructor()
{
	count_Instructors--;
}
