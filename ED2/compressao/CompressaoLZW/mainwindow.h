#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextStream>
#include <QMessageBox>
#include<QFileDialog>
#include <QDebug>
#include <QFile>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString filename;
    FILE *inputFile, *outputFile, *dictionaryInput;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void imprimirArquivo();
    void exibirDicionario(char name[]);
    void compress(FILE *inputFile, FILE *outputFile);
    void dictionaryDestroy();

private slots:
    void on_escolherArquivo_clicked();

    void on_comprimirButton_clicked();

    void on_descomprimirButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
