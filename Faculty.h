#ifndef FACULTY_H
#define FACULTY_H

#include <string>
#include <iostream>
#include "NaiveList.h"
using namespace std;

class Faculty
{
public:
  Faculty();
  Faculty(int id, string nm, string lvl, string dpmt, NaiveList<int>* advIds);
  ~Faculty();

  void print();

//modifiers
  void setID(int id);
  void setName(string nm);
  void setLevel(string lvl);
  void setDepartment(string dpmt);
//accessors
  int getID();
  string getName();
  string getLevel();
  string getDepartment();
  NaiveList<int>* getAdviseesIds();
  void addAdviseesID(int id);
  void removeAdviseesId(int id);

  friend ostream& operator<<(ostream& os, const Faculty f);
  friend bool operator<(const Faculty& facultyA, const Faculty& facultyB);
  friend bool operator>(const Faculty& facultyA, const Faculty& facultyB);
  friend bool operator<=(const Faculty& facultyA, const Faculty& facultyB);
  friend bool operator>=(const Faculty& facultyA, const Faculty& facultyB);
  friend bool operator==(const Faculty& facultyA, const Faculty& facultyB);
  friend bool operator!=(const Faculty& facultyA, const Faculty& facultyB);

private:
  int ID;
  string name;
  string level;
  string department;
  NaiveList<int>* adviseesIDs;

  
};

#endif