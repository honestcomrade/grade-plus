#ifndef STUDENT_H
#define STUDENT_H

#include "Database.h"

#include <map>
#include <string>

using namespace std;

class Student {
public:
  Student(string, string, string, Database &);

  // Getters
  string getId() const;
  string getFirstName() const;
  string getLastName() const;

  // Setters
  void setId(string);
  void setFirstName(string);
  void setLastName(string);

  // Database query commands
  void insert();
  void update() const;
  void remove() const;

  // Static database query commands
  static void create(Database &);
  static map<string, Student *> read(Database &);

private:
  string id;
  string firstName;
  string lastName;

  Database &db;
};

#endif // STUDENT_H
