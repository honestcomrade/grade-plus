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

int main() {
  // main prompt
  bool isOpen = false; // MUST REPLACE WITH MEMBER FUNCTION FOR COURSE
  Course course;

  string input;
  // string openCourse;
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
      cout << "Which Course: ";
      cin >> input;
      string name = input;
      cout << "Opening Course: " << name << "...\n";
      course.load(name);
      isOpen = true;
      break;
    }

    // create Course
    else if (tolower(input[0]) == 'c') {
      cout << "Please enter a unique name\n";
      cout << "Course Name: ";
      cin >> input;
      string name = input;
      cout << "Creating Course: " << name << endl;
      course.load(name);
      isOpen = true;
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
  while (isOpen) {
    // cout << "LIST ALL THE COURSE DETAILS:\n";
    cout << "Course Name: \t" << course.getName() << "\n\n";
    cout << "\tAdd/Remove/Modify STUDENTS [S]\n\tAdd/Remove/Modify ASSIGNMENTS "
            "[A]\n\tAdd/Remove/Modify CATEGORIES [C]\n\tAdd/Remove/Modify "
            "SUBMITTED [U]\n $: ";
    cin >> input;
    // students handler
    if (tolower(input[0]) == 's' || tolower(input[0]) == 'S' ) {
      course.printStudents();
      cout << "\tAdd STUDENT     [A]\n\tRemove STUDENT [R]\n";
      cout << " $: ";
      cin >> input;
      // add student
      if (tolower(input[0]) == 'a') {
        cout << "Student ID?: ";
        cin >> input;
        string id = input;
        cout << "Student First Name?: ";
        cin >> input;
        string firstName = input;
        cout << "Student Last Name?: ";
        cin >> input;
        string lastName = input;
        cout << "Student Name: " << firstName << " " << lastName
             << " Student ID: " << id << endl;
        course.addStudent(id, firstName, lastName);
      }
      // modify student
      else if (tolower(input[0]) == 'a') {
        cout << "Student ID: ";
        cin >> input;
        cin.ignore();
        string id = input;
        cout << "Student First Name (or press enter to keep current one): ";
        getline(cin, input);
        string firstName = input;
        cout << "Student Last Name (or press enter to keep current one): ";
        getline(cin, input);
        string lastName = input;
        cout << "Student Name: " << firstName << " " << lastName
             << " Student ID: " << id << endl;
        course.updateStudent(id, firstName, lastName);
      }
      // drop student
      else if (tolower(input[0]) == 'r') {
        cout << "Remove student with ID: ";
        cin >> input;
        string id = input;

        // call drop student function on that student
        course.deleteStudent(id);
      }
      // quit
      else if (tolower(input[0]) == 'q') {
        cout << "Goodbye\n";
        isOpen = false; // MUST REPLACE WITH MEMBER FUNCTION FOR COURSE
        break;
      }
      // print students after all student related activities have been done
      cout << "Here's the current list roster for " << course.getName() << ":\n";
      course.printStudents();
    }
    // ASSIGNMENTS HANDLER
    else if (tolower(input[0]) == 'a') {
      cout << "Here's a current list of all the assignments in " << course.getName() << ":\n";
      cout << "\t"; course.printAssignments(); cout << endl;
      cout.width(6);
      cout << "\tADD Assignment " << right << "[A]\n\tREMOVE Assignment" << right
           << " [R]\n\tMODIFY Assignment" << right << "[M]:\n $: ";
      cin >> input;
      cin.ignore();
      // add assignment
      if (tolower(input[0]) == 'a') {
        cout << "Adding a new assignment:\n";
        cout << "Assignment Name: ";
        getline(cin, input);
        string name = input;
        course.printCategories();
        cout << "Category ID: ";
        getline(cin, input);
        int category = stoi(input);
        cout << "Points possible: ";
        getline(cin, input);
        int weight = stoi(input);
        course.addAssignment(category, name, weight);
      }
      // modify assignment
      else if (tolower(input[0]) == 'm') {
        cout << "Modify assignment with ID: ";
        cin >> input;
        cin.ignore();
        int id = stoi(input);
        cout << "Assignment Name (or press enter to keep current one): ";
        getline(cin, input);
        string name = input;
        course.printCategories();
        cout << "Category ID (or press enter to keep current one): ";
        getline(cin, input);
        int category = atoi(input.c_str());
        cout << "Points possible (or press enter to keep current one): ";
        getline(cin, input);
        int weight = atoi(input.c_str());
        course.updateAssignment(id, category, name, weight);
      }
      // remove assignment
      else if (tolower(input[0]) == 'r') {
        cout << "Remove assignment with ID: ";
        cin >> input;
        int id = stoi(input);
        // cout << "Calling course.deleteAssignment(" << id << ")\n";
        course.deleteAssignment(id);
      }
      // quit
      else if (tolower(input[0]) == 'q') {
        cout << "Goodbye\n";
        !isOpen; // MUST REPLACE WITH MEMBER FUNCTION FOR COURSE
        break;
      }

      // invalid
      else {
        cout << "Invalid entry: " << input << endl;
        continue;
      }
      cout << "Here's a current list of all the assignments in " << course.getName() << ":\n";
      course.printAssignments();
    }

    // CATEGORIES HANDLER
    else if (tolower(input[0]) == 'c') {
      course.printCategories();
      cout.width(6);
      cout << "\tADD Category " << right << "[A]\nREMOVE Category" << right
           << " [R]\n MODIFY Category" << right << "[M]:\n $: ";
      cin >> input;
      // add category
      if (tolower(input[0]) == 'a') {
        cout << "Adding a new category:\n";
        cout << "Category Name: ";
        cin >> input;
        string name = input;
        cout << "Weight: ";
        cin >> input;
        int weight = stoi(input);
        course.addCategory(name, weight);
      }
      // modify category
      else if (tolower(input[0]) == 'm') {
        cout << "Modify category with ID: ";
        cin >> input;
        cin.ignore();
        int id = stoi(input);
        cout << "Category Name (or press enter to keep current one): ";
        getline(cin, input);
        string name = input;
        cout << "Weight (or press enter to keep current one): ";
        getline(cin, input);
        int weight = atoi(input.c_str());
        course.updateCategory(id, name, weight);
      }
      // remove category
      else if (tolower(input[0]) == 'r') {
        cout << "Remove category with ID: ";
        cin >> input;
        int id = stoi(input);
        course.deleteCategory(id);
      }
      // quit
      else if (tolower(input[0]) == 'q') {
        cout << "Goodbye\n";
        !isOpen; // MUST REPLACE WITH MEMBER FUNCTION FOR COURSE
        break;
      }

      // invalid
      else {
        cout << "Invalid entry: " << input << endl;
        continue;
      }
    }

    // SUBMITTED HANDLER
    else if (tolower(input[0]) == 'u') {
      course.printSubmitted();
      cout.width(6);
      cout << "\tADD Submitted " << right << "[A]\nREMOVE Submitted" << right
           << " [R]\nMODIFY Submitted" << right << "[M]:\n $: ";
      cin >> input;
      // add submitted
      if (tolower(input[0]) == 'a') {
        cout << "Adding a new submitted:\n";
        cout << "Assignment ID: ";
        getline(cin, input);
        int assignmentId = stoi(input); // stoi not working with addSubmitted
        cout << "Student ID: ";
        getline(cin, input);
        string studentId = input;
        cout << "Points earned: ";
        getline(cin, input);
        double pointsEarned = stod(input);
        course.addSubmitted(assignmentId, studentId, pointsEarned);
      }
      // modify submitted
      else if (tolower(input[0]) == 'm') {
        cout << "Modify submitted with ID: ";
        cin >> input;
        cin.ignore();
        int id = stoi(input);
        cout << "Assignment ID (or press enter to keep current one): ";
        getline(cin, input);
        int assignmentId = stoi(input);
        cout << "Student ID (or press enter to keep current one): ";
        getline(cin, input);
        string studentId = input;
        cout << "Points earned (or press enter to keep current one): ";
        getline(cin, input);
        double pointsEarned = stod(input);
        course.updateSubmitted(id, assignmentId, studentId, pointsEarned);
      }
      // remove submitted
      else if (tolower(input[0]) == 'r') {
        cout << "Remove submitted with ID: ";
        cin >> input;
        int id = stoi(input);
        course.deleteSubmitted(id);
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
