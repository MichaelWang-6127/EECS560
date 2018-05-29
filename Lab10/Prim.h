/** 
/   @file:Prim.h
*   @author:Michael Wang
*   @date:11/16/2016
*   Purpose:THe header file for the Prim class
*/

#ifndef PRIM_H
#define PRIM_H

#include <iostream>
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
	void PrimSolver(int gSize, SkewHeap heap, int array[], int xArray[], int yArray[], int xArray2[], int yArray2[]);
	/**
	*  @pre None
	*  @post creates a spanning tree using Prim's algorithm
	*  @return None
	*/
	void setArray(int array[]);
	/**
	*  @pre an array
	*  @post sets the array to the given input
	*  @return None
	*/
	void setXArray(int array[]);
	/**
	*  @pre an array
	*  @post sets the xArray to the given input
	*  @return None
	*/
	void setYArray(int array[]);
	/**
	*  @pre an array
	*  @post sets the yArray to the given input
	*  @return None
	*/
	void printArray(int numElements);
	/**
	*  @pre number of elements in the array
	*  @post print m_array;
	*  @return None
	*/
	void printXArray(int numElements);
	/**
	*  @pre number of elements in the array
	*  @post print m_xArray;
	*  @return None
	*/
	void printYArray(int numElements);
	/**
	*  @pre number of elements in the array
	*  @post print m_yArray;
	*  @return None
	*/


private:
	int m_graphSize;
	int* m_array;
	int* m_xArray;
	int* m_yArray;

};
#endif