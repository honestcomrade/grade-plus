#include "Database.h"
#include "Student.h"

#include <iostream>
#include <string>

using namespace std;

int main() {
  // main prompt
  bool isOpen = true; // MUST REPLACE WITH MEMBER FUNCTION FOR COURSE

  // test instantiation of a Database object.
  cout << "Testing instantiation of a Database object:\n";
  Database db("test-1.sqlite");

  // test instantiation of a Student object.
  cout << "Testing instantiation of a Student object:\n";
  Student s("1234567", "Jamie", "Green", db);

  cout << "Name: \t\t" << s.getFirstName() << " " << s.getLastName() << endl;
  cout << "ID: \t\t" << s.getId() << endl;

  // test writing Student to the database file
  cout << "Testing writing Student to the database file:\n\n";
  s.save();

  string input;
  cout << "Welcome to grade-plus\n";
  cout << "What would you like to do?\n";
  cout << "WORK on an existing course [W] -or- CREATE a new Course [C]: ";

  // input loop
  while (true) {
    cin >> input;
    if (tolower(input[0]) == 'w') {
      cout << "Which Course?: ";
      cin >> input;
      cout << "Opening course: " << input << "...\n";
      // open the course with openCourse function
      cout << "//course.open(" << input << ");\n";
      break;
    }

    else if (tolower(input[0]) == 'c') {
      cout << "Please enter a unique name\n";
      cout << "Course Name?: "; cin >> input;
      string cName = input;
      cout << "Course Subject?: "; cin >> input;
      string cSubj = input;
      cout << "Creating Course: " << cName << " - " << cSubj << endl;
      // call the createcourse function
      cout << "createCourse(" << cName << "," << cSubj << ");\n";
      break;
    }

    else if (tolower(input[0]) == 'q') {
      cout << "Goodbye\n";
      !isOpen; // MUST REPLACE WITH MEMBER FUNCTION FOR COURSE
      break;
    }

    else {
      cout << "Invalid entry: " << input << endl;
      cout << "What would you like to do?\n";
      cout << "WORK on an existing course [W] -or- CREATE a new course [C]: ";
      continue;
    }
  }  // opening loop
  
  // second loop whule the course is open
  
  while (isOpen) {
    cout << "LIST ALL THE COURSE DETAILS:\n";
    cout << "Add/Remove STUDENTS [S] -or- Add/Remove/Modify ASSIGNMENTS [A]: ";
    cin >> input;
    // students handler
    if (tolower(input[0]) == 's') {
      cout << "List all the students in this course\n";
      cout << "Student1 name Student1 id Student1 grade\n";
      cout << "Student2 name Student2 id Student2 grade\n";
      cout << "Student3 name Student3 id Student3 grade\n";
      cout << "Student4 name Student4 id Student4 grade\n";
      cout << "ADD Student [A] -or- REMOVE  Student [R]: ";
      cin >> input;
      // add student
      if (tolower(input[0]) == 'a') {
        cout << "Student First Name?: ";
        cin >> input;
        string stuFirst = input;
        cout << "Student Last Name?: ";
        cin >> input;
        string stuLast = input;
        cout << "Student ID?: ";
        cin >> input;
        string stuID = input;
        cout << "Student Name: " << stuFirst << " " << stuLast << " Student ID: " << stuID << endl; 
      }
      // drop student
      else if (tolower(input[0]) == 'r') {
        cout << "Which student to drop? [name]: ";
        cin >> input;
        // call drop student function on that student

        // cout << "Name: \t\t" << input.getFirstName() << " " << input.getLastName() << endl;
        // cout << "ID: \t\t" << input.getId() << endl;
        // call drop student function on that student
        cout << "Calling dropStudent(" << input << ")\n";
      }
    }
    // ASSIGNMENTS HANDLER
    else if (tolower(input[0]) == 'a') {
      cout << "List all the assignments in this course\n";
      cout << "Assignment1 number Assignment1 name Assignment1 type Assignment1 weight Assignment1 average\n";
      cout << "Assignment2 number Assignment2 name Assignment2 type Assignment2 weight Assignment2 average\n";
      cout << "Assignment3 number Assignment3 name Assignment3 type Assignment3 weight Assignment3 average\n";
      cout << "Assignment4 number Assignment4 name Assignment4 type Assignment4 weight Assignment4 average\n";
      cout << "Assignment5 number Assignment5 name Assignment5 type Assignment5 weight Assignment5 average\n";
      cout << "ADD Assignment [A] -or- REMOVE Assignment [R] -or- MODIFY Assignment [M]: ";
      cin >> input;
      // add assignment
      if (tolower(input[0]) == 'a') {
        cout << "Adding a new assignment: \n";
        cout << "Assignment Name?: ";
        cin >> input;
        string assName = input;
        cout << "Assignment type?: ";
        cin >> input;
        string assType = input;
        cout << "Assignment weight?: ";
        cin >> input;
        string assWeight = input;
        cout << "Calling assignmentCreate(" << assName<< "," << assType << "," << assWeight <<");\n";
      }
      // remove assignment
      else if (tolower(input[0]) == 'r') {
        cout << "Remove which assignment? [number]: ";
        cin >> input;
        cout << "Calling assignmentRemove(" << input << ")\n";  // to replace with member function
        break;
      }
      // modify assignment
      else if (tolower(input[0]) == 'm') {
        cout << "Modify which assignment? [number]: ";
        cin >> input;
        cout << "Calling assignmentChange(" << input << ")\n";
        break;
      }
      else {
      cout << "Invalid entry: " << input << endl;
      continue;
      }
   
    }

    // else invalid
    else {
    cout << "Invalid entry: " << input << endl;
    continue;
    }
  } // while course is open
}