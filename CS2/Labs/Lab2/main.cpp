#include "student.h"
#include "gradStudent.h"
#include "department.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	//Declare an instance of the struct Student
	//Student a_student;

	//Delcare variables to store data
	string name;
	string firstname;
	string lastname;
	int id;
	string research_area;
	int index = 0;
	int gradindex = 0;
	float GPA;

	//Student students_array[10];   //declaring student array
	//gradStudent gradstudents_array[10];
	Student a_student;

	department sdepartment;

	cout << "This is the list of undergraduate students: " << endl;

	ifstream instream;
	instream.open("Student.txt");  //Opening the student file to read data

	while (!instream.eof()) {
		instream >> firstname >> lastname >> id >> GPA;
		
		sdepartment.students_array[index].initialize(firstname + ' ' + lastname, id, GPA);
		index++;

		//a_student.getName() = firstname + " " + lastname;
		//a_student.getId() = id;
		//a_student.getgpa() = GPA;

		


	};
	instream.close();

	


	//Set data members of struct Student
	//a_student.name = "John";
	//a_student.id = 1234567;
	//a_student.GPA = 0.0;

	//Call member function to print the struct
	sdepartment.sortStudentArrayGPA(sdepartment.students_array, index);
	sdepartment.printStudents(sdepartment.students_array, index);


	cout << endl;
	cout << "This is the list of Graduate students:" << endl;

	ifstream gradinstream;
	gradinstream.open("gradStudent.txt");  //Opening the student file to read data

	while (!gradinstream.eof()) {
		gradinstream >> firstname >> lastname >> id >> GPA >> research_area;

		//cout << firstname << lastname << id << GPA << research_area;

		sdepartment.gradstudents_array[gradindex].initialize(firstname + ' ' + lastname, id, GPA, research_area);
		gradindex++;

		//a_student.getName() = firstname + " " + lastname;
		//a_student.getId() = id;
		//a_student.getgpa() = GPA;




	};
	gradinstream.close();

	sdepartment.sortgradStudentArrayGPA(sdepartment.gradstudents_array, gradindex);
	sdepartment.printgradStudents(sdepartment.gradstudents_array, gradindex);

	

	system("pause"); // Only necessary if using Visual Studio
	return 0;

	system("pause"); // Only necessary if using Visual Studio
	return 0;
}
