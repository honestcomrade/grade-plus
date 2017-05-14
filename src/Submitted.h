#ifndef SUBMITTED_H
#define SUBMITTED_H

#include "Database.h"
#include "DatabaseItem.h"

#include <map>
#include <string>

using namespace std;

class Submitted : public DatabaseItem {
  friend ostream &operator<<(ostream &, const Submitted &);

public:
  Submitted(int, int, string, double, Database &);

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

  // Database query commands
  virtual void insert();
  virtual void update() const;
  virtual void remove() const;

  // Static database query commands
  static void create(Database &);
  static map<int, Submitted *> read(Database &);

private:
  int id;
  int assignmentId;
  string studentId;
  double pointsEarned;
};

#endif // SUBMITTED_H
