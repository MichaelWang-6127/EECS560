/** 
*   @file:SHNode.cpp
*   @author:Michael Wang
*   @date:11/01/2016
*   Purpose:The definition for the methods of the SHNode class
*/
#include "SHNode.h"

SHNode::SHNode()//constructor
{
	m_value = 0;
	m_xCoordinate = -1;
	m_yCoordinate = -1;
	m_left = nullptr;
        m_right = nullptr;
}

void SHNode::setValue(int val)//sets the value stored in the node
{
	m_value = val;
}

int SHNode::getValue() const//gets the value stored in the node
{
	return (m_value);
}

void SHNode::setX(int val)//sets the x coordinate stored in the node
{
	m_xCoordinate = val;
}

int SHNode::getX() const//gets the x coordinate stored in the node
{
	return (m_xCoordinate);
}

void SHNode::setY(int val)//sets the y coordinate stored in the node
{
	m_yCoordinate = val;
}

int SHNode::getY() const//gets the y coordinate stored in the node
{
	return (m_yCoordinate);
}

void SHNode::setLeft(SHNode* left)//sets the left pointer of the node
{
	m_left = left;
}

SHNode* SHNode::getLeft() const//gets the left pointer of the node
{
	return (m_left);
}

void SHNode::setRight(SHNode* right)//sets the right pointer of the node
{
	m_right = right;
}

SHNode* SHNode::getRight() const//gets the right pointer of the node
{
	return (m_right);
}
