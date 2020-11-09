#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "plateau.h"
#include <QPushButton>
#include <QFrame>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void nouvellePartie();
private:
    Ui::MainWindow *ui;
    Plateau* plateauJeu;
    QPushButton* newGame;
    QFrame* centralFrame;
};

#endif // MAINWINDOW_H
