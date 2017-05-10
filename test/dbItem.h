// dbItem.h

#ifndef DBITEM_H
#define DBITEM_H

#include "Database.h"

using namespace std;

class dbItem {

  dbItem(Database &);
  
  // Getters
  // int getId() const;
  // int getCategoryId() const;
  // string getName() const;
  // double getPointsPossible() const;

  // Setters
  // void setCategoryId(int);
  // void setName(string);
  // void setPointsPossible(double);
  virtual void insert() = 0;
  virtual void update() const = 0;
  virtual void remove() const = 0;

 protected:
  Database &db;

};

#endif
// DBITEM.H
