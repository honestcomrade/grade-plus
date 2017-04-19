#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <string>

using namespace std;

class Database {
 public:
  Database(string);
  ~Database();

  void execute(string);

 private:
  sqlite3 *db;
};

#endif
