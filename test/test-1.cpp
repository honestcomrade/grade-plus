#include "Database.h"
#include "Student.h"

#include <iostream>
#include <string>

using namespace std;

int main() {
    // main prompt
    
    // test instantiation of a Database object.
    cout << "Testing instantiation of a Database object:\n";
    Database db("test-1.sqlite");
    
    // test instantiation of a Student object.
    cout << "Testing instantiation of a Student object:\n";
    Student s("1234567", "Jamie", "Green", db);
    
    cout << "Name: \t\t" << s.getFirstName() << " " << s.getLastName() << endl;
    cout << "ID: \t\t" << s.getId() << endl;
    
    // test writing Student to the database file
    cout << "Testing writing Student to the database file:\n\n";
    s.save();
    
    string input;
    cout << "Welcome to grade-plus\n";
    cout << "Import from a file? [Y/N/Q]: ";
    
    // input loop
    while (true) {
        cin >> input;
        if (tolower(input[0]) == 'y') {
            cout << "\nFilename: ";
            cin >> input;
            cout << "Opening file: " << input << "...\n";
            break;
        }
        
        else if (tolower(input[0]) == 'n') {
            cout << "\nCreating new course...\n";
            break;
        }
        
        else if (tolower(input[0]) == 'q') {
            cout << "Goodbye\n";
            break;
        }
        
        else {
            cout << "Invalid entry\n";
            continue;
        }
    }  // opening loop
}
