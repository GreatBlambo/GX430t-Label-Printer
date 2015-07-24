#include "templateprinter.h"
#include "ui_templateprinter.h"

#include "label.h"
#include "templateparser.h"

#include "winsock_wrapper.h"

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

void TemplatePrinter::on_Cancel_clicked()
{
    this->close();
}

void TemplatePrinter::on_Print_clicked()
{
    Label label(templateFiller(":/templates/template1.xml"));
    QString zbl(label.toString());

    QByteArray zbl_string = zbl.toLocal8Bit();
    const char* zbl_c = zbl_string.data();

    Connection printer_connection;
    int printer_error = setup_connection_TCP(printer_connection, "172.16.216.81", 9100);

    if (printer_error == 1)
        send_data(printer_connection, zbl_c);
}

Label TemplatePrinter::templateFiller(const char * templateFilePath)
{
    /* THIS IMPLEMENTATION IS TEMPORARY
     * In the future, TemplatePrinter will have a container of fields and columns
     * just like the label. The templateFiller will loop through the fields and columns to
     * A) format the label object with enough columns and fields and B) fill in the data from
     * the text fields of the gui. DO NOT rely on this implementation in the future!
     */
    Label tempLabel;
    QFile xmlFile(templateFilePath);
    LabelParser parser(xmlFile, tempLabel);
    parser.start();
    QString line1(ui->lineEdit->displayText());
    QString line2(ui->lineEdit_2->displayText());
    QString line3(ui->lineEdit_3->displayText());

    Column* column = &((tempLabel.getColumns())->at(0));
    Field* field1 = &(column->fields.at(0));
    field1->value = line1;
    Field* field2 = &(column->fields.at(1));
    field2->value = line2;
    Column* column2 = &((tempLabel.getColumns())->at(1));
    Field* field3 = &(column2->fields.at(1));
    field3->value = line3;

    return tempLabel;
}
