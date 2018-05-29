/** 
*   @file:BinarySearchTree.h
*   @author:Michael Wang
*   @date:11/05/2015
*   Purpose:This is the header file for the BinarySearchTree class
*/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BSTNode.h"
#include "Queue.h"

class BinarySearchTree
{
public:
        BinarySearchTree();
	/**
	*  @pre None
	*  @post Creates and initializes a BinarySearchTree instance
	*  @return Initialzed BinarySearchTree
	*/
        ~BinarySearchTree();
	/**
	*  @pre None
	*  @post Deletes the entire BinarySearchTree
	*  @return None
	*/
        bool isEmpty();
        /**
	*  @pre None
	*  @post None
	*  @return true if no nodes in the tree, otherwise returns false.
	*/
        bool insert(int x);
        /**
	*  @pre a value to insert
	*  @post inserts a value into the BinarySearchTree
	*  @return true if the value was successfully inserted and false if it was not inserted
	*/
        bool remove(int x);
        /**
	*  @pre a value to remove
	*  @post removes a value from the BinarySearchTree
	*  @return true if the value was successfully removed and false if it was not removed
	*/
        BSTNode* search(int x);
        /**
	*  @pre a value to search for
	*  @post None
	*  @return a pointer to the given value and NULL if the value is not found
	*/
        void deletemin();
        /**
	*  @pre None
	*  @post deletes the smallest value from the BinarySearchTree
	*  @return None
	*/
        void deletemax();
        /**
	*  @pre None
	*  @post deletes the largest value from the BinarySearchTree
	*  @return None
	*/
        void preorder();
        /**
	*  @pre None
	*  @post prints the elements in the BinarySearchTree using preorder traversal
	*  @return None
	*/
        void inorder();
        /**
	*  @pre None
	*  @post prints the elements in the BinarySearchTree using inorder traversal
	*  @return None
	*/
        void levelorder();
        /**
	*  @pre None
	*  @post prints the elements in the BinarySearchTree using levelorder traversal
	*  @return None
	*/
private:
        bool insert(int value, BSTNode* subtree);
        /**
	*  @pre a value to insert and a subtree the value into
	*  @post inserts a value into the BinarySearchTree
	*  @return true if the value was successfully inserted and false if it was not inserted
	*/
	bool remove(int value, BSTNode* parent);
	/**
	*  @pre a value to remove and a parent
	*  @post removes a value into the BinarySearchTree
	*  @return true if the value was successfully removed and false if it was not removed
	*/
        bool deleteOne(int value, BSTNode* parent);
        /**
	*  @pre a value to remove and a parent
	*  @post removes a value into the BinarySearchTree if the Node is a leaf
	*  @return true if the value was successfully removed and false if it was not removed
	*/
        void deleteTree(BSTNode* subtree);
        /**
	*  @pre a subtree
	*  @post deltes the BinarySearchTree given a starting subtree
	*  @return None
	*/
        void printTree(BSTNode* subtree, int order);
        /**
	*  @pre None
	*  @post the contents of the subtree are printed to the console in the specified order
	*  @return None
	*/
		BSTNode* searchTree(int value, BSTNode* subtree);
		/**
	*  @pre a subtree and a value
	*  @post searches the tree for the value given
	*  @return a pointer to the node with the given value or nullptr if the value is not in the tree
	*/
		BSTNode* smallestRight(BSTNode* subtree);
		/**
	*  @pre a subtree
	*  @post searches the tree for the smallest value in the right subtree
	*  @return a pointer to the node in the right subtree
	*/
        
    BSTNode* m_root;
};
#endif
