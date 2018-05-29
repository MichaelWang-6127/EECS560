/** 
*   @file:SHQueue.cpp
*   @author:Michael Wang
*   @date:09/22/2016
*   Purpose:Implementation of SHQueue class.
*/
#include "SHQueue.h"
#include <iostream>

SHQueue::SHQueue()
{
	m_front = nullptr;
	m_size = 0;
}

SHQueue::~SHQueue()
{
        while(!(isEmpty()))
	{
		Node1* temp = m_front;
                m_front = temp->getNext();
		delete temp;
		temp = nullptr;
	}
}

void SHQueue::enqueue(SHNode* object)
{
	Node1* temp  = new Node1();
	temp->setValue(object);
	temp->setNext(nullptr);
	if(isEmpty())
	{
                m_front = temp;
	}
	else
	{
		Node1* end = m_front;

		while(end->getNext() != nullptr)
		{
			end = end->getNext();
		}
		end->setNext(temp);
	}
	//temp = nullptr;
	m_size++;
}

SHNode* SHQueue::dequeue()
{	
        Node1* temp = m_front;
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
        //std::cout<<"\n deleteing the temp with number ";
        return value;
}

bool SHQueue::isEmpty()
{
	return (m_front == nullptr);
}
