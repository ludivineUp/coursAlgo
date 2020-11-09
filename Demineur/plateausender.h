#ifndef PLATEAUSENDER_H
#define PLATEAUSENDER_H


#include "buttondemineur.h"
#include <QFrame>
#include <QPair>

class PlateauSender: public QFrame
{
    Q_OBJECT
public:
    PlateauSender();
public slots:
    void devoileButton(int i, int j);
    void buttonClicked();
signals:
    void coor(int i, int j);
private:
    ButtonDemineur *** buttons;
    int ** valeurButtons;
    void initialiseMine();
    void calculVoisin();
    void majButtonGauche(int i,int j);
    void majButtonDroite(int i,int j);
    void majButtonHaut(int i,int j);
};

#endif // PLATEAUSENDER_H
