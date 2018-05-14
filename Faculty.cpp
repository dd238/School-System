#include "Faculty.h"
#include <string>
#include <iostream>
using namespace std;

Faculty::Faculty()
{
  ID = 0;
  name = '\0';
  level = '\0';
  department = '\0';
  adviseesIDs = new NaiveList<int>();
}

Faculty::Faculty(int id, string nm, string lvl, string dpmt, NaiveList<int>* advIds)
{
  ID = id;
  name = nm;
  level = lvl;
  department = dpmt;
  adviseesIDs = advIds;
}

Faculty::~Faculty()
{
  adviseesIDs = NULL;
  delete[] adviseesIDs;
}

void Faculty::print()
{
  cout<<"\nID: "<<ID<<"\nName: "<<name<<"\nLevel: "<<level<<"\nDepartment: "<<department<<"\nAdvisees ID's: "<<endl<< endl;
  adviseesIDs->printList();
}

//modifiers
void Faculty::setID(int id)
{
  ID = id;
}
void Faculty::setName(string nm)
{
  name = nm;
}
void Faculty::setLevel(string lvl)
{
  level = lvl;
}
void Faculty::setDepartment(string dpmt)
{
  department = dpmt;
}


//accessors
int Faculty::getID()
{
  return ID;
}
string Faculty::getName()
{
  return name;
}
string Faculty::getLevel()
{
  return level;
}
string Faculty::getDepartment()
{
  return department;
}
NaiveList<int>* Faculty::getAdviseesIds()
{
  return adviseesIDs;
}

void Faculty::addAdviseesID(int id)
{
  adviseesIDs->insertFront(id);
}

void Faculty::removeAdviseesId(int id)
{
  adviseesIDs->removeNode(id);
}

bool operator<(const Faculty& facultyA, const Faculty& facultyB){return facultyA.ID < facultyB.ID;}
bool operator>(const Faculty& facultyA, const Faculty& facultyB){return (facultyB < facultyA);}
bool operator<=(const Faculty& facultyA, const Faculty& facultyB){return !(facultyA > facultyB);}
bool operator>=(const Faculty& facultyA, const Faculty& facultyB){return !(facultyA < facultyB);}
bool operator==(const Faculty& facultyA, const Faculty& facultyB){return (facultyA.ID == facultyB.ID);}
bool operator!=(const Faculty& facultyA, const Faculty& facultyB){return !(facultyA == facultyB);}
