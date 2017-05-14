#include <iostream>
#include <map>
#include <string>

using namespace std;

// these functions will stand in for the execute calls.
// mock for assignment score
void f1(int max) {
  while (true) {
    if (0 < max && max <= 100) {
      cout << "calling function 1 with " << max << " as param\n";
      break;
    } else {
      cout << max << " is too high for f1.\nTry again: ";
      cin >> max;
      continue;
    }
  }
}

void f2(int max) {
  while (true) {
    if (max > 30) {
      cout << max
           << " is too many students for one course! Try again.\nHow "
              "many students?: ";
      cin >> max;
      continue;
    } else if (max <= 0) {
      cout << max
           << " is too few students for one course! Try again.\nHow "
              "many students?: ";
      cin >> max;
      continue;
    } else {
      cout << "calling function 2 with " << max << " as param\n";
      break;
    }
  }
}

void f3(int max) {
  while (true) {
    if (0 < max && max <= 100) {
      cout << "calling function 3 with " << max << " as param\n";
      break;
    } else {
      cout << max << " is too high for f3.\nTry again: ";
      cin >> max;
      continue;
    }
  }
}

void f4(int max) {
  while (true) {
    if (0 < max && max <= 100) {
      cout << "calling function 4 with " << max << " as param\n";
      break;
    } else {
      cout << max << " is too high for f4.\nTry again: ";
      cin >> max;
      continue;
    }
  }
}
void f5(int max) {
  while (true) {
    if (0 < max && max <= 100) {
      cout << "calling function 5 with " << max << " as param\n";
      break;
    } else {
      cout << max << " is too high for f5. \nTry again: ";
      cin >> max;
      continue;
    }
  }
}

void (*funcs[])(int) = {f1, f2, f3, f4, f5};

int prompt(int max, string p) {
  char buf[100];
  int choice = max + 1;

  while (choice > max) {
    cout << p;

    cin.getline(buf, 100);
    choice = atoi(buf);
  }

  return choice;
}

int main() {
  int func;
  int max = 5;

  // prompt loop
  while (true) {

    func = prompt(max, "Which function? [1, 2, 3, 4, 5]: ");

    // sentinel
    if (func <= 0) {
      cout << "Quitting\n";
      break;
    } else if (func <= max) {
      (*funcs[func - 1])(7);
    } else {
      cout << "Invalid Function choice! Try again.\n";
      // continue;
    }
  }
}
