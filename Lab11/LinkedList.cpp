/** 
*   @file:LinkedList.cpp
*   @author:Michael Wang
*   @date:11/16/2016
*   Purpose:The definition for the methods of the LinkedList class
*/
#include "LinkedList.h"

LinkedList::LinkedList()
{
    m_front = nullptr;
    m_size = 0; 
}

LinkedList::~LinkedList()//deletes the linked list that is created
{
    SHNode* temp = m_front;
    while(!isEmpty())
    {
        removeFront();
    }
    temp = nullptr;
}

SHNode* LinkedList::getFront() const//gets the front pointer of the list
{
    return (m_front);
}

bool LinkedList::isEmpty()//checks to see if the linked list is empty.
{
	return(m_size == 0);
}
	
int LinkedList::size() const//returns the size of the linked list
{
	return(m_size);
}

void LinkedList::addFront(int value, int xCor, int yCor)//it adds a value to the front of the linked list.
{
    SHNode* nNode = new SHNode();
    nNode->setValue(value);
    nNode->setX(xCor);
    nNode->setY(yCor);
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

bool LinkedList::removeFront()//removes fromm the front of the linked list
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
                SHNode* temp = m_front;
                m_front = m_front->getNext();
                delete temp;
                temp = nullptr;
                m_size--;
                return (true);
        }
}

void LinkedList::erase(int x, int y, int value)//deletes a value from the list if it is in the list
{
    bool inList = search(value, x, y);
    while(inList)
    {
        if((m_front->getValue() == value) && (m_front->getX()) && (m_front->getY() == y))
        {
            removeFront();
        }
        else
        {
            SHNode* temp = m_front;
            SHNode* np = temp->getNext();
            while(np != nullptr)
            {
                if((np->getValue() == value) && (np->getX() == x) && (np->getY() == y))
                {
                    temp->setNext(np->getNext());
                    delete np;
                    m_size--;
                    temp = nullptr;
                    np = nullptr;
                }
                else
                {
                    temp = temp->getNext();
                    np = np->getNext();
                }
            }
        }
        inList = search(value, x, y);
    }
}

bool LinkedList::search(int value, int x, int y) const//searches for an input to see if it is in the linked list.
{
    bool bFound = false;
    //cout<<"Searching for " << value <<"...\n";
    SHNode* np = m_front;
    while(np != nullptr)
    {
        if((np->getValue() == value) && (np->getX() == x) && (np->getY() == y))
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