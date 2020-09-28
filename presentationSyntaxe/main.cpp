#include <iostream>
#include <string>
#include "Pony.h"

using namespace std;

void permut1(int n, int m){ // passage par copie, donc les modifications ne sortent pas de la fonction
    int tmp = n;
    n  = m;
    m = tmp;
    // les retours multiples sont interdits, on ne retourne d'une valeur
}

// la référence c'est juste avoir un autre identifiant sur la même varaible
void permut(int &n, int &m);    // signature avant le main pour l'appeler dans le main
                                // passage par référence donc les modifications sont définitives
                                // ce passage de param est plus lent que le passage par copie

void permutPointeurs(int *n, int *m);

int main()
{
    int a, c;
    a = 10;
    c = 20;
    permut(a,c);
    cout << "a : "<< a << " et c : " << c <<endl;
    // Affichage (endl affiche un saut de ligne)
    cout << "Hello World!" << "coucou" << endl << "truc";
    cout << "machin" << endl;

    // Type de données
    int n;  // une variable a par défaut la valeur de son adresse mémoire
    cout << n << endl;

    n = 5;
    bool b = true;
    b = 1; // 1 est équivalent à true et 0 à false
    cout << b << endl;

    double x = 3.14;

    string s = "toto";

    // saisie clavier
    // cin >> s >> x;
    cout << s << endl << x <<endl;

    // opérateurs + - / =  % == != <= >= < > *
    // pas de triple égale car les données sont typées et le compilateur impose que les comparaisons sont faites entre types compatibles
    // opérateurs logique && || !

    // instruction
    if(n=5){        // affectation renvoie true
        cout << "n est égale à 5"<<endl;
    }
    if(3){
        cout << "un nombre positif est équivalent à un true"<<endl;
    }else if(-1){
        cout << "un nombre négatif => false";
    }

    // while, do while, for(int i=0;i<n;i++){}, pas de boucle foreach

    // références
    int z = 34;
    int &r = z; // r est le nouvel identifiant de z, c'est une référence à z
    r = 76;
    cout << " z == " << z << endl; // r et z ont la même case mémoire

    // pointeurs : c'est sert tout simplement à bien organiser la mémoire
    int *p_a = new int; // un pointeur d'entier
    *p_a = 3 ; // la valeur pointée est de 3
    int *p_c = new int; // un pointeur d'entier
    *p_c = 5 ; // la valeur pointée est de 3
    permutPointeurs(p_a, p_c);
    cout << "permut avec pointeurs"<< endl;
    cout << "a : "<< *p_a << " et c : " << *p_c <<endl;
    permutPointeurs(&a,&c);

    // on doit tuer chaque pointeur créer un mew imppose un delete
    delete p_a;
    delete p_c;

    // object : un objet est en gors ene mémoire, donc pointeurs
    Pony *licorne = new Pony(666, "luci", "rouge");
    licorne->affiche(); // pointeur d'objet -> pour appeler une méthode
    licorne->grandit();
    licorne->affiche();

    delete licorne;

    // Pourquoi le main retourne un entier?
    // car c'est le code erreur du programme, 0 ok, 1 crash, 3 telle erreur...
    return 0;
}

void permut(int &n, int &m){
    int tmp = n;
    n  = m;
    m = tmp;
}
void permutPointeurs(int *n, int *m){
    int tmp = *n;
    *n  = *m;
    *m = tmp;
}
