#ifndef ddd_HEADER
#define ddd_HEADER

using namespace std;
#include<string>

class Person{
protected:
	static int counter_persons;
	string name;
	string age;
	string nationalId;
	string email;
public:
	
	Person();
	Person(string name,string age,string nationalId,string email);
	static int no_of_persons();
	string get_name();
	string get_national_Id();
	string get_age();
	string get_email();
	void set_name(string name);
	void set_age(string age);
	void set_nat_id(string natId);
	void set_email(string email);
	~Person();
};
#endif
