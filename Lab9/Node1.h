/** 
/   @file:Node1.h
*   @author:Michael Wang
*   @date:11/01/2016
*   Purpose:THe header file for the Node1 class
*/
#ifndef NODE1_H
#define NODE1_H

#include "SHNode.h"

class Node1
{
public:
	Node1();
	/**
	*  @pre None
	*  @post creates a node
	*  @return initializes a node with 2 variables
	*/
	void setValue(SHNode* val);
	/**
	*  @pre None
	*  @post sets the value of the node with a given parameter
	*  @return None
	*/
	SHNode* getValue() const;
	/**
	*  @pre None
	*  @post None
	*  @return m_value
	*/
	void setNext(Node1* prev);
	/**
	*  @pre None
	*  @post sets the m_next pointer to the given parameter
	*  @return None
	*/
	Node1* getNext() const;
	/**
	*  @pre None
	*  @post None
	*  @return The object that is being pointed at by m_front
	*/

private:
	SHNode* m_value;
	Node1* m_next;

};
#endif
