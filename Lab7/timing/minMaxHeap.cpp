/** 
*   @file:minMaxHeap.cpp
*   @author:Michael Wang
*   @date:10/17/2016
*   Purpose:Implementation of minMaxHeap class.
*/
#include "minMaxHeap.h"
#include <math.h>
#include <iostream>

minMaxHeap::minMaxHeap(int x)
{
    heapLevel = ceil(log(x));
    heapMaxSize = pow(5, ceil(log(x)));
    heapMaxSize++;
    heap = new int[heapMaxSize];
    heapSize = 0;
    lastPosition = 1;
    /*std::cout<< "heapMaxSize = "<<heapMaxSize<<"\n";
    std::cout<< "heapSize = "<<heapSize<<"\n";*/
    for(int i = 0; i < heapMaxSize; i++)
    {
        heap[i] = -1;
    }
}

minMaxHeap::~minMaxHeap()
{
    delete[] heap;
}

void minMaxHeap::resetHeap()
{
    for(int i = 0; i < heapSize; i++)
    {
        heap[i] = -1;
    }
    heapSize = 0;
}

bool minMaxHeap::isEmpty()
{
    return (heapSize == 0);
}

void minMaxHeap::insert(int x)
{
    //std::cout<< "THIS STILL NEEDS IMPLEMENTATION!!!\n";
    heapSize++;
    heap[heapSize] = x;
    heapLevel = ceil(log(heapSize));

    bubbleUp(heapSize);
    
    /*int indexStart = heapSize;
    int startHeap = indexStart;
    while(startHeap > 0)
    {
        bubbleUp(startHeap);
        std::cout<<"bubble up at:"<<startHeap<<"\n";
        levelorder();
        startHeap = findParent(startHeap);
    }*/
    //trickleDown(1);

    
    /*int indexStart = heapSize;
    int startHeap = findParent(indexStart);
    while(startHeap > 0)
    {
        trickleDown(startHeap);
        indexStart--;
        startHeap = findParent(indexStart);
    }*/
}

void minMaxHeap::deletemin()
{
    //std::cout<< "THIS STILL NEEDS IMPLEMENTATION!!!\n";
    if(heapSize == 0)
    {
        return;
    }
    else
    {
        heap[1] = heap[heapSize];
        heap[heapSize] = -1;
        heapSize--;

        /*int tempHeapLevel = ceil(log(heapSize));
        int leveler = ((-1*heapLevel) + 1);*/
        int indexStart = heapSize;
        int startHeap = findParent(indexStart);
        while(startHeap > 0)
        {
            //std::cout<<"startHeap is: "<<startHeap<<" heaplevel is: "<<heapLevel<<"\n";
            trickleDown(startHeap);
            indexStart--;
            startHeap = findParent(indexStart);
            /*if(indexStart <= (pow(tempHeapLevel, 2)+leveler))
            {
                tempHeapLevel--;
            }*/
        }
    }
}

void minMaxHeap::deletemax()
{
    //std::cout<< "THIS STILL NEEDS IMPLEMENTATION!!!\n";
    if(heapSize == 0)
    {
        return;
    }
    else
    {
        if(heap[2] > heap[3])
        {
            heap[2] = heap[heapSize];
            heap[heapSize] = -1;
            heapSize--;
        }
        else
        {
            heap[3] = heap[heapSize];
            heap[heapSize] = -1;
            heapSize--;
        }
        /*int tempHeapLevel = ceil(log(heapSize));
        int leveler = ((-1*heapLevel) + 1);*/
        int indexStart = heapSize;
        int startHeap = findParent(indexStart);
        while(startHeap > 0)
        {
            //std::cout<<"startHeap is: "<<startHeap<<" heaplevel is: "<<heapLevel<<"\n";
            trickleDown(startHeap);
            indexStart--;
            startHeap = findParent(indexStart);
            /*if(indexStart <= (pow(tempHeapLevel, 2)+leveler))
            {
                tempHeapLevel--;
            }*/
        }
    }
}

