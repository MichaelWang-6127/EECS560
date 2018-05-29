/** 
*   @file:DisjointSet.cpp
*   @author:Michael Wang
*   @date:11/16/2016
*   Purpose:The definition for the methods of the DisjointSet class
*/
#include "DisjointSet.h"

DisjointSet::DisjointSet()
{
	m_size = 0;
	m_setSize = 0;
	int* m_setPointer = nullptr;
}

int DisjointSet::getSize()
{
	return m_size;
}

int DisjointSet::getSetSize()
{
	return m_setSize;
}

void DisjointSet::setPointer(int array[])
{
	m_setPointer = array;
}

bool DisjointSet::changeSet(int value, int index)
{
	if(m_setPointer != nullptr)
	{
		if(m_setPointer[index] != -1)
		{
			m_setPointer[index] = value;
			m_setSize++;
			return true;
		}
		return false;
	}
	return false;
}