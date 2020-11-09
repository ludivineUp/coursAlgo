#include "three.h"
#include <stdio.h>

#include "node.h"

using namespace  std;

SearchBinaryThree::SearchBinaryThree(int rootValue)
{
    root = new Node();
    root->value = rootValue;
}
SearchBinaryThree::~SearchBinaryThree(){

}

void SearchBinaryThree::insert(int value, Node* current){
    cout<<"insert "<<value<<" avec dep = "<<current->value<<endl;
    if(current == nullptr){
        current = new  Node();
        current->value = value;
    }else{
        if(value < current->value){
            if(current-> left == nullptr){
                current->left = new Node();
                current->left->value = value;
            }else
                insert(value, current->left);
        }else{
            if(current-> right == nullptr){
                current->right = new Node();
                current->right->value = value;
            }else
                insert(value, current->right);
        }
    }
}
Node* SearchBinaryThree::find(Node* current, int value){
    Node *res;
    if(current->value == value){
        res = current;
        return res;}
    if(current->left != nullptr){
        cout<<"GAUCHE "<<current->left->value<<endl;
        res = find(current->left,value);
        if(res != nullptr && res->value == value){
            return res;}}
    if(current->right != nullptr){
        cout<<"DROITE "<<current->right->value<<endl;
        res = find(current->right,value);
        if(res != nullptr && res->value == value){
            return res;}}
    return res;
}
void SearchBinaryThree::printLargeur(){largeur(root,"");}
void SearchBinaryThree::largeur(Node *tree, string tab)
{
    if(tree != nullptr && (tree->left != nullptr || tree->right != nullptr)){
        cout<<tab<< "Value = " << tree->value << endl;
        if(tree->left != nullptr){
            cout<<tab<< "Value left = " << tree->left->value << endl;
        }
        if(tree->right != nullptr){
            cout<<tab<< "Value right = " << tree->right->value << endl;
        }

        if(tree->left != nullptr){
            largeur(tree->left,tab+"\t");
        }
        if(tree->right != nullptr){
            largeur(tree->right,tab+"\t");
        }

    }
}