void minMaxHeap::levelorder()
{
    //std::cout<< "THIS STILL NEEDS IMPLEMENTATION!!!\n";
    int powerLevel = 1;
    int leveler = 3;
    for(int i=1; i<heapSize+1; i++)
    {
        std::cout<<heap[i]<<" ";
        if(i == 1)
        {
            std::cout<<"\n";
            powerLevel++;
        }
        else if(i == leveler)
        {
            std::cout<<"\n";
            powerLevel++;
            leveler = 2*leveler+1;;
        }
    }
    std::cout<<"\n";
}

void minMaxHeap::build(int x)
{
    //std::cout<< "THIS STILL NEEDS IMPLEMENTATION!!!\n";
    heapSize++;
    heap[heapSize] = x;
}

void minMaxHeap::bubbleUp(int x)
{
    //std::cout<< "THIS STILL NEEDS IMPLEMENTATION!!!\n";
    if(isMinLevel(x))
    {
        //std::cout<<"in minlevel bubble:"<<"\n";
        if((hasParent(x)))
        {
            if((heap[x]>heap[findParent(x)]))
            {
                //std::cout<<"in loop1 minlevel bubble:"<<"\n";
                int temp = heap[x];
                heap[x] = heap[findParent(x)];
                heap[findParent(x)] = temp;
                bubbleUpMax(findParent(x));
            }
            else
            {
                //std::cout<<"in else minlevel bubble:"<<"\n";
                bubbleUpMin(x);
            }
        }
        else
        {
            //std::cout<<"in else minlevel bubble:"<<"\n";
            bubbleUpMin(x);
        }
    }
    else
    {
        //std::cout<<"maxlevel:"<<"\n";
        if((hasParent(x)))
        {
            if((heap[x]<heap[findParent(x)]))
            {
                int temp = heap[x];
                heap[x] = heap[findParent(x)];
                heap[findParent(x)] = temp;
                bubbleUpMin(findParent(x));
            }
            else
            {
                //std::cout<<"bubble max called:"<<"\n";
                bubbleUpMax(x);
            }
        }
        else
        {
            //std::cout<<"bubble max called:"<<"\n";
            bubbleUpMax(x);
        }
    }
}

void minMaxHeap::trickleDown(int x)
{
    //std::cout<< "THIS STILL NEEDS IMPLEMENTATION!!!\n";
    //std::cout<<"This is the x value:"<<x<<" this is the value:"<<heap[x]<<"\n";
    if(isMinLevel(x))
    {
        //std::cout<<"calling tdmin\n";
        trickleDownMin(x);
        //trickleDownMax(x);
    }
    else
    {
        //std::cout<<"calling tdmax\n";
        trickleDownMax(x);
        //trickleDownMin(x);
    }
}

void minMaxHeap::trickleDownMin(int x)
{
    //std::cout<< "THIS STILL NEEDS IMPLEMENTATION!!!\n";
    if(hasChildren(x))
    {
        int m = smallestChild(x);
        if(isGrandChild(x, m))
        {
            if(heap[m] < heap[x])
            {
                //std::cout<<"swap 1 tdmin\n";
                int temp = heap[m];
                heap[m] = heap[x];
                heap[x] = temp;
                //std::cout<<"swap 1 tdmin "<<heap[m] <<" and "<<temp<<"\n";
                //levelorder();
                if(heap[m] > heap[findParent(m)])
                {
                    //std::cout<<"swap 2 tdmin\n";
                    int temp2 = heap[m];
                    heap[m] = heap[findParent(m)];
                    heap[findParent(m)] = temp2;
                    //std::cout<<"swap 2 tdmin "<<heap[m] <<" and "<<temp2<<"\n";
                    //levelorder();
                }
                trickleDownMin(m);
            }
        }
        else if(isChild(x, m))
        {
            if(heap[m] < heap[x])
            {
                //std::cout<<"swap 3 tdmin\n";
                int temp = heap[m];
                heap[m] = heap[x];
                heap[x] = temp;
                //std::cout<<"swap 3 tdmin "<<heap[m] <<" and "<<temp<<"\n";
                //levelorder();
            }
        }
    }
}

