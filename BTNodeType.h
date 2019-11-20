//////////////////////////////////////////////////////////////////////////
//Lucas Warhurst
//Program 4
//Due: 11/01/2019
//
//Description: The purpse is to declare this to make item, left, right. this file is included in the other .h file.
//////////////////////////////////////////////////////////////////////////

#ifndef BTNODETYPE__H
#define BTNODETYPE__H

#include <iostream>

template <class T>
class BTNodeType {
public:
    T item;
    BTNodeType<T> *left;
    BTNodeType<T> *right;
};

#endif

