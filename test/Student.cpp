#include "Student.h"
#include "Database.h"

#include <sstream>
#include <string>

using namespace std;

Student::Student(string id, string firstName, string lastName, Database db)
    : id(id), firstName(firstName), lastName(lastName), db(db) {}

// Getters
string Student::getId() const { return id; }

string Student::getFirstName() const { return firstName; }

string Student::getLastName() const { return lastName; }

// Setters
void Student::setId(string a_id) { id = a_id; }

void Student::setFirstName(string a_firstName) { firstName = a_firstName; }

void Student::setLastName(string a_lastName) { firstName = a_firstName; }

// Database query commands
void Student::insert() {
  stringstream command;
  command << "INSERT INTO students VALUES (";
  command << "'" << getId() << "', ";
  command << "'" << getFirstName() << "', ";
  command << "'" << getLastName() << "'";
  command << ");";

  db.execute(command.str());
}

void Student::update() {
  stringstream command;
  command << "UPDATE students SET ";
  command << "firstName = '" << getFirstName() << "', ";
  command << "lastName = '" << getLastName() << "' ";
  command << "WHERE id = '" << getId() << "'";
  command << ";";

  db.execute(command.str());
}

void Student::remove() {
  stringstream command;
  command << "DELETE from students WHERE id = ";
  command << "'" << getId() << "'";
  command << ";";

  db.execute(command.str());
}
