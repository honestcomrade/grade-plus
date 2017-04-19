#include "Database.h"

#include <sqlite3.h>
#include <iostream>
#include <string>

using namespace std;

Database::Database(string filename) {
  char filenameCharArray[100];
  strcpy(filenameCharArray, filename.c_str());
  sqlite3_open(filenameCharArray, &db);
}

Database::~Database() { sqlite3_close(db); }

void Database::execute(string command) {
  cout << "Executing command: " << command << endl;
}
