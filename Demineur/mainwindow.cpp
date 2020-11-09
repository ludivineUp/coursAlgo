#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "plateau.h"

#include <QFrame>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    plateauJeu = new Plateau();
    newGame = new QPushButton("Nouvelle partie");
    centralFrame = new QFrame();
    QVBoxLayout* centralFrameLayout = new QVBoxLayout();
    centralFrameLayout->addWidget(plateauJeu);
    centralFrameLayout->addWidget(newGame);
    centralFrame->setLayout(centralFrameLayout);
    setCentralWidget(centralFrame);
    connect(newGame,SIGNAL(clicked()),this,SLOT(nouvellePartie()));
    // Récupérer les arguments de la ligne de commande
   // const QStringList args = QCoreApplication::arguments();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::nouvellePartie()
{
    plateauJeu = new Plateau();
    centralFrame = new QFrame();
    QVBoxLayout* centralFrameLayout = new QVBoxLayout();
    centralFrameLayout->addWidget(plateauJeu);
    centralFrameLayout->addWidget(newGame);
    centralFrame->setLayout(centralFrameLayout);
    setCentralWidget(centralFrame);
}


