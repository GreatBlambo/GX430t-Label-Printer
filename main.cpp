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

    return a.exec();
}

