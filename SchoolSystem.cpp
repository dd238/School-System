#include "SchoolSystem.h"

SchoolSystem::SchoolSystem()
{
  facultyBST = new BST<Faculty>();
  studentBST = new BST<Student>();
}

void SchoolSystem::insertFaculty(Faculty f)
{
  facultyBST->insert(f);
}
void SchoolSystem::removeFaculty(Faculty f)
{
  facultyBST->deleteNode(f);
}
void SchoolSystem::printFaculty()
{
	facultyBST->inOrder(facultyBST->getRoot());
}
void SchoolSystem::insertStudent(Student s)
{
	studentBST->insert(s);
}
void SchoolSystem::removeStudent(Student s)
{
	studentBST->deleteNode(s);
}
void SchoolSystem::printStudent()
{
	studentBST->inOrder(studentBST->getRoot());
}

void SchoolSystem::displayStudentInfo(int id)
{
  Student i = Student();
  i.setID(id);
  Student s = studentBST->search(i)->getData();
  s.print();
}

void SchoolSystem::displayFacultyInfo(int id)
{
  Faculty i = Faculty();
  i.setID(id);
  Faculty f = facultyBST->search(i)->getData();
  f.print();
}

void SchoolSystem::displayStudentsAdvisor(int id)
{
  Student i = Student();
  i.setID(id);
  Student s = studentBST->search(i)->getData();
  int fid = s.getAdvisorID();
  displayFacultyInfo(fid);
}

void SchoolSystem::displayFacultiesStudents(int id)
{
  Faculty i = Faculty();
  i.setID(id);
  Faculty f = facultyBST->search(i)->getData();
  NaiveList<int>*  ids = f.getAdviseesIds();
  for (int i = 0; i < ids->getSize(); ++i)
  {
    int sid = ids->removeFront();
    Student a = Student();
    a.setID(sid);
    Student s = studentBST->search(a)->getData();
    s.print();
    ids->insertBack(sid);
  }
}

void SchoolSystem::addStudentToFaculty(int studentID, int facultyID)
{
  Faculty i = Faculty();
  i.setID(facultyID);
  Faculty f = facultyBST->search(i)->getData();
  removeFaculty(i);
  f.addAdviseesID(studentID);
  insertFaculty(f);
}

void SchoolSystem::removeStudentFromFaculty(int studentID, int facultyID)
{
  Faculty i = Faculty();
  i.setID(facultyID);
  Faculty f = facultyBST->search(i)->getData();
  removeFaculty(i);
  f.removeAdviseesId(studentID);
  insertFaculty(f);
}

int SchoolSystem::getRootFacultyID()
{
  Faculty f = facultyBST->getRoot()->getData();
  int id = f.getID();
  return id;
}

bool SchoolSystem::FisEmpty()
{
  return facultyBST->isEmpty();
}

bool SchoolSystem::SisEmpty()
{
  return studentBST->isEmpty();
}

int SchoolSystem::containsF(Faculty f)
{
  return (facultyBST->search(f)->getData().getID());
}
int SchoolSystem::containsS(Student s)
{
  return (studentBST->search(s)->getData().getID());
}