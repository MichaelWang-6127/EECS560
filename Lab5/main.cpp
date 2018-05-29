/** 
*   @file:main.cpp
*   @author:Michael Wang
*   @date:10/03/2016
*   Purpose:Main file. Used as the programs entry point.
*/
#include <iostream>
#include <fstream>
#include "Node.h"
#include "LinkedList.h"
#include "min5Heap.h"
//using namespace std;

void printMenu()//prints the menu of instructions
{
    std::cout << "\n\nPlease choose one of the following commands:\n"
            << "1- insert\n"
            << "2- deletemin\n"
            << "3- deletemax\n"
            << "4- remove\n"
            << "5- levelorder\n"
            << "6- exit\n"
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
        min5Heap heap = min5Heap(heapSize);
        
        /*list.print();
        std::cout<<"\n";*/
        
        while(!(list.isEmpty()))
        {
            listValue = list.getRemoveFront();
            if(listValue != -1)
            {
                heap.build(listValue);
            }
        }
        heap.upHeap();
        

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
                std::cout << "Please insert the number that you want to remove from the 5-Heap\n";
                std::cin >> iValue;
                heap.remove(iValue);
            }
            else if(iOption == 5)
            {
                std::cout << "Level order:\n";
                heap.levelorder();
            }
            else if (iOption == 6)
            {
                std::cout << "Exiting...\n";
            }
        }while(iOption != 6);

	return 0;
}

