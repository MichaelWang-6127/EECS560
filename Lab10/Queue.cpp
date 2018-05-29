/** 
*   @file:Queue.cpp
*   @author:Michael Wang
*   @date:09/22/2016
*   Purpose:Implementation of Queue class.
*/
#include "Queue.h"
#include <iostream>

Queue::Queue()
{
	m_front = nullptr;
	m_size = 0;
}

Queue::~Queue()
{
        while(!(isEmpty()))
	{
		Node* temp = m_front;
                m_front = temp->getNext();
		delete temp;
		temp = nullptr;
	}
}

void Queue::enqueue(SHNode* object)
{
	Node* temp  = new Node();
	temp->setValue(object);
	temp->setNext(nullptr);
	if(isEmpty())
	{
                m_front = temp;
	}
	else
	{
		Node* end = m_front;

		while(end->getNext() != nullptr)
		{
			end = end->getNext();
		}
		end->setNext(temp);
	}
	//temp = nullptr;
	m_size++;
}

SHNode* Queue::dequeue()
{	
        Node* temp = m_front;
        if(m_front == nullptr)
	{
		return nullptr;
	}
	else
	{
                m_front = temp->getNext();
	}
        SHNode* value = temp->getValue();
        delete temp;
        m_size--;
        //std::cout<<"\n deleteing the temp with number ";
        return value;
}

bool Queue::isEmpty()
{
	return (m_front == nullptr);
}
