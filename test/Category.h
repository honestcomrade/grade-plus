// Category is the table of all assignments that are assigned
// - no student pair yet
#ifndef Category_H
#define Category_H

#include "Database.h"

#include <sstream>
#include <string>
#include <map>

using namespace std;

class Category {
public:
  Category(int, string, int, Database);
  ~Category();

  int getId() const;
  int getWeight() const;
  string getName() const;

  void setId(int);
  void setName(string);
  void setWeight(int);

  // database query commands
  void save();
  void insert();
  void update();
  void remove();

  map <int, Category> read(Database&) const;

private:
  int id;
  string name;
  int weight;
  Database db;
};

#endif
