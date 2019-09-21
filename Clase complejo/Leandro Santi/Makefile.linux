CXXARGS  = -g -Wall
CXXFLAGS = -I. $(CXXARGS)
LDFLAGS  =
CXX      = c++

all: test1
	@/bin/true

test1: test1.o complejo.o
	$(CXX) $(LDFLAGS) -o test1 test1.o complejo.o

test1.o: test1.cc complejo.h
	$(CXX) $(CXXFLAGS) -c test1.cc

complejo.o: complejo.cc complejo.h
	$(CXX) $(CXXFLAGS) -c complejo.cc

test: test1
	@set -e; for t in test?; do              \
	  echo testing: $$t.;                    \
	  ./$$t <$$t.in >$$t.t;                  \
	  diff -b $$t.ref $$t.t >/dev/null 2>&1; \
	done
	@echo test ok.

test-valgrind: test1
	@set -e; for t in test?; do                                  \
	  echo testing: $$t.;                                        \
	  valgrind --tool=memcheck ./$$t <$$t.in >$$t.t 2>/dev/null; \
	  diff -b $$t.ref $$t.t >/dev/null 2>&1;                     \
	done
	@echo test ok.

clean:
	rm -f *.o *.t core test?
