/** 
*   @file:LHNode.cpp
*   @author:Michael Wang
*   @date:11/01/2016
*   Purpose:The definition for the methods of the LHNode class
*/
#include "LHNode.h"

LHNode::LHNode()//constructor
{
	m_value = 0;
	m_rank = 0;
	m_left = nullptr;
    m_right = nullptr;
}

void LHNode::setValue(int val)//sets the value stored in the node
{
	m_value = val;
}

int LHNode::getValue() const//gets the value stored in the node
{
	return (m_value);
}

void LHNode::setRank(int rank)//sets the rank stored in the node
{
	m_rank = rank;
}

int LHNode::getRank() const//gets the rank stored in the node
{
	return (m_rank);
}

void LHNode::setLeft(LHNode* left)//sets the left pointer of the node
{
	m_left = left;
}

LHNode* LHNode::getLeft() const//gets the left pointer of the node
{
	return (m_left);
}

void LHNode::setRight(LHNode* right)//sets the right pointer of the node
{
	m_right = right;
}

LHNode* LHNode::getRight() const//gets the right pointer of the node
{
	return (m_right);
}
