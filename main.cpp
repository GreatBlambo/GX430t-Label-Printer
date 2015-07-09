#include "cmdseeder.h"
#include "templateparser.h"
#include "label.h"
#include "winsock_wrapper.h"
#include <QApplication>
#include <QDebug>
#include <iostream>



int main(int argc, char *argv[])
{
    char path[256];

    getcwd(path,255);
    strcat(path,"/");
    strcat(path,argv[0]);

    printf("%s\n", path);

    QApplication a(argc, argv);

    Q_INIT_RESOURCE(templates);
    cmdSeeder pad;
    pad.show();

    QFile xmlFile(":/templates/template1.xml");
    Label label;
    LabelParser labelParser(xmlFile, label);
    labelParser.start();

    QString zbl = label.toString();
    qDebug(zbl.toLatin1());
/*
    QByteArray zbl_string = zbl.toLocal8Bit();
    const char* zbl_c = zbl_string.data();
    Connection printer_connection;

    int printer_error = setup_connection_TCP(printer_connection, "172.16.216.81", 9100);

    if (printer_error == 1)
        send_data(printer_connection, zbl_c);
*/

    return a.exec();
}

