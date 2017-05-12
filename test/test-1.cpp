#include "Assignment.h"
#include "Category.h"
#include "Course.h"
#include "Database.h"
#include "Student.h"
#include "Submitted.h"

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int convertToInt(string);

int main() {
  // main prompt
  bool isOpen = true; // MUST REPLACE WITH MEMBER FUNCTION FOR COURSE
  Course course;

  string input;
  string openCourse;
  cout << "Welcome to grade-plus\n";
  cout << "What would you like to do?\n";
  cout << "WORK on an existing Course ";
  cout.width(6);
  cout << right << "[W]\nCREATE a new Course " << right << " [C]\n $: ";
  // input loop
  while (true) {
    cin >> input;

    // open Course
    if (tolower(input[0]) == 'w') {
      cout << "Which Course?: ";
      cin >> input;
      cout << "Opening Course: " << input << "...\n";
      course.load(input);
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
      course.load(cName);
      break;
    }

    // quit
    else if (tolower(input[0]) == 'q') {
      cout << "Goodbye\n";
      isOpen = false;
      break;
    }

    // invalid
    else {
      cout << "Invalid entry: " << input << endl;
      cout << "What would you like to do?\n";
      continue;
    }
  } // opening loop

  // second loop while the course is open
  while (/*openCourse*/ isOpen) {
    cout << "LIST ALL THE COURSE DETAILS:\n";
    cout << "Name: \t" << openCourse << "\n\n";
    cout << "\tAdd/Remove STUDENTS [S]\n\tAdd/Remove/Modify ASSIGNMENTS\n $: ";
    cin >> input;
    // students handler
    if (tolower(input[0]) == 's') {
      course.printStudents();
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
        course.addStudent(stuID, stuFirst, stuLast);
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
        course.deleteStudent(input);
      }
      // quit
      else if (tolower(input[0]) == 'q') {
        cout << "Goodbye\n";
        isOpen = false; // MUST REPLACE WITH MEMBER FUNCTION FOR COURSE
        break;
      }
    }
    // ASSIGNMENTS HANDLER
    else if (tolower(input[0]) == 'a') {
      course.printAssignments();
      cout.width(6);
      cout << "\tADD Assignment " << right << "[A]\nREMOVE Assignment" << right
           << " [R]\n MODIFY Assignment" << right << "[M]:\n $: ";
      cin >> input;
      // add assignment
      if (tolower(input[0]) == 'a') {
        cout << "Adding a new assignment:\n";
        cout << "Assignment Name? ";
        cin >> input;
        string name = input;
        course.printCategories();
        cout << "Category ID? ";
        cin >> input;
        int category = stoi(input);
        cout << "Points possible? ";
        cin >> input;
        int weight = stoi(input);
        cout << "Calling course.addAssignment(" << category << "," << name << ","
             << weight << ");\n";
        course.addAssignment(category, name, weight);
      }
      // modify assignment
      else if (tolower(input[0]) == 'm') {
        cout << "Modify assignment with ID: ";
        cin >> input;
        int id = stoi(input);
        cout << "Assignment Name? (or press enter to keep current one)";
        getline(cin, input);
        string name = input;
        course.printCategories();
        cout << "Category ID? (or press enter to keep current one)";
        getline(cin, input);
        int category = convertToInt(input);
        cout << "Points possible? (or press enter to keep current one)";
        getline(cin, input);
        int weight = convertToInt(input);
        cout << "Calling course.addAssignment(" << category << "," << name << ","
        << weight << ");\n";
        course.updateAssignment(id, category, name, weight);
      }
      // remove assignment
      else if (tolower(input[0]) == 'r') {
        cout << "Remove assignment with ID: ";
        cin >> input;
        int id = stoi(input);
        cout << "Calling course.deleteAssignment(" << id << ")\n";
        course.deleteAssignment(id);
      }
      // quit
      else if (tolower(input[0]) == 'q') {
        cout << "Goodbye\n";
        !isOpen; // MUST REPLACE WITH MEMBER FUNCTION FOR COURSE
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
  } // while course is open
}

int convertToInt(string input) {
  if (input.size() == 0) {
    return -1;
  }
  return stoi(input);
}
