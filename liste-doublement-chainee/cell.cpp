#include "cell.h"

Cell::Cell(){
    value = 42;
    next = nullptr;
}
Cell::~Cell(){
    delete next;
}
