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
  Course();
  Course(string);
    
  void load(string);

  string getName() const;
  Database &getDb();

  map<int, Assignment *> assignments;
  map<int, Category *> categories;
  map<string, Student *> students;
  map<int, Submitted *> submitted;

private:
  string name;

  Database db;
};

#endif // COURSE_H
