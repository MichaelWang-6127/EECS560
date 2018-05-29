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
#include <math.h>
#include "Node.h"
#include "LinkedList.h"
#include "minMaxHeap.h"
#include "min5Heap.h"
#include "Timer.cpp"
//using namespace std;

void printMenu()//prints the menu of instructions
{
    std::cout << "\n\nPlease choose one of the following commands:\n"
            << "1- insert\n"
            << "2- deletemin\n"
            << "3- deletemax\n"
            << "4- levelorder\n"
            << "5- exit\n"
            << "Enter your choice: ";
}

int  main(int argc, char const *argv[])//main entry point for the program. runs the menu and the options.
{
    LinkedList list;
    int iValue;
    int iOption;

        int heapSize;
        
        std::fstream data("data.txt", std::ios_base::in);
        int listValue;
        while(data>>listValue)
        {
            list.addBack(listValue);
        }
        
        heapSize = list.size();
        minMaxHeap heap = minMaxHeap(heapSize);

     while(!(list.isEmpty()))
        {
            listValue = list.getRemoveFront();
            if(listValue != -1)
            {
                heap.build(listValue);
            }
        }
        //heap.trickleDown(1);
        heapSize++;

        int tempHeapLevel = ceil(log(heapSize));
        int leveler = ((-1*tempHeapLevel) + 1);
        int indexStart = heapSize;
        int startHeap = heap.findParent(indexStart);
        while(startHeap > 0)
        {
            heap.trickleDown(startHeap);
            indexStart--;
            startHeap = heap.findParent(indexStart);
        }

        /*int heapLevel = ceil(log(heapSize));
        int leveler = ((-1*heapLevel) + 1);*/
        //int indexStart = heapSize;
        //int startHeap = heap.findParent(indexStart);
        /*int startHeap = 1;
        while(startHeap < heapSize)
        {
            std::cout << "This is the startheap:"<<startHeap<<"\n";
            heap.trickleDown(startHeap);
            startHeap++;
        }*/

    do
    {
        printMenu();
        std::cin >> iOption;
        if(iOption == 1)
        {
            std::cout << "Please insert the number that you want to be inserted in the heap\n";
            std::cin >> iValue;
            heap.insert(iValue);
        }
        else if(iOption == 2)
        {
            heap.deletemin();
        }
        else if(iOption == 3)
        {
            heap.deletemax();
        }
        else if(iOption == 4)
        {
            std::cout << "Level order:\n";
            heap.levelorder();
        }
        else if (iOption == 5)
        {
            std::cout << "Exiting...\n";
        }
    }while(iOption != 5);

	return 0;
}

