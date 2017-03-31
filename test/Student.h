#include <sqlite3.h>
#include <string>

using namespace std;

class Student {
public:
  Student(string id, string firstName, string lastName);
  ~Student();

  string getId();
  string getFirstName();
  string getLastName();

  void setId(string);
  void setFirstName(string);
  void setLastName(string);

private:
  sqlite3 *db;

  string id;
  string firstName;
  string lastName;
};
