#include "student.h"
#include <iostream>
#include <string>

void Student::initialize(string Name, int Id, float gpa) {
	name = Name;
	id = Id;
	GPA = gpa;
}

string Student::getName() {
	return name;
}

int Student::getId() {
	return id;
}

float Student::getgpa() {
	return GPA;
}

//int i;

void Student::printStudent()
{
	cout << "Name: " << getName() << endl;
	cout << "ID: " << getId() << endl;
	cout << "GPA: " << getgpa() << endl;
}
//This function takes an array of students and the total number //of students and sorts them in ascending order according to GPA
/*
void sortStudentArrayGPA(Student arr[], int n) {
	int minindex = 0;
	int startindex = 0;
	for (startindex; startindex < n; startindex++)
	{
		minindex = startindex;
		for (int studentindex = 0; studentindex < n; studentindex++)
		{
			if (arr[studentindex].getgpa() < arr[minindex].getgpa())
			{
				Student temp = arr[minindex];
				arr[minindex] = arr[studentindex];
				arr[studentindex] = temp;
			}
		}
	}

}

//This function takes an array of students and the total number //of students and prints them to console
void printStudents(Student students[], int index) {
	for (i = 0; i < index; i++)
	{
		students[i].printStudent();

	}
}

*/