/** 
*   @file:HashTable.cpp
*   @author:Michael Wang
*   @date:09/16/2016
*   Purpose:Implementation of HashTable class.
*/
#include "HashTable.h"
#include <iostream>
using namespace std;

HashTable::HashTable(int x)//creates a HashTable with the given size
{
    tableSize = x;
    hashTable = new int[x];
    wasRemoved = new bool[x];
    
    for(int i = 0; i < x; i++)
    {
        hashTable[i] = -1;
        wasRemoved[i] = false;
    }
}

HashTable::~HashTable()//deletes the HashTable that is created
{
    delete[] hashTable;
    delete[] wasRemoved;
}

void HashTable::insert(int x)//insert a value into the HashTable
{
    if(contains(x))
    {
        return;
    }
    else
    {
        hash(x);
    }
}

void HashTable::remove(int x)//remove a value from the HashTable
{
    for(int i = 0; i < tableSize; i++)
    {
        if(hashTable[i] == x)
        {
            hashTable[i] = -1;
            wasRemoved[i] = true;
        }
    }
}

void HashTable::print()//prints the values in the HashTable along with the flags
{
    for(int i = 0; i < tableSize; i++)
    {
        if(wasRemoved[i] == false)
        {
            std::cout << i << ": " << hashTable[i] << " flag =false" << endl;
        }
        else
        {
            std::cout << i << ": " << hashTable[i] << " flag =true" << endl;
        }
    }
}

void HashTable::hash(int x)//hashes a given value
{
    int hashedValue;
    for(int i = 0; i < tableSize; i++)
    {
        hashedValue = ((x%tableSize + i*i)%tableSize);
        if(hashTable[hashedValue] == -1)
        {
            if(wasRemoved[hashedValue] == false)
            {
                hashTable[hashedValue] = x;
                break;
            }
        }
        //break;
    }
    if(contains(x))
    {
        return;
    }
    for(int i = 0; i < tableSize; i++)
    {
        hashedValue = ((x%tableSize + i*i)%tableSize);
        if(hashTable[hashedValue] == -1)
        {
            if(wasRemoved[hashedValue] == true)
            {
                hashTable[hashedValue] = x;
                wasRemoved[hashedValue] = false;
                break;
            }
        }
       // break;
    }
}

bool HashTable::contains(int x)//returns true if a value is in the table and false if the value is not in the table
{
    bool inTable = false;
    for(int i = 0; i < tableSize; i++)
    {
        if(hashTable[i] == x)
        {
            inTable = true;
        }
    }
    return (inTable);
}

bool HashTable::isfull()//returns true if the table is full and false if the table is not full
{
    bool isFull = true;
    for(int i = 0; i < tableSize; i++)
    {
        if(hashTable[i] == -1)
        {
            isFull = false;
        }
    }
    return (isFull);
}
