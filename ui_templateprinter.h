/********************************************************************************
** Form generated from reading UI file 'templateprinter.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPLATEPRINTER_H
#define UI_TEMPLATEPRINTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_TemplatePrinter
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;

    void setupUi(QDialog *TemplatePrinter)
    {
        if (TemplatePrinter->objectName().isEmpty())
            TemplatePrinter->setObjectName(QStringLiteral("TemplatePrinter"));
        TemplatePrinter->resize(400, 300);
        lineEdit = new QLineEdit(TemplatePrinter);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(80, 40, 113, 20));
        lineEdit_2 = new QLineEdit(TemplatePrinter);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(80, 70, 113, 20));
        lineEdit_3 = new QLineEdit(TemplatePrinter);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(80, 100, 113, 20));

        retranslateUi(TemplatePrinter);

        QMetaObject::connectSlotsByName(TemplatePrinter);
    } // setupUi

    void retranslateUi(QDialog *TemplatePrinter)
    {
        TemplatePrinter->setWindowTitle(QApplication::translate("TemplatePrinter", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class TemplatePrinter: public Ui_TemplatePrinter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPLATEPRINTER_H
