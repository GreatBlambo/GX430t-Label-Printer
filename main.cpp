#include "cmdseeder.h"
#include "templateparser.h"
#include "label.h"
#include <QApplication>
#include <QDebug>
#include <iostream>
/*
Column ColumnTest()
{
    Column returnColumn;
    Field testField;

    testField.name = "TestName";
    testField.value = "TestValue";

    returnColumn.addField(testField);

    return returnColumn;
}*/


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
    /*
    Column testColumn = ColumnTest();
    qDebug(testColumn.fields.at(0).name.toLatin1());
    */
    return a.exec();
}

