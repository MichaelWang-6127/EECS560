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

void Kruskal::KruskalSolver(int gSize, SkewHeap heap)
{
	m_graphSize = gSize;
	int array [gSize];
	int setSize = 0;
	Queue queue1;
	SHNode* temp = nullptr;
	int xCor;
	int yCor;

	for(int i=0; i<gSize; i++)
	{
		array[i] = -1;
	}

	while((!(heap.isEmpty())) && (setSize != (gSize-1)))
	{
		temp = heap.deleteminPop();
		xCor = temp->getX();
		yCor = temp->getY();
		//printArray(array);
		//std::cout<<"xCor:"<<xCor<<" yCor:"<<yCor<<"\n";
		if((array[xCor] != yCor))
		{
			//std::cout<<"xCor:"<<xCor<<" yCor:"<<yCor<<"\n";
			if(!cycleMade(array, xCor, yCor))
			{
				if(array[yCor] != -1)
				{
					int value = array[yCor];
					array[xCor] = value;
					array[yCor] = xCor;
					setSize++;
					queue1.enqueue(temp);
				}
				else
				{
					array[yCor] = xCor;
					setSize++;
					queue1.enqueue(temp);
				}
			}
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
		//std::cout<<" value:"<<temp->getValue();
		std::cout<<" ("<< temp->getX() <<", "<< temp->getY() <<")";
		if(temp != nullptr)
		{
			delete temp;
			temp = nullptr;
		}
	}
	std::cout<<"\n";

	if((heap.isEmpty()) && (setSize != (gSize-1)))
	{
		std::cout<<"NO SOLUTION!!!!!\n";
	}

	//delete queue1;
	//queue1 = nullptr;

	if(!heap.isEmpty())
	{
		heap.~SkewHeap();
	}
}

bool Kruskal::cycleMade(int array[], int x, int y)
{
	bool cycleFound = false;
	int xCor = x;
	while((array[xCor] != -1))
	{
		xCor = array[xCor];
		if(y == xCor)
		{
			cycleFound = true;
		}
	}
	int yCor = y;
	while((array[yCor] != -1))
	{
		yCor = array[yCor];
		if(x == yCor)
		{
			cycleFound = true;
		}
	}
	return (cycleFound);
}

void Kruskal::printArray(int array[])
{
	for(int i=0; i<m_graphSize; i++)
	{
		std::cout<<array[i]<<" ";
	}
	std::cout<<"\n";
}