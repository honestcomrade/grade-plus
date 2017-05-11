#ifndef DBITEM_H
#define DBITEM_H

#include "Database.h"

using namespace std;

class dbItem {
public:
  dbItem(Database &);

  virtual void insert() = 0;
  virtual void update() const = 0;
  virtual void remove() const = 0;

protected:
  Database &db;
};

#endif // DBITEM.H
