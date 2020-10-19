#include <iostream>
#include "three.h"

using namespace std;

int main()
{
    Three* t = new Three(1);
    t->insert(2,1);
    t->insert(3,1);
    t->insert(4,2);
    t->insert(5,2);
    t->insert(7,3);
    //t->printLargeurNode(t->root);

    t->printLargeur();

}
