// LinkedlistDemo2024.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Linkedlist.h"
using namespace std;

int main()
{
    //Create a linkedlist name myList
    Linkedlist<char> myList;
    myList.addFirst('A');
    myList.addFirst('B');
    myList.addFirst('C');
    myList.addFirst('D');
    myList.printList();
    cout << endl;

    myList.insertAfter('B', 'F');
    myList.printList();
    cout << endl;

    myList.insertBefore('A', 'G');
    myList.printList();
    cout << endl;

    myList.Remove('C');
    myList.printList();
    cout << endl;
    

    myList.addLast('H');
    myList.printList();
    cout << endl;

    Linkedlist<char> copyed_list;
    cout << "The copyed linkedlist:" << endl;
    copyed_list=myList.copy();
    copyed_list.printList();
    cout << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
