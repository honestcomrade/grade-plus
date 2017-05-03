#include "Submitted.h"
#include "Database.h"

#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

Submitted::Submitted(int id, int assignmentId, string studentId,
                     double pointsEarned, Database &db)
    : id(id),
      assignmentId(assignmentId),
      studentId(studentId),
      pointsEarned(pointsEarned),
      db(db) {}

// Getters
int Submitted::getId() const { return id; }

int Submitted::getAssignmentId() const { return assignmentId; }

string Submitted::getStudentId() const { return studentId; }

double Submitted::getPointsEarned() const { return pointsEarned; }

// Setters
void Submitted::setAssignmentId(int a_assignmentId) {
  assignmentId = a_assignmentId;
}

void Submitted::setStudentId(string a_studentId) { studentId = a_studentId; }

void Submitted::setPointsEarned(double a_pointsEarned) {
  pointsEarned = a_pointsEarned;
}

// Database query commands
void Submitted::insert() {
  stringstream command;
  command << "INSERT INTO submittedAssignments ";
  command << "(assignmentId, studentId, pointsEarned) ";
  command << "VALUES (";
  command << getAssignmentId() << ", ";
  command << "'" << getStudentId() << "', ";
  command << getPointsEarned();
  command << ");";

  db.execute(command.str());
}

void Submitted::update() const {
  stringstream command;
  command << "UPDATE submittedAssignments SET ";
  command << "assignmentId = " << getAssignmentId() << ", ";
  command << "studentId = '" << getStudentId() << "', ";
  command << "pointsEarned = " << getPointsEarned() << " ";
  command << "WHERE id = " << getId();
  command << ";";

  db.execute(command.str());
}

void Submitted::remove() const {
  stringstream command;
  command << "DELETE FROM submittedAssignments WHERE ";
  command << "id = " << getId();
  command << ";";

  db.execute(command.str());
}

// Static database query commands
void Submitted::create(Database &db) {
  string command =
      "CREATE TABLE IF NOT EXISTS submittedAssignments (\n"
      "    id           INTEGER     PRIMARY KEY,\n"
      "    assignmentId INTEGER (2) NOT NULL,\n"
      "    studentId    TEXT (16)   NOT NULL,\n"
      "    pointsEarned NUMERIC (4) NOT NULL\n"
      ");";

  db.execute(command);
}

map<int, Submitted *> Submitted::read(Database &db) {
  map<int, Submitted *> data;
  vector<vector<string>> results;

  results = db.execute("SELECT * FROM submittedAssignments;");

  for (vector<string> row : results) {
    int id = stoi(row[0]);

    data[id] = new Submitted(id, stoi(row[1]), row[2], stod(row[3]), db);
  }

  return data;
}
