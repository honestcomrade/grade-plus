// Category is the table of all assignments that are assigned
// - no student pair yet
#ifndef Category_H
#define Category_H

#include "Database.h"

#include <map>
#include <string>

using namespace std;

class Category {
public:
  Category(int, string, int, Database);

  // Getters
  int getId() const;
  string getName() const;
  int getWeight() const;

  // Setters
  // NOTE: `id` cannot change externally
  void setName(string);
  void setWeight(int);

  // Database query commands
  void insert();
  void update() const;
  void remove() const;

  // Create and read database table
  static void create(Database);
  static map<int, Category *> read(Database);

private:
  int id;
  string name;
  int weight;

  Database db;
};

#endif
