#include "Student.h"
#include "gradStudent.h"
#include "department.h"
#include <iostream>
#include <string>

void department::sortStudentArrayGPA(Student arr[], int n) {
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
void department::printStudents(Student students[], int index) {
	for (int i = 0; i < index; i++)
	{
		students[i].printStudent();

	}
}


//This function takes an array of students and the total number //of students and sorts them in ascending order according to GPA
void department::sortgradStudentArrayGPA(gradStudent gradarr[], int gradn) {
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
void department::printgradStudents(gradStudent students[], int index) {
	for (int j = 0; j < index; j++)
	{
		students[j].printgradStudent();

	}
}
