#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include "Database.h"
#include "DatabaseItem.h"

#include <map>
#include <string>

using namespace std;

class Assignment : public DatabaseItem {
  friend ostream &operator<<(ostream &, const Assignment &);

public:
  Assignment(int, int, string, double, Database &);

  // Getters
  int getId() const;
  int getCategoryId() const;
  string getName() const;
  double getPointsPossible() const;

  // Setters
  // NOTE: `id` cannot change externally
  void setCategoryId(int);
  void setName(string);
  void setPointsPossible(double);

  // Database query commands
  virtual void insert();
  virtual void update() const;
  virtual void remove() const;

  // Static database query commands
  static void create(Database &);
  static map<int, Assignment *> read(Database &);

private:
  int id;
  int categoryId;
  string name;
  double pointsPossible;
};

#endif // ASSIGNMENT_H