void minMaxHeap::trickleDownMax(int x)
{
    //std::cout<< "THIS STILL NEEDS IMPLEMENTATION!!!\n";
    if(hasChildren(x))
    {
        //std::cout<<"tdmax1\n";
        int m = largestChild(x);
        //std::cout<<"this is m: "<<m<<" \n";
        if(isGrandChild(x, m))
        {
            //std::cout<<"tdmax2\n";
            if(heap[m] > heap[x])
            {
                //std::cout<<"tdmax3\n";
                //std::cout<<"swap 1 tdmax\n";
                int temp = heap[m];
                heap[m] = heap[x];
                heap[x] = temp;
                //std::cout<<"swap 1 tdmax "<<heap[m] <<" and "<<temp<<"\n";
                //levelorder();
                if(heap[m] < heap[findParent(m)])
                {
                    //std::cout<<"tdmax4\n";
                    //std::cout<<"swap 2 tdmax\n";
                    int temp2 = heap[m];
                    heap[m] = heap[findParent(m)];
                    heap[findParent(m)] = temp2;
                    //std::cout<<"swap 2 tdmax "<<heap[m] <<" and "<<temp2<<"\n";
                    //levelorder();
                }
                trickleDownMax(m);
            }
        }
        else if(isChild(x, m))
        {
            if(heap[m] > heap[x])
            {
                //std::cout<<"swap 3 tdmax\n";
                int temp = heap[m];
                heap[m] = heap[x];
                heap[x] = temp;
                //std::cout<<"swap 3 tdmax "<<heap[m] <<" and "<<temp<<"\n";
                //levelorder();
            }
        }
    }
}

void minMaxHeap::bubbleUpMin(int x)
{
    //std::cout<< "THIS STILL NEEDS IMPLEMENTATION!!!\n";
    if(hasGrandParent(x))
    {
        //std::cout<<"in the bubbleupmin at index:"<<x<<"\n";
        if(heap[x] < heap[findGrandParent(x)])// && (heap[findGrandParent(x)] != -1)
        {
            int temp = heap[x];
            heap[x] = heap[findGrandParent(x)];
            heap[findGrandParent(x)] = temp;
            //std::cout<<"in the bubbleupmin loop at index:"<<x<<"\n";
            bubbleUpMin(findGrandParent(x));
        }
    }
}

void minMaxHeap::bubbleUpMax(int x)
{
    //std::cout<< "THIS STILL NEEDS IMPLEMENTATION!!!\n";
    if(hasGrandParent(x))
    {
        //std::cout<<"in the bubbleupmax at index:"<<x<<"\n";
        if((heap[x] > heap[findGrandParent(x)]))// && (heap[findGrandParent(x)] != -1)
        {
            int temp = heap[x];
            heap[x] = heap[findGrandParent(x)];
            heap[findGrandParent(x)] = temp;
            //std::cout<<"in the bubbleupmax loop at index:"<<x<<"\n";
            bubbleUpMax(findGrandParent(x));
        }
    }
}

int minMaxHeap::findParent(int x)
{
    if((x%2)==1)
    {
        return((x-1)/2);
    }
    else
    {
        return(x/2);
    }
}

int minMaxHeap::findGrandParent(int x)
{
    if((x%2)==1)
    {
        return(findParent(((x-1)/2)));
    }
    else
    {
        return(findParent(x/2));
    }
}

bool minMaxHeap::hasChildren(int x)
{
    if((heap[2*x] != -1)||(heap[2*x+1] != -1))
    {
        return true;
    }
    return false;
}

bool minMaxHeap::hasGrandChildren(int x)
{
    if((heap[4*x] != -1)||(heap[4*x+1] != -1)||(heap[4*x+2] != -1)||(heap[4*x+3] != -1))
    {
        return true;
    }
    return false;
}

