CXX=clang++
CPPFLAGS=-std=c++11 -l sqlite3

OBJS=Assignment.cpp Category.cpp Course.cpp Database.cpp Student.cpp Submitted.cpp

all: test0

test0: test0.out
test1: test1.out

test0.out: test-0.cpp ${OBJS}
	$(CXX) $(CPPFLAGS) $^ -o $@

test1.out: test-1.cpp ${OBJS}
	$(CXX) $(CPPFLAGS) $^ -o $@

clean:
	rm *.out
