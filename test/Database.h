#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <string>
#include <vector>

using namespace std;

class Database {
 public:
  Database();
  Database(string);
  ~Database();

  void load(string);

  vector<vector<string>> execute(string) const;

 private:
  sqlite3 *db;
};

#endif
