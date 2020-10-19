#include "list.h"
// ajouter les pointeurs previous et leur gestion

List::List(){
    cell = nullptr;
}
List::~List(){
    clear();
}
void List::add(int val){
    Cell * current = cell;
    // premier cas la liste est vide
    if(cell == nullptr){
        cell = new Cell();
        cell->value = val;
        cell->previous = nullptr;
    }else{
        while(current->next != nullptr){
            current = current->next;
        }
        Cell *newCell = new Cell();
        newCell->value = val;
        newCell->previous = current;
        current->next = newCell;
    }
}
void List::show(){
    Cell * current = cell;
    while(current->next != nullptr){
        cout << current->value << " - ";
        current = current->next;
    }
    cout << current->value << endl;

    cout<< "previous & next for each element"<<endl;
    Cell * current2 = cell;
    while(current2->next != nullptr){
           cout<< current2->value << " previous : ";
           if(current2->previous != nullptr){
              cout << current2->previous->value;
           }else{
               cout << "NULL";
           }
           cout<<" - next :";
           if(current2->next != nullptr){
              cout << current2->next->value;
           }else{
               cout << "NULL";
           }
           cout<<endl;
           current2 = current2->next;
    }
    cout<< current2->value << " previous : ";
    if(current2->previous != nullptr){
       cout << current->previous->value;
    }else{
        cout << "NULL";
    }
    cout<<" - next :";
    if(current2->next != nullptr){
       cout << current2->next->value;
    }else{
        cout << "NULL";
    }
    cout<<endl;
}
int List::first(){
    return cell->value;
}
int List::last(){
    Cell * current = cell;
    while(current->next != nullptr){
        current = current->next;
    }
    return current->value;
}
int List::size(){
    int res = 0;
    if( cell != nullptr){
        Cell * current = cell;
        while(current->next != nullptr){
            current = current->next;
            res ++;
        }
    }
    return ++res; //res++ n'est pas bon
    // i = 0; i = i++; => i vaut 0

}
void List::insert(int val, int position){
    int cpt = 1;
    Cell * current = cell;
    while(cpt < position ){
        current = current->next;
        cpt ++;
    }
    Cell *newCell = new Cell();
    newCell->value = val;
    newCell->next = current->next;
    newCell->previous = current;
    current->next->previous = newCell;
    current->next = newCell;
}
void List::deleteCell(int position){
    int cpt = 1;
    Cell * current = cell;
    while(cpt != position){
        current = current->next;
        cpt ++;
    }
    Cell *toDel = current->next;
    current->next = current->next->next;
    current->next->previous = current;
    toDel->next = nullptr;
    toDel->previous= nullptr;
    delete toDel;
}
void List::clear(){
    cout<<endl;
    Cell * current = cell;
    while(current->next != nullptr){
            current = current->next;
    }
    while(current != nullptr){
            current = current->previous;
            //cout<<"on est à : "<<current<<" - "<<current->value<<endl;
            current->next->previous = nullptr;
            //cout<<"on suppr : "<<current->next<<" - "<<current->next->value<<endl;   // si affiche 0x0 == pointeur null
            delete current->next;
            current->next = nullptr;
    }
    delete current;
}
