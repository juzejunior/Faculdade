#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matrizwindow.h"
#include <QDebug>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pixmap("config/mapa.png");
    ui->mapa->setPixmap(pixmap);
    QPixmap pixmap2("config/sombra.png");
    ui->sombra->setPixmap(pixmap2);
    //ruas
    std::vector<Street> streets;
    //carrega as ruas
    chargeStreets(&streets);
    //carrega as distancias
    chargeDistance();
    //adicione o nome das ruas em cada combobox(origem e destino)
    for(Street street : streets)
    {
        ui->origCbBox->addItem(street.getName());
        ui->origCbBox_2->addItem(street.getName());
        ui->destCbBox->addItem(street.getName());
    }
    ui->origCbBox_2->setVisible(false);
}

void MainWindow::chargeDistance()
{
    QFile file("config/grafo.txt");
    QString origem, destino;
    double distancia;
    //caso ocorra erro ao abrir
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }else{
        //cria as ruas e adiciona no vetor de ruas
        QTextStream in(&file);
        while(!in.atEnd()) {
            //pega o nome da rua completa na linha
            origem = in.readLine();
            distancia = in.readLine().toDouble();
            destino = in.readLine();
            //qInfo() << "Origem: " << origem << "Destino: " << destino << "Distância: " << QString::number(distancia);
            Street orig(origem);
            Street dest(destino);
            //QString nome = "R. Gilberto Amado";
            //adiciona a aresta ao grafo
            qInfo() << "Existencia origem: " << graph.streetIndex(orig) << "Existencia destino: " << graph.streetIndex(dest);
            graph.addEdge(orig, dest, distancia);
        }
    }
}

void MainWindow::searchClick()
{
    //verifica se o menor caminho esta selecionado
    if(ui->menorCaminhoCB->isChecked())
    {
       //pega os valores dos comboboxes
       if(ui->origCbBox->currentText().compare("") != 0 && ui->destCbBox->currentText().compare("") != 0)
       {
           Street origem(ui->origCbBox->currentText());
           Street destino(ui->destCbBox->currentText());
           //onde guardaremos o caminho percorrido
           std::vector<QString> road;
           //caminho final
           QString roads;
           //compara se existe o caminho se existir exibe a distancia
           if(graph.dijkstra(origem, destino, &road) != INF)
           {
               for(int i = road.size() - 1; i >= 0; i--)
               {
                   if(i != 0) roads += road.at(i)+" -> ";
                   else roads += road.at(i);
               }
               //exibe o caminho
               ui->exibeBrowser->setText("Rota:\n\nCaminho: "+roads+"\n\nDistância:\n\nA distância miníma de "+origem.getName()+" até "+destino.getName()+ " são "+QString::number(graph.dijkstra(origem, destino, &road))+" km.");
           }else{
               QMessageBox msgBox;
               msgBox.setText("Não há caminho disponível entre "+origem.getName()+" e "+destino.getName()+"");
               msgBox.exec();
           }
           //ui->exibeBrowser->setText();
       }
    }else if(ui->caminhosalterCB->isChecked())
    {

    }else if(ui->todoscaminhosCB->isChecked())
    {
        Street origem(ui->origCbBox_2->currentText());
        std::vector<std::vector<QString>> todosCaminhos;
        std::vector<QString> roads;
        QString road;
        graph.dijkstra(origem, &roads, &todosCaminhos);
        for(int i = 0 ; i < todosCaminhos.size(); i++)
        {
            for(int j = todosCaminhos.at(i).size() - 1; j >= 0; j--)
            {
                if(j != 0) road += todosCaminhos.at(i).at(j) + " -> ";
                else road += todosCaminhos.at(i).at(j);
            }
            road += "\n\n";
        }
        ui->exibeBrowser->setText("Todos os caminhos de: "+origem.getName() + "\n\n" + road);
    }
}
//este metodo carrega as ruas no arquivo no vetor de ruas
void MainWindow::chargeStreets(std::vector<Street> *streets)
{
    QFile file("config/ruas.txt");
    //caso ocorra erro ao abrir
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }else{
        //cria as ruas e adiciona no vetor de ruas
        QTextStream in(&file);
        while(!in.atEnd()) {
            //pega o nome da rua completa na linha
            QString streetName = in.readLine();
            //cria uma nova rua
            Street street(streetName);
            //adiciona a rua ao nosso vetor
            streets->push_back(street);
        }
        //adiciona as ruas ao grafo
        graph.addStreets(*streets);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_matrizBT_clicked()
{
     MatrizWindow *m = new MatrizWindow();
     m->show();
}

void MainWindow::on_todoscaminhosCB_clicked(bool checked)
{
    if (checked) {
        ui->origCbBox_2->setVisible(true);
        ui->origCbBox->setVisible(false);
        ui->destCbBox->setVisible(false);
        ui->destino->setVisible(false);
    }
}

void MainWindow::on_caminhosalterCB_clicked(bool checked)
{
    if (checked) {
        ui->origCbBox_2->setVisible(false);
        ui->origCbBox->setVisible(true);
        ui->destCbBox->setVisible(true);
        ui->destino->setVisible(true);
    }
}

void MainWindow::on_menorCaminhoCB_clicked(bool checked)
{
    if (checked) {
        ui->origCbBox_2->setVisible(false);
        ui->origCbBox->setVisible(true);
        ui->destCbBox->setVisible(true);
        ui->destino->setVisible(true);
    }
}
