#ifndef SCHOOLSYSTEM_H
#define SCHOOLSYSTEM_H

#include "BST.h"
#include "Faculty.h"
#include "Student.h"

class SchoolSystem
{
private:
	BST<Faculty> * facultyBST;
	BST<Student> * studentBST;
public:	
	SchoolSystem();
	~SchoolSystem();
	void insertFaculty(Faculty f);
	void removeFaculty(Faculty f);
	void printFaculty();
	void insertStudent(Student s);
	void removeStudent(Student s);
	void printStudent();

	void displayStudentInfo(int id);
	void displayFacultyInfo(int id);
	void displayStudentsAdvisor(int id);
	void displayFacultiesStudents(int id);
	void addStudentToFaculty(int studentID, int facultyID);
	void removeStudentFromFaculty(int studentID, int facultyID);
	int getRootFacultyID();
	bool FisEmpty();
	bool SisEmpty();
	int containsF(Faculty f);
	int containsS(Student s);
};

#endif