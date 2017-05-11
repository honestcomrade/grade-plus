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
  cout << "Created " << course.getName() << endl;

  // Test students
  course.addStudent("1", "Thomas", "Munduchira");
  course.addStudent("2", "Jesse", "Smick");
  course.addStudent("3", "Joe", "Saraceno");
  course.printStudents();

  // Test categories
  course.addCategory("Homework", 20);
  course.addCategory("Labs", 30);
  course.addCategory("Exams", 50);
  course.printCategories();

  // Test assignments
  course.addAssignment(1, "Homework 1", 25);
  course.addAssignment(1, "Homework 2", 30);
  course.addAssignment(2, "Lab 1", 15);
  course.addAssignment(2, "Lab 2", 10);
  course.addAssignment(3, "Exam 1", 100);
  course.addAssignment(3, "Exam 2", 150);
  course.printAssignments();

  // Test submitted
  course.addSubmitted(1, "1", 25);
  course.addSubmitted(3, "2", 10);
  course.addSubmitted(5, "3", 125);
  course.printSubmitted();
}
