/** 
*   @file:minMaxHeap.h
*   @author:Michael Wang
*   @date:10/17/2016
*   Purpose:Header for minMaxHeap. Used to emulate a minMaxHeap.
*/
#ifndef MINMAXHEAP_H
#define MINMAXHEAP_H
class minMaxHeap
{
public:
	minMaxHeap(int x);
            /**
		*  @pre None
		*  @post Creates and initializes a minMaxHeap instance
		*  @return Initialzed minMaxHeap with the given size
		*/
	~minMaxHeap();
            /**
		*  @pre None
		*  @post destructs a minMaxHeap instance
		*  @return destructed minMaxHeap
		*/
	void resetHeap();
        /**
		*  @pre None
		*  @post resets the heap
		*  @return None
		*/
	bool isEmpty();
	        /**
		*  @pre None
		*  @post None
		*  @return true if no values in the heap, otherwise returns false.
		*/
	void insert(int x);
            /**
		*  @pre a value to insert
		*  @post inserts a value into the heap
		*  @return None
		*/
    void deletemin();
            /**
		*  @pre None
		*  @post deletes the minimum value in the heap
		*  @return None
		*/
    void deletemax();
            /**
		*  @pre None
		*  @post deletes the maximum value in the heap
		*  @return None
		*/
    void levelorder();
            /**
		*  @pre None
		*  @post prints the values of the heap in levelorder
		*  @return None
		*/
    void build(int x);
		/**
		*  @pre None
		*  @post inserts the initial values of the heap
		*  @return None
		*/
    void bubbleUp(int x);
    		/**
		*  @pre None
		*  @post gives the heap the correct structure when inserting
		*  @return None
		*/
    void trickleDown(int x);
    		/**
		*  @pre None
		*  @post gives the heap the correct structure after build
		*  @return None
		*/
    int findParent(int x);
			/**
		*  @pre None
		*  @post finds the parent of the node
		*  @return the parent's location
		*/
	int findGrandParent(int x);
			/**
		*  @pre None
		*  @post finds the grand parent of the node
		*  @return the grand parent's location
		*/
	bool hasChildren(int x);
			/**
		*  @pre None
		*  @post returns a boolean depending on if the parent has children
		*  @return true if the parent has children and false otherwise
		*/
	bool hasGrandChildren(int x);
			/**
		*  @pre None
		*  @post returns a boolean depending on if the parent has grand children
		*  @return true if the parent has grand children and false otherwise
		*/
	int smallestChild(int x);
			/**
		*  @pre None
		*  @post finds the smallest value of a parent between the children and grand children
		*  @return the index of the smallest value
		*/
	int largestChild(int x);
			/**
		*  @pre None
		*  @post finds the largest value of a parent between the children and grand children
		*  @return the index of the largest value
		*/
	bool isChild(int x, int y);
			/**
		*  @pre None
		*  @post returns a boolean depending on if the index is a child
		*  @return true if the index is a child and false otherwise
		*/
	bool isGrandChild(int x, int y);
			/**
		*  @pre None
		*  @post returns a boolean depending on if the index is a grand child
		*  @return true if the index is a grand child and false otherwise
		*/
	bool hasParent(int x);
			/**
		*  @pre None
		*  @post returns a boolean depending on if the parent has parent
		*  @return true if the parent has parent and false otherwise
		*/
	bool hasGrandParent(int x);
			/**
		*  @pre None
		*  @post returns a boolean depending on if the parent has grand parent
		*  @return true if the parent has grand parent and false otherwise
		*/
	bool isMinLevel(int x);
			/**
		*  @pre None
		*  @post returns a boolean depending on if the level is a min level
		*  @return true if the level is a min level and false otherwise
		*/
	bool isMaxLevel(int x);
			/**
		*  @pre None
		*  @post returns a boolean depending on if the level is a max level
		*  @return true if the level is a max level and false otherwise
		*/
private:
	void trickleDownMin(int x);
			/**
		*  @pre None
		*  @post gives the heap the correct structure on a min level
		*  @return None
		*/
	void trickleDownMax(int x);
			/**
		*  @pre None
		*  @post gives the heap the correct structure on a max level
		*  @return None
		*/
	void bubbleUpMin(int x);
			/**
		*  @pre None
		*  @post gives the heap the correct structure on a min level
		*  @return None
		*/
	void bubbleUpMax(int x);
			/**
		*  @pre None
		*  @post gives the heap the correct structure on a max level
		*  @return None
		*/

	int heapLevel;
    int heapSize;
    int heapMaxSize;
    int lastPosition;
    int *heap;

};
#endif