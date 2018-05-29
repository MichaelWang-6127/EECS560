/** 
/   @file:SHQueue.h
*   @author:Michael Wang
*   @date:09/22/2016
*   Purpose:THe header file for the SHQueue class
*/
#ifndef SHQUEUE_H
#define SHQUEUE_H
#include "SHNode.h"
#include "Node1.h"
//#include "BinarySearchTree.h"

class SHQueue
{
public:
	SHQueue();
	/**
	*  @pre None
	*  @post Creates and initializes a Queue instance
	*  @return Initialzed Queue with 1 variable
	*/
	~SHQueue();
	/**
	*  @pre None
	*  @post destructs a Queue instance
	*  @return destructed Queue
	*/
	void enqueue(SHNode* object);
	/**
	*  @pre None
	*  @post adds a value to the end of the queue
	*  @return None
	*/
	SHNode* dequeue();
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
	Node1* m_front;
	int m_size;
};
#endif
