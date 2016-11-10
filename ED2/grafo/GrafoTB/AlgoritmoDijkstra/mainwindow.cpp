#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("/home/mateus/Pictures/foto2");
    ui->label->setPixmap(pix);

    QPixmap pix2("/home/mateus/Pictures/sombra");
    ui->label_2->setPixmap(pix2);
}

MainWindow::~MainWindow()
{
    delete ui;
}
