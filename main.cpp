#include "mainwindow.h"


#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Camera camera;
    camera.show();

    return app.exec();
}

//right before commit swap carriage in Git: look up in google
// look for option for line ending
// usability and user experience. Should we prompt the user otherwise?
