/** 
*   @file:LeftistHeap.h
*   @author:Michael Wang
*   @date:11/01/2015
*   Purpose:This is the header file for the LeftistHeap class
*/

#ifndef LeftistHeap_H
#define LeftistHeap_H

#include "LHNode.h"
#include "Queue.h"

class LeftistHeap
{
public:
        LeftistHeap();
	/**
	*  @pre None
	*  @post Creates and initializes a LeftistHeap instance
	*  @return Initialzed LeftistHeap
	*/
        ~LeftistHeap();
	/**
	*  @pre None
	*  @post Deletes the entire LeftistHeap
	*  @return None
	*/
        bool isEmpty();
        /**
	*  @pre None
	*  @post None
	*  @return true if no nodes in the tree, otherwise returns false.
	*/
        void insert(int x);
        /**
	*  @pre a value to insert
	*  @post inserts a value into the LeftistHeap
	*  @return None
	*/
        void deletemin();
        /**
	*  @pre None
	*  @post deletes the smallest value from the LeftistHeap
	*  @return None
	*/
        void preorder();
        /**
	*  @pre None
	*  @post prints the elements in the LeftistHeap using preorder traversal
	*  @return None
	*/
        void inorder();
        /**
	*  @pre None
	*  @post prints the elements in the LeftistHeap using inorder traversal
	*  @return None
	*/
        void levelorder();
        /**
	*  @pre None
	*  @post prints the elements in the LeftistHeap using levelorder traversal
	*  @return None
	*/
private:
        void deleteTree(LHNode* subtree);
        /**
	*  @pre a subtree
	*  @post deltes the LeftistHeap given a starting subtree
	*  @return None
	*/
		LHNode* merge(LHNode* subtreeLeft, LHNode* subtreeRight);
        /**
	*  @pre two LHNode* to the two LeftistHeaps to be merges
	*  @post merges two LeftistHeaps
	*  @return LHNode* to the merged tree
	*/
        void printTree(LHNode* subtree, int order);
        /**
	*  @pre None
	*  @post the contents of the subtree are printed to the console in the specified order
	*  @return None
	*/

    LHNode* m_root;
};
#endif
