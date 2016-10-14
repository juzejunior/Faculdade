#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//buttons handles
private slots:
    void printarMensagem();
    void on_BtnBuscar_clicked();

    void on_information_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
