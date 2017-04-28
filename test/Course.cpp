#include "Course.h"
#include "Assignment.h"
#include "Category.h"
#include "Database.h"
#include "Student.h"
#include "Submitted.h"

#include <string>

Course::Course(string name) : name(name), db(Database(name.append(".sqlite"))) {
  Assignment::create(db);
  Category::create(db);
  Student::create(db);
  Submitted::create(db);

  assignments = Assignment::read(db);
  catagories = Category::read(db);
  students = Student::read(db);
  submitted = Submitted::read(db);
}
