CXX=clang++
CPPFLAGS=-std=c++11 -D'DEBUG(x)'
LDFLAGS=-l sqlite3

OBJS=Assignment.o Category.o Course.o Database.o DatabaseItem.o Student.o Submitted.o

all: grade-plus

grade-plus: main.cpp ${OBJS}
	$(CXX) $(CPPFLAGS) $(LDFLAGS) -o $@ $^

clean:
	ls | grep '[.]out' > /dev/null && rm *.out || true
	ls | grep '[.]o' > /dev/null && rm *.o || true
	ls | grep 'grade-plus' /dev/null && rm grade-plus || true
