TEMPLATE = app
TARGET = camera

QT += multimedia multimediawidgets

# The following lines tells Qmake to use pkg-config for opencv
QT_CONFIG -= no-pkg-config
CONFIG  += link_pkgconfig
PKGCONFIG += opencv

HEADERS = \
    ./inc/camera.h \
    ./inc/imagesettings.h \
    ./inc/videosettings.h \
    ./inc/driver.hpp \
    ./inc/logic.hpp \
    ./inc/view.hpp

SOURCES = \
    app.cpp \
    ./src/camera.cpp \
    ./src/imagesettings.cpp \
    ./src/videosettings.cpp \
    ./src/driver.cpp \
    ./src/logic.cpp \
    ./src/view.cpp

FORMS += \
    ./ui/camera.ui \
    ./ui/videosettings.ui \
    ./ui/imagesettings.ui

RESOURCES += camera.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/multimediawidgets/camera
INSTALLS += target

QT+=widgets
include(../../multimedia/shared/shared.pri)
