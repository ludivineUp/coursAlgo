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

    cout<<"60 : "<<t->find(t->root, 60)<<endl;
    cout<<"100 : "<<t->find(t->root, 100)<<endl;
    cout<<"5 : "<<t->find(t->root, 5)<<endl;

    cout<<"Taille root "<<t->nbNode(t->root)<<endl;
    cout<<"Taille root "<<t->nbNode(nullptr)<<endl;

    string s = t->compare(t->root, t->root)?"VRAI":"FAUX";
    cout<<"compare "<< s <<endl;

    cout<< "Infixe "<<t->infixe(t->root)<<endl;
    cout<< "Postfixe "<<t->postfixe(t->root)<<endl;
    cout<< "Prefixe "<<t->prefixe(t->root)<<endl;


    cout<<"On efface l'arbre pour éviter les fuites mémoires"<<endl;
    delete t;

    cout<<"END -- Arbre binaire de recherche"<<endl;
}
