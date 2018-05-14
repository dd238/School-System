#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
using namespace std;

class Student
{
public:
  Student();
  Student(int id, string nm, string lvl, string mj, double gpa, int adID);
  ~Student();

  void print();

//modifiers
  void setID(int id);
  void setName(string nm);
  void setLevel(string lvl);
  void setMajor(string mjr);
  void setGPA(double gpa);
  void setAdvisorID(int adID);
//accessors
  int getID();
  string getName();
  string getLevel();
  string getMajor();
  double getGPA();
  int getAdvisorID();

  friend ostream& operator<<(ostream& os, const Student s);
  friend bool operator<(const Student& studentA, const Student& studentB);
  friend bool operator>(const Student& studentA, const Student& studentB);
  friend bool operator<=(const Student& studentA, const Student& studentB);
  friend bool operator>=(const Student& studentA, const Student& studentB);
  friend bool operator==(const Student& studentA, const Student& stuentB);
  friend bool operator!=(const Student& studentA, const Student& stuentB);

private:
  int ID;
  string name;
  string level;
  string major;
  double GPA;
  int advisorID;


};

#endif