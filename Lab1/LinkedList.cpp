/** 
*   @file:LinkedList.cpp
*   @author:Michael Wang
*   @date:08/24/2016
*   Purpose:Implementation of LinkedList class.
*/
#include "LinkedList.h"
#include "Node.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList()//creates a linked list with 2 variables
{
    m_front = nullptr;
	m_size = 0;	
}

LinkedList::~LinkedList()//deletes the linked list that is created
{
    Node* temp = m_front;
     while(!isEmpty())
     {
            removeFront();
     }
     temp = nullptr;
}

bool LinkedList::isEmpty()//checks to see if the linked list is empty.
{
	return(m_size == 0);
}
	
int LinkedList::size() const//returns the size of the linked list
{
	return(m_size);
}

bool LinkedList::search(int value) const//searches for an input to see if it is in the linked list.
{
	bool bFound = false;
    //cout<<"Searching for " << value <<"...\n";
	Node* np = m_front;
	while(np != nullptr)
	{
        if(np->getValue() == value)
		{
			bFound = true;
            np = nullptr;
		}
		else
		{
			np = np->getNext();
		}
	}
	return (bFound);
}

void LinkedList::print() const//it prints out the linked list.
{
	Node* np = m_front;
        cout << "List: \n";
	if(np == nullptr)
	{
		cout << "List Empty\n";
	}
	else
	{
		while(np != nullptr)
		{
                        cout << np->getValue() <<" ";
            np = np -> getNext();
		}
	}
}

void LinkedList::addBack(int value)//it adds a value to the end of the linked list.
{
    Node* nNode = new Node();
    nNode->setValue(value);
    nNode->setNext(nullptr);
    if(isEmpty())
    {
            m_front = nNode;
    }
    else
    {
            Node* temp = m_front;
            while(temp->getNext() != nullptr)
            {
                    temp = temp->getNext();
            }
            temp->setNext(nNode);
    }
    m_size++;
}

void LinkedList::addFront(int value)//it adds a value to the front of the linked list.
{
    Node* nNode = new Node();
    nNode->setValue(value);
    nNode->setNext(nullptr);
    if(isEmpty())
    {
            m_front = nNode;
    }
    else
    {
            nNode->setNext(m_front);
            m_front = nNode;
    }
    m_size++;

}

bool LinkedList::removeBack()//removes from the back of the linked list
{
        if(isEmpty())
        {
                return (false);
        }
        else if(m_size == 1)
        {
                delete m_front;
                m_front = nullptr;
                m_size--;
                return (true);
        }
        else
        {
                Node* temp = m_front;
                Node* temp2 = m_front;
                while(temp->getNext() != nullptr)
                {
                        temp = temp->getNext();

                }
                while(temp2->getNext() != temp)
                {
                        temp2 = temp2->getNext();
                }
                delete temp;
                temp = nullptr;
                temp2->setNext(nullptr);
                m_size--;
                return (true);

        }
}

bool LinkedList::removeFront()//removes fromm the front of the linked list
{
        if(isEmpty())
        {
                return (false);
        }
        else
        {
                Node* temp = m_front;
                m_front = m_front->getNext();
                delete temp;
                temp = nullptr;
                m_size--;
                return (true);
        }
}

void LinkedList::insert(int x)
{
    bool inList = search(x);
    if(!(inList))
    {
        addBack(x);
    }
}
