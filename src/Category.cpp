#include "Category.h"
#include "Database.h"
#include "DatabaseItem.h"

#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

ostream &operator<<(ostream &output, const Category &category) {
  output << "Category " << category.getId() << " ";
  output << "Name: " << category.getName() << ", ";
  output << "Weight: " << category.getWeight();
  return output;
}

Category::Category(int id, string name, int weight, Database &db)
    : DatabaseItem(db), id(id), name(name), weight(weight) {}

// Getters
int Category::getId() const { return id; }

string Category::getName() const { return name; }

int Category::getWeight() const { return weight; }

// Setters
void Category::setName(string a_name) { name = a_name; }

void Category::setWeight(int a_weight) { weight = a_weight; }

// Database query commands
void Category::insert() {
  stringstream command;
  command << "INSERT INTO categories ";
  command << "(name, weight) ";
  command << "VALUES (";
  command << "'" << getName() << "', ";
  command << getWeight();
  command << ");";

  db.execute(command.str());

  id = db.lastInsertRowid();
}

// Static database query commands
void Category::update() const {
  stringstream command;
  command << "UPDATE categories SET ";
  command << "name = '" << getName() << "', ";
  command << "weight = " << getWeight() << " ";
  command << "WHERE id = " << getId();
  command << ";";

  db.execute(command.str());
}

void Category::remove() const {
  stringstream command;
  command << "DELETE FROM categories WHERE ";
  command << "id = " << getId();
  command << ";";

  db.execute(command.str());
}

// Static database query commands
void Category::create(Database &db) {
  string command = "CREATE TABLE IF NOT EXISTS categories (\n"
                   "    id     INTEGER     PRIMARY KEY,\n"
                   "    name   TEXT (50)   UNIQUE\n"
                   "                       NOT NULL,\n"
                   "    weight INTEGER (1) NOT NULL\n"
                   ");";

  db.execute(command);
}

map<int, Category *> Category::read(Database &db) {
  map<int, Category *> data;
  vector<vector<string>> results;

  results = db.execute("SELECT * FROM categories;");

  for (vector<string> row : results) {
    int id = stoi(row[0]);

    data[id] = new Category(id, row[1], stoi(row[2]), db);
  }

  return data;
}
