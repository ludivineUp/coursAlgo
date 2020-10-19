#include "cell.h"

Cell::Cell(){
    value = 42;
}
Cell::~Cell(){
    delete next;
}
