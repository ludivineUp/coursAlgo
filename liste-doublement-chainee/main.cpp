#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    cout << "Main sur la liste doublement chainee" << endl;

    List *l = new List();
    l->add(1);
    l->add(2);
    l->add(3);
    l->add(4);
    l->show();

    cout<<"TAILLE "<<l->size()<<endl;
    l->show();
    cout << "***********************************************"<<endl<<endl;

    cout<<"PREMIER valeur "<<l->first()<<endl;
    l->show();
    cout << "***********************************************"<<endl<<endl;

    cout<<"dernière valeur "<<l->last()<<endl;
    l->show();
    cout << "***********************************************"<<endl<<endl;

    cout<<"insertion"<<endl;
    l->insert(10,2);
    l->show();
    cout << "***********************************************"<<endl<<endl;

     cout<<"suppression"<<endl;
    l->deleteCell(2);
    l->show();
    cout << "***********************************************"<<endl<<endl;

    cout<<"on efface et c'est fini";
    delete l;
    return 0;
}
