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
           << " is too many students for one course! Try again.\nHow many "
              "students?: ";
      cin >> max;
      continue;
    } else if (max <= 0) {
      cout << max
           << " is too few students for one course! Try again.\nHow many "
              "students?: ";
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

int prompt(int func) { return func; }

int main() {

  int func = 0;
  int max = 0;
  char buf[100];
  // prompt loop
  while (true) {

    cout << "Which function? [1, 2, 3, 4, 5]\n";
    cin >> buf;
    func = atoi(buf);
    cout << "How many?: ";
    cin >> buf;
    max = atoi(buf);

    // sentinel
    if (prompt(func) < 0) {
      cout << "Quitting\n";
      break;
    }

    else if (prompt(func) == 1) {
      f1(max);
      // break;
    }

    else if (prompt(func) == 2) {
      f2(max);
      // break;
    }

    else if (prompt(func) == 3) {
      f3(max);
      // break;
    }

    else if (prompt(func) == 4) {
      f5(max);
      // break;
    }

    else if (prompt(func) == 5) {
      f5(max);
      // break;
    }

    else {
      cout << "Invalid Function choice! Try again.\n";
      // continue;
    }
  }
}
