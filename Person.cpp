#include "Person.h"

int Person::counter_persons = 0;

Person::Person()
{
	counter_persons++;
}

Person::Person(string name, string age, string nationalId,string email):name(name),age(age),nationalId(nationalId),email(email)
{
	counter_persons++;
}

int Person::no_of_persons()
{
	return counter_persons;
}

string Person::get_name()
{
	return name;
}

string Person::get_national_Id()
{
	return nationalId;
}

string Person::get_age()
{
	return age;
}

string Person::get_email()
{
	return email;
}

void Person::set_name(string name)
{
	this->name = name;
}

void Person::set_age(string age)
{
	this->age = age;
}

void Person::set_nat_id(string natId)
{
	this->nationalId = natId;
}

void Person::set_email(string email)
{
	this->email = email;
}


Person::~Person()
{
	counter_persons--;
}
