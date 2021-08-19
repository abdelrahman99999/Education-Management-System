#include<iostream>
#include<sstream>
#include <fstream>
#include<vector>
#include<string>
#include "Student.h"
#include "Instructor.h"
#include "course.h"
#include "TermSpecifications.h"
#include "LinkedList.h" 
using namespace std;

void parse_line(string detalis_csv, Instructor &I);
void fill_Instructors_Data_from_files();
void get_Students_Data_from_User_save_it_in_files();



int main() {
	cout << "\t\t\t***************************\n";
	cout << "\t\t\tEducation Management System \n";
	cout << "\t\t\t***************************\n";
	fill_Instructors_Data_from_files();
	fstream fout;
	// opens an existing csv file or creates a new file.
	fout.open(students_path_file, ios::out );
	fout << "Id" << "," << "Name" << "," << "national_ID" << "," << "email" << "," << "Age" << "," << "gpa" << "," << "expexted_grad_year" << "\n";
	fout.close();

	int select_option;
	while(1){
		cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
		cout << "select your options:\n";
		cout << "1. Enter Students Data?\n" 
			 << "2. Get Instructors Informations?\n" 
			 << "3. Get the 1st Student of all students?   *you should use this option After enter students data*\n"
			 << "4. Get total numbers of students?\n"
			 << "5. Get Info about specific student and his selected courses?       *you should use this option After enter students data*\n"    
			 << "6. exit the program\n";
		cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
		cin >> select_option;
		switch (select_option)
		{
		case 1:
			get_Students_Data_from_User_save_it_in_files();
			break;
		case 2:
			int select_Instructors_options;
			cout << "enter 0 for Math Instructors\n";
			cout << "enter 1 for physics Instructions\n";
			cout << "enter 2 for Drawing Instructions\n";
			cout << "enter 3 for Fundamentals Instructions\n";
			cout << "enter 4 for Production Instructions\n";
			cout << "enter 5 for Report Instructions\n";
			cout << "enter 6 for Statics Instructions\n";
			cout << "enter 7 for Dynamics Instructions\n";
			cout << "enter 8 for Programming Instructions\n";
			cout << "enter 9 for Logic Instructions\n";
			cin >> select_Instructors_options;
			cout << "---------------------------------------\n";
			cout << "Name   ||   Email   ||  office hours\n";
			cout << "---------------------------------------\n";
			for(int i=0;i<3;i++){
				cout << Instructors[select_Instructors_options][i].get_name() << " || " << Instructors[select_Instructors_options][i].get_email() <<" || "<< Instructors[select_Instructors_options][i].get_office_hours() << "\n";
			}
			cout << "---------------------------------------\n";
			break;

		case 3:
			if (students.listSize() == 0)cout << "you must have student in system to get 1st student among them\n";
			else{
				cout << "-------------------------------\n";
				cout << "Id   ||   Name   ||  GPA \n";
				cout << "-------------------------------\n";
				cout << get_1st_student().get_Id() << "  ||  " << get_1st_student().get_name()<<"  ||  "<< get_1st_student().get_GPA()<<"\n";
			}
			break;
		case 4:
			cout << "total numbers of students in system: " << students.listSize() << "\n";
			break;
		case 5:
			if (students.listSize() == 0)cout << "you must have student in system to get 1st student among them\n";
			else {
				int selected_student;
				cout << "enter Id of student you want to show his Info: ";
				cin >> selected_student;
				cout << "-------------------------------------\n";
				cout << "Id   ||   Name   ||  GPA   ||  Email \n";
				cout << "-------------------------------------\n";
				cout << students.retrieveList(selected_student).get_Id() << "  ||  " << students.retrieveList(selected_student).get_name() << "  ||  " << students.retrieveList(selected_student).get_GPA() << "  ||  " << students.retrieveList(selected_student).get_email() << "\n";
				cout << "-------------------------------------\n";
				cout << "courses taken:\n";
				if (students.retrieveList(selected_student).get_cources()[0].get_course_name() == courses_1_term[0].get_course_name()) {
					cout << "		 " << courses_1_term[0].get_course_name() << "\n";
					cout << "		 " << courses_1_term[1].get_course_name() << "\n";
					cout << "		 " << courses_1_term[2].get_course_name() << "\n";
					cout << "		 " << courses_1_term[3].get_course_name() << "\n";
					cout << "		 " << courses_1_term[4].get_course_name() << "\n";
				}
				else {
					cout << "		 " << courses_2_term[0].get_course_name() << "\n";
					cout << "		 " << courses_2_term[1].get_course_name() << "\n";
					cout << "		 " << courses_2_term[2].get_course_name() << "\n";
					cout << "		 " << courses_2_term[3].get_course_name() << "\n";
					cout << "		 " << courses_2_term[4].get_course_name() << "\n";
				}
			}
			break;
		case 6:
			exit(0);
			break;
		}
		
	}
	return 0;
}


