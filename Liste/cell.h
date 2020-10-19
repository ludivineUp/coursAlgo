#ifndef CELL_H
#define CELL_H

class Cell
{
public:
    Cell();
    ~Cell();
    int value;
    Cell *next; // par défaut sa valeur est null si pas instancié
};

#endif // CELL_H
