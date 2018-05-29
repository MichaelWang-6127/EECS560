Lab6: main.o Node.o Queue.o BSTNode.o BinarySearchTree.o min5Heap.o
	g++ -std=c++11 -g main.o Node.o Queue.o BSTNode.o BinarySearchTree.o min5Heap.o -o Lab6
main.o: main.cpp Node.h Node.cpp Queue.h Queue.cpp BSTNode.h BSTNode.cpp BinarySearchTree.h BinarySearchTree.cpp min5Heap.h min5Heap.cpp Timer.cpp
	g++ -std=c++11 -g -c main.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -c Node.cpp
Queue.o: Queue.h Queue.cpp Node.h Node.cpp
	g++ -std=c++11 -g -c Queue.cpp
BSTNode.o: BSTNode.h BSTNode.cpp
	g++ -std=c++11 -g -c BSTNode.cpp
BinarySearchTree.o: BinarySearchTree.h BinarySearchTree.cpp
	g++ -std=c++11 -g -c BinarySearchTree.cpp
min5Heap.o: min5Heap.h min5Heap.cpp
	g++ -std=c++11 -g -c min5Heap.cpp
clean:
	rm *.o Lab6
	clean done
