/** 
*   @file:BinarySearchTree.hpp
*   @author:Michael Wang
*   @date:09/21/2016
*   Purpose:This is the implementation of methods for the BinarySearchTree class
*/
#include <iostream>
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()//constructor
{
    m_root = nullptr;
}

BinarySearchTree::~BinarySearchTree()//destructor
{
    if(m_root != nullptr)
    {
        deleteTree(m_root);
    }
    m_root = nullptr;
}

bool BinarySearchTree::isEmpty()
{
    return (m_root == nullptr);
}

bool BinarySearchTree::insert(int x)
{
    return (insert(x, m_root));
    /*if(search(x) == nullptr)
    {
        return (insert(x, m_root));
    }
    else
    {
        std::cout<< "The value "<< x <<" is already in the tree!\n";
        return false;
    }*/
}

bool BinarySearchTree::remove(int x)
{
    bool inTree = (search(x) != nullptr);
    //std::cout<< "intree:"<< inTree<<"\n";
    while(inTree == true)
    {
        (remove(x, m_root));
        inTree = (search(x) != nullptr);
    }
    /*if(search(x) != nullptr)
    {
        return (remove(x, m_root));
    }
    else
    {
        std::cout<< "The value "<< x <<" is not in the tree!\n";
        return false;
    }*/
}

BSTNode* BinarySearchTree::search(int x)
{
    return (searchTree(x, m_root));  
}

void BinarySearchTree::deletemin()
{
    if(!isEmpty())
    {
        BSTNode* temp1 = m_root;
        if(temp1->getLeft() == nullptr)
        {
            m_root = temp1->getRight();
            delete temp1;
            temp1 = nullptr;
        }
        else
        {
            BSTNode* temp2 = temp1->getLeft();
            while(temp2->getLeft() != nullptr)
            {
                temp1 = temp1->getLeft();
                temp2 = temp2->getLeft();
            }
            if(temp2->getRight() == nullptr)
            {
                delete temp2;
                temp2 = nullptr;
                temp1->setLeft(nullptr);
            }
            else
            {
                temp1->setLeft(temp2->getRight());
                delete temp2;
                temp2 = nullptr;
            }
        }
    }
    else
    {
        std::cout<<"Tree Empty" << "\n";
    }
}

void BinarySearchTree::deletemax()
{
    if(!isEmpty())
    {
        BSTNode* temp1 = m_root;
        if(temp1->getRight() == nullptr)
        {
            m_root = temp1->getLeft();
            delete temp1;
            temp1 = nullptr;
        }
        else
        {
            BSTNode* temp2 = temp1->getRight();
            while(temp2->getRight() != nullptr)
            {
                temp1 = temp1->getRight();
                temp2 = temp2->getRight();
            }
            if(temp2->getLeft() == nullptr)
            {
                delete temp2;
                temp2 = nullptr;
                temp1->setRight(nullptr);
            }
            else
            {
                temp1->setRight(temp2->getLeft());
                delete temp2;
                temp2 = nullptr;
            }
        }
    }
    else
    {
        std::cout<<"Tree Empty" << "\n";
    }
}

void BinarySearchTree::preorder()
{
    if (isEmpty())
	{
		std::cout << "Tree Empty" << "\n";
		return;
	}
	printTree(m_root, 1);
	std::cout << "\n";
}

void BinarySearchTree::inorder()
{
    if (isEmpty())
	{
		std::cout << "Tree Empty" << "\n";
		return;
	}
	printTree(m_root, 2);
	std::cout << "\n";
}

void BinarySearchTree::levelorder()
{
    if (isEmpty())
    {
        std::cout << "Tree Empty" << "\n";
        return;
    }
	//printTree(m_root, order);
    else
    {
        Queue* printQueue = new Queue();
        printQueue->enqueue(m_root);
        BSTNode* temp = nullptr;
        while(!(printQueue->isEmpty()))
        {
            temp = printQueue->dequeue();
            if(temp != nullptr)
            {
                if(temp->getLeft() != nullptr)
                {
                    printQueue->enqueue(temp->getLeft());
                }
                if(temp->getRight() != nullptr)
                {
                    printQueue->enqueue(temp->getRight());
                }
                if(temp != nullptr)
                {
                    std::cout<< temp->getValue() << " ";
                }
            }
        }
            //std::cout<< "I still need to be implemented";
            std::cout << "\n";
        delete printQueue;
        printQueue = nullptr;
    }
}

