/** 
/   @file:Kruskal.h
*   @author:Michael Wang
*   @date:11/16/2016
*   Purpose:THe header file for the Kruskal class
*/

#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <iostream>
#include "LinkedList.h"
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
	void KruskalSolver(int gSize, LinkedList array[]);
	/**
	*  @pre None
	*  @post creates a spanning tree using Kruskal's algorithm
	*  @return None
	*/
	bool hasCycle(LinkedList array[], int x, int y, int gSize);
	/**
	*  @pre a set, a coordinate and a graph size
	*  @post None
	*  @return true if there is a cycle and false if there is none
	*/
	bool recCycle(bool bArray[], LinkedList array[], int x, int y, int gSize, int start, int parent);
	/**
	*  @pre a set, a coordinate and a graph size
	*  @post None
	*  @return true if there is a cycle and false if there is none
	*/


private:
	int m_graphSize;

};
#endif