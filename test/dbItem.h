// dbItem.h
#include "Database.h"
#include "dbItem.h"

#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

dbItem::dbItem(int id, int categoryId, string name, double pointsPossible,
               Database &db)
    : id(id), categoryId(categoryId), name(name),
      pointsPossible(pointsPossible), db(db) {}

// Getters
int dbItem::getId() const { return id; }

int dbItem::getCategoryId() const { return categoryId; }

string dbItem::getName() const { return name; }

double dbItem::getPointsPossible() const { return pointsPossible; }

// Setters
void dbItem::setCategoryId(int a_categoryId) { categoryId = a_categoryId; }

void dbItem::setName(string a_name) { name = a_name; }

void dbItem::setPointsPossible(double a_pointsPossible) {
  pointsPossible = a_pointsPossible;
}

// Database query commands
void dbItem::insert() {
  stringstream command;
  command << "INSERT INTO dbItems ";
  command << "(categoryId, name, pointsPossible) ";
  command << "VALUES (";
  command << getCategoryId() << ", ";
  command << "'" << getName() << "', ";
  command << getPointsPossible();
  command << ");";

  db.execute(command.str());
}

void dbItem::update() const {
  stringstream command;
  command << "UPDATE dbItems SET ";
  command << "categoryId = " << getCategoryId() << ", ";
  command << "name = '" << getName() << "', ";
  command << "pointsPossible = " << getPointsPossible() << " ";
  command << "WHERE id = " << getId();
  command << ";";

  db.execute(command.str());
}

void dbItem::remove() const {
  stringstream command;
  command << "DELETE FROM dbItems WHERE ";
  command << "id = " << getId();
  command << ";";

  db.execute(command.str());
}

// Static database query commands
void dbItem::create(Database &db) {
  string command = "CREATE TABLE IF NOT EXISTS dbItems (\n"
                   "    id             INTEGER     PRIMARY KEY,\n"
                   "    categoryId     INTEGER (1) NOT NULL,\n"
                   "    name           TEXT (150)  NOT NULL\n"
                   "                               UNIQUE,\n"
                   "    pointsPossible NUMERIC (4) NOT NULL\n"
                   ");";

  db.execute(command);
}

map<int, dbItem *> dbItem::read(Database &db) {
  map<int, dbItem *> data;
  vector<vector<string>> results;

  results = db.execute("SELECT * FROM dbItems;");

  for (vector<string> row : results) {
    int id = stoi(row[0]);

    data[id] = new dbItem(id, stoi(row[1]), row[2], stod(row[3]), db);
  }

  return data;
}
