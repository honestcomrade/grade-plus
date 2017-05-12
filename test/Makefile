CXX=clang++
CPPFLAGS=-std=c++11
LDFLAGS=-l sqlite3

OBJS=Assignment.o Category.o Course.o Database.o DatabaseItem.o Student.o Submitted.o

all: test0

test0: test0.out
test1: test1.out

test0.out: test-0.cpp ${OBJS}
	$(CXX) $(CPPFLAGS) $(LDFLAGS) -o $@ $^

test1.out: test-1.cpp ${OBJS}
	$(CXX) $(CPPFLAGS) $(LDFLAGS) -o $@ $^

clean:
	ls | grep '[.]out' > /dev/null && rm *.out || true
	ls | grep '[.]o' > /dev/null && rm *.o || true
