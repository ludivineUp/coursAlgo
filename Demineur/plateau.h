#ifndef PLATEAU_H
#define PLATEAU_H

#include <QPushButton>
#include <QFrame>
#include <QPair>

class Plateau: public QFrame
{
    Q_OBJECT
public:
    Plateau();
public slots:
    void devoileButton(QString c);
signals:
    void coor(QString c);
private:
    QPushButton *** buttons;
    int ** valeurButtons;
    void initialiseMine();
    void calculVoisin();
    void majButtonGauche(int i,int j);
    void majButtonDroite(int i,int j);
    void majButtonHaut(int i,int j);
};

#endif // PLATEAU_H
