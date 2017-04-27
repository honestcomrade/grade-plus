#include "Category.h"
#include "Database.h"

#include <string>

using namespace std;

Category::Category(int id, string name, int weight, Database db)
    : id(id), weight(weight), name(name), db(db) {}

Category::~Category() {}

int Category::getId() {
  return id;
}

string Category::getName() {
  string copy(name);
  return copy;
}

int Category::getWeight() {
  return weight;
}

void Category::save() {
  string command = "save";
  db.execute(command);
}


Category(int, string, int, Database);
  ~Category();

  int getId();
  int getWeight();
  string getName();

  void setId(int);
  void setName(string);
  void setWeight(int);
  
  void save();