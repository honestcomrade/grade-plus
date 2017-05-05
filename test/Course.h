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

  void addAssignment(int, string, int);
  void updateAssignment(int, int, string, int);
  void deleteAssignment(int);
  void printAssignments();

  void addCategory(string, int);
  void updateCategory(int, string, int);
  void deleteCategory(int);
  void printCategories();

  void addStudent(string, string, string);
  void updateStudent(string, string, string);
  void deleteStudent(string);
  void printStudents();

  void addSubmitted(int, string, double);
  void updateSubmitted(int, int, string, double);
  void deleteSubmitted(int);
  void printSubmitted();

private:
  string name;
  Database db;

  map<int, Assignment *> assignments;
  map<int, Category *> categories;
  map<string, Student *> students;
  map<int, Submitted *> submitted;
};

#endif // COURSE_H
