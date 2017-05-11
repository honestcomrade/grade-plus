#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include "Database.h"
#include "dbItem.h"

#include <map>
#include <string>

using namespace std;

class Assignment : public dbItem {

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

  friend ostream &operator<<(ostream &, const Assignment &);

private:
  int id;
  int categoryId;
  string name;
  double pointsPossible;

  // Database &db;
};

#endif // ASSIGNMENT_H
