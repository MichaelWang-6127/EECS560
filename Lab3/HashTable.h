/** 
*   @file:HashTable.h
*   @author:Michael Wang
*   @date:09/16/2016
*   Purpose:Header for HashTable. Used to emulate a HashTable.
*/
#ifndef HASTABLE_H
#define HASTABLE_H
#include "LinkedList.h"

class HashTable
{
	public:
            HashTable(int x);
            /**
		*  @pre None
		*  @post Creates and initializes a HashTable instance
		*  @return Initialzed HashTable with the given size
		*/
            ~HashTable();
            /**
		*  @pre None
		*  @post destructs a HashTable instance
		*  @return destructed HashTable
		*/
            void insert(int x);
            /**
		*  @pre a value to insert
		*  @post inserts a value into the table based of the hasing function
		*  @return None
		*/
            void remove(int x);
            /**
		*  @pre a value to remove
		*  @post removes a value from the table if it is in the table
		*  @return None
		*/
            void print();
            /**
		*  @pre None
		*  @post prints the values of the HashTable
		*  @return None
		*/
            void hash(int x);
            /**
		*  @pre a value to hash
		*  @post this method hashes the value to find the place to store the value in the table
		*  @return None
		*/
            bool contains(int x);
            /**
		*  @pre a value to search for
		*  @post None
		*  @return true if the value is in the table and false if the value is not in the table
		*/
            bool isfull();
            /**
		*  @pre None
		*  @post None
		*  @return true if the table is full and false if the table is not full
		*/
        private:
            int tableSize;
            int *hashTable;
            bool *wasRemoved;
};
#endif
