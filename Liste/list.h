#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

#include "cell.h"

class List
{
public:
    List();
    ~List();
    Cell *cell;
    // methods
    void add(int val);
    void show();
    Cell first();
    Cell last();
};

#endif // LIST_H
