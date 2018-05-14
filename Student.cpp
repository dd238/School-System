#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

Student::Student()
{
  ID = 0;
  name = '\0';
  level = '\0';
  major = '\0';
  GPA = 0;
  advisorID = 0;
}

Student::Student(int id, string nm, string lvl, string mj, double gpa, int adID)
{
  ID = id;
  name = nm;
  level = lvl;
  major = mj;
  GPA = gpa;
  advisorID = adID;
}

Student::~Student()
{
  
}

void Student::print()
{
  cout<<"\nID: "<<getID()<<"\nName: "<<getName()<<"\nLevel: "<<getLevel()<<"\nMajor: "<<getMajor()<<"\nGPA: "<<getGPA()<<"\nAdvisor ID: "<<getAdvisorID()<<endl<< endl;
}

//modifiers
void Student::setID(int id)
{
  ID = id;
}
void Student::setName(string nm)
{
  name = nm;
}
void Student::setLevel(string lvl)
{
  level = lvl;
}
void Student::setMajor(string mjr)
{
  major = mjr;
}
void Student::setGPA(double gpa)
{
  GPA = gpa;
}
void Student::setAdvisorID(int adID)
{
  advisorID = adID;
}

//accessors
int Student::getID()
{
  return ID;
}
string Student::getName()
{
  return name;
}
string Student::getLevel()
{
  return level;
}
string Student::getMajor()
{
  return major;
}
double Student::getGPA()
{
  return GPA;
}
int Student::getAdvisorID()
{
  return advisorID;
}

bool operator<(const Student& studentA, const Student& studentB){return studentA.ID < studentB.ID;}
bool operator>(const Student& studentA, const Student& studentB){return (studentB < studentA);}
bool operator<=(const Student& studentA, const Student& studentB){return !(studentA > studentB);}
bool operator>=(const Student& studentA, const Student& studentB){return !(studentA < studentB);}
bool operator==(const Student& studentA, const Student& studentB){return (studentA.ID == studentB.ID);}
bool operator!=(const Student& studentA, const Student& studentB){return !(studentA == studentB);}

