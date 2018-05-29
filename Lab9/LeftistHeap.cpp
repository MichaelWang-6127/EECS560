/** 
*   @file:LeftistHeap.hpp
*   @author:Michael Wang
*   @date:11/01/2016
*   Purpose:This is the implementation of methods for the LeftistHeap class
*/
#include <iostream>
#include <cmath>
#include "LeftistHeap.h"

LeftistHeap::LeftistHeap()//constructor
{
    m_root = nullptr;
}

LeftistHeap::~LeftistHeap()//destructor
{
    if(m_root != nullptr)
    {
        deleteTree(m_root);
    }
    m_root = nullptr;
}

bool LeftistHeap::isEmpty()
{
    return (m_root == nullptr);
}

void LeftistHeap::insert(int x)
{
    LHNode* temp = new LHNode();
    temp->setValue(x);
    m_root = merge(m_root, temp);
    return;
}

void LeftistHeap::deletemin()
{
    if(!isEmpty())
    {
        LHNode* temp1 = m_root;
        LHNode* tempLeft = temp1->getLeft();
        LHNode* tempRight = temp1->getRight();
        m_root = merge(tempLeft, tempRight);
        delete temp1;
        temp1 = nullptr;
        return;
    }
    else
    {
        std::cout<<"Tree Empty" << "\n";
        return;
    }
}

void LeftistHeap::preorder()
{
    if (isEmpty())
	{
		std::cout << "Tree Empty" << "\n";
		return;
	}
	printTree(m_root, 1);
	std::cout << "\n";
}

void LeftistHeap::inorder()
{
    if (isEmpty())
	{
		std::cout << "Tree Empty" << "\n";
		return;
	}
	printTree(m_root, 2);
	std::cout << "\n";
}

void LeftistHeap::levelorder()
{
    if (isEmpty())
    {
        std::cout << "Tree Empty" << "\n";
        return;
    }
    else
    {
        LHQueue* currentLevel = new LHQueue();
        LHQueue* nextLevel = new LHQueue();
        currentLevel->enqueue(m_root);
        LHNode* temp = nullptr;
        LHNode* temp2 = nullptr;
        while(!(currentLevel->isEmpty()))
        {
            temp = currentLevel->dequeue();
            if(temp != nullptr)
            {
                if(temp != nullptr)
                {
                    std::cout<< temp->getValue() << " ";
                }
                if(temp->getLeft() != nullptr)
                {
                    nextLevel->enqueue(temp->getLeft());
                }
                if(temp->getRight() != nullptr)
                {
                    nextLevel->enqueue(temp->getRight());
                }
            }
            if(currentLevel->isEmpty())
            {
                std::cout<<"\n";
                LHQueue* temp = currentLevel;
                currentLevel = nextLevel;
                nextLevel = temp;
                temp = nullptr;
            }
        }
            //std::cout << "\n";
        delete currentLevel;
        currentLevel = nullptr;
        delete nextLevel;
        nextLevel = nullptr;
    }
}

void LeftistHeap::deleteTree(LHNode* subtree)
{
    if(subtree != nullptr)
    {
        if(subtree->getLeft() != nullptr)
        {
            deleteTree(subtree->getLeft());
        }
        if(subtree->getRight() != nullptr)
        {
            deleteTree(subtree->getRight());
        }
        delete subtree;
        subtree = nullptr;
    }
}

LHNode* LeftistHeap::merge(LHNode* subtreeLeft, LHNode* subtreeRight)
{
    if(subtreeLeft == nullptr)
    {
        return subtreeRight;
    }
    if(subtreeRight == nullptr)
    {
        return subtreeLeft;
    }

    if(subtreeLeft->getValue() > subtreeRight->getValue())
    {
        LHNode* temp = subtreeLeft;
        subtreeLeft = subtreeRight;
        subtreeRight = temp;
    }

    subtreeLeft->setRight(merge(subtreeLeft->getRight(), subtreeRight));

    if(subtreeLeft->getLeft() == nullptr)
    {
        subtreeLeft->setLeft(subtreeLeft->getRight());
        subtreeLeft->setRight(nullptr);
    }
    else
    {
        if((subtreeLeft->getLeft()->getRank())<(subtreeLeft->getRight()->getRank()))
        {
            LHNode* temp2 = subtreeLeft->getLeft();
            subtreeLeft->setLeft(subtreeLeft->getRight());
            subtreeLeft->setRight(temp2);
        }
        subtreeLeft->setRank((subtreeLeft->getRight()->getRank())+1);
    }
    return subtreeLeft;
}

void LeftistHeap::printTree(LHNode* subtree, int order)
{
    if(order == 1)
    {
        std::cout << subtree->getValue() << " ";
        if (subtree->getLeft() != nullptr)
        {
            printTree(subtree->getLeft(), order);
        }
        if (subtree->getRight() != nullptr)
        {
            printTree(subtree->getRight(), order);
        }
    }
	else if(order == 2)
    {
		if (subtree->getLeft() != nullptr)
        {
            printTree(subtree->getLeft(), order);
        }
        std::cout << subtree->getValue() << " ";
        if (subtree->getRight() != nullptr)
        {
            printTree(subtree->getRight(), order);
        }
    }
}