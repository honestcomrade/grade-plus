#include "Student.h"

#include <iostream>

using namespace std;

int main() {

  // main prompt
  char buf[100];
  cout << "Welcome to grade-plus\n";
  cout << "Import from a file? [Y/N/Q]: ";

  // input loop
  while (true) {
    cin >> buf; 
    if (buf[0] == 'Y' || buf[0] == 'y') {
      cout << "\nFilename: ";
      cin >> buf;
      cout << "Opening file: " << buf << "...\n";
      break;
    }

    else if (buf[0] == 'N' || buf[0] == 'n') {
      cout << "\nCreating new course...\n";
      break;
    }

    else if (buf[0] == 'Q' || buf[0] == 'q') {
      cout << "Goodbye\n";
      break;
    }

    else {
      cout << "Invalid entry\n";
      continue;
    }
  } // opening loop    

  // test instantiation of a student Object.
  cout << "Testing instantiation of a student Object:\n";
  Student s("1234567", "Jamie", "Green");

  cout << "Name: \t\t" << s.getFirstName() << " " << s.getLastName() << endl;
  cout << "ID: \t\t" << s.getId() << endl;

  // test writing Student to the database file
  cout << "Testing writing Student to the database file:\n";



}