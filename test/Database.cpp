#include "Database.h"

#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>

using namespace std;

Database::Database(string filename) {
  char filenameCharArray[100];
  strcpy(filenameCharArray, filename.c_str());
  sqlite3_open(filenameCharArray, &db);
}

Database::~Database() { sqlite3_close(db); }

int callback(void *res, int columns, char **data, char **) {
  vector<vector<string>> &results =
      *(static_cast<vector<vector<string>> *>(res));
  vector<string> row;

  for (int i = 0; i < columns; i++) {
    row.push_back(data[i] ? data[i] : "NULL");
    cout << data[i] << " ";
  }

  results.push_back(row);

  return 0;
}

vector<vector<string>> Database::execute(string command) const {
  cout << "Executing command: " << command << endl;
  vector<vector<string>> results;
  sqlite3_exec(db,              /* An open database */
               command.c_str(), /* SQL to be evaluated */
               callback,        /* Callback function */
               &results,        /* 1st argument to callback */
               0                /* Error msg written here */
               );
  return results;
}
