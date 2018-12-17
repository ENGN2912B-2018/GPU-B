/********************************************************************************
** Form generated from reading UI file 'camera.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERA_H
#define UI_CAMERA_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "qcameraviewfinder.h"

QT_BEGIN_NAMESPACE

class Ui_Camera
{
public:
    QAction *actionExit;
    QAction *actionStartCamera;
    QAction *actionStopCamera;
    QAction *actionSettings;
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QStackedWidget *stackedWidget;
    QWidget *viewfinderPage;
    QGridLayout *gridLayout_5;
    QCameraViewfinder *viewfinder;
    QWidget *previewPage;
    QGridLayout *gridLayout_4;
    QLabel *lastImagePreviewLabel;
    QTabWidget *captureWidget;
    QWidget *tab_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *takeImageButton;
    QSpacerItem *verticalSpacer_2;
    QSlider *exposureCompensation;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QPushButton *muteButton;
    QPushButton *pauseButton;
    QPushButton *recordButton;
    QPushButton *stopButton;
    QSpacerItem *verticalSpacer;
    QPushButton *lockButton;
    QWidget *tab_4;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuDevices;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Camera)
    {
        if (Camera->objectName().isEmpty())
            Camera->setObjectName(QString::fromUtf8("Camera"));
        Camera->resize(1075, 752);
        actionExit = new QAction(Camera);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionStartCamera = new QAction(Camera);
        actionStartCamera->setObjectName(QString::fromUtf8("actionStartCamera"));
        actionStopCamera = new QAction(Camera);
        actionStopCamera->setObjectName(QString::fromUtf8("actionStopCamera"));
        actionSettings = new QAction(Camera);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        centralwidget = new QWidget(Camera);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        stackedWidget = new QStackedWidget(tab_3);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(20, 50, 721, 581));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(145, 145, 145, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        stackedWidget->setPalette(palette);
        viewfinderPage = new QWidget();
        viewfinderPage->setObjectName(QString::fromUtf8("viewfinderPage"));
        gridLayout_5 = new QGridLayout(viewfinderPage);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        viewfinder = new QCameraViewfinder(viewfinderPage);
        viewfinder->setObjectName(QString::fromUtf8("viewfinder"));

        gridLayout_5->addWidget(viewfinder, 0, 0, 1, 1);

        stackedWidget->addWidget(viewfinderPage);
        previewPage = new QWidget();
        previewPage->setObjectName(QString::fromUtf8("previewPage"));
        gridLayout_4 = new QGridLayout(previewPage);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        lastImagePreviewLabel = new QLabel(previewPage);
        lastImagePreviewLabel->setObjectName(QString::fromUtf8("lastImagePreviewLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lastImagePreviewLabel->sizePolicy().hasHeightForWidth());
        lastImagePreviewLabel->setSizePolicy(sizePolicy1);
        lastImagePreviewLabel->setFrameShape(QFrame::Box);

        gridLayout_4->addWidget(lastImagePreviewLabel, 0, 0, 1, 1);

        stackedWidget->addWidget(previewPage);
        captureWidget = new QTabWidget(tab_3);
        captureWidget->setObjectName(QString::fromUtf8("captureWidget"));
        captureWidget->setEnabled(true);
        captureWidget->setGeometry(QRect(810, 110, 171, 306));
        captureWidget->setLayoutDirection(Qt::LeftToRight);
        captureWidget->setTabPosition(QTabWidget::North);
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout = new QGridLayout(tab_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        takeImageButton = new QPushButton(tab_2);
        takeImageButton->setObjectName(QString::fromUtf8("takeImageButton"));
        takeImageButton->setEnabled(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/shutter.svg"), QSize(), QIcon::Normal, QIcon::Off);
        takeImageButton->setIcon(icon);

        gridLayout->addWidget(takeImageButton, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 161, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 0, 1, 1);

        exposureCompensation = new QSlider(tab_2);
        exposureCompensation->setObjectName(QString::fromUtf8("exposureCompensation"));
        exposureCompensation->setMinimum(-4);
        exposureCompensation->setMaximum(4);
        exposureCompensation->setPageStep(2);
        exposureCompensation->setOrientation(Qt::Horizontal);
        exposureCompensation->setTickPosition(QSlider::TicksAbove);

        gridLayout->addWidget(exposureCompensation, 3, 0, 1, 1);

        captureWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        muteButton = new QPushButton(tab);
        muteButton->setObjectName(QString::fromUtf8("muteButton"));
        muteButton->setCheckable(true);

        gridLayout_2->addWidget(muteButton, 4, 0, 1, 1);

        pauseButton = new QPushButton(tab);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));

        gridLayout_2->addWidget(pauseButton, 1, 0, 1, 1);

        recordButton = new QPushButton(tab);
        recordButton->setObjectName(QString::fromUtf8("recordButton"));

        gridLayout_2->addWidget(recordButton, 0, 0, 1, 1);

        stopButton = new QPushButton(tab);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));

        gridLayout_2->addWidget(stopButton, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 76, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 3, 0, 1, 1);

        captureWidget->addTab(tab, QString());
        lockButton = new QPushButton(tab_3);
        lockButton->setObjectName(QString::fromUtf8("lockButton"));
        lockButton->setGeometry(QRect(820, 60, 161, 31));
        tabWidget->addTab(tab_3, QString());
        stackedWidget->raise();
        lockButton->raise();
        captureWidget->raise();
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget->addTab(tab_4, QString());

        gridLayout_3->addWidget(tabWidget, 0, 2, 1, 1);

        Camera->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Camera);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1075, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuDevices = new QMenu(menubar);
        menuDevices->setObjectName(QString::fromUtf8("menuDevices"));
        Camera->setMenuBar(menubar);
        statusbar = new QStatusBar(Camera);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Camera->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuDevices->menuAction());
        menuFile->addAction(actionStartCamera);
        menuFile->addAction(actionStopCamera);
        menuFile->addSeparator();
        menuFile->addAction(actionSettings);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(Camera);
        QObject::connect(actionExit, SIGNAL(triggered()), Camera, SLOT(close()));
        QObject::connect(actionSettings, SIGNAL(triggered()), Camera, SLOT(configureCaptureSettings()));
        QObject::connect(actionStartCamera, SIGNAL(triggered()), Camera, SLOT(startCamera()));
        QObject::connect(actionStopCamera, SIGNAL(triggered()), Camera, SLOT(stopCamera()));
        QObject::connect(stopButton, SIGNAL(clicked()), Camera, SLOT(stop()));
        QObject::connect(exposureCompensation, SIGNAL(valueChanged(int)), Camera, SLOT(setExposureCompensation(int)));
        QObject::connect(takeImageButton, SIGNAL(clicked()), Camera, SLOT(takeImage()));
        QObject::connect(pauseButton, SIGNAL(clicked()), Camera, SLOT(pause()));
        QObject::connect(muteButton, SIGNAL(toggled(bool)), Camera, SLOT(setMuted(bool)));
        QObject::connect(recordButton, SIGNAL(clicked()), Camera, SLOT(record()));
        QObject::connect(lockButton, SIGNAL(clicked()), Camera, SLOT(toggleLock()));

        tabWidget->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);
        captureWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Camera);
    } // setupUi

    void retranslateUi(QMainWindow *Camera)
    {
        Camera->setWindowTitle(QApplication::translate("Camera", "Camera", nullptr));
        actionExit->setText(QApplication::translate("Camera", "Exit", nullptr));
        actionStartCamera->setText(QApplication::translate("Camera", "Start Camera", nullptr));
        actionStopCamera->setText(QApplication::translate("Camera", "Stop Camera", nullptr));
        actionSettings->setText(QApplication::translate("Camera", "Settings", nullptr));
        lastImagePreviewLabel->setText(QString());
        label->setText(QApplication::translate("Camera", "Exposure Compensation:", nullptr));
        takeImageButton->setText(QApplication::translate("Camera", "Capture Photo", nullptr));
        captureWidget->setTabText(captureWidget->indexOf(tab_2), QApplication::translate("Camera", "Image", nullptr));
        muteButton->setText(QApplication::translate("Camera", "Mute", nullptr));
        pauseButton->setText(QApplication::translate("Camera", "Pause", nullptr));
        recordButton->setText(QApplication::translate("Camera", "Record", nullptr));
        stopButton->setText(QApplication::translate("Camera", "Stop", nullptr));
        captureWidget->setTabText(captureWidget->indexOf(tab), QApplication::translate("Camera", "Video", nullptr));
        lockButton->setText(QApplication::translate("Camera", "Focus", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Camera", "Take Picture", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Camera", "Video Analysis", nullptr));
        menuFile->setTitle(QApplication::translate("Camera", "File", nullptr));
        menuDevices->setTitle(QApplication::translate("Camera", "Devices", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Camera: public Ui_Camera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERA_H
