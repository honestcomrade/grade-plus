#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <string>
#include <vector>

using namespace std;

class Database {
 public:
  Database(string);
  ~Database();

  vector<vector<string>> execute(string);

 private:
  sqlite3 *db;
};

#endif
