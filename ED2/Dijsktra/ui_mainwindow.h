/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *mapa;
    QLabel *label_2;
    QPushButton *buscaBT;
    QTextBrowser *exibeBrowser;
    QComboBox *destCbBox;
    QCheckBox *todoscaminhosCB;
    QCheckBox *caminhosalterCB;
    QCheckBox *menorCaminhoCB;
    QComboBox *origCbBox;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *matrizBT;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(938, 589);
        MainWindow->setStyleSheet(QStringLiteral("background-color: #fafafa"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        mapa = new QLabel(centralWidget);
        mapa->setObjectName(QStringLiteral("mapa"));
        mapa->setGeometry(QRect(510, 0, 431, 591));
        mapa->setPixmap(QPixmap(QString::fromUtf8("config/mapa.png")));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(410, 0, 441, 541));
        buscaBT = new QPushButton(centralWidget);
        buscaBT->setObjectName(QStringLiteral("buscaBT"));
        buscaBT->setEnabled(true);
        buscaBT->setGeometry(QRect(30, 160, 441, 41));
        buscaBT->setStyleSheet(QLatin1String("background-color: #00AFFA;\n"
"font: 12pt \"Arial\" bold;\n"
"color: white;\n"
"border: none;"));
        exibeBrowser = new QTextBrowser(centralWidget);
        exibeBrowser->setObjectName(QStringLiteral("exibeBrowser"));
        exibeBrowser->setGeometry(QRect(30, 290, 441, 261));
        destCbBox = new QComboBox(centralWidget);
        destCbBox->setObjectName(QStringLiteral("destCbBox"));
        destCbBox->setGeometry(QRect(280, 110, 191, 31));
        todoscaminhosCB = new QCheckBox(centralWidget);
        todoscaminhosCB->setObjectName(QStringLiteral("todoscaminhosCB"));
        todoscaminhosCB->setGeometry(QRect(340, 220, 141, 20));
        todoscaminhosCB->setAutoExclusive(true);
        caminhosalterCB = new QCheckBox(centralWidget);
        caminhosalterCB->setObjectName(QStringLiteral("caminhosalterCB"));
        caminhosalterCB->setGeometry(QRect(30, 220, 161, 20));
        caminhosalterCB->setAutoExclusive(true);
        menorCaminhoCB = new QCheckBox(centralWidget);
        menorCaminhoCB->setObjectName(QStringLiteral("menorCaminhoCB"));
        menorCaminhoCB->setGeometry(QRect(200, 220, 121, 20));
        menorCaminhoCB->setChecked(true);
        menorCaminhoCB->setAutoExclusive(true);
        origCbBox = new QComboBox(centralWidget);
        origCbBox->setObjectName(QStringLiteral("origCbBox"));
        origCbBox->setGeometry(QRect(30, 110, 191, 31));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(190, 10, 131, 51));
        QFont font;
        font.setPointSize(20);
        label_3->setFont(font);
        label_3->setTextFormat(Qt::PlainText);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 70, 59, 31));
        QFont font1;
        font1.setPointSize(12);
        label_4->setFont(font1);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(280, 70, 61, 31));
        label_5->setFont(font1);
        matrizBT = new QPushButton(centralWidget);
        matrizBT->setObjectName(QStringLiteral("matrizBT"));
        matrizBT->setEnabled(true);
        matrizBT->setGeometry(QRect(790, 530, 131, 41));
        matrizBT->setStyleSheet(QLatin1String("background-color: #00AFFA;\n"
"font: 12pt \"Arial\" bold;\n"
"color: white;\n"
"border: none;"));
        MainWindow->setCentralWidget(centralWidget);
        label_2->raise();
        mapa->raise();
        buscaBT->raise();
        exibeBrowser->raise();
        destCbBox->raise();
        todoscaminhosCB->raise();
        caminhosalterCB->raise();
        menorCaminhoCB->raise();
        origCbBox->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        matrizBT->raise();

        retranslateUi(MainWindow);
        QObject::connect(buscaBT, SIGNAL(clicked()), MainWindow, SLOT(searchClick()));

        buscaBT->setDefault(true);
        matrizBT->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Algoritmo de Dijsktra", 0));
        mapa->setText(QString());
        label_2->setText(QString());
        buscaBT->setText(QApplication::translate("MainWindow", "BUSCAR", 0));
        todoscaminhosCB->setText(QApplication::translate("MainWindow", "Todos os caminhos", 0));
        caminhosalterCB->setText(QApplication::translate("MainWindow", "Caminhos alternativos", 0));
        menorCaminhoCB->setText(QApplication::translate("MainWindow", "Melhor Caminho", 0));
        label_3->setText(QApplication::translate("MainWindow", "DIJSKTRA", 0));
        label_4->setText(QApplication::translate("MainWindow", "Origem", 0));
        label_5->setText(QApplication::translate("MainWindow", "Destino", 0));
        matrizBT->setText(QApplication::translate("MainWindow", "Exibir Matriz ", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
