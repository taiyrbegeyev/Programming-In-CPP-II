CC = g++
CFLAGS = -Wall

all: test-all
	./testArithmetic
	./testRelational
	./testIO
	./testExceptions

test-all: testArithmetic testExceptions testIO testRelational

run-testArithmetic: testArithmetic
	./testArithmetic

testArithmetic: testArithmetic.o
	$(CC) $(CFLAGS) -o testArithmetic Fraction.cpp testArithmetic.cpp
testArithmetic.o: Fraction.h Fraction.cpp testArithmetic.cpp

run-testExceptions: testExceptions
	./testExceptions

testExceptions: testExceptions.o
	$(CC) $(CFLAGS) -o testExceptions Fraction.cpp testExceptions.cpp
testExceptions.o: Fraction.h Fraction.cpp testExceptions.cpp

run-testIO: testIO
	./testIO

testIO: testIO.o
	$(CC) $(CFLAGS) -o testIO Fraction.cpp testIO.cpp
testIO.o: Fraction.h Fraction.cpp testIO.cpp

run-testRelational: testRelational
	./testRelational

testRelational: testRelational.o
	$(CC) $(CFLAGS) -o testRelational Fraction.cpp testRelational.cpp
testRelational.o: Fraction.h Fraction.cpp	 testRelational.cpp

clean:
	rm *.o
	rm -f testArithmetic
	rm -f testExceptions
	rm -f testIO
	rm -f testRelational

