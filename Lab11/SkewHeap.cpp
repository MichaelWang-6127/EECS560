/** 
*   @file:SkewHeap.hpp
*   @author:Michael Wang
*   @date:11/16/2016
*   Purpose:This is the implementation of methods for the SkewHeap class
*/
#include <iostream>
#include "SkewHeap.h"

SkewHeap::SkewHeap()//constructor
{
    m_root = nullptr;
    m_leftLevel = 0;
    m_rightLevel = 0;
}

SkewHeap::~SkewHeap()//destructor
{
    if(m_root != nullptr)
    {
        deleteTree(m_root);
    }
    m_root = nullptr;
}

bool SkewHeap::isEmpty()
{
    return (m_root == nullptr);
}

void SkewHeap::insert(int x)
{
    SHNode* temp = new SHNode();
    temp->setValue(x);
    temp->setX(0);
    temp->setY(0);
    m_root = merge(m_root, temp);
    return;
}

void SkewHeap::insert(int x, int xCor, int yCor)
{
    SHNode* temp = new SHNode();
    temp->setValue(x);
    temp->setX(xCor);
    temp->setY(yCor);
    m_root = merge(m_root, temp);
    return;
}

void SkewHeap::deletemin()
{
    if(!isEmpty())
    {
        SHNode* temp1 = m_root;
        SHNode* tempLeft = temp1->getLeft();
        SHNode* tempRight = temp1->getRight();
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

SHNode* SkewHeap::deleteminPop()
{
    if(!isEmpty())
    {
        SHNode* temp1 = m_root;
        SHNode* tempLeft = temp1->getLeft();
        SHNode* tempRight = temp1->getRight();
        m_root = merge(tempLeft, tempRight);

        temp1->setLeft(nullptr);
        temp1->setRight(nullptr);

        return temp1;

        /*SHNode* temp2 = new SHNode();
        temp2->setValue(temp1->getValue());
        temp2->setX(temp1->getX());
        temp2->setY(temp1->getY());

        delete temp1;
        temp1 = nullptr;
        return temp2;*/
    }
    else
    {
        std::cout<<"Tree Empty" << "\n";
        return (nullptr);
    }
}

void SkewHeap::preorder()
{
    if (isEmpty())
	{
		std::cout << "Tree Empty" << "\n";
		return;
	}
	printTree(m_root, 1);
	std::cout << "\n";
}

void SkewHeap::inorder()
{
    if (isEmpty())
	{
		std::cout << "Tree Empty" << "\n";
		return;
	}
	printTree(m_root, 2);
	std::cout << "\n";
}

void SkewHeap::levelorder()
{
    if (isEmpty())
    {
        std::cout << "Tree Empty" << "\n";
        return;
    }
    else
    {
        Queue* currentLevel = new Queue();
        Queue* nextLevel = new Queue();
        currentLevel->enqueue(m_root);
        SHNode* temp = nullptr;
        SHNode* temp2 = nullptr;
        while(!(currentLevel->isEmpty()))
        {
            temp = currentLevel->dequeue();
            if(temp != nullptr)
            {
                if(temp != nullptr)
                {
                    std::cout<< temp->getValue() << " ";
                    std::cout << "("<< temp->getX() << ", "<< temp->getY() << ") ";
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
                Queue* temp = currentLevel;
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

SHNode* SkewHeap::merge(SHNode* subtreeLeft, SHNode* subtreeRight)
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
        SHNode* temp = subtreeLeft;
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
        SHNode* temp2 = subtreeLeft->getLeft();
        subtreeLeft->setLeft(subtreeLeft->getRight());
        subtreeLeft->setRight(temp2);
    }
    return subtreeLeft;
}

void SkewHeap::deleteTree(SHNode* subtree)
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

void SkewHeap::printTree(SHNode* subtree, int order)
{
    if(order == 1)
    {
        std::cout << subtree->getValue() << " ";
        std::cout << "("<< subtree->getX() << ", "<< subtree->getY() << ") ";
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
        std::cout << "("<< subtree->getX() << ", "<< subtree->getY() << ") ";
        if (subtree->getRight() != nullptr)
        {
            printTree(subtree->getRight(), order);
        }
    }
}