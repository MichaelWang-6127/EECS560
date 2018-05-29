/** 
*   @file:LinkedList.h
*   @author:Michael Wang
*   @date:09/03/2016
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
		LinkedList(const LinkedList &copy);
		/**
		*  @pre None
		*  @post Creates and initializes a copy of LinkedList instance
		*  @return Initialzed a copy of a LinkedList with 2 variables
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
		void erase(int x);
        /**
		*  @pre None
		*  @post takes in a value and checks every node to see if it is in the list and if it is in the list then it deletes the value. If the value is not in the list it does not change the list.
		*  @return None
		*/
		void reverse();
		/**
		*  @pre LinkedList
		*  @post splits the linked list into head and calls reverse(Node* head)
		*  @return None
		*/
		void reverseRecurse(Node* head);
		/**
		*  @pre head of the list and body of the list
		*  @post reverses the list recursively given a head of the list
		*  @return None
		*/
        void concatenate(LinkedList list2);
		/**
		*  @pre takes two lists
		*  @post takes a second list and adds the list to the end of another list
		*  @return None
		*/
		void concatenateRecurse(Node* list1, Node* list2);
		/**
		*  @pre takes a LinkedList and a Node* to the second LinkedList
		*  @post takes a second list and adds the list to the end of another list
		*  @return None
		*/
                int getRemoveFront();
                /**
		*  @pre None
		*  @post removes the front node in the list
		*  @return the value of the front of the list
		*/

	private:
		Node* m_front;
		int m_size;

};
#endif
