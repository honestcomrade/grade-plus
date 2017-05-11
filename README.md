# grade-plus
A Teacher's Aide -- From the Command Line

grade-plus is a lightweight command line application to be used by teachers, TAs, and other educators to make managing
classroom grades easier. 
It's built in C++ with extensibility in mind: A teacher can create their own types of assignments
with custom weights and scores to let grade-plus do all the calculus. 
Simply fire up the application and choose what type of work is to be done.

The API will allow a user to:

   * Create a course roster with a desired number of students
   
   * Add new students or remove them from the roster
   
   * Add exams, lab exercises, or participation grades to each student's score
   
   * Adjust the grade weight of any particular score or per type of assignment

   * Quickly view (in the command line) the performance of each student in any category

   * Export a student's grades to an Excel or text file for progress reports
   
This project is intended for use by anyone who can work in a bash terminal, and upon release
will be freely available to anyone who chooses to use it.

# Current Usage
We've fully implemented the Class hierachy and added the SQL database to all the classes. To run the test as it is
currently implemented, pull the whole repository, then:

```

cd test
make
./test0.out

```

# Why 'make' ?
Since we are including the sqlite functionality, we need to link the object files to the data base. And there's plenty of object files.
Leveraging c-make by including a "make file" to generate the executable automates that process.


