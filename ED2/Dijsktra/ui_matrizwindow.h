/********************************************************************************
** Form generated from reading UI file 'matrizwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATRIZWINDOW_H
#define UI_MATRIZWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MatrizWindow
{
public:
    QWidget *centralwidget;
    QTextBrowser *matrizBrowser;
    QPushButton *closeButton;

    void setupUi(QMainWindow *MatrizWindow)
    {
        if (MatrizWindow->objectName().isEmpty())
            MatrizWindow->setObjectName(QStringLiteral("MatrizWindow"));
        MatrizWindow->resize(631, 473);
        centralwidget = new QWidget(MatrizWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        matrizBrowser = new QTextBrowser(centralwidget);
        matrizBrowser->setObjectName(QStringLiteral("matrizBrowser"));
        matrizBrowser->setGeometry(QRect(20, 20, 591, 391));
        matrizBrowser->setStyleSheet(QStringLiteral(""));
        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setEnabled(true);
        closeButton->setGeometry(QRect(250, 420, 131, 41));
        closeButton->setStyleSheet(QLatin1String("background-color: #00AFFA;\n"
"font: 12pt \"Arial\" bold;\n"
"color: white;\n"
"border: none;"));
        MatrizWindow->setCentralWidget(centralwidget);

        retranslateUi(MatrizWindow);
        QObject::connect(closeButton, SIGNAL(clicked()), MatrizWindow, SLOT(close()));

        closeButton->setDefault(true);


        QMetaObject::connectSlotsByName(MatrizWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MatrizWindow)
    {
        MatrizWindow->setWindowTitle(QApplication::translate("MatrizWindow", "Matriz de Adjacencia", 0));
        closeButton->setText(QApplication::translate("MatrizWindow", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class MatrizWindow: public Ui_MatrizWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATRIZWINDOW_H
