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
    int first();
    int last();
    int size();
    void insert(int val, int position);
    void deleteCell(int position);
    void clear();
};

#endif // LIST_H
