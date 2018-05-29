Lab03: main.o Node.o LinkedList.o HashTable.o
	g++ -std=c++11 -g main.o Node.o LinkedList.o HashTable.o -o Lab03
main.o: main.cpp Node.h Node.cpp LinkedList.h LinkedList.cpp HashTable.h HashTable.cpp
	g++ -std=c++11 -g -c main.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -c Node.cpp
LinkedList.o: LinkedList.h LinkedList.cpp Node.h Node.cpp
	g++ -std=c++11 -g -c LinkedList.cpp
HashTable.o: HashTable.h HashTable.cpp LinkedList.h LinkedList.cpp Node.h Node.cpp
	g++ -std=c++11 -g -c HashTable.cpp
clean:
	rm *.o Lab03
	clean done
