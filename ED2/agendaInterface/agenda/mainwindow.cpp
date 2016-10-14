#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "contato.h"
#include "arvoreB.h"
#include <QMessageBox>

using namespace std;
//dicionario
Apontador dicionario;

//init the program
MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setting the logo
    QPixmap pix("/home/blackwolf/agenda/image/logo.png");
    ui->labelLogo->setPixmap(pix);//logo
    //init the tree
    inicializa(&dicionario);
    //set pre checked search
    ui->searchCheck->setChecked(true);

    Contato c;
    strcpy(c.nome,"junior");

    //search list
    for(int i = 0; i < 10; i++){
        ui->searchList->addItem(c.nome);
    }

}

//void MainWindow::search

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printarMensagem()
{
    if(ui->searchCheck->isChecked())
    {
        QMessageBox::information(this,"Mensagem", "busca simples ativada!");
    }else{
        QMessageBox::information(this,"Mensagem", "busca simples desativada");
    }
}
//on searched button clicked - The main menu
void MainWindow::on_BtnBuscar_clicked()
{
    Contato c;
    //simple search
    if(ui->searchCheck->isChecked())
    {
        QString search = ui->EtxBuscar->text();
        if(search != NULL)
        {
            QMessageBox::information(this,"Mensagem", search);
        }else{
            QMessageBox::information(this,"Alerta", "Escreva o que procura na caixa de busca!");
        }
    }
}

void MainWindow::on_information_clicked()
{
    // ui->searchList->item();
}
