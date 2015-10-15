#pragma once
#ifndef department_H
#define department_H
#include "Student.h"
#include "gradStudent.h"
#include <iostream>
#include <string>

struct department {
	Student students_array[15];   //declaring student array
	gradStudent gradstudents_array[15];

	//This function takes an array of students and the total number //of students and sorts them in ascending order according to GPA
	void sortStudentArrayGPA(Student arr[], int n);

	//This function takes an array of students and the total number //of students and prints them to console
	void printStudents(Student students[], int index);

	//This function takes an array of students and the total number //of students and sorts them in ascending order according to GPA
	void sortgradStudentArrayGPA(gradStudent gradarr[], int gradn);

	//This function takes an array of students and the total number //of students and prints them to console
	void printgradStudents(gradStudent students[], int index);

};
#endif