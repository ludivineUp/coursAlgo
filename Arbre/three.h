#ifndef THREE_H
#define THREE_H
#include <iostream>
using namespace std;

#include "node.h"

class Three
{
public:
    Three(int rootValue);
    ~Three();
    Node* root;
    void insert(int value, int father);
    void printLargeur();
    void printLargeurNodeLeft(Node* current);
    void printLargeurNodeRight(Node* current);
private:
        Node* find(Node* current, int value);
};

#endif // THREE_H
