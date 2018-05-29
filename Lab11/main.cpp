/** 
*   @file:main.cpp
*   @author:Michael Wang
*   @date:11/16/2016
*   Purpose:Main file. Used as the programs entry point.
*/
#include <iostream>
#include <fstream>
#include "Timer.cpp"
#include "LinkedList.h"
#include "SHNode.h"
#include "SkewHeap.h"
#include "Kruskal.h"
#include "Prim.h"

//using namespace std;

int summation(int upperBound)
{
    int result = 0;
    for(int i = 0; i< upperBound; i++)
    {
        result += i;
    }
    return (result);
}

void printPrimArray(int array[], int size)
{
    for(int i=0; i<size; i++)
    {
        std::cout<<array[i]<<" ";
    }
    std::cout<<"\n";
}

int  main(int argc, char const *argv[])//main entry point for the program. runs the menu and the options.
{
    std::cout<<"Starting the time testing!!!\n";

    int iValue;
    int iNum;
    int nNum;
    int zNum;

    double timeCount;
    Timer timer;
    Timer timer2;

    //working with 50000 numbers
    //___________________________
    //___________________________
    //___________________________
    //___________________________
    //___________________________

   for(int i=1; i <= 5; i++)
    {
        std::cout<<"\nStarting the build!!!\n";
        srand(i);
        nNum = 500;
        //nNum = 10;
        //SkewHeap heap1;
        Kruskal k1;
        Prim p1;

        LinkedList list1 [nNum];

        for(int k=0; k<nNum; k++)
        {
            for(int j = k+1; j<nNum; j++)
            {
                zNum = rand()/nNum;
                if((0 <= zNum)&&(zNum < 0.50))
                {
                    iNum = -1;
                    list1[k].addFront(iNum, k, j);
                }
                else
                {
                    iNum = rand() % (4*nNum) + 1;
                    list1[k].addFront(iNum, k, j);
                }
            }
        }
        
        timer.start();
        k1.KruskalSolver(nNum, list1);
        std::cout<<"Time the Kruskal Algorithm with "<<nNum<<" values: ";
        timer.printTime(timer.stop());

        timer.start();
        p1.PrimSolver(nNum, list1);
        std::cout<<"Time the Prim Algorithm with "<<nNum<<" values: ";
        timer.printTime(timer.stop());        
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
        std::cout<<"\nStarting the build!!!\n";
        srand(i);
        nNum = 1000;
       //SkewHeap heap3;
        Kruskal k3;
        Prim p3;

        LinkedList list3 [nNum];
        
        for(int k=0; k<nNum; k++)
        {
            for(int j = k+1; j<nNum; j++)
            {
                zNum = rand()/nNum;
                if((0 <= zNum)&&(zNum < 0.50))
                {
                    iNum = -1;
                    list3[k].addFront(iNum, k, j);
                }
                else
                {
                    iNum = rand() % (4*nNum) + 1;
                    list3[k].addFront(iNum, k, j);
                }
            }
        }

        timer.start();
        k3.KruskalSolver(nNum, list3);
        std::cout<<"Time the Kruskal Algorithm with "<<nNum<<" values: ";
        timer.printTime(timer.stop());

        timer.start();
        p3.PrimSolver(nNum, list3);
        std::cout<<"Time the Prim Algorithm with "<<nNum<<" values: ";
        timer.printTime(timer.stop());
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
        std::cout<<"\nStarting the build!!!\n";
        srand(i);
        nNum = 2000;
        //SkewHeap heap5;
        Kruskal k5;
        Prim p5;

        LinkedList list5 [nNum];
        
        for(int k=0; k<nNum; k++)
        {
            for(int j = k+1; j<nNum; j++)
            {
                zNum = rand()/nNum;
                if((0 <= zNum)&&(zNum < 0.50))
                {
                    iNum = -1;
                    list5[k].addFront(iNum, k, j);
                }
                else
                {
                    iNum = rand() % (4*nNum) + 1;
                    list5[k].addFront(iNum, k, j);
                }
            }
        }

        timer.start();
        k5.KruskalSolver(nNum, list5);
        std::cout<<"Time the Kruskal Algorithm with "<<nNum<<" values: ";
        timer.printTime(timer.stop());

        timer.start();
        p5.PrimSolver(nNum, list5);
        std::cout<<"Time the Prim Algorithm with "<<nNum<<" values: ";
        timer.printTime(timer.stop());      
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
        std::cout<<"\nStarting the build!!!\n";
        srand(i);
        nNum = 4000;
        //SkewHeap heap7;
        Kruskal k7;
        Prim p7;

        LinkedList list7 [nNum];
        
        for(int k=0; k<nNum; k++)
        {
            for(int j = k+1; j<nNum; j++)
            {
                zNum = rand()/nNum;
                if((0 <= zNum)&&(zNum < 0.50))
                {
                    iNum = -1;
                    list7[k].addFront(iNum, k, j);
                }
                else
                {
                    iNum = rand() % (4*nNum) + 1;
                    list7[k].addFront(iNum, k, j);
                }
            }
        }

        timer.start();
        k7.KruskalSolver(nNum, list7);
        std::cout<<"Time the Kruskal Algorithm with "<<nNum<<" values: ";
        timer.printTime(timer.stop());

        timer.start();
        //p7.PrimSolver(nNum, list7);
        std::cout<<"Time the Prim Algorithm with "<<nNum<<" values: ";
        timer.printTime(timer.stop());
    }
    return 0;
}