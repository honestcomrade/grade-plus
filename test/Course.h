#ifndef COURSE_H
#define COURSE_H

#include "Assignment.h"
#include "Category.h"
#include "Database.h"
#include "Student.h"
#include "Submitted.h"

#include <string>

using namespace std;

class Course {
public:
  Course(string);

  string getName() const;

  map<int, Assignment *> assignments;
  map<int, Category *> catagories;
  map<string, Student *> students;
  map<int, Submitted *> submitted;

private:
  string name;

  Database db;
};

#endif // COURSE_H
