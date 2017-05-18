#include "Course.h"
#include "Assignment.h"
#include "Category.h"
#include "Database.h"
#include "Student.h"
#include "Submitted.h"

#include <iostream>
#include <string>

using namespace std;

// parametized construction - c++11 shortcut
Course::Course() {}

// Course constructor loads the course by that name
Course::Course(string name) { load(name); }

// load function calls db load
void Course::load(string name) {
  this->name = name;
  db.load(name.append(".sqlite"));

  // calls the other class create functions
  Assignment::create(db);
  Category::create(db);
  Student::create(db);
  Submitted::create(db);

  // calls each class' read function pointing to the database
  // loads the members into memory
  assignments = Assignment::read(db);
  categories = Category::read(db);
  students = Student::read(db);
  submitted = Submitted::read(db);
}

// name getter - principle of least privelige
string Course::getName() const { return name; }

// Returns the Database
Database &Course::getDb() { return db; }

// utility function to create a new assignment in the course
void Course::addAssignment(int categoryId, string name, int pointsPossible) {
  Assignment *assignment =
      new Assignment(0, categoryId, name, pointsPossible, db);
  assignment->insert();
  int id = assignment->getId();
  assignments[id] = assignment;
}

// utility function to update existing assignment in the course
void Course::updateAssignment(int id, int categoryId, string name,
                              int pointsPossible) {
  if (categoryId != -1)
    assignments[id]->setCategoryId(categoryId);
  if (name.size() != 0)
    assignments[id]->setName(name);
  if (pointsPossible != -1)
    assignments[id]->setPointsPossible(pointsPossible);
  assignments[id]->update();
}

// utility function to delete assignment in the course
void Course::deleteAssignment(int id) {
  assignments[id]->remove();
  assignments.erase(id);
}

// utility function to print all the assignments
void Course::printAssignment(int id) { cout << assignments[id] << "\n"; }

void Course::printAssignments() {
  for (auto const &item : assignments) {
    cout << *item.second << "\n";
  }
}

// utility function creates a new category for assignments
void Course::addCategory(string name, int weight) {
  Category *category = new Category(0, name, weight, db);
  category->insert();
  int id = category->getId();
  categories[id] = category;
}

// utility function to update an existing category of assignments
void Course::updateCategory(int id, string name, int weight) {
  if (name.size() != 0)
    categories[id]->setName(name);
  if (weight != -1)
    categories[id]->setWeight(weight);
  categories[id]->update();
}

// utility function to delete a category of assignments
void Course::deleteCategory(int id) {
  categories[id]->remove();
  categories.erase(id);
}

// utility function prints one assignment category
void Course::printCategory(int id) { cout << categories[id] << "\n"; }

// utility function to print all the assignment categories
void Course::printCategories() {
  for (auto const &item : categories) {
    cout << *item.second << "\n";
  }
}

// utility function to add a new sutdent to the course
void Course::addStudent(string id, string firstName, string lastName) {
  Student *student = new Student(id, firstName, lastName, db);
  students[id] = student;
  student->insert();
}

// update the information of a specific student
void Course::updateStudent(string id, string firstName, string lastName) {
  if (firstName.size() != 0)
    students[id]->setFirstName(firstName);
  if (lastName.size() != 0)
    students[id]->setLastName(lastName);
  students[id]->update();
}

// delete an existing student
void Course::deleteStudent(string id) {
  students[id]->remove();
  students.erase(id);
}

// print all the information for a student
void Course::printStudent(string id) { cout << students[id] << "\n"; }

// print all the information for all students
void Course::printStudents() {
  for (auto const &item : students) {
    cout << *item.second << "\n";
  }
}

// create a new assignment to be assigned to students
void Course::addSubmitted(int assignmentId, string studentId,
                          double pointsEarned) {
  Submitted *submitted =
      new Submitted(0, assignmentId, studentId, pointsEarned, db);
  submitted->insert();
  int id = submitted->getId();
  this->submitted[id] = submitted;
}

// update an existing assignment
void Course::updateSubmitted(int id, int assignmentId, string studentId,
                             double pointsEarned) {
  if (assignmentId != -1)
    submitted[id]->setAssignmentId(assignmentId);
  if (studentId.size() != 0)
    submitted[id]->setStudentId(studentId);
  if (pointsEarned != -1)
    submitted[id]->setPointsEarned(pointsEarned);
  submitted[id]->update();
}

// deletes an existing assignment
void Course::deleteSubmitted(int id) {
  submitted[id]->remove();
  submitted.erase(id);
}

// prints a specific assigned assignment
void Course::printSubmitted(int id) { cout << submitted[id] << "\n"; }

// print all assigned assignments
void Course::printSubmitted() {
  for (auto const &item : submitted) {
    cout << *item.second << "\n";
  }
}

void Course::printSubmittedOfStudent(string id) {
  int totalPointsEarned = 0;
  int totalPointsPossible = 0;
  for (auto const &item : submitted) {
    if (item.second->getStudentId() == id) {
      cout << *item.second << "\n";
      totalPointsEarned += item.second->getPointsEarned();
      int assignmentId = item.second->getAssignmentId();
      totalPointsPossible += assignments[assignmentId]->getPointsPossible();
    }
  }
  double grade = (totalPointsEarned / totalPointsPossible) * 100;
  cout << "Points earned: " << totalPointsEarned << "\n";
  cout << "Points possible: " << totalPointsPossible << "\n";
  cout << "Grade: " << grade << "%\n";
}

void Course::printSubmittedOfAssignment(int id) {
  int totalPointsEarned = 0;
  int pointsPossible = assignments[id]->getPointsPossible();
  int totalPointsPossible = 0;
  for (auto const &item : submitted) {
    if (item.second->getAssignmentId() == id) {
      cout << *item.second << "\n";
      totalPointsEarned += item.second->getPointsEarned();
      totalPointsPossible += pointsPossible;
    }
  }
  double grade = (totalPointsEarned / totalPointsPossible) * 100;
  cout << "Average grade: " << grade << "%\n";
}
