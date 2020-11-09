#include <iostream>
#include "three.h"

using namespace std;

int main()
{
    /* La dernière fois soit ça marchait à gauche mais
     * pas à droite et vice versa
     * Aujourd'hui qu'est ce qui change pour que ça fonctionne
     * aussi bien à droite qu'à gauche
     */
    Three* t = new Three(1);
    t->insert(2,1);
    t->insert(3,1);
    t->insert(4,2);
    t->insert(5,2);
    t->insert(7,3);
    t->insert(6,5);

    t->printLargeur();

}
