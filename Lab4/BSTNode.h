/** 
/   @file:BSTNode.h
*   @author:Michael Wang
*   @date:09/21/2016
*   Purpose:THe header file for the BSTNode class
*/
#ifndef BSTNODE_H
#define BSTNODE_H

class BSTNode
{
public:
	BSTNode();
	/**
	*  @pre None
	*  @post creates a node
	*  @return initializes a node with 3 variables
	*/
	void setValue(int val);
	/**
	*  @pre None
	*  @post sets the value of the node with a given parameter
	*  @return None
	*/
	int getValue() const;
	/**
	*  @pre None
	*  @post None
	*  @return m_value
	*/
	void setRight(BSTNode* right);
	/**
	*  @pre None
	*  @post sets the right pointer to the given parameter
	*  @return None
	*/
        void setLeft(BSTNode* left);
	/**
	*  @pre None
	*  @post sets the left pointer to the given parameter
	*  @return None
	*/
	BSTNode* getRight() const;
	/**
	*  @pre None
	*  @post None
	*  @return The right node
	*/
        BSTNode* getLeft() const;
	/**
	*  @pre None
	*  @post None
	*  @return The left node
	*/

private:
	int m_value;
	BSTNode* m_left;
        BSTNode* m_right;

};
#endif
