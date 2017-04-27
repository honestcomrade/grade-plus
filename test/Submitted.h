#ifndef SUBMITTED_H
#define SUBMITTED_H

#include "Database.h"

#include <string>

using namespace std;

class Submitted {
 public:
  Submitted();
  ~Submitted();

 private:
  int id;
  Database db;
};

#endif // SUBMITTED_H
