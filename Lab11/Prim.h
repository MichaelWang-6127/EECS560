/** 
/   @file:Prim.h
*   @author:Michael Wang
*   @date:11/16/2016
*   Purpose:THe header file for the Prim class
*/

#ifndef PRIM_H
#define PRIM_H

#include <iostream>
#include "LinkedList.h"
#include "SHNode.h"
#include "SkewHeap.h"
#include "Queue.h"

class Prim
{
public:
	Prim();
	/**
	*  @pre None
	*  @post creates a Prim
	*  @return initializes a Prim
	*/
	void PrimSolver(int gSize, LinkedList array[]);
	/**
	*  @pre None
	*  @post creates a spanning tree using Prim's algorithm
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
	bool inList(SHNode* pointer, int x, int y);
	/**
	*  @pre a coordinate and a pointer
	*  @post None
	*  @return true if the point is in the list and false otherwise
	*/
	void addToList(SHNode* pointer, int x, int y, int value);
	/**
	*  @pre a point and a pointer
	*  @post adds the point to the list
	*  @return None
	*/


private:
	int m_graphSize;
	int* m_array;
	int* m_xArray;
	int* m_yArray;

};
#endif