#ifndef TEMPLATEPRINTER_H
#define TEMPLATEPRINTER_H

#include <QDialog>

namespace Ui {
class TemplatePrinter;
}

class TemplatePrinter : public QDialog
{
    Q_OBJECT

public:
    explicit TemplatePrinter(QWidget *parent = 0);
    ~TemplatePrinter();

private:
    Ui::TemplatePrinter *ui;
};

#endif // TEMPLATEPRINTER_H
