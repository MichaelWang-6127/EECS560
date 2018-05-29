/** 
*   @file:SkewHeap.h
*   @author:Michael Wang
*   @date:11/01/2015
*   Purpose:This is the header file for the SkewHeap class
*/

#ifndef SkewHeap_H
#define SkewHeap_H

#include "SHNode.h"
#include "SHQueue.h"

class SkewHeap
{
public:
        SkewHeap();
	/**
	*  @pre None
	*  @post Creates and initializes a SkewHeap instance
	*  @return Initialzed SkewHeap
	*/
        ~SkewHeap();
	/**
	*  @pre None
	*  @post Deletes the entire SkewHeap
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
	*  @post inserts a value into the SkewHeap
	*  @return None
	*/
        void deletemin();
        /**
	*  @pre None
	*  @post deletes the smallest value from the SkewHeap
	*  @return None
	*/
        void preorder();
        /**
	*  @pre None
	*  @post prints the elements in the SkewHeap using preorder traversal
	*  @return None
	*/
        void inorder();
        /**
	*  @pre None
	*  @post prints the elements in the SkewHeap using inorder traversal
	*  @return None
	*/
        void levelorder();
        /**
	*  @pre None
	*  @post prints the elements in the SkewHeap using levelorder traversal
	*  @return None
	*/
private:
        void deleteTree(SHNode* subtree);
        /**
	*  @pre a subtree
	*  @post deltes the SkewHeap given a starting subtree
	*  @return None
	*/
		SHNode* merge(SHNode* subtreeLeft, SHNode* subtreeRight);
        /**
	*  @pre two SHNode* to the two LeftistHeaps to be merges
	*  @post merges two LeftistHeaps
	*  @return SHNode* to the merged tree
	*/
        void printTree(SHNode* subtree, int order);
        /**
	*  @pre None
	*  @post the contents of the subtree are printed to the console in the specified order
	*  @return None
	*/
        
    SHNode* m_root;
    int m_leftLevel;
    int m_rightLevel;
};
#endif
