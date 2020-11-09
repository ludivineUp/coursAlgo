#include <iostream>
#include "three.h"

using namespace std;

int main()
{
    cout<<"Arbre binaire de recherche"<<endl;
    SearchBinaryThree* t = new SearchBinaryThree(25);
    t->insert(60, t->root);
    t->insert(35, t->root);
    t->insert(10, t->root);
    t->insert(5, t->root);
    t->insert(20, t->root);
    t->insert(65, t->root);
    t->insert(45, t->root);
    t->insert(70, t->root);
    t->insert(40, t->root);
    t->insert(50, t->root);
    t->insert(55, t->root);
    t->insert(30, t->root);
    t->insert(15, t->root);

    t->printLargeur();

    cout<<"END -- Arbre binaire de recherche"<<endl;
}
