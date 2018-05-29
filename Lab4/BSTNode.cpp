/** 
*   @file:BSTNode.cpp
*   @author:Michael Wang
*   @date:08/24/2016
*   Purpose:The definition for the methods of the BSTNode class
*/
#include "BSTNode.h"

BSTNode::BSTNode()//constructor
{
	m_value = 0;
	m_left = nullptr;
        m_right = nullptr;
}

void BSTNode::setValue(int val)//sets the value stored in the node
{
	m_value = val;
}

int BSTNode::getValue() const//gets the value stored in the node
{
	return (m_value);
}

void BSTNode::setLeft(BSTNode* left)//sets the left pointer of the node
{
	m_left = left;
}

BSTNode* BSTNode::getLeft() const//gets the left pointer of the node
{
	return (m_left);
}

void BSTNode::setRight(BSTNode* right)//sets the right pointer of the node
{
	m_right = right;
}

BSTNode* BSTNode::getRight() const//gets the right pointer of the node
{
	return (m_right);
}
