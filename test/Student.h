#ifndef STUDENT_H
#define STUDENT_H

#include "Database.h"

#include <string>

using namespace std;

class Student {
public:
    Student(string, string, string, Database);
    ~Student();
    
    string getId();
    string getFirstName();
    string getLastName();
    
    void setId(string);
    void setFirstName(string);
    void setLastName(string);
    
    void save();
private:
    string id;
    string firstName;
    string lastName;
    Database db;
};

#endif
