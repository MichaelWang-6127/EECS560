/** 
*   @file:main.cpp
*   @author:Michael Wang
*   @date:11/16/2016
*   Purpose:Main file. Used as the programs entry point.
*/
#include <iostream>
#include <fstream>
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
	SkewHeap SH1;
	int iValue;
	int numGraphs;
	int sizeGraphs;
	int arraySize;
	int heapValue;
    int modMod;
    int indexMod;
	//int* array2;
	SkewHeap heap1;
    SkewHeap heap2;
	Kruskal k1;
	Prim p1;

        std::fstream data("data.txt", std::ios_base::in);

        if(data>>numGraphs)
        {
            for(int i = 0; i < numGraphs; i++)
            {
                //SkewHeap heap1;
                //SkewHeap heap2;

            	std::cout<<"Graph"<<i+1<<": \n";
            	if(data>>sizeGraphs)
            	{
                    //std::cout<<sizeGraphs<<"\n";

            		arraySize = summation(sizeGraphs);
                    int array1 [arraySize];
                    int array2 [arraySize];
                    int array3 [arraySize];
                    int array4 [arraySize];
                    int array5 [arraySize];

                    modMod = sizeGraphs-3;
                    indexMod = (-1);

                    //std::cout<<"modMod:"<<modMod<<"\n";
                    //std::cout<<"indexMod:"<<indexMod<<"\n";

                    //std::cout<<arraySize<<"\n";
            		int array[sizeGraphs][sizeGraphs];
            		
                    for(int j = 0; j < sizeGraphs; j++)
            		{
            			for(int k = 0; k < sizeGraphs; k++)
            			{ 
            				if(data>>heapValue)
            				{
            					array[j][k] = heapValue;
            					if(heapValue != 0)
            					{
                                    heap1.insert(heapValue, j, k);
            					}
                                if(j == 0)
                                {
                                    //std::cout<<"inserting into heap2!!!\n";
                                    heap2.insert(heapValue, j, k);
                                }
            					//std::cout<<heapValue<<" ";
            				}
            			}
            			//std::cout<<"\n";
            		}
                    k1.KruskalSolver(sizeGraphs, heap1);

                    //std::cout<<"\n";
                    //std::cout<<sizeGraphs<<"\n";
                    for(int l=0; l<sizeGraphs; l++)
                    {
                        //std::cout<<"modMod:"<<modMod<<"\n";
                        //std::cout<<"indexMod:"<<indexMod<<"\n";
                        for(int n=l; n<sizeGraphs; n++)
                        {
                            if(l != n)
                            {
                                //std::cout<< array[l][n] << " index:"<< ((l+n)+indexMod)<< " \n";
                                array1[(l+n)+indexMod] = array[l][n];
                                array2[(l+n)+indexMod] = l;
                                array3[(l+n)+indexMod] = n;
                                array4[(l+n)+indexMod] = n;
                                array5[(l+n)+indexMod] = l;
                            }
                        }
                        indexMod += modMod;
                        modMod--;
                    }

                    //printPrimArray(array1, arraySize);
                    //printPrimArray(array2, arraySize);
                    //printPrimArray(array3, arraySize);

                    //heap1.levelorder();
                    //heap2.levelorder();

                    p1.PrimSolver(sizeGraphs, heap2, array1, array2, array3, array4, array5);
            	}
            	std::cout<<"\n";
                /*if(!heap1.isEmpty())
                {
                    heap1.~SkewHeap();
                }
                if(!heap2.isEmpty())
                {
                    heap2.~SkewHeap();
                }*/
            }
        }
        else
        {
        	std::cout<<"The data.txt file is empty!!!\n";
        }

    return 0;
}