CPPFLAGS=-g -O2   -DNDEBUG  -std=c++11
LDFLAGS=-g -O2  -DNDEBUG
LDLIBS=-Wall

main: main.o lisp.o
	g++ $(LDFLAGS) -o main main.o lisp.o $(LDLIBS)

# io_utils.o: io_utils.hpp
# 	g++ $(CPPFLAGS) -c io_utils.hpp -o io_utils.o

main.o: main.cpp
	g++ $(CPPFLAGS) -c main.cpp -o main.o
lisp.o:	lisp.cc
	g++ $(CPPFLAGS) -c lisp.cc -o lisp.o
	
clean:
	rm -r -f *
