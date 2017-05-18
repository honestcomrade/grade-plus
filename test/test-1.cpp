#include "Course.h"

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
  cout.width(6);
  cout << "\tWORK on an existing Course [W]\n\tCREATE a new Course [C]\n\t$: ";
  // input loop
  while (true) {
    getline(cin, input);

    // open Course
    if (tolower(input[0]) == 'w') {
      cout << "Which Course: ";
      getline(cin, input);
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
      getline(cin, input);
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
    cout << "\n";
    cout << "Course Name: \t" << course.getName() << "\n";
    cout << "\tSELECT students [S]\n\tSELECT assignments "
            "[A]\n\tSELECT categories [C]\n\tSELECT submissions [U]\n\tQUIT "
            "[Q]\n\t$: ";
    getline(cin, input);
    // students handler
    if (tolower(input[0]) == 's' || tolower(input[0]) == 'S') {
      course.printStudents();
      cout << "\tADD student [A]\n\tREMOVE student [R]\n\tQUIT [Q]\n\t$: ";
      getline(cin, input);
      // add student
      if (tolower(input[0]) == 'a') {
        cout << "Student ID?: ";
        getline(cin, input);
        string id = input;
        cout << "Student first name?: ";
        getline(cin, input);
        string firstName = input;
        cout << "Student last name?: ";
        getline(cin, input);
        string lastName = input;
        cout << "Student name: " << firstName << " " << lastName
             << " Student ID: " << id << endl;
        course.addStudent(id, firstName, lastName);
      }
      // modify student
      else if (tolower(input[0]) == 'a') {
        cout << "Student ID: ";
        getline(cin, input);
        string id = input;
        cout << "Student first name (or press enter to keep current one): ";
        getline(cin, input);
        string firstName = input;
        cout << "Student last name (or press enter to keep current one): ";
        getline(cin, input);
        string lastName = input;
        cout << "Student name: " << firstName << " " << lastName
             << " Student ID: " << id << endl;
        course.updateStudent(id, firstName, lastName);
      }
      // drop student
      else if (tolower(input[0]) == 'r') {
        cout << "Remove student with ID: ";
        getline(cin, input);
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
      cout << "Here's the current list roster for " << course.getName()
           << ":\n";
      course.printStudents();
    }
    // ASSIGNMENTS HANDLER
    else if (tolower(input[0]) == 'a') {
      cout << "Here's a current list of all the assignments in "
           << course.getName() << ":\n";
      cout << "\t";
      course.printAssignments();
      cout << endl;
      cout.width(6);
      cout << "\tADD assignment [A]\n\tREMOVE assignment [R]\n\tMODIFY "
              "assignment [M]\n\tQUIT [Q]\n\t$: ";
      getline(cin, input);
      // add assignment
      if (tolower(input[0]) == 'a') {
        cout << "Adding a new assignment:\n";
        cout << "Assignment name: ";
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
        getline(cin, input);
        int id = stoi(input);
        cout << "Assignment name (or press enter to keep current one): ";
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
        getline(cin, input);
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
      cout << "Here's a current list of all the assignments in "
           << course.getName() << ":\n";
      course.printAssignments();
    }

    // CATEGORIES HANDLER
    else if (tolower(input[0]) == 'c') {
      course.printCategories();
      cout.width(6);
      cout << "\tADD category [A]\n\tREMOVE category [R]\n\tMODIFY category "
              "[M]\n\tQUIT [Q]\n\t$: ";
      getline(cin, input);
      // add category
      if (tolower(input[0]) == 'a') {
        cout << "Adding a new category:\n";
        cout << "Category name: ";
        getline(cin, input);
        string name = input;
        cout << "Weight: ";
        getline(cin, input);
        int weight = stoi(input);
        course.addCategory(name, weight);
      }
      // modify category
      else if (tolower(input[0]) == 'm') {
        cout << "Modify category with ID: ";
        getline(cin, input);
        int id = stoi(input);
        cout << "Category name (or press enter to keep current one): ";
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
        getline(cin, input);
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
      do {
        cout << "\tFILTER by student [S]\n\tFILTER by assignment [T]\n\tADD "
                "submission [A]\n\tREMOVE submission [R]\n\tMODIFY submission "
                "[M]\n\tGRADE submission [G]\n\tQUIT [Q]\n\t$: ";
        getline(cin, input);
        // filter by student
        if (tolower(input[0]) == 's') {
          cout << "Student ID: ";
          getline(cin, input);
          string studentId = input;
          course.printSubmittedOfStudent(studentId);
        }
        // filter by assignment
        else if (tolower(input[0]) == 't') {
          cout << "Assignment ID: ";
          getline(cin, input);
          int assignmentId = stoi(input);
          course.printSubmittedOfAssignment(assignmentId);
        }
      } while (tolower(input[0]) == 's' || tolower(input[0]) == 't');
      // add submitted
      if (tolower(input[0]) == 'a') {
        cout << "Adding a new submission:\n";
        cout << "Assignment ID: ";
        getline(cin, input);
        int assignmentId = stoi(input); // stoi not working with addSubmitted
        cout << "Student ID: ";
        getline(cin, input);
        string studentId = input;
        course.addSubmitted(assignmentId, studentId, NULL);
      }
      // modify submitted
      else if (tolower(input[0]) == 'm') {
        cout << "Modify submission with ID: ";
        getline(cin, input);
        int id = stoi(input);
        cout << "Assignment ID (or press enter to keep current one): ";
        getline(cin, input);
        int assignmentId = stoi(input);
        cout << "Student ID (or press enter to keep current one): ";
        getline(cin, input);
        string studentId = input;
        course.updateSubmitted(id, assignmentId, studentId, NULL);
      }
      // remove submitted
      else if (tolower(input[0]) == 'r') {
        cout << "Remove submission with ID: ";
        getline(cin, input);
        int id = stoi(input);
        course.deleteSubmitted(id);
      }
      // grade submitted
      else if (tolower(input[0]) == 'g') {
        cout << "Grade submission with ID: ";
        getline(cin, input);
        int id = stoi(input);
        cout << "Points earned: ";
        getline(cin, input);
        double pointsEarned = stod(input);
        course.updateSubmitted(id, -1, "", pointsEarned);
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
