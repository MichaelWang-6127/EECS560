Lab11: main.o Node.o LinkedList.o Queue.o SHNode.o SkewHeap.o Kruskal.o Prim.o
	g++ -std=c++11 -g main.o Node.o LinkedList.o Queue.o SHNode.o SkewHeap.o Kruskal.o Prim.o -o Lab11
main.o: main.cpp Node.h Node.cpp LinkedList.h LinkedList.cpp SHNode.h SHNode.cpp SkewHeap.h SkewHeap.cpp Kruskal.h Kruskal.cpp Prim.h Prim.cpp Timer.cpp
	g++ -std=c++11 -g -c main.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -c Node.cpp
LinkedList.o: LinkedList.h LinkedList.cpp SHNode.h SHNode.cpp
	g++ -std=c++11 -g -c LinkedList.cpp
Queue.o: Queue.h Queue.cpp Node.h Node.cpp
	g++ -std=c++11 -g -c Queue.cpp
SHNode.o: SHNode.h SHNode.cpp
	g++ -std=c++11 -g -c SHNode.cpp
SkewHeap.o: SkewHeap.h SkewHeap.cpp SHNode.h SHNode.cpp Queue.h Queue.cpp Node.h Node.cpp
	g++ -std=c++11 -g -c SkewHeap.cpp
Kruskal.o: Kruskal.h Kruskal.cpp SHNode.h SHNode.cpp Queue.h Queue.cpp Node.h Node.cpp LinkedList.h LinkedList.cpp
	g++ -std=c++11 -g -c Kruskal.cpp
Prim.o: Prim.h Prim.cpp SHNode.h SHNode.cpp Queue.h Queue.cpp Node.h Node.cpp LinkedList.h LinkedList.cpp
	g++ -std=c++11 -g -c Prim.cpp
clean:
	rm *.o Lab11
	clean done