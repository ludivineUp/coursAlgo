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
    // ssArbreG puis la racine puis le SSarbre D
    string infixe(Node* current);   // ou ordre croissant
    // racine puis ssarbre G puis le ssArbre D
    string prefixe(Node* current);
    // ssArbre G, puis le ssArbre D, puis la racine
    string postfixe(Node* current);
    void orderDesc(Node*current);
    /*
     * Si le noeud n'a pas de fils aucun souci
     * s'il a un fils, son fils prend sa place
     * s'il a deux fils, le plus petit fils prend sa place
     * et le plus grand deivent son fils à droite
     */
    void deleteValue(int value);
};

#endif // THREE_H
