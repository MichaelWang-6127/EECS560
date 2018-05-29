/** 
*   @file:main.cpp
*   @author:Michael Wang
*   @date:09/03/2015
*   Purpose:Main file. Used as the programs entry point.
*/

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include <iostream>
#include <fstream>
#include "Node.h"
#include "BSTNode.h"
#include "BinarySearchTree.h"
#include "min5Heap.h"
#include "Timer.cpp"
//using namespace std;

/*double timeAverage(int arraySize, double BuildtimeArray[])
{
    double averageTime = 0.0;
    for(int i=0; i<arraySize; i++)
    {
        averageTime = averageTime + BuildtimeArray[i];
    }
    return (averageTime/arraySize);
}*/

int  main(int argc, char const *argv[])//main entry point for the program. runs the menu and the options.
{

    std::cout<<"Starting the time testing!!!\n";

	//BinarySearchTree BST1;

    int iValue;
    int iNum;
    int nNum;
    int zNum;

    double timeCount;
    Timer timer;
    Timer timer2;

    //BinarySearchTree BST1;

    //working with 50000 numbers
    //___________________________
    //___________________________
    //___________________________
    //___________________________
    //___________________________

   for(int i=1; i <= 5; i++)
    {
        std::cout<<"Starting the build!!!\n";
        srand(i);
        nNum = 50000;
        min5Heap heap1 = min5Heap(nNum);
        BinarySearchTree BST1;
        
        std::cout<<"Time the min5Heap Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                iNum = rand() % 4*nNum + 1;
                heap1.insert(iNum);
            }
        timer.printTime(timer.stop());

        std::cout<<"Time the BST Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                BST1.insert(rand() % 4*nNum + 1);
            }
            timer.printTime(timer.stop());

            std::cout<<"Time the min5Heap Operations with "<<nNum<<" values: ";
        timer.start();
            for(int n=0; n<nNum/10; n++)
            {
                zNum = rand()/nNum;
                if((0 <= zNum)&&(zNum < 0.25))
                {
                    heap1.deletemin();
                }
                else if((0.25 <= zNum)&&(zNum < 0.5))
                {
                    heap1.deletemax();
                }
                else if((0.5 <= zNum)&&(zNum < 0.75))
                {
                    iNum = rand()%4*nNum+1;
                    heap1.remove(iNum);
                }
                else
                {
                    iNum = rand()%4*nNum+1;
                    heap1.insert(iNum);
                }
            }
            timer.printTime(timer.stop());

        std::cout<<"Time the BST Operations with "<<nNum<<" values: ";
        timer.start();
            for(int n=0; n<nNum/10; n++)
            {
                zNum = rand()/nNum;
                if((0 <= zNum)&&(zNum < 0.25))
                {
                    BST1.deletemin();
                }
                else if((0.25 <= zNum)&&(zNum < 0.5))
                {
                    BST1.deletemax();
                }
                else if((0.5 <= zNum)&&(zNum < 0.75))
                {
                    iNum = rand()%4*nNum+1;
                    heap1.remove(iNum);
                }
                else
                {
                    iNum = rand()%4*nNum+1;
                    BST1.insert(iNum);
                }
            }
            timer.printTime(timer.stop());

        if(i < 5)
        {
            if(!heap1.isEmpty())
            {
                //std::cout<<"Time the min5Heap Delete with "<<nNum<<" values: ";
                //timer2.start();
                //heap1.~min5Heap();
                heap1.resetHeap();
                //timer2.printTime(timer2.stop());
            }
            while(!BST1.isEmpty())
            {
                //std::cout<<"Time the BST Delete with "<<nNum<<" values: ";
                //timer2.start();
                //BST1.deletemin();
                BST1.~BinarySearchTree();
                //timer2.printTime(timer2.stop());
            }
        }        
    }

    //working with 100000 numbers
    //___________________________
    //___________________________
    //___________________________
    //___________________________
    //___________________________
    //___________________________
    //___________________________
    //___________________________
    //___________________________


    for(int i=6; i <= 10; i++)
    {
        std::cout<<"Starting the build!!!\n";
        srand(i);
        nNum = 100000;
        min5Heap heap1 = min5Heap(nNum);
        BinarySearchTree BST1;
        
        std::cout<<"Time the min5Heap Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                iNum = rand() % 4*nNum + 1;
                heap1.insert(iNum);
            }
        timer.printTime(timer.stop());

        std::cout<<"Time the BST Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                BST1.insert(rand() % 4*nNum + 1);
            }
            timer.printTime(timer.stop());

            std::cout<<"Time the min5Heap Operations with "<<nNum<<" values: ";
        timer.start();
            for(int n=0; n<nNum/10; n++)
            {
                zNum = rand()/nNum;
                if((0 <= zNum)&&(zNum < 0.25))
                {
                    heap1.deletemin();
                }
                else if((0.25 <= zNum)&&(zNum < 0.5))
                {
                    heap1.deletemax();
                }
                else if((0.5 <= zNum)&&(zNum < 0.75))
                {
                    iNum = rand()%4*nNum+1;
                    heap1.remove(iNum);
                }
                else
                {
                    iNum = rand()%4*nNum+1;
                    heap1.insert(iNum);
                }
            }
            timer.printTime(timer.stop());

        std::cout<<"Time the BST Operations with "<<nNum<<" values: ";
        timer.start();
            for(int n=0; n<nNum/10; n++)
            {
                zNum = rand()/nNum;
                if((0 <= zNum)&&(zNum < 0.25))
                {
                    BST1.deletemin();
                }
                else if((0.25 <= zNum)&&(zNum < 0.5))
                {
                    BST1.deletemax();
                }
                else if((0.5 <= zNum)&&(zNum < 0.75))
                {
                    iNum = rand()%4*nNum+1;
                    heap1.remove(iNum);
                }
                else
                {
                    iNum = rand()%4*nNum+1;
                    BST1.insert(iNum);
                }
            }
            timer.printTime(timer.stop());

        if(i < 10)
        {
            if(!heap1.isEmpty())
            {
                //std::cout<<"Time the min5Heap Delete with "<<nNum<<" values: ";
                //timer2.start();
                //heap1.~min5Heap();
                heap1.resetHeap();
                //timer2.printTime(timer2.stop());
            }
            while(!BST1.isEmpty())
            {
                //std::cout<<"Time the BST Delete with "<<nNum<<" values: ";
                //timer2.start();
                //BST1.deletemin();
                BST1.~BinarySearchTree();
                //timer2.printTime(timer2.stop());
            }
        }        
    }
    
    //working with 200000 numbers
    //___________________________
    //___________________________
    //___________________________
    //___________________________
    //___________________________
    //___________________________
    //___________________________
    //___________________________
    //___________________________
    //___________________________
    //___________________________
    //___________________________

    for(int i=11; i <= 15; i++)
    {
        std::cout<<"Starting the build!!!\n";
        srand(i);
        nNum = 200000;
        min5Heap heap1 = min5Heap(nNum);
        BinarySearchTree BST1;
        
        std::cout<<"Time the min5Heap Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                iNum = rand() % 4*nNum + 1;
                heap1.insert(iNum);
            }
        timer.printTime(timer.stop());

        std::cout<<"Time the BST Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                BST1.insert(rand() % 4*nNum + 1);
            }
            timer.printTime(timer.stop());

            std::cout<<"Time the min5Heap Operations with "<<nNum<<" values: ";
        timer.start();
            for(int n=0; n<nNum/10; n++)
            {
                zNum = rand()/nNum;
                if((0 <= zNum)&&(zNum < 0.25))
                {
                    heap1.deletemin();
                }
                else if((0.25 <= zNum)&&(zNum < 0.5))
                {
                    heap1.deletemax();
                }
                else if((0.5 <= zNum)&&(zNum < 0.75))
                {
                    iNum = rand()%4*nNum+1;
                    heap1.remove(iNum);
                }
                else
                {
                    iNum = rand()%4*nNum+1;
                    heap1.insert(iNum);
                }
            }
            timer.printTime(timer.stop());

        std::cout<<"Time the BST Operations with "<<nNum<<" values: ";
        timer.start();
            for(int n=0; n<nNum/10; n++)
            {
                zNum = rand()/nNum;
                if((0 <= zNum)&&(zNum < 0.25))
                {
                    BST1.deletemin();
                }
                else if((0.25 <= zNum)&&(zNum < 0.5))
                {
                    BST1.deletemax();
                }
                else if((0.5 <= zNum)&&(zNum < 0.75))
                {
                    iNum = rand()%4*nNum+1;
                    heap1.remove(iNum);
                }
                else
                {
                    iNum = rand()%4*nNum+1;
                    BST1.insert(iNum);
                }
            }
            timer.printTime(timer.stop());

        if(i < 15)
        {
            if(!heap1.isEmpty())
            {
                //std::cout<<"Time the min5Heap Delete with "<<nNum<<" values: ";
                //timer2.start();
                //heap1.~min5Heap();
                heap1.resetHeap();
                //timer2.printTime(timer2.stop());
            }
            while(!BST1.isEmpty())
            {
                //std::cout<<"Time the BST Delete with "<<nNum<<" values: ";
                //timer2.start();
                //BST1.deletemin();
                BST1.~BinarySearchTree();
                //timer2.printTime(timer2.stop());
            }
        }        
    }
    

    //working with 400000 numbers
    //___________________________
    //___________________________
    //___________________________
    //___________________________
    //___________________________
    //___________________________
    //___________________________
    //___________________________
    //___________________________
    //___________________________
    //___________________________
    //___________________________

    for(int i=16; i <= 20; i++)
    {
        std::cout<<"Starting the build!!!\n";
        srand(i);
        nNum = 400000;
        min5Heap heap1 = min5Heap(nNum);
        BinarySearchTree BST1;
        
        std::cout<<"Time the min5Heap Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                iNum = rand() % 4*nNum + 1;
                heap1.insert(iNum);
            }
        timer.printTime(timer.stop());

        std::cout<<"Time the BST Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                BST1.insert(rand() % 4*nNum + 1);
            }
            timer.printTime(timer.stop());

            std::cout<<"Time the min5Heap Operations with "<<nNum<<" values: ";
        timer.start();
            for(int n=0; n<nNum/10; n++)
            {
                zNum = rand()/nNum;
                if((0 <= zNum)&&(zNum < 0.25))
                {
                    heap1.deletemin();
                }
                else if((0.25 <= zNum)&&(zNum < 0.5))
                {
                    heap1.deletemax();
                }
                else if((0.5 <= zNum)&&(zNum < 0.75))
                {
                    iNum = rand()%4*nNum+1;
                    heap1.remove(iNum);
                }
                else
                {
                    iNum = rand()%4*nNum+1;
                    heap1.insert(iNum);
                }
            }
            timer.printTime(timer.stop());

        std::cout<<"Time the BST Operations with "<<nNum<<" values: ";
        timer.start();
            for(int n=0; n<nNum/10; n++)
            {
                zNum = rand()/nNum;
                if((0 <= zNum)&&(zNum < 0.25))
                {
                    BST1.deletemin();
                }
                else if((0.25 <= zNum)&&(zNum < 0.5))
                {
                    BST1.deletemax();
                }
                else if((0.5 <= zNum)&&(zNum < 0.75))
                {
                    iNum = rand()%4*nNum+1;
                    heap1.remove(iNum);
                }
                else
                {
                    iNum = rand()%4*nNum+1;
                    BST1.insert(iNum);
                }
            }
            timer.printTime(timer.stop());

        if(i < 20)
        {
            if(!heap1.isEmpty())
            {
                //std::cout<<"Time the min5Heap Delete with "<<nNum<<" values: ";
                //timer2.start();
                //heap1.~min5Heap();
                heap1.resetHeap();
                //timer2.printTime(timer2.stop());
            }
            while(!BST1.isEmpty())
            {
                //std::cout<<"Time the BST Delete with "<<nNum<<" values: ";
                //timer2.start();
                //BST1.deletemin();
                BST1.~BinarySearchTree();
                //timer2.printTime(timer2.stop());
            }
        }        
    }

	return 0;
}

