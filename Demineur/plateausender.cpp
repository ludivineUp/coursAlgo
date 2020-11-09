#include "plateausender.h"
#include "buttondemineur.h"

#include <QGridLayout>
#include <QDebug>
#include <QSignalMapper>
#include <QPair>
#include <QPalette>
#include <QColor>
#include <math.h>

PlateauSender::PlateauSender():QFrame()
{
    // Allocation mémoire du tableau de boutons
    QGridLayout* _layout = new QGridLayout();
    buttons = new ButtonDemineur**[10];
    for(int i = 0; i < 10; i++){
        buttons[i]= new ButtonDemineur*[10];
    }

    // Création des boutons et le lien entre le click et la gestion du bouton
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            buttons[i][j] = new  ButtonDemineur(i,j);
            buttons[i][j]->setFixedSize(40,40);
            connect( buttons[i][j],SIGNAL(clicked()),this, SLOT(buttonClicked()));
            _layout->addWidget(buttons[i][j],i,j);
            _layout->setSpacing(0);
        }
    }
    setLayout(_layout);
    connect(this,SIGNAL(coor(int,int)),this,SLOT(devoileButton(int,int)));

    setFixedSize(400,400);
    valeurButtons = new int*[10];
    for(int i = 0; i < 10; i++){
        valeurButtons[i]= new int[10];
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            valeurButtons[i][j] = 0;
        }
    }
    initialiseMine();
    calculVoisin();
}
void PlateauSender::buttonClicked(){
    // on récupère l'objet qui a envoyé le signal au slot buttonCLicked
    ButtonDemineur * bouttonPresse = (ButtonDemineur *) sender();
    emit coor(bouttonPresse->getI(),bouttonPresse->getJ());
}

void PlateauSender::initialiseMine()
{
    for(int i = 0; i < 10; i++){
        int x = rand()%10;
        int y = rand()%10;
        //qDebug();
        if(valeurButtons[x][y] == -1)--i;
        valeurButtons[x][y] = -1;


    }
    for(int i = 0; i < 10; i++){
        QString s = "";
        for(int j = 0; j < 10; j++){
            s = s + QString::number( valeurButtons[i][j]);
            s = s + "  ";
        }
        qDebug() << s;
    }
    qDebug();
}

void PlateauSender::calculVoisin()
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
                int sum = 0;
                 if(j< 9) {
                    if(valeurButtons[i][j+1] == -1)sum++;
                    if( i > 0){
                         if(valeurButtons[i-1][j+1] == -1)sum++;
                         if(valeurButtons[i-1][j] == -1)sum++;}
                    if(i<9) {
                        if(valeurButtons[i+1][j+1] == -1)sum++;
                        if(valeurButtons[i+1][j] == -1)sum++; }
                }
                if(j > 0){
                     if(valeurButtons[i][j-1] == -1)sum++;
                    if( i > 0){
                         if(valeurButtons[i-1][j-1] == -1)sum++;}
                    if(i<9){
                        if(valeurButtons[i+1][j-1] == -1)sum++; }
                }
                if(valeurButtons[i][j] != -1){
                    valeurButtons[i][j] = sum;
                }
            //}
        }
    }


    for(int i = 0; i < 10; i++){
        QString s = "";
        for(int j = 0; j < 10; j++){
            s = s + QString::number( valeurButtons[i][j]);
            s = s + "  ";
        }
        qDebug() << s;
    }
    qDebug();
}

void PlateauSender::devoileButton(int i, int j)
{
    if(valeurButtons[i][j] == -1){
        buttons[i][j]->setStyleSheet("background-color: red;");
        buttons[i][j]->setEnabled(false);
        setEnabled(false);
    }else{
        majButtonGauche(i,j);
        //majButtonDroite(i,j);
    }
}

void PlateauSender::majButtonGauche(int i,int j){
    if(valeurButtons[i][j] == 0  && buttons[i][j]->isEnabled()){
        buttons[i][j]->setEnabled(false);
        if(j< 9){
            majButtonGauche(i,j+1);
            if( i > 0){
                majButtonGauche(i-1,j+1);
                majButtonGauche(i-1,j);
            }
            if(i<9){
                majButtonGauche(i+1,j+1);
                majButtonGauche(i+1,j);
            }
        }
        if(j > 0){
            majButtonGauche(i,j-1);
            if( i > 0){
                majButtonGauche(i-1,j-1);
            }
            if(i<9)
            {
                majButtonGauche(i+1,j-1);
            }
        }
        /*int yMin = i - 1 >= 0 ? i - 1 : 0;
        int yMax = i + 1 < 9 ? i + 1 : 10 - 1;
        int xMin = j - 1 > 0 ? j - 1 : 0;
        int xMax = j + 1 < 9 ? j + 1 : 10 - 1;
        for (int y2 = yMin; y2 <= yMax; y2++) {
            for (int x2 = xMin; x2 <= xMax; x2++) {
                if((x2 != j || y2 != i)) {
                    qDebug() << y2<<"   "<<x2;
                    majButton(y2,x2);
                }
            }
        }*/
    }else if( buttons[i][j]->isEnabled() &&
              valeurButtons[i][j] != -1){
        buttons[i][j]->setEnabled(false);
        buttons[i][j]->setText(QString::number(valeurButtons[i][j]));
    }

}

void PlateauSender::majButtonDroite(int i,int j)
{
    if(valeurButtons[i][j] == 0 && buttons[i][j]->isEnabled()){
        buttons[i][j]->setEnabled(false);
        if(j > 0)
        {
            majButtonDroite(i,j-1);
            if( i > 0)
            {
                majButtonDroite(i-1,j-1);
            }
            if(i<9)
            {
                majButtonDroite(i+1,j-1);
            }
        }

        /*int yMin = i - 1 >= 0 ? i - 1 : 0;
        int yMax = i + 1 < 9 ? i + 1 : 10 - 1;
        int xMin = j - 1 > 0 ? j - 1 : 0;
        int xMax = j + 1 < 9 ? j + 1 : 10 - 1;
        for (int y2 = yMin; y2 <= yMax; y2++) {
            for (int x2 = xMin; x2 <= xMax; x2++) {
                if((x2 != j || y2 != i)) {
                    qDebug() << y2<<"   "<<x2;
                    majButton(y2,x2);
                }
            }
        }*/
    }else if( buttons[i][j]->isEnabled()){
        buttons[i][j]->setEnabled(false);
        buttons[i][j]->setText(QString::number(valeurButtons[i][j]));
    }

}











//delete [ ] Matrice;
