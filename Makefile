all: acquireheuristics.o acquirelinks.o link.o list.o main.o node.o
	g++ -std=c++11 -Wall -g -o program acquireheuristics.o acquirelinks.o link.o list.o main.o node.o

acquireheuristics.o: includes.h
acquirelinks.o: includes.h
link.o: includes.h
list.o: includes.h
main.o: includes.h
node.o: includes.h

clean:
	del *.o *.exe
