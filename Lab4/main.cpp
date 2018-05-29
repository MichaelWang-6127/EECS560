/** 
*   @file:main.cpp
*   @author:Michael Wang
*   @date:09/03/2015
*   Purpose:Main file. Used as the programs entry point.
*/
#include <iostream>
#include <fstream>
#include "Node.h"
#include "BSTNode.h"
#include "BinarySearchTree.h"
//using namespace std;

void printMenu()//prints the menu of instructions
{
    std::cout << "\n\nPlease choose one of the following commands:\n"
            << "1- insert\n"
            << "2- remove\n"
            << "3- deletemin\n"
            << "4- deletemax\n"
            << "5- preorder\n"
            << "6- inorder\n"
            << "7- levelorder\n"
            << "8- exit\n"
            << "Enter your choice: ";
}

int  main(int argc, char const *argv[])//main entry point for the program. runs the menu and the options.
{
	BinarySearchTree BST1;
	int iValue;
	int iOption;

        std::fstream data("data.txt", std::ios_base::in);
        int treeValue;
        while(data>>treeValue)
        {
            BST1.insert(treeValue);
        }

	do
	{
            printMenu();
            std::cin >> iOption;
            if(iOption == 1)
            {
                std::cout << "Please insert the number that you want to be inserted in the tree:";
                std::cin >> iValue;
                BST1.insert(iValue);
            }
            else if(iOption == 2)
            {
                std::cout << "Which number do you like to remove from the tree?:";
                std::cin >> iValue;
                BST1.remove(iValue);
            }
            else if(iOption == 3)
            {
                BST1.deletemin();
            }
            else if(iOption == 4)
            {
                BST1.deletemax();
            }
            else if(iOption == 5)
            {
                //std::cout << "List:";
                BST1.preorder();
            }
            else if(iOption == 6)
            {
                //std::cout << "List:";
                BST1.inorder();
            }
            else if(iOption == 7)
            {
                //std::cout << "List:";
                BST1.levelorder();
            }
            else if (iOption == 8)
            {
                std::cout << "Exiting...\n";
            }
        }while(iOption != 8);

	return 0;
}

