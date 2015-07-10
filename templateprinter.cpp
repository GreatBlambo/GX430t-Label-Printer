#include "templateprinter.h"
#include "ui_templateprinter.h"

TemplatePrinter::TemplatePrinter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TemplatePrinter)
{
    ui->setupUi(this);
}

TemplatePrinter::~TemplatePrinter()
{
    delete ui;
}
