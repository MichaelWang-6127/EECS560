/** 
/   @file:Node.h
*   @author:Michael Wang
*   @date:11/01/2016
*   Purpose:THe header file for the Node class
*/
#ifndef NODE_H
#define NODE_H

#include "LHNode.h"

class Node
{
public:
	Node();
	/**
	*  @pre None
	*  @post creates a node
	*  @return initializes a node with 2 variables
	*/
	void setValue(LHNode* val);
	/**
	*  @pre None
	*  @post sets the value of the node with a given parameter
	*  @return None
	*/
	LHNode* getValue() const;
	/**
	*  @pre None
	*  @post None
	*  @return m_value
	*/
	void setNext(Node* prev);
	/**
	*  @pre None
	*  @post sets the m_next pointer to the given parameter
	*  @return None
	*/
	Node* getNext() const;
	/**
	*  @pre None
	*  @post None
	*  @return The object that is being pointed at by m_front
	*/

private:
	LHNode* m_value;
	Node* m_next;

};
#endif
