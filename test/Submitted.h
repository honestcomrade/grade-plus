#ifndef SUBMITTED_H
#define SUBMITTED_H

#include "Database.h"

#include <map>
#include <string>

using namespace std;

class Submitted {
public:
  // Constructor
  Submitted(int, int, string, double, Database db);

  // Getters
  int getId() const;
  int getAssignmentId() const;
  string getStudentId() const;
  double getPointsEarned() const;

  // Setters
  // NOTE: `id` cannot change externally
  void setAssignmentId(int);
  void setStudentId(string);
  void setPointsEarned(double);

  // Database functions
  void update() const;
  void remove() const;
  void insert() const;

  // Static functions
  static void create(Database);
  static map<int, Submitted *> read(Database);

private:
  int id;
  int assignmentId;
  string studentId;
  double pointsEarned;

  Database db;
};

#endif // SUBMITTED_H
