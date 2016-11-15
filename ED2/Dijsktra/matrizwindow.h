#ifndef MATRIZWINDOW_H
#define MATRIZWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QMessageBox>

namespace Ui {
class MatrizWindow;
}

class MatrizWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MatrizWindow(QWidget *parent = 0);
    ~MatrizWindow();
    void showMatriz();

public slots:

private:
    void buildMatrizDeAdjacencia();
    void adicionarBotao();
    Ui::MatrizWindow *ui;
};

#endif // MATRIZWINDOW_H
