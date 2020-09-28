#include "pony.h"

// l'implémentation de la classe
Pony::Pony()
{
    age = 0;
    nom = "";
    color = "";
}
Pony::Pony(int a, string n, string c): age(a), nom(n),color(c){}

Pony::~Pony(){
    // vide
    // desctructeur ne sert qu'à tuer les pointeurs
}
void Pony::affiche(){
    cout << nom << " : " << age << " - " << color << endl;
}
void Pony::grandit(){
    age++;
}

