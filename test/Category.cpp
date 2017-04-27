#include "Category.h"
#include "Database.h"

#include <string>
#include <sstream>

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

void Category::update() {
    stringstream command;
    command << "UPDATE students SET ";
    command << "id = '" << getId() << "', ";
    command << "weight = '" << getWeight() << "', ";
    command << "name = '" << getName() << "' ";
    command << "WHERE id = '" << getId() << "'";
    command << ";";
    
    db.execute(command.str());
}

void Category::remove() {
    stringstream command;
    command << "DELETE from students WHERE id = ";
    command << "'" << getId() << "'";
    command << ";";
    
    db.execute(command.str());
}

void Category::insert() {
    stringstream command;
    command << "INSERT into students VALUES (";
    command << getId() << ", ";
    command << getWeight() << ", ";
    command << getName() << ", ";
    command << ");";
    
    db.execute(command.str());
}