void timeTest()//runs the time test
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
        minMaxHeap heap2 = minMaxHeap(nNum);
        
        std::cout<<"Time the min5Heap Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                iNum = rand() % 4*nNum + 1;
                heap1.insert(iNum);
            }
        timer.printTime(timer.stop());

        std::cout<<"Time the minMaxHeap Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                iNum = rand() % 4*nNum + 1;
                heap2.insert(iNum);
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
                else
                {
                    iNum = rand()%4*nNum+1;
                    heap1.insert(iNum);
                }
            }
            timer.printTime(timer.stop());

        std::cout<<"Time the minMaxHeap Operations with "<<nNum<<" values: ";
        timer.start();
            for(int n=0; n<nNum/10; n++)
            {
                zNum = rand()/nNum;
                if((0 <= zNum)&&(zNum < 0.25))
                {
                    heap2.deletemin();
                }
                else if((0.25 <= zNum)&&(zNum < 0.5))
                {
                    heap2.deletemax();
                }
                else
                {
                    iNum = rand()%4*nNum+1;
                    heap2.insert(iNum);
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
            while(!heap2.isEmpty())
            {
                //std::cout<<"Time the BST Delete with "<<nNum<<" values: ";
                //timer2.start();
                //BST1.deletemin();
                heap2.resetHeap();
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
        minMaxHeap heap2 = minMaxHeap(nNum);
        
        std::cout<<"Time the min5Heap Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                iNum = rand() % 4*nNum + 1;
                heap1.insert(iNum);
            }
        timer.printTime(timer.stop());

        std::cout<<"Time the minMaxHeap Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                iNum = rand() % 4*nNum + 1;
                heap2.insert(iNum);
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
                else
                {
                    iNum = rand()%4*nNum+1;
                    heap1.insert(iNum);
                }
            }
            timer.printTime(timer.stop());

        std::cout<<"Time the minMaxHeap Operations with "<<nNum<<" values: ";
        timer.start();
            for(int n=0; n<nNum/10; n++)
            {
                zNum = rand()/nNum;
                if((0 <= zNum)&&(zNum < 0.25))
                {
                    heap2.deletemin();
                }
                else if((0.25 <= zNum)&&(zNum < 0.5))
                {
                    heap2.deletemax();
                }
                else
                {
                    iNum = rand()%4*nNum+1;
                    heap2.insert(iNum);
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
            while(!heap2.isEmpty())
            {
                //std::cout<<"Time the BST Delete with "<<nNum<<" values: ";
                //timer2.start();
                //BST1.deletemin();
                heap2.resetHeap();
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
        minMaxHeap heap2 = minMaxHeap(nNum);
        
        std::cout<<"Time the min5Heap Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                iNum = rand() % 4*nNum + 1;
                heap1.insert(iNum);
            }
        timer.printTime(timer.stop());

        std::cout<<"Time the minMaxHeap Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                iNum = rand() % 4*nNum + 1;
                heap2.insert(iNum);
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
                else
                {
                    iNum = rand()%4*nNum+1;
                    heap1.insert(iNum);
                }
            }
            timer.printTime(timer.stop());

        std::cout<<"Time the minMaxHeap Operations with "<<nNum<<" values: ";
        timer.start();
            for(int n=0; n<nNum/10; n++)
            {
                zNum = rand()/nNum;
                if((0 <= zNum)&&(zNum < 0.25))
                {
                    heap2.deletemin();
                }
                else if((0.25 <= zNum)&&(zNum < 0.5))
                {
                    heap2.deletemax();
                }
                else
                {
                    iNum = rand()%4*nNum+1;
                    heap2.insert(iNum);
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
            while(!heap2.isEmpty())
            {
                //std::cout<<"Time the BST Delete with "<<nNum<<" values: ";
                //timer2.start();
                //BST1.deletemin();
                heap2.resetHeap();
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
        minMaxHeap heap2 = minMaxHeap(nNum);
        
        std::cout<<"Time the min5Heap Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                iNum = rand() % 4*nNum + 1;
                heap1.insert(iNum);
            }
        timer.printTime(timer.stop());

        std::cout<<"Time the minMaxHeap Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                iNum = rand() % 4*nNum + 1;
                heap2.insert(iNum);
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
                else
                {
                    iNum = rand()%4*nNum+1;
                    heap1.insert(iNum);
                }
            }
            timer.printTime(timer.stop());

        std::cout<<"Time the minMaxHeap Operations with "<<nNum<<" values: ";
        timer.start();
            for(int n=0; n<nNum/10; n++)
            {
                zNum = rand()/nNum;
                if((0 <= zNum)&&(zNum < 0.25))
                {
                    heap2.deletemin();
                }
                else if((0.25 <= zNum)&&(zNum < 0.5))
                {
                    heap2.deletemax();
                }
                else
                {
                    iNum = rand()%4*nNum+1;
                    heap2.insert(iNum);
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
            while(!heap2.isEmpty())
            {
                //std::cout<<"Time the BST Delete with "<<nNum<<" values: ";
                //timer2.start();
                //BST1.deletemin();
                heap2.resetHeap();
                //timer2.printTime(timer2.stop());
            }
        }        
    }
}

