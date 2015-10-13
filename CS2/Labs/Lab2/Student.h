#pragma once
#ifndef Student_H
#define Student_H
#include <string>
using namespace std;

class Student
{
public:
	void initialize(string Name, int Id, float gpa);

	string getName();

	int getId();

	float getgpa();


private:
	string name;
	int id;
	float GPA;

public:
	void printStudent();
};

//This function takes an array of students and the total number //of students and sorts them in ascending order according to GPA
void sortStudentArrayGPA(Student arr[], int n);

//This function takes an array of students and the total number //of students and prints them to console
void printStudents(Student students[], int index);

#endif