void fill_Instructors_Data_from_files() {
	ifstream fin1;
	string line;
	for (int a = 0; a < no_of_cources; a++) {
		fin1.open(Instructors_files_paths[a]);
		fin1 >> line;
		int i = 0;
		while (!fin1.eof()) {
			fin1 >> line;
			parse_line(line, Instructors[a][i]);
			i++;
		}
		fin1.close();
	}

}

void get_Students_Data_from_User_save_it_in_files() {
	//ostream f_out(students_path_file, ios_base::app);
	//f_out.open(students_path_file,  ios_base::app, ios::out );
	fstream f_out;
	f_out.open(students_path_file, std::fstream::in | std::fstream::out | std::fstream::app);
	int flag = 1;
	static int Id = 0;
	int select_cources_group = 1;
	string name, age, national_ID, email;
	float gpa;
	course *selected_group = new course[5];
	while (flag) {
		cout << "enter student data?\n";
		cout << "Name: ";
		cin >> name;
		cout << "Age: ";
		cin >> age;
		cout << "National Id: ";
		cin >> national_ID;
		cout << "Email: ";
		cin >> email;
		cout << "GPA: ";
		cin >> gpa;
		cout << "there are 2 groups of courses for this term, you can select one only\n";
		cout << "--------------------------\n";
		cout << "group 1      |     group 2\n";
		cout << "--------------------------\n";
		cout << courses_1_term[0].get_course_name() << "         | " << courses_2_term[0].get_course_name() << "\n";
		cout << courses_1_term[1].get_course_name() << "      | " << courses_2_term[1].get_course_name() << "\n";
		cout << courses_1_term[2].get_course_name() << "      | " << courses_2_term[2].get_course_name() << "\n";
		cout << courses_1_term[3].get_course_name() << "  | " << courses_2_term[3].get_course_name() << "\n";
		cout << courses_1_term[4].get_course_name() << "  | " << courses_2_term[4].get_course_name() << "\n";
		cout << "--------------------------\n";
		cout << "Selct your prefered group of courses,enter 1 or 2: ";
		cin >> select_cources_group;
		switch (select_cources_group)
		{
		case 1:
			selected_group = courses_1_term;
			break;
		case 2:
			selected_group = courses_2_term;
			break;
		default:
			selected_group = courses_1_term;
			break;
		}
		f_out << Id <<","<< name << "," << national_ID << "," << email << "," << age << "," << gpa << "," << expexted_grad_year << "\n";
		students.insertList(Id, Student(name, age, national_ID, email, Id, gpa, selected_group, expexted_grad_year));
		//cout << Student::no_of_students() << "\n";	 // will give me always const number as life time of local end with end of his scope, so use linkedList size to know total numbers of students;
		Id++;
		cout << "do you want to add another students? enter (1 for yes) (0 for no)\n";
		cin >> flag;
		cin.ignore();
	}
	f_out.close();
}

void parse_line(string detalis_csv, Instructor &I)
{
	string name, age, nationalId, email, office_hours;
	vector<string >v;
	stringstream ss(detalis_csv);
	while (ss.good()) {
		string substr;
		getline(ss, substr, ',');
		v.push_back(substr);
	}
	name = v[0]; 	age = v[1]; 	nationalId = v[2];	email = v[3];	office_hours = v[4];
	I.set_name(name);
	I.set_age(age);
	I.set_nat_id(nationalId);
	I.set_email(email);
	I.set_office_hours(office_hours);
}



