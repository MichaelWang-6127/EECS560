/** 
/   @file:LHNode.h
*   @author:Michael Wang
*   @date:11/01/2016
*   Purpose:THe header file for the LHNode class
*/
#ifndef LHNODE_H
#define LHNODE_H

class LHNode
{
public:
	LHNode();
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
	void setRank(int rank);
	/**
	*  @pre None
	*  @post sets the rank of the node with a given parameter
	*  @return None
	*/
	int getRank() const;
	/**
	*  @pre None
	*  @post None
	*  @return m_rank
	*/
	void setRight(LHNode* right);
	/**
	*  @pre None
	*  @post sets the right pointer to the given parameter
	*  @return None
	*/
        void setLeft(LHNode* left);
	/**
	*  @pre None
	*  @post sets the left pointer to the given parameter
	*  @return None
	*/
	LHNode* getRight() const;
	/**
	*  @pre None
	*  @post None
	*  @return The right node
	*/
        LHNode* getLeft() const;
	/**
	*  @pre None
	*  @post None
	*  @return The left node
	*/

private:
	int m_value;
	int m_rank;
	LHNode* m_left;
        LHNode* m_right;

};
#endif
