#include "fenprincipale.h"

FenPrincipale::FenPrincipale(QWidget *parent)
    : QMainWindow(parent)
{
    //Création des menus
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");

    QMenu *fichiersRecents = menuFichier->addMenu("Fichiers &récents");
    fichiersRecents->addAction("Fichier bidon 1.txt");
    fichiersRecents->addAction("Fichier bidon 2.txt");
    fichiersRecents->addAction("Fichier bidon 3.txt");
    QAction *actionQuitter = new QAction("&Quitter", this);
    menuFichier->addAction(actionQuitter);
    actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
    actionQuitter->setIcon(QIcon("quitter.png"));

    QMenu *menuEdition = menuBar()->addMenu("&Edition");
    QAction *actionGras = menuEdition->addAction("Gras");
    actionGras->setCheckable(true);
    actionGras->setShortcut(QKeySequence("Ctrl+G"));
    QMenu *menuAffichage = menuBar()->addMenu("&Affichage");

    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

    // Création de la barre d'outils
    QToolBar *toolBarFichier = addToolBar("Fichier");
    toolBarFichier->addAction(actionQuitter);

    QFontComboBox *choixPolice = new QFontComboBox;
    toolBarFichier->addWidget(choixPolice);
    resize(500,400);
 }

FenPrincipale::~FenPrincipale()
{

}
