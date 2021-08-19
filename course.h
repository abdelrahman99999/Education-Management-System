#ifndef AAA_HEADER
#define AAA_HEADER

using namespace std;
#include <string>
#include "Instructor.h"

class course
{
private:
	string course_name;
	string course_code;
	string grade;
	int course_hours;
	Instructor *Instructors_of_course;    //3 Instructor;
public:
	course();
	course( string course_name,string course_code,string grade,int course_hours,Instructor *Instructors_of_course);
	string get_course_name();
	string get_course_code();
	string get_course_grade();
	int get_course_hours();
	Instructor* get_Instructors_of_course();
	
	~course();
};

#endif
