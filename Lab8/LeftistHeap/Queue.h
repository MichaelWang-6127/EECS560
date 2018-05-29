/** 
/   @file:Queue.h
*   @author:Michael Wang
*   @date:09/22/2016
*   Purpose:THe header file for the Queue class
*/
#ifndef QUEUE_H
#define QUEUE_H
#include "LHNode.h"
#include "Node.h"
//#include "BinarySearchTree.h"

class Queue
{
public:
	Queue();
	/**
	*  @pre None
	*  @post Creates and initializes a Queue instance
	*  @return Initialzed Queue with 1 variable
	*/
	~Queue();
	/**
	*  @pre None
	*  @post destructs a Queue instance
	*  @return destructed Queue
	*/
	void enqueue(LHNode* object);
	/**
	*  @pre None
	*  @post adds a value to the end of the queue
	*  @return None
	*/
	LHNode* dequeue();
	/**
	*  @pre None
	*  @post removes the first element of the queue
	*  @return a pointer to the first element of the queue and nullptr when the queue is empty
	*/
	bool isEmpty();
	/**
	*  @pre None
	*  @post None
	*  @return true if the queue is empty false otherwise
	*/
private:
	Node* m_front;
	int m_size;
};
#endif
