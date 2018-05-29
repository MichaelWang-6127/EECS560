Lab8: main.o Node.o Queue.o LHNode.o LeftistHeap.o
	g++ -std=c++11 -g main.o Node.o Queue.o LHNode.o LeftistHeap.o -o Lab8
main.o: main.cpp Node.h Node.cpp Queue.h Queue.cpp LHNode.h LHNode.cpp LeftistHeap.h LeftistHeap.cpp
	g++ -std=c++11 -g -c main.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -c Node.cpp
Queue.o: Queue.h Queue.cpp Node.h Node.cpp
	g++ -std=c++11 -g -c Queue.cpp
LHNode.o: LHNode.h LHNode.cpp
	g++ -std=c++11 -g -c LHNode.cpp
LeftistHeap.o: LeftistHeap.h LeftistHeap.cpp
	g++ -std=c++11 -g -c LeftistHeap.cpp
clean:
	rm *.o Lab8
	clean done
