#include "cmdseeder.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    char path[256];

    getcwd(path,255);
    strcat(path,"/");
    strcat(path,argv[0]);

    printf("%s\n", path);

    QApplication a(argc, argv);
    cmdSeeder pad;
    pad.show();

    return a.exec();
}
