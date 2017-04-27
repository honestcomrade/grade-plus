#include "Database.h"
#include "Student.h"

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
  // main prompt
  bool isOpen = true;  // MUST REPLACE WITH MEMBER FUNCTION FOR COURSE

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
  // s.save();

  string input;
  string openCourse;
  cout << "Welcome to grade-plus\n";
  cout << "What would you like to do?\n";
  cout << "WORK on an existing Course ";
  cout.width(6);
  cout << right << "[W]\nCREATE a new Course " << right << " [C]\n";
  cout << " $: ";
  // input loop
  while (true) {
    cin >> input;

    // open Course
    if (tolower(input[0]) == 'w') {
      cout << "Which Course?: ";
      cin >> input;
      cout << "Opening Course: " << input << "...\n";
      // open the course with openCourse function
      openCourse = input;
      cout << "Calling course.open(" << openCourse << ");\n";

      break;
    }

    // create Course
    else if (tolower(input[0]) == 'c') {
      cout << "Please enter a unique name\n";
      cout << "Course Name?: ";
      cin >> input;
      string cName = input;
      cout << "Course Subject?: ";
      cin >> input;
      string cSubj = input;
      cout << "Creating Course: " << cName << " - " << cSubj << endl;
      // call the createcourse function
      cout << "createCourse(" << cName << "," << cSubj << ");\n";
      break;
    }

    // quit
    else if (tolower(input[0]) == 'q') {
      cout << "Goodbye\n";
      !isOpen;  // MUST REPLACE WITH MEMBER FUNCTION FOR COURSE
      break;
    }

    // invalid
    else {
      cout << "Invalid entry: " << input << endl;
      cout << "What would you like to do?\n";
      continue;
    }
  }  // opening loop

  // second loop while the course is open
  while (/*openCourse*/ isOpen) {
    cout << "LIST ALL THE COURSE DETAILS:\n";
    cout << "Name: \t" << openCourse << "\n\n";
    cout << "\tAdd/Remove STUDENTS [S]\n\tAdd/Remove/Modify ASSIGNMENTS\n $: ";
    cin >> input;
    // students handler
    if (tolower(input[0]) == 's') {
      cout << "List all the students in this course\n";
      cout << "Student1 name Student1 id Student1 grade\n";
      cout << "Student2 name Student2 id Student2 grade\n";
      cout << "Student3 name Student3 id Student3 grade\n";
      cout << "Student4 name Student4 id Student4 grade\n\n";
      cout << "\tADD Student [A]\n\tREMOVE Student [R]\n";
      cout << " $: ";
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
        cout << "Student Name: " << stuFirst << " " << stuLast
             << " Student ID: " << stuID << endl;
      }
      // drop student
      else if (tolower(input[0]) == 'r') {
        cout << "Which student to drop? [ID]: ";
        cin >> input;

        // call drop student function on that student
        // cout << "Name: \t\t" << input.getFirstName() << " " <<
        // input.getLastName() << endl; cout << "ID: \t\t" << input.getId() <<
        // endl; call drop student function on that student
        cout << "Calling dropStudent(" << input << ")\n";
      }
      // quit
      else if (tolower(input[0]) == 'q') {
        cout << "Goodbye\n";
        isOpen = false;  // MUST REPLACE WITH MEMBER FUNCTION FOR COURSE
        break;
      }
    }
    // ASSIGNMENTS HANDLER
    else if (tolower(input[0]) == 'a') {
      cout << "List all the assignments in this course\n";
      cout << "Assignment1 number Assignment1 name Assignment1 type "
              "Assignment1 weight Assignment1 average\n";
      cout << "Assignment2 number Assignment2 name Assignment2 type "
              "Assignment2 weight Assignment2 average\n";
      cout << "Assignment3 number Assignment3 name Assignment3 type "
              "Assignment3 weight Assignment3 average\n";
      cout << "Assignment4 number Assignment4 name Assignment4 type "
              "Assignment4 weight Assignment4 average\n";
      cout << "Assignment5 number Assignment5 name Assignment5 type "
              "Assignment5 weight Assignment5 average\n";
      cout.width(6);
      cout << "\tADD Assignment " << right << "[A]\nREMOVE Assignment" << right
           << " [R]\n MODIFY Assignment" << right << "[M]: ";
      cin >> input;
      // add assignment
      if (tolower(input[0]) == 'a') {
        cout << "Adding a new assignment: \n";
        cout << "Assignment Name?: ";
        cin >> input;
        string aName = input;
        cout << "Assignment type? Quiz/Lab/Extra Credit [Q/L/E]: ";
        cin >> input;
        string aType = input;
        if (tolower(input[0]) == 'q') {
          cout << "assignment.type = Quiz;\n";
        } else if (tolower(input[0]) == 'l') {
          cout << "assignment.type = Lab;\n";
        } else if (tolower(input[0]) == 'e') {
          cout << "assignment.type = Extra;\n";
        } else {
          cout << "Invalid entry: " << input << endl;
          continue;
        }
        cout << "Assignment weight?: ";
        cin >> input;
        string aWeight = input;
        cout << "Calling assignmentCreate(" << aName << "," << aType << ","
             << aWeight << ");\n";
      }
      // remove assignment
      else if (tolower(input[0]) == 'r') {
        cout << "Remove which assignment? [number]: ";
        cin >> input;
        cout << "Calling assignmentRemove(" << input
             << ")\n";  // to replace with member function
        break;
      }
      // modify assignment
      else if (tolower(input[0]) == 'm') {
        cout << "Modify which assignment? [number]: ";
        cin >> input;
        cout << "Calling assignmentChange(" << input << ")\n";
        break;
      }
      // quit
      else if (tolower(input[0]) == 'q') {
        cout << "Goodbye\n";
        !isOpen;  // MUST REPLACE WITH MEMBER FUNCTION FOR COURSE
        break;
      }

      // invalid
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
  }  // while course is open
}