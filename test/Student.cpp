#include "Student.h"
#include "Database.h"

#include <string>
#include <sstream>

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

void Student::update() {
    stringstream command;
    command << "UPDATE students SET ";
    command << "id = '" << getId() << "', ";
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

void Student::insert() {
    stringstream command;
    command << "INSERT into students VALUES (";
    command << "'" << getId() << "', ";
    command << "'" << getFirstName() << "', ";
    command << "'" << getLastName() << "'";
    command << ");";
    
    db.execute(command.str());
}
