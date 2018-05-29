/** 
*   @file:Node1.cpp
*   @author:Michael Wang
*   @date:11/01/2016
*   Purpose:The definition for the methods of the Node1 class
*/
#include "Node1.h"

Node1::Node1()//constructor
{
	m_value = nullptr;
	m_next = nullptr;
}

void Node1::setValue(SHNode* val)//sets the value stored in the node
{
	m_value = val;
}

SHNode* Node1::getValue() const//gets the value stored in the node
{
	return (m_value);
}

void Node1::setNext(Node1* prev)//sets the next pointer of the node
{
	m_next = prev;
}

Node1* Node1::getNext() const//gets the next pointer of the node
{
	return (m_next);
}
