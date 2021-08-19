#ifndef bbb_HEADER
#define bbb_HEADER

using namespace std;
#include "course.h"
#include "Person.h"
#include <string>
#include <ctime>

class Student:public Person
{
private:
	int id;
	float GPA;
	course *courses;   //6 courses
	int expected_graduation_year;
	string pass;
	static int count_students;
public:
	
	Student();
	Student(string name, string age, string nationalId, string email,int id,float gpa,course *courses,int grad_year);
	static int no_of_students();
	int get_Id();
	float get_GPA();
	course* get_cources();
	int how_long_to_graduate();
	int get_expected_graduation_year();
	string get_Password();
	void set_Id(int id);
	void set_GPA(float gpa);
	void set_courses(course* courses);
	void set_pass(string pass);
	void set_expected_graduation_year(int year);
	~Student();
};
#endif

