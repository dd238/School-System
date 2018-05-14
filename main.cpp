#include <iostream>
#include <fstream>
#include <string>
#include "BST.h"
#include "SchoolSystem.h"
#include "GenStack.h"
#include "NaiveList.h"
using namespace std;

int main(int argc, char** argv)
{
  int option;
  int studentID;
  string studentN;
  string studentLvl;
  string studentMajor;
  double studentGPA;
  int studentADID;
  int facultyID;
  string facultyN;
  string facultyLvl;
  string facultyDep;
  Student S = Student();
  Faculty F = Faculty();
  char yOn;
  int numOfS = 0;

  fstream myFile;

  //check to see if these files exist in 
  if(ifstream("studentTable.bin") && ifstream("facultyTable.bin"))
  {
    myFile.open("studentTable.bin", ios::in | ios::out | ios::binary);
    myFile.open("facultyTable.bin", ios::in | ios::out | ios::binary);
  }
  SchoolSystem* masterStudent = new SchoolSystem();
  SchoolSystem* masterFaculty = new SchoolSystem();
  
  GenStack<SchoolSystem*> studentStack = GenStack<SchoolSystem*>(1000);
  GenStack<SchoolSystem*> facultyStack = GenStack<SchoolSystem*>(1000);

  studentStack.push(masterStudent);
  facultyStack.push(masterFaculty);

  // do-while loop to make sure user enters a proper menu option
  do
  {
    cout << "Enter one of the following numbers to perform the listed function: " << endl
         << "1. Print all students and their information " << endl 
         << "2. Print all faculty and their information " << endl
         << "3. Find and display student information given the students id " << endl
         << "4. Find and display faculty information given the faculty id " << endl
         << "5. Given a student’s id, print the name and info of their faculty advisor " << endl
         << "6. Given a faculty id, print ALL the names and info of his/her advisees " << endl
         << "7. Add a new student " << endl
         << "8. Delete a student given the id " << endl
         << "9. Add a new faculty member " << endl
         << "10. Delete a faculty member given the id " << endl
         << "11. Change a student’s advisor given the student id and the new faculty id " << endl
         << "12. Remove an advisee from a faculty member given the ids " << endl
         << "13. Rollback " << endl
         << "14. Exit " << endl;
    cin >> option;

    if(option == 1)
    {
      if(masterStudent->SisEmpty())
      {
        cout << "No students in the system." << endl << endl;
      }
      else
      {
        masterStudent->printStudent();
      }
    }
    else if(option == 2)
    {
      if(masterFaculty->FisEmpty())
      {
        cout << "No faculty in the system." << endl << endl;
      }
      else
      {
        masterFaculty->printFaculty();
      }
    }
    else if(option == 3)
    {
      cout << "Enter the student's ID number: " << endl;
      cin >> studentID;
      if(masterStudent->SisEmpty())
      {
        cout << "This student does not exist." << endl << endl;;
      }
      else
      {
        masterStudent->displayStudentInfo(studentID); 
      }
    }
    else if(option == 4)
    {
      cout << "Enter the faculty ID number: " << endl;
      cin >> facultyID;
      if(masterFaculty->FisEmpty())
      {
        cout << "This faculty does not exist." << endl << endl;;
      }
      else
      {
        masterFaculty->displayFacultyInfo(facultyID); 
      }
    }
    else if(option == 5)
    {
      cout << "Enter the student's ID number: " << endl;
      cin >> studentID;
      if(masterStudent->SisEmpty())
      {
        cout << "This student or faculty does not exist." << endl << endl;;
      }
      else
      {
        masterStudent->displayStudentsAdvisor(studentID); 
      }
    }
    else if(option == 6)
    {
      cout << "Enter the faculty ID number: " << endl;
      cin >> facultyID;
      if(masterFaculty->FisEmpty())
      {
        cout << "This student or faculty does not exist." << endl << endl;;
      }
      else
      {
        masterFaculty->displayFacultiesStudents(facultyID); 
      }     
    }
    else if(option == 7)
    {
      cout << "Enter the student's ID: " << endl;
      cin >> studentID;
      cout << "Enter the student's name: " << endl;
      cin >> studentN;
      cout << "Enter the student's grade level: " << endl;
      cin >> studentLvl;
      cout << "Enter the student's major: " << endl;
      cin >> studentMajor;
      cout << "Enter the student's GPA: " << endl;
      cin >> studentGPA;
      cout << "Enter the student advisor ID: " << endl;
      cin >> studentADID;
      S.setID(studentID);
      S.setName(studentN);
      S.setLevel(studentLvl);
      S.setMajor(studentMajor);
      S.setGPA(studentGPA);
      
      F.setID(studentADID);

      if(masterFaculty->FisEmpty())
      {
        cout << "Faculty does not exist." << endl;
      }
      else
      {
        int id = masterFaculty->containsF(F);
        if(studentADID == id)
        {
          S.setAdvisorID(studentADID);
          F.addAdviseesID(studentID);
        }
        else
        {
          cout << "Faculty does not exist." << endl;
        }
      }
      
      masterStudent->insertStudent(S);

      studentStack.push(masterStudent);
      facultyStack.push(masterFaculty);
    }
    else if(option == 8)
    {
      cout << "Enter the student's ID number: " << endl;
      cin >> studentID;
      S.setID(studentID);
      F.setID(S.getAdvisorID());
      F.removeAdviseesId(studentID);
      masterStudent->removeStudent(S);

      studentStack.push(masterStudent);
      facultyStack.push(masterFaculty);
    }
    else if(option == 9)
    {
      cout << "Enter the faculty ID: " << endl;
      cin >> facultyID;
      cout << "Enter the faculty name: " << endl;
      cin >> facultyN;
      cout << "Enter the faculty level: " << endl;
      cin >> facultyLvl;
      cout << "Enter the faculty department: " << endl;
      cin >> facultyDep;
      cout << "Does the faculty advise students? (Y/N): " << endl;
      cin >> yOn;
      if(toupper(yOn) == 'Y')
      {
        cout << "How many students: " << endl;
        cin >> numOfS;

        for(int i = 0; i < numOfS; ++i)
        {
          cout << "Enter student’s ID: " << endl;
          cin >> studentID;
          S.setID(studentID);

          if(masterStudent->SisEmpty())
          {
            cout << "Student does not exist." << endl;
          }
          else
          {
            int id = masterStudent->containsS(S);
            if(studentID == id)
            {
              F.addAdviseesID(studentID);
              S.setAdvisorID(facultyID);
            }
            else
            {
              cout << "Student does not exist." << endl;
            }
          }  
        }
      }
      F.setID(facultyID);
      F.setName(facultyN);
      F.setLevel(facultyLvl);
      F.setDepartment(facultyDep);
      masterFaculty->insertFaculty(F);

      studentStack.push(masterStudent);
      facultyStack.push(masterFaculty);
    }
    else if(option == 10)
    {
      cout << "Enter the faculty ID number: " << endl;
      cin >> facultyID;
      F.setID(facultyID);
      masterFaculty->removeFaculty(F);

      /*
      NaiveList<int>* advisees = F.getAdviseesIds();

      for(int i = 0; i < advisees->getSize(); ++i)
      {
        S.setID(advisees);
        S.setAdvisorID(0);
      }
      */

      studentStack.push(masterStudent);
      facultyStack.push(masterFaculty);
    }
    else if(option == 11)
    {
      cout << "Enter the student's ID number: " << endl;
      cin >> studentID;
      cout << "Enter the faculty ID number: " << endl;
      cin >> facultyID;
      S.setID(studentID);
      S.setAdvisorID(facultyID);

      studentStack.push(masterStudent);
      facultyStack.push(masterFaculty);
    }
    else if(option == 12)
    {
      cout << "Enter the faculty ID number: " << endl;
      cin >> facultyID;
      F.setID(facultyID);

      cout << "How many students: " << endl;
      cin >> numOfS;

      for(int i = 0; i < numOfS; ++i)
      {
        cout << "Enter student’s ID: " << endl;
        cin >> studentID;
        F.removeAdviseesId(studentID);
      }
      studentStack.push(masterStudent);
      facultyStack.push(masterFaculty);
    }
    else if(option == 13)
    {
      if(studentStack.isEmpty() && facultyStack.isEmpty())
      {
        cout << "No commands to rollback. " << endl << endl;
      }
      else
      {
        studentStack.pop();
        facultyStack.pop();
        masterStudent = studentStack.peek();
        masterFaculty = facultyStack.peek();
      }  
    }
    else if(option == 14)
    {
      exit(0);
    }
    else
    {
      cout << "Please enter a number 1 - 14 " << endl;
    }

  }while(true);

  return 0;
}     


