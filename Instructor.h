#ifndef ccc_HEADER
#define ccc_HEADER

using namespace std;
#include<string>
#include "Person.h"

class Instructor:public Person
{
private:
	
	static int count_Instructors;
	string office_hours;
public:
	
	Instructor();
	Instructor(string name, string age, string nationalId,string email,string office_hours);
	static int no_of_Instructors();
	string get_office_hours();
	void set_office_hours(string off_hours);
	~Instructor();
};

#endif