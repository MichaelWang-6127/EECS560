/** 
*   @file:min5Heap.h
*   @author:Michael Wang
*   @date:10/03/2016
*   Purpose:Header for min5Heap. Used to emulate a min5Heap.
*/
#ifndef MIN5HEAP_H
#define MIN5HEAP_H

class min5Heap
{
	public:
            min5Heap(int x);
            /**
		*  @pre None
		*  @post Creates and initializes a min5Heap instance
		*  @return Initialzed min5Heap with the given size
		*/
            ~min5Heap();
            /**
		*  @pre None
		*  @post destructs a min5Heap instance
		*  @return destructed min5Heap
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
		*  @post prints the values of the heap in levelorder
		*  @return None
		*/
            void deletemax();
            /**
		*  @pre None
		*  @post prints the values of the heap in levelorder
		*  @return None
		*/
            void remove(int x);
            /**
		*  @pre a value to remove
		*  @post removes a value from the heap
		*  @return None
		*/
            void levelorder();
            /**
		*  @pre None
		*  @post prints the values of the heap in levelorder
		*  @return None
		*/
			void upHeap();
			/**
		*  @pre None
		*  @post upHeaps the heap to have the correct structure
		*  @return None
		*/
			void build(int x);
		/**
		*  @pre None
		*  @post inserts the initial values of the heap
		*  @return None
		*/
			bool minAtTop();
		/**
		*  @pre None
		*  @post makes the parent value smaller than its children
		*  @return true if the condition is met false otherwise
		*/
			bool inHeap(int x);
		/**
		*  @pre None
		*  @post tells if a value is in the heap
		*  @return true if the value is in the heap and false otherwise
		*/
        private:
        	int heapLevel;
            int heapSize;
            int heapMaxSize;
            int *heap;
            //bool *wasRemoved;
};
#endif
