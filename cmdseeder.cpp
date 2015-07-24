#include "winsock_wrapper.h"
#include "cmdseeder.h"
#include "ui_cmdseeder.h"
#include "templateparser.h"
#include "label.h"
#include "templateprinter.h"

cmdSeeder::cmdSeeder(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cmdSeeder)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

cmdSeeder::~cmdSeeder()
{
    delete ui;
}

void cmdSeeder::on_actionNew_triggered()
{
    fileName = "";
    ui->textEdit->setPlainText("");
}

void cmdSeeder::on_actionOpen_triggered()
{
    QString inputFile = QFileDialog::getOpenFileName(this, "Open a file.");

    if(!inputFile.isEmpty())
    {
        QFile openFile(inputFile);
        if (openFile.open(QFile::ReadOnly | QFile::Text))
        {
            fileName = inputFile;
            QTextStream in(&openFile);
            QString text = in.readAll();
            openFile.close();

            ui->textEdit->setPlainText(text);
        }
    }
}

void cmdSeeder::on_actionSave_triggered()
{
    QFile saveFile(fileName);

    if(fileName.isEmpty())  //if new file, then save as
    {
        on_actionSave_as_triggered();
    }

    if(saveFile.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out(&saveFile);

        out<< ui->textEdit->toPlainText(); // save to plaintext

        saveFile.flush();
        saveFile.close();
    }

}

void cmdSeeder::on_actionSave_as_triggered()
{
    QString file = QFileDialog::getSaveFileName(this, "Open a file");

    if(!file.isEmpty())
    {
        fileName = file;
        on_actionSave_triggered();
    }
}

void cmdSeeder::on_actionPrint_triggered()
{

    QTextDocument *doc = ui->textEdit->document();
    QString line;

    int lineCount = 0;
    int yCount = 50;

    std::string yNumber;
    const char* yCoordinate;

    QString zbl("");
    QString pre("^XA^FO50,");
    QString preLine("^FS^FO50,");
    QString post("^ADN,36,20^FD");

    QString end("^XZ");

    do {

        yNumber = std::to_string(yCount);
        yCoordinate = yNumber.c_str();

        QString yCoord(yCoordinate);

        line = doc->findBlockByLineNumber(lineCount).text();

        if(lineCount == 0)
            zbl.append(pre);
        else if (lineCount > 0)
            zbl.append(preLine);

        zbl.append(yCoord);
        zbl.append(post);
        zbl.append(line);

        yCount += 50;
        lineCount++;

    } while (line != NULL);

    zbl.append(end);

    QByteArray zbl_string = zbl.toLocal8Bit();
    const char* zbl_c = zbl_string.data();

    Connection printer_connection;
    int printer_error = setup_connection_TCP(printer_connection, "172.16.216.81", 9100);

    if (printer_error == 1)
        send_data(printer_connection, zbl_c);

    zbl.clear();
}

void cmdSeeder::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void cmdSeeder::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void cmdSeeder::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void cmdSeeder::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void cmdSeeder::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}
void cmdSeeder::on_actionTemplate_triggered()
{
/*
    QString inputFile = QFileDialog::getOpenFileName(this, "Open a xml template file to print.", "",
                                                     tr("XML files (*.xml)"));

    if(!inputFile.isEmpty())
    {
        QFile openFile(inputFile);
        Label label;
        LabelParser labelParser(openFile, label);
        labelParser.start();

        QString zbl(label.toString());

        QByteArray zbl_string = zbl.toLocal8Bit();
        const char* zbl_c = zbl_string.data();

        Connection printer_connection;
        int printer_error = setup_connection_TCP(printer_connection, "172.16.216.81", 9100);

        if (printer_error == 1)
            send_data(printer_connection, zbl_c);
    }
*/
    TemplatePrinter templatePrinter;
    templatePrinter.exec();
}
