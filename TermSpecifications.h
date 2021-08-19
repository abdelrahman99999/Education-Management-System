#pragma once
#include<string>
#include "Instructor.h"
#include "course.h"
#include"LinkedList.h"
using namespace std;
#define no_of_cources 10


string Instructors_files_paths[no_of_cources] = { 
"C:\\Users\\boody\\Desktop\\cources\\math-Instructors.csv",
"C:\\Users\\boody\\Desktop\\cources\\physics-Instructors.csv" ,
"C:\\Users\\boody\\Desktop\\cources\\drawing-Instructors.csv",
"C:\\Users\\boody\\Desktop\\cources\\fundamental-Instructors.csv",
"C:\\Users\\boody\\Desktop\\cources\\production-Instructors.csv",
"C:\\Users\\boody\\Desktop\\cources\\report-Instructors.csv",
"C:\\Users\\boody\\Desktop\\cources\\static-Instructors.csv",
"C:\\Users\\boody\\Desktop\\cources\\dynamic-Instructors.csv",
"C:\\Users\\boody\\Desktop\\cources\\programming-Instructors.csv",
"C:\\Users\\boody\\Desktop\\cources\\logic-Instructors.csv"
};

string students_path_file = "C:\\Users\\boody\\Desktop\\cources\\students\\students.csv";

LinkedList<Student> students;

Instructor *Math_Instructors1 = new Instructor[3], 
*physics_Instructors1 = new Instructor[3], 
*Drawing_Instructors1 = new Instructor[3],
*Fundamental_Instructors1 = new Instructor[3], 
*Production_Instructors1 = new Instructor[3],
*Report_Instructors1 = new Instructor[3], 
*statics_Instructors1 = new Instructor[3], 
*Dynamics_Instructors1 = new Instructor[3],
*programming_Instructors1 = new Instructor[3],
*logic_Instructors = new Instructor[3];

Instructor * Instructors[no_of_cources] = { 
	Math_Instructors1 ,
	physics_Instructors1,
	Drawing_Instructors1,
	Fundamental_Instructors1,
	Production_Instructors1,
	Report_Instructors1 ,
	statics_Instructors1 ,
	Dynamics_Instructors1,
	programming_Instructors1,
	logic_Instructors 
};

course courses_1_term[5] = { 
	course("Math", "PHM123", " ", 3, Math_Instructors1),
	course("Physics", "PHM122", " ", 4, physics_Instructors1),
	course("Drawing", "abc222", " ", 3, Drawing_Instructors1),
	course("Fundamental", "ASU509", " ", 2, Fundamental_Instructors1),
	course("Programming", "CSE509", " ", 3, programming_Instructors1) 
};


course courses_2_term[5] = { 
	course("Report", "ASU912", " ", 2, Report_Instructors1) ,
	course("statics", "PHM001", " ", 3, statics_Instructors1) ,
	course("Dynamics", "PHM777", " ", 3, Dynamics_Instructors1) ,
	course("Fundamental", "ASU509", " ", 2, Fundamental_Instructors1) ,
	course("Production", "MEC870", " ", 4, Production_Instructors1)
};


Student get_1st_student() {
	Student first_student=students.retrieveList(0);
	for (int i = 1; i < students.listSize(); i++) {
		if(students.retrieveList(i).get_GPA()>first_student.get_GPA()) first_student= students.retrieveList(i);
	}
	return first_student;
}

int expexted_grad_year = 2023;