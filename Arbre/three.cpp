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
        cout<<"GAUCHE"<<endl;
        res = find(current->left,value);
    }
    if(current->right != nullptr){
        cout<<"DROITE"<<endl;
        res = find(current->right,value);
    } else{
            res = nullptr;
    }
    return res;
}
/*
Fonction largeur(nœud)

Afficher (valeur)

Si le nœud est une feuille

    STOP

Sinon Pour tous les fils

    Largeur(fils)
*/
void Three::printLargeur(){
    cout<<"Affichage de l'arbre de racine "<<root->value<<endl;
    cout<<""<<root->value<< "   "<<endl;

    Node * current = root;
    // affiche les fils
    //cout<<""<<current->left->value<< "   "<<endl;
    //cout<<""<<current->right->value<< "   "<<endl;
    while(current != nullptr){
        printLargeurNodeLeft(current);
        printLargeurNodeRight(current);
        current = current->left;
    }

}
void Three::printLargeurNodeLeft(Node* current){
    cout<<""<<current->left->value<< "   "<<endl;;

}
void Three::printLargeurNodeRight(Node* current){
    cout<<""<<current->right->value<< "   "<<endl;;

}