bool BinarySearchTree::insert(int value, BSTNode* subtree)
{
    
    if(subtree == nullptr)
    {
    	subtree = new BSTNode();
    	subtree->setValue(value);
    	if (m_root == nullptr)
    	{
    		m_root = subtree;
    	}
	    return (true);
    }
    else if(value >= subtree->getValue())
    {
            if(subtree->getRight() == nullptr)
            {
                    subtree->setRight(new BSTNode());
                    subtree->getRight()->setValue(value);
                    return (true);
            }
            else
            {
                    return insert(value, subtree->getRight());
            }
    }
    else if(value < subtree->getValue())
    {
        if(subtree->getLeft() == nullptr)
        {
            subtree->setLeft(new BSTNode());
            subtree->getLeft()->setValue(value);
            return (true);
        }
        else
        {
            return insert(value, subtree->getLeft());
        }
    }
    else
    {	
        return (false);
    }
}

bool BinarySearchTree::remove(int value, BSTNode* parent)
{
    if(parent->getValue() == value)
    {
        if((parent->getLeft() == nullptr)&&(parent->getRight() == nullptr))
        {
            if(parent == m_root)
            {
                delete m_root;
                m_root = nullptr;
                return true;
            }
            else
            {
                return (deleteOne(value, m_root));
            }
        }
        else if((parent->getRight() == nullptr)&&(parent->getLeft() != nullptr))
        {
            BSTNode* temp = parent;
            parent = parent->getLeft();
            delete temp;
            temp = nullptr;
            return true;
        }
        else
        {
            BSTNode* temp = smallestRight(parent->getRight());
            int smallestValue = temp->getValue();
            parent->setValue(smallestValue);

            BSTNode* temp2 = parent->getRight();
            if(temp2->getValue() == smallestValue)
            {
                parent->setRight(temp->getRight());
            }
            else
            {
                while(temp2->getLeft()->getValue() != smallestValue)
                {
                    temp2 = temp2->getLeft();
                }
                temp2->setLeft(temp->getRight());
            }
            delete temp;
            temp = nullptr;
            return true;
        }
    }
    else
    {
        if(parent->getValue() > value)
        {
            return remove(value, parent->getLeft());
        }
        else if(parent->getValue() <= value)
        {
            return remove(value, parent->getRight());
        }
    }
}

bool BinarySearchTree::deleteOne(int value, BSTNode* parent)
{
        BSTNode* temp = search(value);
        if(parent->getValue() <= value)
        {
            if(parent->getRight() != nullptr)
            {
                if(parent->getRight() == temp)
                {
                    delete temp;
                    temp = nullptr;
                    parent->setRight(nullptr);
                    return true;
                }
                else
                {
                    return (deleteOne(value, parent->getRight()));
                }
            }
            else
            {
                return false;
            }

        }
        else if(parent->getValue() > value)
        {
            if(parent->getLeft() != nullptr)
            {
                if(parent->getLeft() == temp)
                {
                    delete temp;
                    temp = nullptr;
                    parent->setLeft(nullptr);
                    return true;
                }
                else
                {
                    return (deleteOne(value, parent->getLeft()));
                }
            }
            else
            {
                return false;
            }


        }
}

void BinarySearchTree::deleteTree(BSTNode* subtree)
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

void BinarySearchTree::printTree(BSTNode* subtree, int order)
{
    switch (order)
	{
	case 1:
		std::cout << subtree->getValue() << " ";
		if (subtree->getLeft() != nullptr)
		{
			printTree(subtree->getLeft(), order);
		}
		if (subtree->getRight() != nullptr)
		{
			printTree(subtree->getRight(), order);
		}
	break;
	case 2:
		if (subtree->getLeft() != nullptr)
		{
			printTree(subtree->getLeft(), order);
		}
		std::cout << subtree->getValue() << " ";
		if (subtree->getRight() != nullptr)
		{
			printTree(subtree->getRight(), order);
		}
	break;
	case 3:
		if (subtree->getLeft() != nullptr)
		{
			printTree(subtree->getLeft(), order);
		}
		if (subtree->getRight() != nullptr)
		{
			printTree(subtree->getRight(), order);
		}
		std::cout << subtree->getValue() << " ";
	break;
	default:
	break;
	}
}

BSTNode* BinarySearchTree::searchTree(int value, BSTNode* subtree)
{
    if(subtree == nullptr)
    {
        //std::cout<<"search part 1";
        return nullptr;
    }
    else
    {
        if(subtree->getValue() == value)
        {
            return subtree;
        }
        else if ((subtree->getLeft() == nullptr)&&(subtree->getRight() == nullptr))
        {
            //std::cout <<"search part 2";
            return nullptr;
        }
        else
        {
            if(subtree->getValue() > value)
            {
                return searchTree(value, subtree->getLeft());
            }
            if(subtree->getValue() <= value)
            {
                return searchTree(value, subtree->getRight());
            }
        }
    }
    //std::cout<<"outside of the block";
}

BSTNode* BinarySearchTree::smallestRight(BSTNode* subtree)
{
    //subtree = subtree->getRight();
    if(subtree->getLeft() != nullptr)
    {
        return smallestRight(subtree->getLeft());
    }
    else
    {
        return (subtree);
    }
}
