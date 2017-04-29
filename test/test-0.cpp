#include "Course.h"

#include <iostream>

using namespace std;

int main() {
  // test instantiation of a Course object.
  cout << "Testing instantiation of a Course object:" << endl;
  Course course("test-0");
  cout << "Created " << course.getName() << endl;

  cout << "All Assignments:" << endl;

  for (auto it : course.assignments) {
    cout << it.first << "=>" << it.second << '\n';
  }
}
