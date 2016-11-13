#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //move a janela para o centro
    w.move(QApplication::desktop()->availableGeometry().center() - w.rect().center());
    w.show();

    return a.exec();
}
