#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "algoritmo.cpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_escolherArquivo_clicked()
{
    filename = "";
    filename = QFileDialog::getOpenFileName(
                this,
                tr("Escolha um arquivo"),
                "C://",
                "All files (*.*)"
                );
    if(filename == ""){
        ui->nomeArquivo->setText("Nenhum arquivo escolhido");
        return;
    }else if (filename.length() >= 150){
        filename = "";
        QMessageBox::information(this, tr("Erro"), "Tamanho do caminho muito grande");
        return;
    }
    ui->nomeArquivo->setText(filename);
}

void MainWindow::on_comprimirButton_clicked()
{
    if(filename == NULL || filename == ""){
        QMessageBox::information(this, tr("Erro"), "Nenhum arquivo escolhido");
        return;
    }
    QByteArray ba = filename.toLatin1();
    const char *name = ba.data();
    char newName[150];
    int length = filename.length();
    strcpy(newName, name);
    newName[length] = '\0';
    inputFile = fopen(newName, "r"); // read from the input file (HTML)
    outputFile = fopen(strcat(newName, ".lzw"), "w+b"); // binary write to output file
    dictionaryInput = fopen(strcat(newName, ".dict.txt"), "a");
    if (outputFile == NULL || inputFile == NULL) {
        QMessageBox::information(this, tr("Erro"), "Não foi possível abrir o arquivo");
        return;
    }
    compress(inputFile, outputFile);
    fclose(inputFile); fclose(outputFile); fclose(dictionaryInput);
    inputFile = outputFile = dictionaryInput = NULL;
    exibirDicionario(newName);
}

void MainWindow::on_descomprimirButton_clicked()
{
    if(filename == NULL){
        QMessageBox::information(this, tr("Erro"), "Nenhum arquivo escolhido");
        return;
    }
    QByteArray ba = filename.toLatin1();
    const char *name = ba.data();
    char newName[100];
    strcpy(newName, name);
    inputFile = fopen(newName, "rb"); // read from the input file (HTML)
    int length = (int) strlen(newName)-4;
    strncpy(newName, name, length);
    newName[length] = '\0';
    outputFile = fopen(newName, "w"); // write to output file (HTML)
    if (outputFile == NULL || inputFile == NULL) {
        QMessageBox::information(this, tr("Erro"), "Não foi possível abrir o arquivo");
        return;
    }
    decompress(inputFile, outputFile);
    fclose(inputFile); fclose(outputFile);
    inputFile = outputFile = NULL;
}

void MainWindow::exibirDicionario(char name[])
{
    QFile file(name);
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0, "info", file.errorString());
    QTextStream in(&file);
    ui->detalhesBrowser->setText(in.readAll());
}
