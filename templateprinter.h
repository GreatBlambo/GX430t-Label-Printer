#ifndef TEMPLATEPRINTER_H
#define TEMPLATEPRINTER_H

#include <QDialog>
#include <QFileDialog>
#include "label.h"

namespace Ui {
class TemplatePrinter;
}

class TemplatePrinter : public QDialog
{
    Q_OBJECT

public:
    explicit TemplatePrinter(QWidget *parent = 0);
    ~TemplatePrinter();

private slots:
    void on_Cancel_clicked();

    void on_Print_clicked();

private:
    Label templateFiller(const char * templateFilePath); //fills in a template with the text fields

    Ui::TemplatePrinter *ui;
};

#endif // TEMPLATEPRINTER_H
