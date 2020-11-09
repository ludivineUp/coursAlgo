#ifndef THREE_H
#define THREE_H
#include <iostream>
#include <string>
using namespace std;

#include "node.h"

class SearchBinaryThree
{
public:
    SearchBinaryThree(int rootValue);
    ~SearchBinaryThree();
    Node* root;
    void insert(int value, Node* current);
    void printLargeur();
    void largeur(Node* current, string tab);
    Node* find(Node* current, int value);
};

#endif // THREE_H
