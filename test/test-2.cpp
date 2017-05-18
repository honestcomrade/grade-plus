#include "Course.h"

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    if (remove("test-2.sqlite") != 0) {
        cout << "Error with deletion of database file\n";
    } else {
        cout << "Database file successfully deleted\n";
    }
    
    // Instante Course object.
    cout << "Testing instantiation of a Course object:" << endl;
    Course course("test-2");
    cout << "Created " << course.getName() << "\n\n";
    
    // Add students
    course.addStudent("1", "Thomas", "Munduchira");
    course.addStudent("2", "Jesse", "Smick");
    course.addStudent("3", "Joe", "Saraceno");
    course.addStudent("4", "The", "Rock");
    course.addStudent("5", "Justin", "Timberlake");
    course.addStudent("6", "Taylor", "Swift");
    course.addStudent("7", "Tom", "Cruise");
    course.addStudent("8", "Leonardo", "DiCaprio");
    course.addStudent("9", "Jennifer", "Lawrence");
    course.addStudent("10", "Emma", "Watson");
    course.printStudents();
    cout << "\n";
    
    // Add categories
    course.addCategory("Participation", 10);
    course.addCategory("Homework", 20);
    course.addCategory("Labs", 20);
    course.addCategory("Exams", 50);
    course.printCategories();
    cout << "\n";
    
    // Add assignments
    course.addAssignment(1, "Attendance Day 1", 10);
    course.addAssignment(1, "Attendance Day 2", 10);
    course.addAssignment(1, "Attendance Day 3", 10);
    course.addAssignment(1, "Attendance Day 4", 10);
    course.addAssignment(1, "Attendance Day 5", 10);
    course.addAssignment(1, "Attendance Day 6", 10);
    course.addAssignment(1, "Attendance Day 7", 10);
    course.addAssignment(2, "Homework 1", 25);
    course.addAssignment(2, "Homework 2", 30);
    course.addAssignment(2, "Homework 3", 25);
    course.addAssignment(2, "Homework 4", 30);
    course.addAssignment(2, "Homework 5", 35);
    course.addAssignment(3, "Lab 1", 15);
    course.addAssignment(3, "Lab 2", 15);
    course.addAssignment(3, "Lab 3", 20);
    course.addAssignment(3, "Lab 4", 20);
    course.addAssignment(3, "Lab 5", 25);
    course.addAssignment(4, "Midterm 1", 150);
    course.addAssignment(4, "Midterm 2", 150);
    course.addAssignment(4, "Final", 300);
    course.printAssignments();
    cout << "\n";
    
    // Add submitted
    course.addSubmitted(1, "1", 10);
    course.addSubmitted(1, "2", 10);
    course.addSubmitted(1, "3", 10);
    course.addSubmitted(1, "4", 10);
    course.addSubmitted(1, "5", 10);
    course.addSubmitted(1, "6", 10);
    course.addSubmitted(1, "7", 10);
    course.addSubmitted(1, "8", 10);
    course.addSubmitted(1, "9", 10);
    course.addSubmitted(1, "10", 10);
    
    course.addSubmitted(2, "1", 10);
    course.addSubmitted(2, "2", 10);
    course.addSubmitted(2, "3", 10);
    course.addSubmitted(2, "4", 10);
    course.addSubmitted(2, "5", 10);
    course.addSubmitted(2, "6", 10);
    course.addSubmitted(2, "7", 10);
    course.addSubmitted(2, "8", 10);
    course.addSubmitted(2, "9", 10);
    course.addSubmitted(2, "10", 10);
    
    course.addSubmitted(3, "1", 10);
    course.addSubmitted(3, "2", 10);
    course.addSubmitted(3, "3", 10);
    course.addSubmitted(3, "4", 10);
    course.addSubmitted(3, "5", 10);
    course.addSubmitted(3, "6", 10);
    course.addSubmitted(3, "7", 10);
    course.addSubmitted(3, "8", 10);
    course.addSubmitted(3, "9", 10);
    course.addSubmitted(3, "10", 10);

    course.addSubmitted(4, "1", 10);
    course.addSubmitted(4, "2", 10);
    course.addSubmitted(4, "3", 10);
    course.addSubmitted(4, "4", 10);
    course.addSubmitted(4, "5", 10);
    course.addSubmitted(4, "6", 10);
    course.addSubmitted(4, "7", 10);
    course.addSubmitted(4, "8", 10);
    course.addSubmitted(4, "9", 10);
    course.addSubmitted(4, "10", 10);

    course.addSubmitted(5, "1", 10);
    course.addSubmitted(5, "2", 10);
    course.addSubmitted(5, "3", 10);
    course.addSubmitted(5, "4", 10);
    course.addSubmitted(5, "5", 10);
    course.addSubmitted(5, "6", 10);
    course.addSubmitted(5, "7", 10);
    course.addSubmitted(5, "8", 10);
    course.addSubmitted(5, "9", 10);
    course.addSubmitted(5, "10", 10);

    course.addSubmitted(6, "1", 10);
    course.addSubmitted(6, "2", 10);
    course.addSubmitted(6, "3", 10);
    course.addSubmitted(6, "4", 10);
    course.addSubmitted(6, "5", 10);
    course.addSubmitted(6, "6", 10);
    course.addSubmitted(6, "7", 10);
    course.addSubmitted(6, "8", 10);
    course.addSubmitted(6, "9", 10);
    course.addSubmitted(6, "10", 10);

    course.addSubmitted(7, "1", 10);
    course.addSubmitted(7, "2", 10);
    course.addSubmitted(7, "3", 10);
    course.addSubmitted(7, "4", 10);
    course.addSubmitted(7, "5", 10);
    course.addSubmitted(7, "6", 10);
    course.addSubmitted(7, "7", 10);
    course.addSubmitted(7, "8", 10);
    course.addSubmitted(7, "9", 10);
    course.addSubmitted(7, "10", 10);
    
    course.addSubmitted(8, "1", 25);
    course.addSubmitted(8, "2", 25);
    course.addSubmitted(8, "3", 25);
    course.addSubmitted(8, "4", 25);
    course.addSubmitted(8, "5", 25);
    course.addSubmitted(8, "6", 25);
    course.addSubmitted(8, "7", 25);
    course.addSubmitted(8, "8", 25);
    course.addSubmitted(8, "9", 25);
    course.addSubmitted(8, "10", 25);

    course.addSubmitted(9, "1", 30);
    course.addSubmitted(9, "2", 30);
    course.addSubmitted(9, "3", 30);
    course.addSubmitted(9, "4", 30);
    course.addSubmitted(9, "5", 30);
    course.addSubmitted(9, "6", 30);
    course.addSubmitted(9, "7", 30);
    course.addSubmitted(9, "8", 30);
    course.addSubmitted(9, "9", 30);
    course.addSubmitted(9, "10", 30);

    course.addSubmitted(10, "1", 25);
    course.addSubmitted(10, "2", 25);
    course.addSubmitted(10, "3", 25);
    course.addSubmitted(10, "4", 25);
    course.addSubmitted(10, "5", 25);
    course.addSubmitted(10, "6", 25);
    course.addSubmitted(10, "7", 25);
    course.addSubmitted(10, "8", 25);
    course.addSubmitted(10, "9", 25);
    course.addSubmitted(10, "10", 25);

    course.addSubmitted(11, "1", 30);
    course.addSubmitted(11, "2", 30);
    course.addSubmitted(11, "3", 30);
    course.addSubmitted(11, "4", 30);
    course.addSubmitted(11, "5", 30);
    course.addSubmitted(11, "6", 30);
    course.addSubmitted(11, "7", 30);
    course.addSubmitted(11, "8", 30);
    course.addSubmitted(11, "9", 30);
    course.addSubmitted(11, "10", 30);

    course.addSubmitted(12, "1", 35);
    course.addSubmitted(12, "2", 35);
    course.addSubmitted(12, "3", 35);
    course.addSubmitted(12, "4", 35);
    course.addSubmitted(12, "5", 35);
    course.addSubmitted(12, "6", 35);
    course.addSubmitted(12, "7", 35);
    course.addSubmitted(12, "8", 35);
    course.addSubmitted(12, "9", 35);
    course.addSubmitted(12, "10", 35);
    
    course.addSubmitted(13, "1", 15);
    course.addSubmitted(13, "2", 15);
    course.addSubmitted(13, "3", 15);
    course.addSubmitted(13, "4", 15);
    course.addSubmitted(13, "5", 15);
    course.addSubmitted(13, "6", 15);
    course.addSubmitted(13, "7", 15);
    course.addSubmitted(13, "8", 15);
    course.addSubmitted(13, "9", 15);
    course.addSubmitted(13, "10", 15);

    course.addSubmitted(14, "1", 15);
    course.addSubmitted(14, "2", 15);
    course.addSubmitted(14, "3", 15);
    course.addSubmitted(14, "4", 15);
    course.addSubmitted(14, "5", 15);
    course.addSubmitted(14, "6", 15);
    course.addSubmitted(14, "7", 15);
    course.addSubmitted(14, "8", 15);
    course.addSubmitted(14, "9", 15);
    course.addSubmitted(14, "10", 15);

    course.addSubmitted(15, "1", 20);
    course.addSubmitted(15, "2", 20);
    course.addSubmitted(15, "3", 20);
    course.addSubmitted(15, "4", 20);
    course.addSubmitted(15, "5", 20);
    course.addSubmitted(15, "6", 20);
    course.addSubmitted(15, "7", 20);
    course.addSubmitted(15, "8", 20);
    course.addSubmitted(15, "9", 20);
    course.addSubmitted(15, "10", 20);

    course.addSubmitted(16, "1", 20);
    course.addSubmitted(16, "2", 20);
    course.addSubmitted(16, "3", 20);
    course.addSubmitted(16, "4", 20);
    course.addSubmitted(16, "5", 20);
    course.addSubmitted(16, "6", 20);
    course.addSubmitted(16, "7", 20);
    course.addSubmitted(16, "8", 20);
    course.addSubmitted(16, "9", 20);
    course.addSubmitted(16, "10", 20);

    course.addSubmitted(17, "1", 25);
    course.addSubmitted(17, "2", 25);
    course.addSubmitted(17, "3", 25);
    course.addSubmitted(17, "4", 25);
    course.addSubmitted(17, "5", 25);
    course.addSubmitted(17, "6", 25);
    course.addSubmitted(17, "7", 25);
    course.addSubmitted(17, "8", 25);
    course.addSubmitted(17, "9", 25);
    course.addSubmitted(17, "10", 25);
    
    course.addSubmitted(18, "1", 150);
    course.addSubmitted(18, "2", 150);
    course.addSubmitted(18, "3", 150);
    course.addSubmitted(18, "4", 150);
    course.addSubmitted(18, "5", 150);
    course.addSubmitted(18, "6", 150);
    course.addSubmitted(18, "7", 150);
    course.addSubmitted(18, "8", 150);
    course.addSubmitted(18, "9", 150);
    course.addSubmitted(18, "10", 150);

    course.addSubmitted(19, "1", 150);
    course.addSubmitted(19, "2", 150);
    course.addSubmitted(19, "3", 150);
    course.addSubmitted(19, "4", 150);
    course.addSubmitted(19, "5", 150);
    course.addSubmitted(19, "6", 150);
    course.addSubmitted(19, "7", 150);
    course.addSubmitted(19, "8", 150);
    course.addSubmitted(19, "9", 150);
    course.addSubmitted(19, "10", 150);

    course.addSubmitted(20, "1", 300);
    course.addSubmitted(20, "2", 300);
    course.addSubmitted(20, "3", 300);
    course.addSubmitted(20, "4", 300);
    course.addSubmitted(20, "5", 300);
    course.addSubmitted(20, "6", 300);
    course.addSubmitted(20, "7", 300);
    course.addSubmitted(20, "8", 300);
    course.addSubmitted(20, "9", 300);
    course.addSubmitted(20, "10", 300);
    
    course.printSubmitted();
    cout << "\n";
}
