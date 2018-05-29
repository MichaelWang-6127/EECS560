Lab9: main.o Node.o Node1.o LHQueue.o SHQueue.o LHNode.o SHNode.o LeftistHeap.o SkewHeap.o
	g++ -std=c++11 -g main.o Node.o Node1.o LHQueue.o SHQueue.o LHNode.o SHNode.o LeftistHeap.o SkewHeap.o -o Lab9
main.o: main.cpp Node.h Node.cpp LHQueue.h LHQueue.cpp SHQueue.h SHQueue.cpp LHNode.h LHNode.cpp LeftistHeap.h LeftistHeap.cpp SkewHeap.h SkewHeap.cpp
	g++ -std=c++11 -g -c main.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -c Node.cpp
Node1.o: Node1.h Node1.cpp
	g++ -std=c++11 -g -c Node1.cpp
LHQueue.o: LHQueue.h LHQueue.cpp Node.h Node.cpp
	g++ -std=c++11 -g -c LHQueue.cpp
SHQueue.o: SHQueue.h SHQueue.cpp Node1.h Node1.cpp
	g++ -std=c++11 -g -c SHQueue.cpp
LHNode.o: LHNode.h LHNode.cpp
	g++ -std=c++11 -g -c LHNode.cpp
SHNode.o: SHNode.h SHNode.cpp
	g++ -std=c++11 -g -c SHNode.cpp
LeftistHeap.o: LeftistHeap.h LeftistHeap.cpp
	g++ -std=c++11 -g -c LeftistHeap.cpp
SkewHeap.o: SkewHeap.h SkewHeap.cpp
	g++ -std=c++11 -g -c SkewHeap.cpp
clean:
	rm *.o Lab9
	clean done
