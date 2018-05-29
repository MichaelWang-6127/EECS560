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
#include "LinkedList.h"
#include "minMaxHeap.h"
#include "min5Heap.h"
#include "Timer.cpp"
//using namespace std;

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

           /* std::cout<<"Time the minMaxHeap Build with "<<nNum<<" values: ";
            timer.start();
            for(int k=0; k<nNum; k++)
            {
                iNum = rand() % 4*nNum + 1;
                //std::cout<<"inserting numbner: "<<k<<"\n";
                heap2.build(iNum);
            }
            int indexStart = nNum;
            int startHeap = heap2.findParent(indexStart);
            while(startHeap > 0)
            {
                heap2.trickleDown(startHeap);
                indexStart--;
                startHeap = heap2.findParent(indexStart);
            }
            timer.printTime(timer.stop());*/

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
        /*else
        {
            heap1.~min5Heap();
            heap2.~minMaxHeap();
        }*/           
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
        min5Heap heap3 = min5Heap(nNum);
        minMaxHeap heap4 = minMaxHeap(nNum);
        
        std::cout<<"Time the min5Heap Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                iNum = rand() % 4*nNum + 1;
                heap3.insert(iNum);
            }
        timer.printTime(timer.stop());

        std::cout<<"Time the minMaxHeap Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                iNum = rand() % 4*nNum + 1;
                heap4.insert(iNum);
            }
            timer.printTime(timer.stop());

            std::cout<<"Time the min5Heap Operations with "<<nNum<<" values: ";
        timer.start();
            for(int n=0; n<nNum/10; n++)
            {
                zNum = rand()/nNum;
                if((0 <= zNum)&&(zNum < 0.25))
                {
                    heap3.deletemin();
                }
                else if((0.25 <= zNum)&&(zNum < 0.5))
                {
                    heap3.deletemax();
                }
                else
                {
                    iNum = rand()%4*nNum+1;
                    heap3.insert(iNum);
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
                    heap4.deletemin();
                }
                else if((0.25 <= zNum)&&(zNum < 0.5))
                {
                    heap4.deletemax();
                }
                else
                {
                    iNum = rand()%4*nNum+1;
                    heap4.insert(iNum);
                }
            }
            timer.printTime(timer.stop());

        if(i < 10)
        {
            if(!heap3.isEmpty())
            {
                //std::cout<<"Time the min5Heap Delete with "<<nNum<<" values: ";
                //timer2.start();
                //heap3.~min5Heap();
                heap3.resetHeap();
                //timer2.printTime(timer2.stop());
            }
            while(!heap4.isEmpty())
            {
                //std::cout<<"Time the BST Delete with "<<nNum<<" values: ";
                //timer2.start();
                //BST1.deletemin();
                heap4.resetHeap();
                //timer2.printTime(timer2.stop());
            }
        }
        /*else
        {
            heap3.~min5Heap();
            heap4.~minMaxHeap();
        } */       
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
        min5Heap heap5 = min5Heap(nNum);
        minMaxHeap heap6 = minMaxHeap(nNum);
        
        std::cout<<"Time the min5Heap Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                iNum = rand() % 4*nNum + 1;
                heap5.insert(iNum);
            }
        timer.printTime(timer.stop());

        std::cout<<"Time the minMaxHeap Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                iNum = rand() % 4*nNum + 1;
                heap6.insert(iNum);
            }
            timer.printTime(timer.stop());

            std::cout<<"Time the min5Heap Operations with "<<nNum<<" values: ";
        timer.start();
            for(int n=0; n<nNum/10; n++)
            {
                zNum = rand()/nNum;
                if((0 <= zNum)&&(zNum < 0.25))
                {
                    heap5.deletemin();
                }
                else if((0.25 <= zNum)&&(zNum < 0.5))
                {
                    heap5.deletemax();
                }
                else
                {
                    iNum = rand()%4*nNum+1;
                    heap5.insert(iNum);
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
                    heap6.deletemin();
                }
                else if((0.25 <= zNum)&&(zNum < 0.5))
                {
                    heap6.deletemax();
                }
                else
                {
                    iNum = rand()%4*nNum+1;
                    heap6.insert(iNum);
                }
            }
            timer.printTime(timer.stop());

        if(i < 15)
        {
            if(!heap5.isEmpty())
            {
                //std::cout<<"Time the min5Heap Delete with "<<nNum<<" values: ";
                //timer2.start();
                //heap5.~min5Heap();
                heap5.resetHeap();
                //timer2.printTime(timer2.stop());
            }
            while(!heap6.isEmpty())
            {
                //std::cout<<"Time the BST Delete with "<<nNum<<" values: ";
                //timer2.start();
                //BST1.deletemin();
                heap6.resetHeap();
                //timer2.printTime(timer2.stop());
            }
        }
        /*else
        {
            heap5.~min5Heap();
            heap6.~minMaxHeap();
        } */          
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
        min5Heap heap7 = min5Heap(nNum);
        minMaxHeap heap8 = minMaxHeap(nNum);
        
        std::cout<<"Time the min5Heap Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                iNum = rand() % 4*nNum + 1;
                heap7.insert(iNum);
            }
        timer.printTime(timer.stop());

        std::cout<<"Time the minMaxHeap Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                iNum = rand() % 4*nNum + 1;
                heap8.insert(iNum);
            }
            timer.printTime(timer.stop());

            std::cout<<"Time the min5Heap Operations with "<<nNum<<" values: ";
        timer.start();
            for(int n=0; n<nNum/10; n++)
            {
                zNum = rand()/nNum;
                if((0 <= zNum)&&(zNum < 0.25))
                {
                    heap7.deletemin();
                }
                else if((0.25 <= zNum)&&(zNum < 0.5))
                {
                    heap7.deletemax();
                }
                else
                {
                    iNum = rand()%4*nNum+1;
                    heap7.insert(iNum);
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
                    heap8.deletemin();
                }
                else if((0.25 <= zNum)&&(zNum < 0.5))
                {
                    heap8.deletemax();
                }
                else
                {
                    iNum = rand()%4*nNum+1;
                    heap8.insert(iNum);
                }
            }
            timer.printTime(timer.stop());

        if(i < 20)
        {
            if(!heap7.isEmpty())
            {
                //std::cout<<"Time the min5Heap Delete with "<<nNum<<" values: ";
                //timer2.start();
                //heap7.~min5Heap();
                heap7.resetHeap();
                //timer2.printTime(timer2.stop());
            }
            while(!heap8.isEmpty())
            {
                //std::cout<<"Time the BST Delete with "<<nNum<<" values: ";
                //timer2.start();
                //BST1.deletemin();
                heap8.resetHeap();
                //timer2.printTime(timer2.stop());
            }
        }
        /*else
        {
            heap7.~min5Heap();
            heap8.~minMaxHeap();
        }*/           
    }
    return 0;
}

