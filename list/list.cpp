#include "list.h"

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
    }else{
        while(current->next != nullptr){
            current = current->next;
        }
        Cell *newCell = new Cell();
        newCell->value = val;
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
    int cpt = 0;
    Cell * current = cell;
    while(cpt < position ){
        current = current->next;
        cpt ++;
    }
    Cell *newCell = new Cell();
    newCell->value = val;
    newCell->next = current->next;
    current->next = newCell;
}
void List::deleteCell(int position){
    int cpt = 0;
    Cell * current = cell;
    while(cpt != position){
        current = current->next;
        cpt ++;
    }
    Cell *toDel = current->next;
    current->next = current->next->next;
    // effacer la cellule en mémoire avec delete.

}
void List::clear(){
    Cell * current = cell;
    while(current != nullptr){
        while(current->next != nullptr){
            current = current->next;
        }
        delete current;
        current = cell;
    }

}
