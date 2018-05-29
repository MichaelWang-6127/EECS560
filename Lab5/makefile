Lab5: main.o Node.o LinkedList.o min5Heap.o
	g++ -std=c++11 -g main.o Node.o LinkedList.o min5Heap.o -o Lab5
main.o: main.cpp Node.h Node.cpp LinkedList.h LinkedList.cpp min5Heap.h min5Heap.cpp
	g++ -std=c++11 -g -c main.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -c Node.cpp
LinkedList.o: LinkedList.h LinkedList.cpp Node.h Node.cpp
	g++ -std=c++11 -g -c LinkedList.cpp
min5Heap.o: min5Heap.h min5Heap.cpp
	g++ -std=c++11 -g -c min5Heap.cpp
clean:
	rm *.o Lab5
	clean done
