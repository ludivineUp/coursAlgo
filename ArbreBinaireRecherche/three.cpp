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
    deleteNode(root);
}
void SearchBinaryThree::deleteNode(Node* current){
    if(current == nullptr){
        return; // prorpe en c++
    }
    deleteNode(current->left);
    deleteNode(current->right);
    cout<<"on delete "<<current->value<< endl;
    delete current;
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
bool SearchBinaryThree::find(Node* current, int value){
    if(current == nullptr){
        return false;
    }else{
        if(current->value == value){
            return true;
        }else{
            if(current->value > value){
                return find(current->left,value);
            }else{
                return find(current->right,value);
            }
        }
    }
}
int SearchBinaryThree::nbNode(Node* current){
    if(current == nullptr){
        return 0;
    }else{
        return 1 + nbNode(current->left) + nbNode(current->right);
    }
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
bool SearchBinaryThree::compare(Node* root1, Node* root2){
    if(root1 == nullptr){
        return root2 == nullptr;
    }else if(root2 != nullptr){
        return (root1->value == root2->value)
                && compare(root1->left, root2->left)
                && compare(root1->right, root2->right);
    }else{
        return false;
    }
}

string SearchBinaryThree::infixe(Node* current){
    if(current == nullptr){
        return "";
    }else{
        return infixe(current->left) + " " + to_string(current->value)
                + " " + infixe(current->right);
    }
}
string SearchBinaryThree::prefixe(Node* current){if(current == nullptr){
        return "";
    }else{
        return to_string(current->value) + " " + prefixe(current->left)
                + " " + prefixe(current->right);
    }}
string SearchBinaryThree::postfixe(Node* current){
    if(current == nullptr){
        return "";
    }else{
        return postfixe(current->left) + " " + postfixe(current->right)
                + " " + to_string(current->value);
    }}
void SearchBinaryThree::orderDesc(Node*current){
    if(current != nullptr){
        orderDesc(current->right);
        cout << current->value << " ";
        orderDesc(current->left);
    }
}

void SearchBinaryThree::deleteValue(int value){}
