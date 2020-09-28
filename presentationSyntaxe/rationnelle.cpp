#include "rationnelle.h"

Rationnelle::Rationnelle()
{
    n = 1;
    d= 1;
}
Rationnelle::Rationnelle(int i, int j):n(i),d(j){
    if(d < 0){
        d *= -1;
        n *= -1;
    }
    if( d == 0){
        d = 1;
    }
}
Rationnelle::~Rationnelle(){}
void Rationnelle::affiche(){
    cout<<n<<"/"<<d<<endl;
}
Rationnelle Rationnelle::inverse(){
    return Rationnelle(d,n);
}
int Rationnelle::partieReelle(){
    return (int) n/d;
}
int Rationnelle::getD(){
    return d;
}
void Rationnelle::setD(int i){
    d = i;
}
int Rationnelle::getN(){
    return n;
}
void Rationnelle::setN(int i){
    n = i;
}
