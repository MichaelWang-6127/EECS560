/** 
/   @file:Kruskal.h
*   @author:Michael Wang
*   @date:11/16/2016
*   Purpose:THe header file for the Kruskal class
*/

#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <iostream>
#include "SHNode.h"
#include "SkewHeap.h"
#include "Queue.h"

class Kruskal
{
public:
	Kruskal();
	/**
	*  @pre None
	*  @post creates a Kruskal
	*  @return initializes a Kruskal
	*/
	~Kruskal();
	/**
	*  @pre None
	*  @post destructs a Kruskal
	*  @return None
	*/
	void KruskalSolver(int gSize, SkewHeap heap);
	/**
	*  @pre None
	*  @post creates a spanning tree using Kruskal's algorithm
	*  @return None
	*/
	bool cycleMade(int array[], int x, int y);
	/**
	*  @pre a value's coordinate and a set
	*  @post tells if a cycle is created
	*  @return true if a cycle is created and false otherwise
	*/
	void printArray(int array[]);
	/**
	*  @pre an array
	*  @post prints an array given to it
	*  @return None
	*/

private:
	int m_graphSize;

};
#endif