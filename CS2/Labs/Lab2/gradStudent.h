#pragma once

#ifndef gradStudent_H
#define gradStudent_H
#include "Student.h"
#include <iostream>
#include <string>

class gradStudent : public Student 
{
public:
	void initialize(string Name, int Id, float gpa, string Research_Area);

	string getResearch_Area();

private:
	string research_area;

public:
	void printgradStudent();
};

//This function takes an array of students and the total number //of students and sorts them in ascending order according to GPA
void sortgradStudentArrayGPA(gradStudent gradarr[], int gradn);

//This function takes an array of students and the total number //of students and prints them to console
void printgradStudents(gradStudent students[], int index);

#endif

