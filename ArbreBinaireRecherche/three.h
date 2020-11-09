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
    bool find(Node* current, int value);
    int nbNode(Node* current);
    void deleteNode(Node* current);
    bool compare(Node* root1, Node* root2);
    void infixe(Node* current);
    void prefixe(Node* current);
    void postfixe(Node* current);
    void deleteValue(int value);
private :
    // va stocker les values à afficher dans l'ordre
    int* tabForPrint;
};

#endif // THREE_H
