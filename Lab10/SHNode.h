/** 
/   @file:SHNode.h
*   @author:Michael Wang
*   @date:11/01/2016
*   Purpose:THe header file for the SHNode class
*/
#ifndef SHNode_H
#define SHNode_H

class SHNode
{
public:
	SHNode();
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
	void setX(int val);
	/**
	*  @pre None
	*  @post sets the x coordinate of the node with a given parameter
	*  @return None
	*/
	int getX() const;
	/**
	*  @pre None
	*  @post None
	*  @return m_xCoordinate
	*/
	void setY(int val);
	/**
	*  @pre None
	*  @post sets the y coordinate of the node with a given parameter
	*  @return None
	*/
	int getY() const;
	/**
	*  @pre None
	*  @post None
	*  @return m_yCoordinate
	*/
	void setRight(SHNode* right);
	/**
	*  @pre None
	*  @post sets the right pointer to the given parameter
	*  @return None
	*/
    void setLeft(SHNode* left);
	/**
	*  @pre None
	*  @post sets the left pointer to the given parameter
	*  @return None
	*/
	SHNode* getRight() const;
	/**
	*  @pre None
	*  @post None
	*  @return The right node
	*/
    SHNode* getLeft() const;
	/**
	*  @pre None
	*  @post None
	*  @return The left node
	*/

private:
	int m_value;
	int m_xCoordinate;
	int m_yCoordinate;
	SHNode* m_left;
    SHNode* m_right;

};
#endif
