#include "Course.h"

#include <iostream>

using namespace std;

int main() {
  // test instantiation of a Course object.
  cout << "Testing instantiation of a Course object:" << endl;
  Course db("test-0");

  cout << "All Assignments:" << endl;

  for (auto it : db.assignments) {
    cout << it.first << "=>" << it.second << '\n';
  }
}
