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

  cout << "All Assignments:" << endl;

  for (auto it : course.assignments) {
    cout << it.first << "=>" << it.second << '\n';
  }
}
