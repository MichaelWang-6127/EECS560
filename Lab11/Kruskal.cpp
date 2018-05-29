/** 
*   @file:Kruskal.cpp
*   @author:Michael Wang
*   @date:11/16/2016
*   Purpose:The definition for the methods of the Kruskal class
*/
#include "Kruskal.h"

Kruskal::Kruskal()
{
	
}

Kruskal::~Kruskal()
{
	
}

void Kruskal::KruskalSolver(int gSize, LinkedList array[])
{
	int visitedArray[gSize];
	int setSize = 0;
	Queue queue1;
	SkewHeap heap1;
	SHNode* temp = nullptr;
	LinkedList lPointer;
	int xCor;
	int yCor;
	int totalCost = 0;
	LinkedList list1 [gSize];

	for(int i=0; i<gSize; i++)
	{
		visitedArray[i] = -1;
	}

	for(int i = 0; i<gSize; i++)
	{
		temp = array[i].getFront();
		while(temp != nullptr)
		{
			if(temp->getValue() != -1)
			{
				heap1.insert(temp->getValue(), temp->getX(), temp->getY());
			}
			temp = temp->getNext();
		}
	}

	while((!(heap1.isEmpty())) && (setSize != (gSize-1)))
	{
		temp = heap1.deleteminPop();
		xCor = temp->getX();
		yCor = temp->getY();

		if(!hasCycle(list1, xCor, yCor, gSize))
		{
			setSize++;
			queue1.enqueue(temp);
			list1[xCor].addFront(temp->getValue(), xCor, yCor);
			list1[yCor].addFront(temp->getValue(), yCor, xCor);
		}
		else
		{
			delete temp;
			temp = nullptr;
		}
	}

	std::cout<<"Kruskal:";
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

	if((heap1.isEmpty()) && (setSize != (gSize-1)))
	{
		std::cout<<"NO SOLUTION!!!!!\n";
	}

}

bool Kruskal::hasCycle(LinkedList array[], int x, int y, int gSize)
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

bool Kruskal::recCycle(bool bArray[], LinkedList array[], int x, int y, int gSize, int start, int parent)
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