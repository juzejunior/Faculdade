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
    QPushButton *comprimirButton;
    QPushButton *descomprimirButton;
    QLabel *label;
    QTextBrowser *detalhesBrowser;
    QTextBrowser *nomeArquivo;
    QPushButton *escolherArquivo;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(411, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        comprimirButton = new QPushButton(centralWidget);
        comprimirButton->setObjectName(QStringLiteral("comprimirButton"));
        comprimirButton->setGeometry(QRect(40, 119, 131, 31));
        descomprimirButton = new QPushButton(centralWidget);
        descomprimirButton->setObjectName(QStringLiteral("descomprimirButton"));
        descomprimirButton->setGeometry(QRect(240, 120, 131, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 30, 231, 20));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft NeoGothic"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setTextFormat(Qt::AutoText);
        label->setScaledContents(false);
        detalhesBrowser = new QTextBrowser(centralWidget);
        detalhesBrowser->setObjectName(QStringLiteral("detalhesBrowser"));
        detalhesBrowser->setGeometry(QRect(10, 170, 391, 111));
        nomeArquivo = new QTextBrowser(centralWidget);
        nomeArquivo->setObjectName(QStringLiteral("nomeArquivo"));
        nomeArquivo->setGeometry(QRect(10, 70, 371, 31));
        escolherArquivo = new QPushButton(centralWidget);
        escolherArquivo->setObjectName(QStringLiteral("escolherArquivo"));
        escolherArquivo->setGeometry(QRect(280, 70, 121, 31));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        comprimirButton->setText(QApplication::translate("MainWindow", "Comprimir", 0));
        descomprimirButton->setText(QApplication::translate("MainWindow", "Descomprimir", 0));
        label->setText(QApplication::translate("MainWindow", "Algoritmo de Compress\303\243o LZW", 0));
        detalhesBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">Programa desenvolvido para o trabalho de Estrutura de Dados 2 da Universidade do Estado da Bahia.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">Desenvolvedores:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Sh"
                        "ell Dlg 2'; font-size:8.25pt;\">        - Fernando Maia</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">        - Jos\303\251 Di\303\264go</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">        - Mateus Nascimento</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">        - Wellington Correia</span></p></body></html>", 0));
        nomeArquivo->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:10pt;\">Nenhum arquivo escolhido</span></p></body></html>", 0));
        escolherArquivo->setText(QApplication::translate("MainWindow", "Escolher Arquivo", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
