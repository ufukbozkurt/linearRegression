PROG = lreg
CC = g++
CCFLAGS = -Wall
INCLUDE_PATHS = -I ./auxiliary -I ./LinearRegression
OBJS = main.o LinearRegression.o auxiliary.o

$(PROG) : $(OBJS)
	$(CC) $(CCFLAGS) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(INCLUDE_PATHS) -c main.cpp

LinearRegression.o : ./LinearRegression/LinearRegression.cpp
	$(CC) $(INCLUDE_PATHS) -c ./LinearRegression/LinearRegression.cpp

auxiliary.o : ./auxiliary/auxiliary.cpp
	$(CC) $(INCLUDE_PATHS) -c ./auxiliary/auxiliary.cpp

clean:
	rm -f $(OBJS)

clean-all :
	rm -f $(PROG) $(OBJS) 