#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "algoritmo.cpp"
#include <sstream>

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

    std::vector<int> compressed;
    ifstream input_file;
    ofstream dicionario_file, output_file;

    input_file.open(newName);

    if (!input_file.is_open()) {
        QMessageBox::information(this, tr("Erro"), "Não foi possível abrir o arquivo");
        return;
    }

    std::stringstream buffer;
    buffer << input_file.rdbuf();
    std::string str = buffer.str();
    input_file.close();

    QString qstr = QString::fromStdString(str);
    qDebug() << qstr;

    compress(str, std::back_inserter(compressed));
    output_file.open(strcat(newName, ".lzw"), std::ios::binary);
    if (!output_file.is_open()) {
        QMessageBox::information(this, tr("Erro"), "Não foi possível abrir o arquivo");
        return;
    }
    saveCompress(output_file, compressed);
    output_file.close();

    dicionario_file.open(strcat(newName, ".dict.txt"), std::ios::out);
    dictionaryDestroy(dicionario_file);
    dicionario_file.close();
    exibirDicionario(newName);
}

void MainWindow::on_descomprimirButton_clicked()
{
    if(filename == NULL || filename == ""){
        QMessageBox::information(this, tr("Erro"), "Nenhum arquivo escolhido");
        return;
    }
    QByteArray ba = filename.toLatin1();
    const char *name = ba.data();
    char newName[100];
    strcpy(newName, name);
    ofstream output_file;
    std::vector<int> compressed;
    char ch;
    string content;
    fstream fin(newName, fstream::in);
    while (fin >> noskipws >> ch) {
        if (ch == ' '){
            compressed.push_back(atoi(content.c_str()));
            content = "";
        }else{
            content += ch;
        }
    }
    int length = (int) strlen(newName)-4;
    strncpy(newName, name, length);
    newName[length] = '\0';
    output_file.open(newName, std::ios::out);
    if (!output_file.is_open()) {
        QMessageBox::information(this, tr("Erro"), "Não foi possível abrir o arquivo");
        return;
    }
    string decompressed;
    decompressed = decompress(compressed.begin(), compressed.end());
    saveDecompress(output_file, decompressed);
    output_file.close();
}

void MainWindow::exibirDicionario(char name[])
{
    QFile file(name);
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0, "info", file.errorString());
    QTextStream in(&file);
    ui->detalhesBrowser->setText(in.readAll());
}
