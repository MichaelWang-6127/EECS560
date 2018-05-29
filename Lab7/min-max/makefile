Lab7: main.o Node.o LinkedList.o minMaxHeap.o min5Heap.o
	g++ -std=c++11 -g main.o Node.o LinkedList.o minMaxHeap.o min5Heap.o -o Lab7
main.o: main.cpp Node.h Node.cpp LinkedList.h LinkedList.cpp minMaxHeap.h minMaxHeap.cpp min5Heap.h min5Heap.cpp Timer.cpp
	g++ -std=c++11 -g -c main.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -c Node.cpp
LinkedList.o: LinkedList.h LinkedList.cpp Node.h Node.cpp
	g++ -std=c++11 -g -c LinkedList.cpp
minMaxHeap.o: minMaxHeap.h minMaxHeap.cpp
	g++ -std=c++11 -g -c minMaxHeap.cpp
min5Heap.o: min5Heap.h min5Heap.cpp
	g++ -std=c++11 -g -c min5Heap.cpp
clean:
	rm *.o Lab7
	clean done
