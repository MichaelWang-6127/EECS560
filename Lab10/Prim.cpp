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

void Prim::PrimSolver(int gSize, SkewHeap heap, int array[], int xArray[], int yArray[], int xArray2[], int yArray2[])
{
	m_graphSize = gSize;
	int visitedArray[gSize];
	int setSize = 1;
	int vertexNumber = 0;
	int arraySize = 0;
	Queue queue1;
	SHNode* temp = nullptr;
	int xCor;
	int yCor;

	for(int i=0; i<gSize; i++)
	{
		visitedArray[i] = -1;
		arraySize += i;
	}
	visitedArray[0] = 1;

	while((!heap.isEmpty()) && (setSize != m_graphSize))
	{
		//std::cout<<"in the do while loop!!!\n";
		temp = heap.deleteminPop();
		while((temp->getValue() == 0))
		{
			if(temp != nullptr)
			{
				delete temp;
				temp = heap.deleteminPop();
			}
		}
		xCor = temp->getX();
		yCor = temp->getY();

		//std::cout<<"xCor:"<<xCor<<" yCor:"<<yCor<<"\n";

		if(visitedArray[yCor] == -1)
		{
			visitedArray[yCor] = 1;
			vertexNumber = yCor;
			setSize++;
			queue1.enqueue(temp);
		}

		for(int i=0; i<arraySize; i++)
		{
			if(xArray[i] == vertexNumber)
			{
				if(visitedArray[yArray[i]] == -1)
				{
					heap.insert(array[i], xArray[i], yArray[i]);
				}
			}
			if(xArray2[i] == vertexNumber)
			{
				if(visitedArray[yArray2[i]] == -1)
				{
					heap.insert(array[i], xArray2[i], yArray2[i]);
					//heap.insert(array[i], yArray2[i], xArray2[i]);
				}
			}
		}

	}

	std::cout<<"Prim:";
	while(!(queue1.isEmpty()))
	{
		temp = queue1.dequeue();
		std::cout<<" ("<< temp->getX() <<", "<< temp->getY() <<")";
		delete temp;
		temp = nullptr;
	}
	std::cout<<"\n";

	//delete queue1;
	//queue1 = nullptr;

	/*if(!heap.isEmpty())
	{
		heap.~SkewHeap();
	}*/
}

void Prim::setArray(int array[])
{
	m_array = array;
}

void Prim::setXArray(int array[])
{
	m_xArray = array;
}

void Prim::setYArray(int array[])
{
	m_yArray = array;
}

void Prim::printArray(int numElements)
{
	for(int i=0; i<numElements; i++)
	{
		std::cout<<m_array[i]<<" ";
	}
	std::cout<<"\n";
}

void Prim::printXArray(int numElements)
{
	for(int i=0; i<numElements; i++)
	{
		std::cout<<m_xArray[i]<<" ";
	}
	std::cout<<"\n";
}

void Prim::printYArray(int numElements)
{
	for(int i=0; i<numElements; i++)
	{
		std::cout<<m_yArray[i]<<" ";
	}
	std::cout<<"\n";
}
