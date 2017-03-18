#include <fstream>
#include <iostream>
using namespace std;

char buf[100];

int main() {

  // input and output file objects
  ifstream fin;
  ofstream fout;

  // main prompt
  cout << "Welcome to grade-plus\n";
  cout << "Import from a file? [Y/N/Q]: ";

  // input loop
  while (true) {
    cin >> buf; 
    if (buf[0] == 'Y' || buf[0] == 'y') {
      cout << "\nFilename: ";
      cin >> buf;
      fin.open(buf);
      if (!fin.good()) throw "I/O error\n";
      cout << "Opening file: " << buf << "...\n";
    }

    else if (buf[0] == 'N' || buf[0] == 'n') {
      cout << "\nCreating new course...\n";
    }

    else if (buf[0] == 'Q' || buf[0] == 'q') {
      cout << "Goodbye\n";
      break;
    }

    else {
      cout << "Invalid entry\n";
      continue;
    }
  }
}