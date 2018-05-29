/** 
/   @file:DisjointSet.h
*   @author:Michael Wang
*   @date:11/16/2016
*   Purpose:THe header file for the DisjointSet class
*/

#ifndef DISJOINTSET_H
#define DISJOINTSET_H

class DisjointSet
{
public:
	DisjointSet();
	/**
	*  @pre None
	*  @post creates a disjointSet
	*  @return initializes a disjointSet with 2 variables
	*/
	int getSize();
	/**
	*  @pre None
	*  @post tells the size of the set array
	*  @return the size of the set array
	*/
	int getSetSize();
	/**
	*  @pre None
	*  @post tells the size of the set
	*  @return the size of the set
	*/
	void setPointer(int array[]);
	/**
	*  @pre takes in an int array
	*  @post sets the setPointer to a given array
	*  @return None
	*/
	bool changeSet(int value, int index);
	/**
	*  @pre takes in an 2 integers
	*  @post changes the array based on the two integers
	*  @return true if the array was changed false otherwise
	*/

private:
	int m_size;
	int m_setSize;
	int* m_setPointer;

};
#endif
