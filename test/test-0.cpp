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

  cout << "All Assignments: " << course.assignments.size() << endl;
  cout << "All Categories: " << course.categories.size() << endl;
  cout << "All Students: " << course.students.size() << endl;
  cout << "All Submitted: " << course.submitted.size() << endl;

  // Test adding items to the db
  Category c1(0, "Homework", 20, course.getDb());
  Category c2(0, "Labs", 30, course.getDb());
  Category c3(0, "Exams", 50, course.getDb());
  c1.insert();
  c2.insert();
  c3.insert();

  course.categories[c1.getId()] = &c1;
  course.categories[c2.getId()] = &c2;
  course.categories[c3.getId()] = &c3;

  for (auto it : course.categories) {
    cout << it.first << " " << it.second->getName() << endl;
  }
}
