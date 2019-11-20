///////////////////////////////////////////////////////////////////////////////
//LUcas Warhurst
//Program 4
// Due 11/01/2019
//
//Description: this file uses the BSTType.h functions
//Input: It will as for user input
//Output: the binary search tree is outputted in all the orders.
///////////////////////////////////////////////////////////////////////////////

#include "BSTType.h"
#include "BTNodeType.h"
#include <iostream>

using namespace std;


int main() {

    BSTType<int> bst;
    int num;
    cout << endl;

    cout << "Enter any positive integer to be inserted. '0' terminates."
	    << endl;
    cin >> num;

    while (num!='0'){
	    bst.insert(num);
	    cin >> num;
	    if(num==0)
		    break;
    }
    cout << endl;

    cout << "Check if empty" << endl;
    if(bst.empty()) {
        cout << "The tree is empty." << endl;
    }
    else {
        cout << "The tree is not empty." << endl;
    }

    cout << endl;

    cout<<"The size of the tree is: " ;
    cout << bst.size() <<endl;
    cout<<endl;
   
    cout << "PRE: \t";
    bst.traverse(cout,PRE);
    cout << endl;

    cout << "IN: \t";
    bst.traverse(cout,IN);
    cout << endl;

    cout << "POST: \t";
    bst.traverse(cout,POST);
    cout << endl<< endl;

    cout << "Enter a number to find. Enter 0 to not use the find feature." << endl;
    cin >> num;
    
    while (num!='0'){

    if(bst.find(num)) {
        cout << num << "  is found." << endl;
    }
    else {
        cout << num <<" is not found." << endl;
    }
   
    cout <<"Enter a number to find. Enter 0 to quit." << endl;
    cin >> num;

    if (num==0)
	    break;
    }

    cout << "Enter a number to erase." << endl;
    cin >> num;
    bst.erase(num);
    cout << num <<" is now erased." << endl;

    cout << endl;

    cout << "The size of the binary search tree is: ";
    cout << bst.size() << endl;

    cout << endl;

    cout << "The new tree looks like this." << endl << endl;

    cout << "PRE: \t";
    bst.traverse(cout,PRE);
    cout << endl;

    cout << "IN: \t";
    bst.traverse(cout,IN);
    cout << endl;

    cout << "POST: \t";
    bst.traverse(cout,POST);
    cout << endl;

    return 0;
}