int minMaxHeap::largestChild(int x)
{
    int maxValue = heap[x];
    int maxIndex = x;
    int returnMax = maxIndex;
    maxIndex = 2*x;
    if(heap[maxIndex] != -1)
    {
        if(maxValue < heap[maxIndex])
        {
            maxValue = heap[maxIndex];
            returnMax = maxIndex;
        }
    }
    maxIndex = 2*x+1;
    if(heap[maxIndex] != -1)
    {
        if(maxValue < heap[maxIndex])
        {
            maxValue = heap[maxIndex];
            returnMax = maxIndex;
        }
    }
    maxIndex = 4*x;
    if(heap[maxIndex] != -1)
    {
        if(maxValue < heap[maxIndex])
        {
            maxValue = heap[maxIndex];
            returnMax = maxIndex;
        }
    }
    maxIndex = 4*x+1;
    if(heap[maxIndex] != -1)
    {
        if(maxValue < heap[maxIndex])
        {
            maxValue = heap[maxIndex];
            returnMax = maxIndex;
        }
    }
    maxIndex = 2*(2*x+1);
    if(heap[maxIndex] != -1)
    {
        if(maxValue < heap[maxIndex])
        {
            maxValue = heap[maxIndex];
            returnMax = maxIndex;
        }
    }
    maxIndex = (2*(2*x+1)+1);
    if(heap[maxIndex] != -1)
    {
        if(maxValue < heap[maxIndex])
        {
            maxValue = heap[maxIndex];
            returnMax = maxIndex;
        }
    }
    return returnMax;
}

int minMaxHeap::smallestChild(int x)
{
    int minValue = heap[x];
    int minIndex = x;
    int returnMin = minIndex;
    minIndex = 2*x;
    if(heap[minIndex] != -1)
    {
        if(minValue > heap[minIndex])
        {
            minValue = heap[minIndex];
            returnMin = minIndex;
        }
    }
    minIndex = 2*x+1;
    if(heap[minIndex] != -1)
    {
        if(minValue > heap[minIndex])
        {
            minValue = heap[minIndex];
            returnMin = minIndex;
        }
    }
    minIndex = 4*x;
    if(heap[minIndex] != -1)
    {
        if(minValue > heap[minIndex])
        {
            minValue = heap[minIndex];
            returnMin = minIndex;
        }
    }
    minIndex = 4*x+1;
    if(heap[minIndex] != -1)
    {
        if(minValue > heap[minIndex])
        {
            minValue = heap[minIndex];
            returnMin = minIndex;
        }
    }
    minIndex = 2*(2*x+1);
    if(heap[minIndex] != -1)
    {
        if(minValue > heap[minIndex])
        {
            minValue = heap[minIndex];
            returnMin = minIndex;
        }
    }
    minIndex = (2*(2*x+1)+1);
    if(heap[minIndex] != -1)
    {
        if(minValue > heap[minIndex])
        {
            minValue = heap[minIndex];
            returnMin = minIndex;
        }
    }
    return returnMin;
}

bool minMaxHeap::isChild(int x, int y)
{
    if(2*x == y)
    {
        return true;
    }
    else if(2*x+1 == y)
    {
        return true;
    }
    return false;
}

bool minMaxHeap::isGrandChild(int x, int y)
{
    if(4*x == y)
    {
        return true;
    }
    else if(4*x+1 == y)
    {
        return true;
    }
    else if(2*(2*x+1) == y)
    {
        return true;
    }
    else if(((2*(2*x+1)+1) == y))
    {
        return true;
    }
    return false;
}

bool minMaxHeap::hasParent(int x)
{
    if((x%2)==1)
    {
        if(heap[((x-1)/2)] != -1)
        {
            return true;
        }
    }
    else
    {
        if(heap[(x/2)] != -1)
        {
            return true;
        }
    }
    return false;
}

bool minMaxHeap::hasGrandParent(int x)
{
    if((x%2)==1)
    {
        if(heap[((x-1)/2)] != -1)
        {
            return hasParent(((x-1)/2));
        }
    }
    else
    {
        if(heap[(x/2)] != -1)
        {
            return hasParent(x/2);
        }
    }
    return false;
}

bool minMaxHeap::isMinLevel(int x)
{
    //std::cout<<"this is the level:"<<((int)(log2((double)x + 1)) % 2)<<"\n";
    //return (((int)(log2(x+2)) % 2) == 1);
    int lmin = 0;
    for(int i=0; i<heapSize; i++)
    {
        lmin = pow(2, i);
        if(x < lmin)
        {
            //std::cout<<"this is the level:"<<i<<"\n";
            return ((i%2) == 1);
        }
    }
}

bool minMaxHeap::isMaxLevel(int x)
{
    return (!(isMinLevel(x)));
}