/** 
*   @file:main.cpp
*   @author:Michael Wang
*   @date:09/03/2015
*   Purpose:Main file. Used as the programs entry point.
*/
#include <iostream>
#include <fstream>
#include "Node.h"
#include "LinkedList.h"
//using namespace std;

void printMenu()//prints the menu of instructions
{
    std::cout << "\n\nPlease choose one of the following commands:\n"
            << "1- insert\n"
            << "2- delete\n"
            << "3- reverse\n"
            << "4- concatenate\n"
            << "5- print\n"
            << "6- exit\n"
            << "Enter your choice: ";
}

int  main(int argc, char const *argv[])//main entry point for the program. runs the menu and the options.
{
	LinkedList list;
	int iValue;
	int iOption;

        std::fstream data("data.txt", std::ios_base::in);
        int listValue;
        while(data>>listValue)
        {
            list.addBack(listValue);
        }

        LinkedList list2;
        std::fstream data2("data2.txt", std::ios_base::in);
        //int listValue;
        while(data2>>listValue)
        {
            list2.addBack(listValue);
        }

	do
	{
            printMenu();
            std::cin >> iOption;
            if(iOption == 1)
            {
                std::cout << "Choose a number to be inserted to the list:";
                std::cin >> iValue;
                list.insert(iValue);
            }
            else if(iOption == 2)
            {
                std::cout << "Choose a number to be deleted to the list:";
                std::cin >> iValue;
                list.erase(iValue);
            }
            else if(iOption == 3)
            {
                //std::cout << "Calling Mr.Reveser";
                list.reverse();
                //std::cout << "How'd the chat go?";
            }
            else if(iOption == 4)
            {
                list.concatenate(list2);
            }
            else if(iOption == 5)
            {
                //std::cout << "List:";
                list.print();
            }
            else if (iOption == 6)
            {
                std::cout << "Exiting...\n";
            }
        }while(iOption != 6);

        //delete list2;

	return 0;
}

