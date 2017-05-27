CXX=clang++
CPPFLAGS=-std=c++11 -D'DEBUG(x)'
LDFLAGS=-l sqlite3

OBJS=Assignment.o Category.o Course.o Database.o DatabaseItem.o Student.o Submitted.o

all: grade-plus

grade-plus: main.cpp ${OBJS}
	$(CXX) $(CPPFLAGS) $(LDFLAGS) -o $@ $^

clean:
	rm -f grade-plus *.o
