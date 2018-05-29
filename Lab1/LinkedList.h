/** 
*   @file:LinkedList.h
*   @author:Michael Wang
*   @date:08/24/2016
*   Purpose:Header for LinkedList. Used to emulate a LinkedList.
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

class LinkedList
{
	public:
		LinkedList();
		/**
		*  @pre None
		*  @post Creates and initializes a LinkedList instance
		*  @return Initialzed LinkedList with 2 variables
		*/
		~LinkedList();
		/**
		*  @pre None
		*  @post destructs a LinkedList instance
		*  @return destructed LinkedList
		*/
		bool isEmpty();
		/**
		*  @pre None
		*  @post checks to see if the list is empty or not
		*  @return true if there are no nodes in the list and false if there are nodes in the list
		*/
		int size() const;
		/**
		*  @pre None
		*  @post checks how many nodes are in the list
		*  @return the size of the list
		*/
		bool search(int value) const;
		/**
		*  @pre None
		*  @post takes in a value and checks every node to see if it is in the list
		*  @return true if the value is in the list and false if the value is not in the list
		*/
		void print() const;
		/**
		*  @pre None
		*  @post prints the values of the list
		*  @return None
		*/
		void addBack(int value);
		/**
		*  @pre None
		*  @post adds a node in the back of the list with a taken value
		*  @return None
		*/
		void addFront(int value);
		/**
		*  @pre None
		*  @post adds a node in the front of the list with a taken value
		*  @return None
		*/
		bool removeBack();
		/**
		*  @pre None
		*  @post removes the node in the back if there is one
		*  @return true if there is a node and false if there is none
		*/
		bool removeFront();
		/**
		*  @pre None
		*  @post removes the node in the front if there is one
		*  @return true if there is a node and false if there is none
		*/
                void insert(int x);
                /**
		*  @pre None
		*  @post takes in a value and checks every node to see if it is in the list and if it is in the list then it ignores the value. If the value is not in the list it adds the value to the back of the list.
		*  @return None
		*/

	private:
		Node* m_front;
		int m_size;

};
#endif
