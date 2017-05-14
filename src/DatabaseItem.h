#ifndef DATABASEITEM_H
#define DATABASEITEM_H

#include "Database.h"

using namespace std;

class DatabaseItem {
public:
  DatabaseItem(Database &);

  virtual void insert() = 0;
  virtual void update() const = 0;
  virtual void remove() const = 0;

protected:
  Database &db;
};

#endif // DatabaseItem.h
