#ifndef CMDSEEDER_H
#define CMDSEEDER_H

#include <QMainWindow>
#include <QFileDialog>
#include <QtCore>
#include <QtGui>
#include <stdio.h>
#include <unistd.h>
#include <string>

namespace Ui {
class cmdSeeder;
}

class cmdSeeder : public QMainWindow
{
    Q_OBJECT

public:
    explicit cmdSeeder(QWidget *parent = 0);
    ~cmdSeeder();

private slots:

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionPrint_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionTemplate_triggered();

private:
    Ui::cmdSeeder *ui;
    QString fileName;
};

#endif // CMDSEEDER_H
