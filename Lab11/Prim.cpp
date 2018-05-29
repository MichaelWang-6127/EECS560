/** 
*   @file:Prim.cpp
*   @author:Michael Wang
*   @date:11/16/2016
*   Purpose:The definition for the methods of the Prim class
*/
#include "Prim.h"

Prim::Prim()
{
	
}

void Prim::PrimSolver(int gSize, LinkedList array[])
{
	int visitedArray[gSize];
	int setSize = 1;
	int vertexNumber = 0;
	Queue queue1;
	SkewHeap heap1;
	SHNode* temp = nullptr;
	LinkedList lPointer;
	int xCor;
	int yCor;
	int totalCost = 0;
	bool noSolution = false;
	LinkedList list1 [gSize];
	SHNode* solutionList = nullptr;

	for(int i=0; i<gSize; i++)
	{
		visitedArray[i] = -1;
	}
	temp = array[0].getFront();
	while(temp != nullptr)
	{
		if(temp->getValue() != -1)
		{
			heap1.insert(temp->getValue(), temp->getX(), temp->getY());
		}
		temp = temp->getNext();
	}
	temp = array[0].getFront();
	while(temp != nullptr)
	{
		array[0].removeFront();
		temp = array[0].getFront();
	}

	//heap1.preorder();

	while((!(heap1.isEmpty())) && (setSize != gSize))
	{
		temp = heap1.deleteminPop();
		xCor = temp->getX();
		yCor = temp->getY();

		/*if(solutionList == nullptr)
		{
			solutionList = temp;
		}*/

		//if(!inList(solutionList, xCor, yCor))
		/*if(!hasCycle(list1, xCor, yCor, gSize))
		{*/
			//addToList(solutionList, xCor, yCor, temp->getValue());
			setSize++;
			queue1.enqueue(temp);
			list1[xCor].addFront(temp->getValue(), xCor, yCor);
			list1[yCor].addFront(temp->getValue(), yCor, xCor);
			for(int i = 0; i<gSize; i++)
			{
				temp = array[i].getFront();
				while(temp != nullptr)
				{
					if((temp->getValue() != -1))
					{
						if((temp->getX() == yCor) || (temp->getY() == yCor) || (temp->getX() == xCor) || (temp->getY() == xCor))
						{
							heap1.insert(temp->getValue(), temp->getX(), temp->getY());
							array[i].erase(temp->getX(), temp->getY(), temp->getValue());
						}
					}
					temp = temp->getNext();
				}
			}
		/*}
		else
		{
			delete temp;
			temp = nullptr;
		}*/
	}

	std::cout<<"Prim:";

	if(noSolution)
	{
		std::cout<<"NO SOLUTION!!!\n";
		return;
	}

	while(!(queue1.isEmpty()))
	{
		temp = queue1.dequeue();
		//std::cout<<" ("<< temp->getX() <<", "<< temp->getY() <<")";
		//std::cout<<temp->getValue();
		if(temp != nullptr)
		{
			totalCost += temp->getValue();
			delete temp;
			temp = nullptr;
		}
	}
	std::cout<<"Total cost: "<<totalCost<<"";
	std::cout<<"\n";
}

bool Prim::hasCycle(LinkedList array[], int x, int y, int gSize)
{
	bool list2 [gSize];
	for(int i=0; i<gSize; i++)
	{
		list2[i] = false;
	}

	if(recCycle(list2, array, x, y, gSize, x, x))
	{
		return true;
	}
	return false;
}

bool Prim::recCycle(bool bArray[], LinkedList array[], int x, int y, int gSize, int start, int parent)
{
	SHNode* tmpPtr1 = nullptr;
	int newValue;

	bArray[start] = true;

	tmpPtr1 = array[start].getFront();

	while(tmpPtr1 != nullptr)
	{
		newValue = tmpPtr1->getY();
		if(newValue == y)
		{
			return true;
		}
		else if(!bArray[newValue])
		{
			if(recCycle(bArray, array, x, y, gSize, newValue, x))
			{
				return true;
			}
		}
		tmpPtr1 = tmpPtr1->getNext();
	}
	return false;
}

bool Prim::inList(SHNode* pointer, int x, int y)
{
	if(pointer == nullptr)
	{
		return false;
	}
	while(pointer != nullptr)
	{
		if((pointer->getX() == x) && (pointer->getY() == y))
		{
			return true;
		}
		pointer = pointer->getNext();
	}
	return false;
}

void Prim::addToList(SHNode* pointer, int x, int y, int value)
{
	SHNode* temp = new SHNode();
	temp->setX(x);
	temp->setY(y);
	temp->setValue(value);
	if(pointer == nullptr)
	{
		pointer = temp;
	}
	while(pointer != nullptr)
	{
		if(pointer->getNext() == nullptr)
		{
			pointer->setNext(temp);
		}
		pointer = pointer->getNext();
	}
}