#ifndef THREE_H
#define THREE_H
#include <iostream>
#include <string>
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
    void largeur(Node* current, string tab);
private:
        Node* find(Node* current, int value);
};

#endif // THREE_H
