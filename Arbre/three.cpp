#include "three.h"
#include <stdio.h>

#include "node.h"

using namespace  std;

Three::Three(int rootValue)
{
    root = new Node();
    root->value = rootValue;
}
Three::~Three(){

}

void Three::insert(int value, int father){

    cout<<"on insere "<<value<<endl;
    Node* p_father = find(root, father);
    if(p_father != nullptr){
        cout<<"on insere avec papa "<<p_father->value<<endl;
        if(p_father->left == nullptr){
            cout<<"a gauche"<<endl;
            p_father->left = new Node();
            p_father->left->value = value;
        }else{
            cout<<"a droite"<<endl;
            p_father->right = new Node();
            p_father->right->value = value;
        }
    }
}

Node* Three::find(Node* current, int value){
    Node *res;
    if(current->value == value){
        res = current;
        return res;
    }
    if(current->left != nullptr){
        cout<<"GAUCHE "<<current->left->value<<endl;
        res = find(current->left,value);
        if(res != nullptr && res->value == value){
            return res;
        }
    }
    if(current->right != nullptr){
        cout<<"DROITE "<<current->right->value<<endl;
        res = find(current->right,value);
        if(res != nullptr && res->value == value){
            return res;
        }
    }
    return res;
}

void Three::printLargeur(){
    largeur(root,"");
}
void Three::largeur(Node *tree, string tab)
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

