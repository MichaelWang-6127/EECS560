/** 
/   @file:LinkedList.h
*   @author:Michael Wang
*   @date:11/16/2016
*   Purpose:THe header file for the LinkedList class
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "SHNode.h"

class LinkedList
{
public:
	LinkedList();
	/**
	*  @pre None
	*  @post creates a LinkedList
	*  @return initializes a LinkedList with 2 variables
	*/
	~LinkedList();
	/**
	*  @pre None
	*  @post destructs a LinkedList instance
	*  @return destructed LinkedList
	*/
	SHNode* getFront() const;
	/**
	*  @pre None
	*  @post None
	*  @return The object that is being pointed at by m_front
	*/
	bool isEmpty();
	/**
	*  @pre None
  	*@post checks to see if the list is empty or not
	*  @return true if there are no nodes in the list and false if there are nodes in the list
	*/
	int size() const;
	/**
	*  @pre None
	*  @post checks how many nodes are in the list
	*  @return the size of the list
	*/
	void addFront(int value, int xCor, int yCor);
	/**
	*  @pre None
	*  @post adds a node in the front of the list with a taken value
	*  @return None
	*/
	bool removeFront();
	/**
	*  @pre None
	*  @post removes the node in the front if there is one
	*  @return true if there is a node and false if there is none
	*/
	void erase(int x, int y, int value);
    /**
	*  @pre None
	*  @post takes in a value and checks every node to see if it is in the list and if it is in the list then it deletes the value. If the value is not in the list it does not change the list.
	*  @return None
	*/
	bool search(int value, int x, int y) const;
	/**
	*  @pre None
	*  @post takes in a value and checks every node to see if it is in the list
	*  @return true if the value is in the list and false if the value is not in the list
	*/

private:
	SHNode* m_front;
	int m_size;

};
#endif
