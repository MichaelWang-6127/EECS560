/** 
*   @file:main.cpp
*   @author:Michael Wang
*   @date:11/01/2015
*   Purpose:Main file. Used as the programs entry point.
*/
#include <iostream>
#include <fstream>
#include "Node.h"
#include "LHNode.h"
#include "LeftistHeap.h"
#include "SkewHeap.h"
#include "Timer.cpp"
//using namespace std;

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
        std::cout<<"Starting the build!!!\n";
        srand(i);
        nNum = 50000;
        LeftistHeap heap1;
        SkewHeap heap2;
        
        std::cout<<"Time the LeftistHeap Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                iNum = rand() % 4*nNum + 1;
                heap1.insert(iNum);
            }
        timer.printTime(timer.stop());

        std::cout<<"Time the SkewHeap Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                iNum = rand() % 4*nNum + 1;
                heap2.insert(iNum);
            }
        timer.printTime(timer.stop());

            std::cout<<"Time the LeftistHeap Operations with "<<nNum<<" values: ";
        timer.start();
            for(int n=0; n<nNum/10; n++)
            {
                zNum = rand()/nNum;
                if((0 <= zNum)&&(zNum < 0.50))
                {
                    heap1.deletemin();
                }
                else
                {
                    iNum = rand()%4*nNum+1;
                    heap1.insert(iNum);
                }
            }
            timer.printTime(timer.stop());

        std::cout<<"Time the SkewHeap Operations with "<<nNum<<" values: ";
        timer.start();
            for(int n=0; n<nNum/10; n++)
            {
                zNum = rand()/nNum;
                if((0 <= zNum)&&(zNum < 0.50))
                {
                    heap2.deletemin();
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
                heap1.~LeftistHeap();
            }
            if(!heap2.isEmpty())
            {
                heap2.~SkewHeap();
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
        LeftistHeap heap3;
        SkewHeap heap4;
        
        std::cout<<"Time the LeftistHeap Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                iNum = rand() % 4*nNum + 1;
                heap3.insert(iNum);
            }
        timer.printTime(timer.stop());

        std::cout<<"Time the SkewHeap Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                iNum = rand() % 4*nNum + 1;
                heap4.insert(iNum);
            }
            timer.printTime(timer.stop());

            std::cout<<"Time the LeftistHeap Operations with "<<nNum<<" values: ";
        timer.start();
            for(int n=0; n<nNum/10; n++)
            {
                zNum = rand()/nNum;
                if((0 <= zNum)&&(zNum < 0.50))
                {
                    heap3.deletemin();
                }
                else
                {
                    iNum = rand()%4*nNum+1;
                    heap3.insert(iNum);
                }
            }
            timer.printTime(timer.stop());

        std::cout<<"Time the SkewHeap Operations with "<<nNum<<" values: ";
        timer.start();
            for(int n=0; n<nNum/10; n++)
            {
                zNum = rand()/nNum;
                if((0 <= zNum)&&(zNum < 0.50))
                {
                    heap4.deletemin();
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
                heap3.~LeftistHeap();
            }
            if(!heap4.isEmpty())
            {
                heap4.~SkewHeap();
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
        LeftistHeap heap5;
        SkewHeap heap6;
        
        std::cout<<"Time the LeftistHeap Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                iNum = rand() % 4*nNum + 1;
                heap5.insert(iNum);
            }
        timer.printTime(timer.stop());

        std::cout<<"Time the SkewHeap Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                iNum = rand() % 4*nNum + 1;
                heap6.insert(iNum);
            }
            timer.printTime(timer.stop());

            std::cout<<"Time the LeftistHeap Operations with "<<nNum<<" values: ";
        timer.start();
            for(int n=0; n<nNum/10; n++)
            {
                zNum = rand()/nNum;
                if((0 <= zNum)&&(zNum < 0.50))
                {
                    heap5.deletemin();
                }
                else
                {
                    iNum = rand()%4*nNum+1;
                    heap5.insert(iNum);
                }
            }
            timer.printTime(timer.stop());

        std::cout<<"Time the SkewHeap Operations with "<<nNum<<" values: ";
        timer.start();
            for(int n=0; n<nNum/10; n++)
            {
                zNum = rand()/nNum;
                if((0 <= zNum)&&(zNum < 0.50))
                {
                    heap6.deletemin();
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
                heap5.~LeftistHeap();
            }
            if(!heap6.isEmpty())
            {
                heap6.~SkewHeap();
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
        LeftistHeap heap7;
        SkewHeap heap8;
        
        std::cout<<"Time the LeftistHeap Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                iNum = rand() % 4*nNum + 1;
                heap7.insert(iNum);
            }
        timer.printTime(timer.stop());

        std::cout<<"Time the SkewHeap Build with "<<nNum<<" values: ";
        timer.start();
            for(int k=0; k<nNum; k++)
            {
                iNum = rand() % 4*nNum + 1;
                heap8.insert(iNum);
            }
            timer.printTime(timer.stop());

            std::cout<<"Time the LeftistHeap Operations with "<<nNum<<" values: ";
        timer.start();
            for(int n=0; n<nNum/10; n++)
            {
                zNum = rand()/nNum;
                if((0 <= zNum)&&(zNum < 0.50))
                {
                    heap7.deletemin();
                }
                else
                {
                    iNum = rand()%4*nNum+1;
                    heap7.insert(iNum);
                }
            }
            timer.printTime(timer.stop());

        std::cout<<"Time the SkewHeap Operations with "<<nNum<<" values: ";
        timer.start();
            for(int n=0; n<nNum/10; n++)
            {
                zNum = rand()/nNum;
                if((0 <= zNum)&&(zNum < 0.50))
                {
                    heap8.deletemin();
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
                heap7.~LeftistHeap();
            }
            if(!heap8.isEmpty())
            {
                heap8.~SkewHeap();
            }
        }
    }
    return 0;
}



