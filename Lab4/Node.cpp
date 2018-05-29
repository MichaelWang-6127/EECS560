/** 
*   @file:Node.cpp
*   @author:Michael Wang
*   @date:08/24/2016
*   Purpose:The definition for the methods of the Node class
*/
#include "Node.h"

Node::Node()//constructor
{
	m_value = nullptr;
	m_next = nullptr;
}

void Node::setValue(BSTNode* val)//sets the value stored in the node
{
	m_value = val;
}

BSTNode* Node::getValue() const//gets the value stored in the node
{
	return (m_value);
}

void Node::setNext(Node* prev)//sets the next pointer of the node
{
	m_next = prev;
}

Node* Node::getNext() const//gets the next pointer of the node
{
	return (m_next);
}
