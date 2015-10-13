
#include "student.h"
#include "gradStudent.h"
#include <iostream>
#include <string>

void gradStudent::initialize(string Name, int Id, float gpa, string Research_Area) {
	Student::initialize(Name, Id, gpa);
	research_area = Research_Area;
}

string gradStudent::getResearch_Area() {
	return research_area;
}

int j;


void gradStudent::printgradStudent()
{
	Student::printStudent();
	cout << "Research Area: " << getResearch_Area() << endl;
}
//This function takes an array of students and the total number //of students and sorts them in ascending order according to GPA
/*
void sortgradStudentArrayGPA(gradStudent gradarr[], int gradn) {
	int minindex = 0;
	int startindex = 0;
	for (startindex; startindex < gradn; startindex++)
	{
		minindex = startindex;
		for (int studentindex = 0; studentindex < gradn; studentindex++)
		{
			if (gradarr[studentindex].getgpa() < gradarr[minindex].getgpa())
			{
				gradStudent temp = gradarr[minindex];
				gradarr[minindex] = gradarr[studentindex];
				gradarr[studentindex] = temp;
			}
		}
	}

}

//This function takes an array of students and the total number //of students and prints them to console
void printgradStudents(gradStudent students[], int index) {
	for (j = 0; j < index; j++)
	{
		students[j].printgradStudent();

	}
}
*/