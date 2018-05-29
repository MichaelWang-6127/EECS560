Lab02: main.o Node.o LinkedList.o
	g++ -std=c++11 -g main.o Node.o LinkedList.o -o Lab02
main.o: main.cpp Node.h Node.cpp LinkedList.h LinkedList.cpp
	g++ -std=c++11 -g -c main.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -c Node.cpp
LinkedList.o: LinkedList.h LinkedList.cpp Node.h Node.cpp
	g++ -std=c++11 -g -c LinkedList.cpp
clean:
	rm *.o Lab02
	clean done
