// Category is the table of all assignments that are assigned 
// - no student pair yet
#ifndef Category_H
#define Category_H

#include "Database.h"

#include <string>

using namespace std;

class Category {
 public:
  Category(int, string, int, Database);
  ~Category();

  int getId();
  int getWeight();
  string getName();

  void setId(int);
  void setName(string);
  void setWeight(int);
  
  void save();

 private:
  int id;
  string name;
  int weight;
  Database db;
};

#endif