#include "Assignment.h"
#include "Course.h"

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  if (remove("test-0.sqlite") != 0) {
    cout << "Error with deletion of database file\n";
  } else {
    cout << "Database file successfully deleted\n";
  }

  // test instantiation of a Course object.
  cout << "Testing instantiation of a Course object:" << endl;
  Course course("test-0");
  cout << "Created " << course.getName() << "\n\n";

  // Test students
  course.addStudent("1", "Thomas", "Munduchira");
  course.addStudent("2", "Jesse", "Smick");
  course.addStudent("3", "Joe", "Saraceno");
  course.printStudents();
  cout << "\n";
  course.updateStudent("1", "Rahul", "Sharma");
  course.deleteStudent("2");
  course.printStudents();
  cout << "\n";

  // Test categories
  course.addCategory("Homework", 20);
  course.addCategory("Labs", 30);
  course.addCategory("Exams", 50);
  course.printCategories();
  cout << "\n";
  course.updateCategory(1, "HW", 45);
  course.deleteCategory(2);
  course.printCategories();
  cout << "\n";

  // Test assignments
  course.addAssignment(1, "Homework 1", 25);
  course.addAssignment(1, "Homework 2", 30);
  course.addAssignment(2, "Lab 1", 15);
  course.addAssignment(2, "Lab 2", 10);
  course.addAssignment(3, "Exam 1", 100);
  course.addAssignment(3, "Exam 2", 150);
  course.printAssignments();
  cout << "\n";
  course.updateAssignment(3, 2, "Lab 1", 30); // here's the problem
  course.printAssignments();
  course.deleteAssignment(2);
  course.printAssignments();
  cout << "\n";

  // Test submitted
  course.addSubmitted(1, "1", 25);
  course.addSubmitted(3, "2", 10);
  course.addSubmitted(5, "3", 125);
  course.printSubmitted();
  cout << "\n";
  course.updateSubmitted(1, 2, "2", 30);
  course.deleteSubmitted(2);
  course.printSubmitted();
}

