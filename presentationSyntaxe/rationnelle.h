#ifndef RATIONNELLE_H
#define RATIONNELLE_H
#include <iostream>

using namespace std;

class Rationnelle
{
public:
    Rationnelle();
    Rationnelle(int i, int j);
    ~Rationnelle();
    void affiche();
    Rationnelle inverse();
    int partieReelle();
    int getD();
    void setD(int i);
    int getN();
    void setN(int i);
private:
    int n;
    int d;
};

#endif // RATIONNELLE_H
