/** 
*   @file:min5Heap.cpp
*   @author:Michael Wang
*   @date:10/03/2016
*   Purpose:Implementation of min5Heap class.
*/
#include "min5Heap.h"
#include <math.h>
#include <iostream>

min5Heap::min5Heap(int x)
{
    heapLevel = ceil(log(x));
    heapMaxSize = pow(5, ceil(log(x)));
    heap = new int[heapMaxSize];
    heapSize = 0;
    /*std::cout<< "heapMaxSize = "<<heapMaxSize<<"\n";
    std::cout<< "heapSize = "<<heapSize<<"\n";*/
    for(int i = 0; i < heapMaxSize; i++)
    {
        heap[i] = -1;
    }
}

min5Heap::~min5Heap()
{
    delete[] heap;
}

void min5Heap::resetHeap()
{
    for(int i = 0; i < heapSize; i++)
    {
        heap[i] = -1;
    }
}

bool min5Heap::isEmpty()
{
    return (heapSize == 0);
}

void min5Heap::insert(int x)
{
    //std::cout<< "THIS STILL NEEDS IMPLEMENTATION!!!\n";
    heap[heapSize] = x;
    heapSize++;
    upHeap();
}

void min5Heap::deletemin()
{
    //std::cout<< "THIS STILL NEEDS IMPLEMENTATION!!!\n";
    heap[0] = heap[heapSize-1];
    //std::cout<< heap[0] << "\n";
    heap[heapSize-1] = -1;
    heapSize--;
    upHeap();
}

void min5Heap::deletemax()
{
    //std::cout<< "THIS STILL NEEDS IMPLEMENTATION!!!\n";
    //int parentLocation = floor(((heapSize-1)-5));
    int maxLocation = 0;
    int maxValue = heap[0];
    for(int i = 0; i < heapSize; i++)
    {
        if(heap[i] > maxValue)
        {
            maxValue = heap[i];
            maxLocation = i;
        }
    }
    heap[maxLocation] = heap[heapSize-1];
    heap[heapSize-1] = -1;
    heapSize--;
    upHeap();
}

void min5Heap::remove(int x)
{
    //std::cout<< "THIS STILL NEEDS IMPLEMENTATION!!!\n";
    while(inHeap(x))
    {
        for(int i = 0; i < heapSize; i++)
        {
            if(heap[i] == x)
            {
                heap[i] = heap[heapSize - 1];
                heap[heapSize - 1] = -1;
                heapSize--;
                upHeap();
                break;
            }
        }
    }
}

void min5Heap::levelorder()
{
    int powerLevel = 0;
    for(int i = 0; i < heapSize; i++)
    {
        std::cout<< heap[i] << " ";
        if(i == 0)
        {
            std::cout<< "\n";
            powerLevel++;
        }
        else if(i == pow(5, powerLevel))
        {
            std::cout<< "\n";
            powerLevel++;
        }
        if((i > 5)&&(i%5 == 0)&&(heap[i+1] != -1))
        {
            std::cout<< "- ";
        }
    }
    std::cout<< "\n";
}

void min5Heap::upHeap()
{
    //std::cout<< "THIS UPHEAP STILL NEEDS IMPLEMENTATION!!!\n";
    //int hSize = pow(5, heapLevel);

    int parentLocation;
    int parentValue;
    int tempVal;
    int tempLoc;
    for(int i = 0; i <= heapLevel; i++)
    {
        int hSize = heapSize;

        if(hSize == 1)
        {

        }
        else
        {
            while(hSize > 1)
            {
                parentLocation = floor(((hSize-1-1)/5));
                //std::cout<<"parent location: "<<parentLocation<<"\n";
                parentValue = heap[parentLocation];
                if(parentValue > heap[heapSize-1])
                {
                    heap[parentLocation] = heap[heapSize-1];
                    heap[heapSize-1] = parentValue;
                }
                else
                {
                    break;
                }
                hSize = hSize - 5;
            }
        }
    }
}

void min5Heap::build(int x)
{
    int hSize = heapSize;
    for(int i = 0; i <= hSize; i++)
    {
        if(heap[i] == -1)
        {
            heap[i] = x;
            heapSize++;
        }
    }
    //upHeap();
    //std::cout<< "build heapSize = "<<heapSize<<"\n";
}

bool min5Heap::minAtTop()
{
    bool minCondition = false;
        for(int i = 0; i = heapSize; i++)
        {
            int child1 = heap[5*i + 1];
            int child2 = heap[5*i + 2];
            int child3 = heap[5*i + 3];
            int child4 = heap[5*i + 4];
            int child5 = heap[5*i + 5];
            int parentValue = heap[i];

            if(!(((child1 != -1)&&(child1 < parentValue))||((child2 != -1)&&(child2 < parentValue))||((child3 != -1)&&(child3 < parentValue))||((child4 != -1)&&(child4 < parentValue))||((child5 != -1)&&(child5 < parentValue))))
            {
                minCondition = true;
            }
        }
    return minCondition;
}

bool min5Heap::inHeap(int x)
{
    for(int i = 0; i < heapSize; i++)
    {
        if(heap[i] == x)
        {
            return true;
        }
    }
    return false;
}