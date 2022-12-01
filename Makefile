CC=g++
CFLAGS=-std=c++11

longhorn: Longhorn.o Account.o Checking.o Savings.o
	$(CC) -o longhorn Longhorn.o Account.o Checking.o Savings.o

Longhorn.o: Longhorn.cpp
	$(CC) -c Longhorn.cpp $(CFLAGS)

Account.o: Account.cpp
	$(CC) -c Account.cpp $(CFLAGS)

Checking.o: Checking.cpp
	$(CC) -c Checking.cpp $(CFLAGS)

Savings.o: Savings.cpp
	$(CC) -c Savings.cpp $(CFLAGS)

clean: 
	-rm Account.o Checking.o longhorn Longhorn.o Savings.o