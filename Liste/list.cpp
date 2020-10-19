#include "list.h"

List::List(){
    cell = new Cell();
}
// destructeur à la fin
void List::add(int val){
    Cell * current = cell;
    while(current->next != NULL){
        current = current->next;
    }
    Cell *newCell = new Cell();
    newCell->value = val;
    current->next = newCell;
}
void List::show(){
    Cell * current = cell;
    while(current->next != NULL){
        cout << current->value << " - ";
    }
    cout << endl;
}
