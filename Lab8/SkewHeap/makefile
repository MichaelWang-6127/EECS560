Lab8: main.o Node.o Queue.o SHNode.o SkewHeap.o
	g++ -std=c++11 -g main.o Node.o Queue.o SHNode.o SkewHeap.o -o Lab8
main.o: main.cpp Node.h Node.cpp Queue.h Queue.cpp SHNode.h SHNode.cpp SkewHeap.h SkewHeap.cpp
	g++ -std=c++11 -g -c main.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -c Node.cpp
Queue.o: Queue.h Queue.cpp Node.h Node.cpp
	g++ -std=c++11 -g -c Queue.cpp
SHNode.o: SHNode.h SHNode.cpp
	g++ -std=c++11 -g -c SHNode.cpp
SkewHeap.o: SkewHeap.h SkewHeap.cpp
	g++ -std=c++11 -g -c SkewHeap.cpp
clean:
	rm *.o Lab8
	clean done
