#ifndef PONY_H
#define PONY_H

#include <string>
#include <iostream>

using namespace  std;

// la déclaration de la classe
class Pony
{
public:
    Pony(); // constructeur
    Pony(int a, string n, string c); // constructeur
    ~Pony(); // destructeur
    void affiche();
    void grandit();
private :
    int age;
    string nom;
    string color;
};

#endif // PONY_H
