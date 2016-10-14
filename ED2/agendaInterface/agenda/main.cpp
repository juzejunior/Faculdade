#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QDesktopWidget dw;
    //setting axis x and y
   // int x= dw.width()*0.7;
   // int y= dw.height()*0.7;
    //move the window to center of screen
    //w.move(QApplication::desktop()->screen()->rect().center() - w.rect().center());
    //define the size of window
    w.setWindowTitle("Agenda");
    //w.setFixedSize(1000,500);
    w.show();

    return a.exec();
}
