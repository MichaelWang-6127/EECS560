/** 
*   @file:LinkedList.cpp
*   @author:Michael Wang
*   @date:09/03/2016
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

LinkedList::LinkedList(const LinkedList &copy)//creates a copy of a linked list with 2 variables
{
    Node* p1 = nullptr;
    Node* p2 = nullptr;
    if(copy.m_front == nullptr)
    {
        this->m_front = nullptr;
    }
    else
    {
        this->m_front = new Node;
        this->m_front->setValue(copy.m_front->getValue());
        //this.m_front.setNext(copy.getNext());
        p1 = m_front;
        p2 = copy.m_front->getNext();
        while(p2 != nullptr)
        {
            Node* p = new Node;
            p1->setNext(p);
            p1 = p1->getNext();
            p1->setValue(p2->getValue());
            p2 = p2->getNext();
        }
        p1->setNext(nullptr);
    }
    this->m_size = copy.m_size;
    //m_front = copy.m_front;
    //m_size = copy.m_size; 
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
                m_front = m_front->getNext();
                delete temp;
                temp = nullptr;
                m_size--;
                return (true);
        }
}

void LinkedList::insert(int x)//inserts a value to the end of the list if the value is not in the list
{
    bool inList = search(x);
    if(!(inList))
    {
        addBack(x);
    }
}

void LinkedList::erase(int x)//deletes a value from the list if it is in the list
{
    bool inList = search(x);
    while(inList)
    {
        if(m_front->getValue() == x)
        {
            removeFront();
        }
        else
        {
            Node* temp = m_front;
            Node* np = temp->getNext();
            while(np != nullptr)
            {
                if(np->getValue() == x)
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
        inList = search(x);
    }
}

void LinkedList::reverse()//splits the list into head and body and calls reverse(Node* head, Node* body)
{
    //if(list.m_size > 1)
    //{
        std::cout << "Hey ready to reverse the list?" << endl;
        reverseRecurse(m_front);
        std::cout << "Done with the reverse?" << endl;
        return;
    //}
}

void LinkedList::reverseRecurse(Node* front)//reverses the list
{

    //std::cout << "Hey nice to meet you I am " << front->getValue() << endl;
    if(front == nullptr)
    {
        //std::cout << "I am null, how the hell did you get hDere?" << endl;
        return;
    }
    if(front->getNext() == nullptr)
    {
        //std::cout << "Hi, I am " << front->getValue() << " my next guy is nullptr, moving m_front to me." << endl;
        m_front = front;
        return;
    }
    reverseRecurse(front->getNext());
    //std::cout << "Welcome back I am " << front->getValue() << endl;
    //std::cout << "Setting " << front->getNext()->getValue() << " to me." << endl;
    front->getNext()->setNext(front);
    //std::cout << "Setting my next to nullptr." << endl;
    front->setNext(nullptr);
}

void LinkedList::concatenate(LinkedList list2)//adds the value from one list to another list
{
    if(list2.m_size > 0)
    {
        //LinkedList list2copy = LinkedList(list2);
        concatenateRecurse(m_front, list2.m_front);
    }
    //m_size = m_size + list2.m_size;
    //free (list2);
}

void LinkedList::concatenateRecurse(Node* list1, Node* list2)//adds the value from one list to another list
{
    if(list1->getNext() != nullptr)
    {
        list1 = list1->getNext();
        concatenateRecurse(list1, list2);
    }
    else
    {
        list1->setNext(list2);
    }
    //delete list2;
}

