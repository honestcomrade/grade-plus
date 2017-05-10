#include "Course.h"
#include "Assignment.h"
#include "Category.h"
#include "Database.h"
#include "Student.h"
#include "Submitted.h"

#include <string>

Course::Course() {}

Course::Course(string name) { load(name); }

void Course::load(string name) {
  this->name = name;
  db.load(name.append(".sqlite"));

  Assignment::create(db);
  Category::create(db);
  Student::create(db);
  Submitted::create(db);

  assignments = Assignment::read(db);
  categories = Category::read(db);
  students = Student::read(db);
  submitted = Submitted::read(db);
}

string Course::getName() const { return name; }

Database &Course::getDb() { return db; }

void Course::addAssignment(int categoryId, string name, int pointsPossible) {
  Assignment assignment(0, categoryId, name, pointsPossible, db);
  assignment.insert();
  int id = assignment.getId();
  assignments[id] = &assignment;
}

void Course::updateAssignment(int id, int categoryId, string name,
                              int pointsPossible) {
  assignments[id]->setCategoryId(categoryId);
  assignments[id]->setName(name);
  assignments[id]->setPointsPossible(pointsPossible);
  assignments[id]->update();
}

void Course::deleteAssignment(int id) {
  assignments[id]->remove();
  assignments.erase(id);
}

void Course::printAssignments() {}

void Course::addCategory(string name, int weight) {
  Category category(0, name, weight, db);
  category.insert();
  int id = category.getId();
  categories[id] = &category;
}

void Course::updateCategory(int id, string name, int weight) {
  categories[id]->setName(name);
  categories[id]->setWeight(weight);
  categories[id]->update();
}

void Course::deleteCategory(int id) {
  categories[id]->remove();
  categories.erase(id);
}

void Course::printCategories() {}

void Course::addStudent(string id, string firstName, string lastName) {
  Student student(id, firstName, lastName, db);
  student.insert();
  students[id] = &student;
}

void Course::updateStudent(string id, string firstName, string lastName) {
  students[id]->setFirstName(firstName);
  students[id]->setLastName(lastName);
  students[id]->update();
}

void Course::deleteStudent(string id) {
  students[id]->remove();
  students.erase(id);
}

void Course::printStudents() {}

void Course::addSubmitted(int assignmentId, string studentId,
                          double pointsEarned) {
  Submitted submitted(0, assignmentId, studentId, pointsEarned, db);
  submitted.insert();
  int id = submitted.getId();
  this->submitted[id] = &submitted;
}

void Course::updateSubmitted(int id, int assignmentId, string studentId,
                             double pointsEarned) {
  submitted[id]->setAssignmentId(assignmentId);
  submitted[id]->setStudentId(studentId);
  submitted[id]->setPointsEarned(pointsEarned);
  submitted[id]->update();
}

void Course::deleteSubmitted(int id) {
  submitted[id]->remove();
  submitted.erase(id);
}

void Course::printSubmitted() {}
