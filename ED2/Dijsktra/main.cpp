#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
//#include "matriz.h" // Matriz de adjacencia tio

//string total[20][20];
//vector<string>ruas;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //move a janela para o centro
    w.move(QApplication::desktop()->availableGeometry().center() - w.rect().center());
    w.show();

    return a.exec();
}
