/********************************************************************************
** Form generated from reading UI file 'cmdseeder.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CMDSEEDER_H
#define UI_CMDSEEDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cmdSeeder
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionPrint;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionCopy;
    QAction *actionCut;
    QAction *actionPaste;
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *cmdSeeder)
    {
        if (cmdSeeder->objectName().isEmpty())
            cmdSeeder->setObjectName(QStringLiteral("cmdSeeder"));
        cmdSeeder->resize(400, 300);
        actionNew = new QAction(cmdSeeder);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/icons/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(cmdSeeder);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/icons/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave = new QAction(cmdSeeder);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionSave_as = new QAction(cmdSeeder);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionPrint = new QAction(cmdSeeder);
        actionPrint->setObjectName(QStringLiteral("actionPrint"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/icons/print.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint->setIcon(icon3);
        actionUndo = new QAction(cmdSeeder);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/icons/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon4);
        actionRedo = new QAction(cmdSeeder);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/icons/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon5);
        actionCopy = new QAction(cmdSeeder);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/icons/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon6);
        actionCut = new QAction(cmdSeeder);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/icons/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon7);
        actionPaste = new QAction(cmdSeeder);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/icons/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon8);
        centralWidget = new QWidget(cmdSeeder);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(40, 30, 104, 84));
        cmdSeeder->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(cmdSeeder);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 29));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        cmdSeeder->setMenuBar(menuBar);
        mainToolBar = new QToolBar(cmdSeeder);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        cmdSeeder->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(cmdSeeder);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        cmdSeeder->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addSeparator();
        menuFile->addAction(actionPrint);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionPaste);
        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionSave);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionPrint);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionUndo);
        mainToolBar->addAction(actionRedo);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionCopy);
        mainToolBar->addAction(actionCut);
        mainToolBar->addAction(actionPaste);

        retranslateUi(cmdSeeder);

        QMetaObject::connectSlotsByName(cmdSeeder);
    } // setupUi

    void retranslateUi(QMainWindow *cmdSeeder)
    {
        cmdSeeder->setWindowTitle(QApplication::translate("cmdSeeder", "cmdSeeder", 0));
        actionNew->setText(QApplication::translate("cmdSeeder", "New", 0));
        actionOpen->setText(QApplication::translate("cmdSeeder", "Open", 0));
        actionSave->setText(QApplication::translate("cmdSeeder", "Save", 0));
        actionSave_as->setText(QApplication::translate("cmdSeeder", "Save as...", 0));
        actionPrint->setText(QApplication::translate("cmdSeeder", "Print", 0));
        actionUndo->setText(QApplication::translate("cmdSeeder", "Undo", 0));
        actionRedo->setText(QApplication::translate("cmdSeeder", "Redo", 0));
        actionCopy->setText(QApplication::translate("cmdSeeder", "Copy", 0));
        actionCut->setText(QApplication::translate("cmdSeeder", "Cut", 0));
        actionPaste->setText(QApplication::translate("cmdSeeder", "Paste", 0));
        menuFile->setTitle(QApplication::translate("cmdSeeder", "File", 0));
        menuEdit->setTitle(QApplication::translate("cmdSeeder", "Edit", 0));
    } // retranslateUi

};

namespace Ui {
    class cmdSeeder: public Ui_cmdSeeder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMDSEEDER_H
