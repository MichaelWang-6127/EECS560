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
#include "HashTable.h"
//using namespace std;

void printMenu()//prints the menu of instructions
{
    std::cout << "\n\nPlease choose one of the following commands:\n"
            << "1- insert\n"
            << "2- delete\n"
            << "3- print\n"
            << "4- exit\n"
            << "Enter your choice: ";
}

int  main(int argc, char const *argv[])//main entry point for the program. runs the menu and the options.
{
	LinkedList list;
	int iValue;
	int iOption;

        int tableSize;
        
        std::fstream data("data.txt", std::ios_base::in);
        int listValue;
        data>>tableSize;
        
        //std::cout << tableSize;
        
        while(data>>listValue)
        {
            list.addBack(listValue);
        }
        
        HashTable table = HashTable(tableSize);
        
        list.print();
        
        while(!(list.isEmpty()))
        {
            listValue = list.getRemoveFront();
            if(listValue != -1)
            {
                table.insert(listValue);
            }
        }
        

	do
	{
            printMenu();
            std::cin >> iOption;
            if(iOption == 1)
            {
                std::cout << "Which number do you want to insert into the hash table?\n";
                std::cin >> iValue;
                table.insert(iValue);
            }
            else if(iOption == 2)
            {
                std::cout << "Which number do you want to remove from the hash table?\n";
                std::cin >> iValue;
                table.remove(iValue);
            }
            else if(iOption == 3)
            {
                //std::cout << "List:";
                table.print();
            }
            else if (iOption == 4)
            {
                std::cout << "Exiting...\n";
            }
        }while(iOption != 4);

	return 0;
}

