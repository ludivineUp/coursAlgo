#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    cout << "Main sur la liste simplement chainee" << endl;

    List *l = new List();
    l->add(1);
    l->add(2);
    l->add(3);
    l->add(4);
    l->show();

    cout<<"taille de la liste "<<l->size()<<endl;
    l->show();

    cout<<"première valeur "<<l->first()<<endl;
    l->show();

    cout<<"dernière valeur "<<l->last()<<endl;
    l->show();

    l->insert(10,2);
    l->show();

    l->deleteCell(2);
    l->show();

    cout<<"on efface et c'est fini";
    delete l;
    return 0;
}
