#include "Student.h"
#include "Database.h"

#include <string>

using namespace std;

Student::Student(string id, string firstName, string lastName, Database db)
    : id(id), firstName(firstName), lastName(lastName), db(db) {}

Student::~Student() {}

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

void Student::save() {
  string command = "save";
  db.execute(command);
}
