#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

//right before commit swap carriage in Git: look up in google
// look for option for line ending
// usability and user experience. Should we prompt the user otherwise?
