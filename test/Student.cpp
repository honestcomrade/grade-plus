#include "Student.h"
#include <sqlite3.h>

#include <string>

using namespace std;

Student::Student(string id, string firstName, string lastName)
    : id(id), firstName(firstName), lastName(lastName) {
  sqlite3_open("test-1.sqlite", &db);
}

Student::~Student() { sqlite3_close(db); }

string Student::getId() {
  string copy(id);
  return copy;
}

string Student::getFirstName() {
  string copy(firstName);
  return copy;
}

string Student::getLastName() {
  string copy(lastName);
  return copy;
}
