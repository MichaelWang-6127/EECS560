Lab4: main.o Node.o Queue.o BSTNode.o BinarySearchTree.o
	g++ -std=c++11 -g main.o Node.o Queue.o BSTNode.o BinarySearchTree.o -o Lab4
main.o: main.cpp Node.h Node.cpp Queue.h Queue.cpp BSTNode.h BSTNode.cpp BinarySearchTree.h BinarySearchTree.cpp
	g++ -std=c++11 -g -c main.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -c Node.cpp
Queue.o: Queue.h Queue.cpp Node.h Node.cpp
	g++ -std=c++11 -g -c Queue.cpp
BSTNode.o: BSTNode.h BSTNode.cpp
	g++ -std=c++11 -g -c BSTNode.cpp
BinarySearchTree.o: BinarySearchTree.h BinarySearchTree.cpp
	g++ -std=c++11 -g -c BinarySearchTree.cpp
clean:
	rm *.o Lab4
	clean done
