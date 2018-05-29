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
//using namespace std;

void printMenu()//prints the menu of instructions
{
    std::cout << "\n\nPlease choose one of the following commands:\n"
            << "1- insert\n"
            << "2- deletemin\n"
            << "3- preorder\n"
            << "4- inorder\n"
            << "5- levelorder\n"
            << "6- exit\n"
            << "Enter your choice: ";
}

int  main(int argc, char const *argv[])//main entry point for the program. runs the menu and the options.
{
	LeftistHeap LH1;
	int iValue;
	int iOption;

    //std::cout<<"This returns if the heap is empty"<<LH1.isEmpty()<<"\n";

        std::fstream data("data.txt", std::ios_base::in);
        int heapValue;
        while(data>>heapValue)
        {
            LH1.insert(heapValue);
        }

	do
	{
            printMenu();
            std::cin >> iOption;
            if(iOption == 1)
            {
                std::cout << "Please insert the number that you want to be inserted in the heap:";
                std::cin >> iValue;
                LH1.insert(iValue);
            }
            else if(iOption == 2)
            {
                LH1.deletemin();
            }
            else if(iOption == 3)
            {
                //std::cout << "List:";
                LH1.preorder();
            }
            else if(iOption == 4)
            {
                //std::cout << "List:";
                LH1.inorder();
            }
            else if(iOption == 5)
            {
                //std::cout << "List:";
                LH1.levelorder();
            }
            else if (iOption == 6)
            {
                std::cout << "Exiting...\n";
            }
        }while(iOption != 6);

	return 0;
}

