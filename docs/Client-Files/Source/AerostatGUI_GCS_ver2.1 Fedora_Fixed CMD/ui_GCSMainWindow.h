/********************************************************************************
** Form generated from reading UI file 'GCSMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GCSMAINWINDOW_H
#define UI_GCSMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "qwt_dial.h"

QT_BEGIN_NAMESPACE

class Ui_GCSMainWindow
{
public:
    QAction *actionAdsasilogo;
    QWidget *centralWidget;
    QFrame *weatherSFrame;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *airTempLabel;
    QLabel *BaroLabel;
    QWidget *gridLayoutWidget;
    QGridLayout *WindSpeedgridLayout;
    QwtDial *DialWindDirection;
    QLabel *sLabel;
    QLabel *windAngleLabel;
    QLabel *wLabel;
    QLabel *aerostatHeadingLabel;
    QLabel *nLabel;
    QLabel *eLabel;
    QwtDial *DialAerostatHeading;
    QLabel *airTempLabel_2;
    QLabel *baroValue;
    QLabel *airTempValue;
    QLabel *eBoxTempValue;
    QFrame *frame_2;
    QLabel *label_11;
    QLabel *tensionLabel;
    QWidget *gridLayoutWidget_2;
    QGridLayout *CPTgridLayout;
    QLabel *maxTensionLabel;
    QLabel *maxTensionValue;
    QLabel *tensionValue;
    QFrame *frame_3;
    QLabel *label_14;
    QLabel *heliumLabel;
    QLabel *ballonetLabel;
    QWidget *gridLayoutWidget_4;
    QGridLayout *BallonetGridLayout;
    QWidget *gridLayoutWidget_3;
    QGridLayout *HeliumGridLayout;
    QLabel *heliumValue;
    QLabel *ballonetValue;
    QFrame *frame_4;
    QLabel *label_21;
    QLabel *rollLabel;
    QLabel *label_16;
    QLabel *magHeadingLabel;
    QLabel *label_6;
    QLabel *label_5;
    QWidget *gridLayoutWidget_6;
    QGridLayout *RollGridLayout;
    QWidget *gridLayoutWidget_7;
    QGridLayout *PitchGridLayout;
    QwtDial *DialHeading;
    QLabel *label_10;
    QLabel *label_7;
    QLabel *magentHeadingValue;
    QLabel *pitchValue;
    QLabel *rollValue;
    QFrame *frame_6;
    QLabel *label_19;
    QLabel *logFileLabel_5;
    QLabel *comsStatus;
    QTextEdit *comsTextEdit;
    QGroupBox *fan1GroupBox;
    QVBoxLayout *verticalLayout;
    QLabel *blower1Label;
    QLabel *fan1Widget;
    QRadioButton *fan1OffBtn;
    QRadioButton *fan1OnBtn;
    QGroupBox *fan2GroupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *blower1Label_2;
    QLabel *fan2Widget;
    QRadioButton *fan2OffBtn;
    QRadioButton *fan2OnBtn;
    QGroupBox *strobeGroupBox;
    QVBoxLayout *verticalLayout_3;
    QLabel *blower1Label_3;
    QLabel *strobeWidget;
    QRadioButton *strobeOffBtn;
    QRadioButton *strobeOnBtn;
    QGroupBox *positionGroupBox;
    QVBoxLayout *verticalLayout_4;
    QLabel *blower1Label_4;
    QLabel *positionWidget;
    QRadioButton *positionOffBtn;
    QRadioButton *positionOnBtn;
    QLabel *dateTimeLabel;
    QFrame *frame_7;
    QLabel *label_20;
    QLabel *logFileLabel_12;
    QTextEdit *LogFileTextEdit;
    QPushButton *browseBtn;
    QPushButton *playBtn;
    QPushButton *fwdBtn;
    QPushButton *stopBtn;
    QLabel *label_12;
    QLabel *displayTypeLabel;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GCSMainWindow)
    {
        if (GCSMainWindow->objectName().isEmpty())
            GCSMainWindow->setObjectName(QString::fromUtf8("GCSMainWindow"));
        GCSMainWindow->resize(919, 715);
        GCSMainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(233, 255, 212);"));
        actionAdsasilogo = new QAction(GCSMainWindow);
        actionAdsasilogo->setObjectName(QString::fromUtf8("actionAdsasilogo"));
        centralWidget = new QWidget(GCSMainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        weatherSFrame = new QFrame(centralWidget);
        weatherSFrame->setObjectName(QString::fromUtf8("weatherSFrame"));
        weatherSFrame->setGeometry(QRect(310, 40, 601, 281));
        weatherSFrame->setStyleSheet(QString::fromUtf8("border-color: rgb(168, 168, 168);"));
        weatherSFrame->setFrameShape(QFrame::Box);
        weatherSFrame->setFrameShadow(QFrame::Sunken);
        label_8 = new QLabel(weatherSFrame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(400, 20, 91, 20));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_8->setFont(font);
        label_9 = new QLabel(weatherSFrame);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(210, 10, 161, 20));
        airTempLabel = new QLabel(weatherSFrame);
        airTempLabel->setObjectName(QString::fromUtf8("airTempLabel"));
        airTempLabel->setGeometry(QRect(240, 140, 91, 20));
        BaroLabel = new QLabel(weatherSFrame);
        BaroLabel->setObjectName(QString::fromUtf8("BaroLabel"));
        BaroLabel->setGeometry(QRect(220, 200, 121, 20));
        gridLayoutWidget = new QWidget(weatherSFrame);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(310, 38, 281, 221));
        WindSpeedgridLayout = new QGridLayout(gridLayoutWidget);
        WindSpeedgridLayout->setSpacing(6);
        WindSpeedgridLayout->setContentsMargins(11, 11, 11, 11);
        WindSpeedgridLayout->setObjectName(QString::fromUtf8("WindSpeedgridLayout"));
        WindSpeedgridLayout->setContentsMargins(0, 0, 0, 0);
        DialWindDirection = new QwtDial(weatherSFrame);
        DialWindDirection->setObjectName(QString::fromUtf8("DialWindDirection"));
        DialWindDirection->setGeometry(QRect(-20, 40, 279, 219));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(233, 255, 212, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        DialWindDirection->setPalette(palette);
        DialWindDirection->setLineWidth(4);
        sLabel = new QLabel(weatherSFrame);
        sLabel->setObjectName(QString::fromUtf8("sLabel"));
        sLabel->setGeometry(QRect(110, 190, 21, 17));
        sLabel->setFont(font);
        windAngleLabel = new QLabel(weatherSFrame);
        windAngleLabel->setObjectName(QString::fromUtf8("windAngleLabel"));
        windAngleLabel->setGeometry(QRect(20, 30, 81, 20));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        windAngleLabel->setFont(font1);
        wLabel = new QLabel(weatherSFrame);
        wLabel->setObjectName(QString::fromUtf8("wLabel"));
        wLabel->setGeometry(QRect(60, 140, 21, 17));
        wLabel->setFont(font);
        aerostatHeadingLabel = new QLabel(weatherSFrame);
        aerostatHeadingLabel->setObjectName(QString::fromUtf8("aerostatHeadingLabel"));
        aerostatHeadingLabel->setGeometry(QRect(10, 10, 121, 20));
        aerostatHeadingLabel->setFont(font1);
        nLabel = new QLabel(weatherSFrame);
        nLabel->setObjectName(QString::fromUtf8("nLabel"));
        nLabel->setGeometry(QRect(110, 90, 21, 17));
        nLabel->setFont(font);
        eLabel = new QLabel(weatherSFrame);
        eLabel->setObjectName(QString::fromUtf8("eLabel"));
        eLabel->setGeometry(QRect(160, 140, 16, 17));
        eLabel->setFont(font);
        DialAerostatHeading = new QwtDial(weatherSFrame);
        DialAerostatHeading->setObjectName(QString::fromUtf8("DialAerostatHeading"));
        DialAerostatHeading->setGeometry(QRect(-20, 40, 279, 219));
        DialAerostatHeading->setLineWidth(4);
        airTempLabel_2 = new QLabel(weatherSFrame);
        airTempLabel_2->setObjectName(QString::fromUtf8("airTempLabel_2"));
        airTempLabel_2->setGeometry(QRect(230, 80, 111, 20));
        baroValue = new QLabel(weatherSFrame);
        baroValue->setObjectName(QString::fromUtf8("baroValue"));
        baroValue->setGeometry(QRect(250, 220, 71, 20));
        baroValue->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        airTempValue = new QLabel(weatherSFrame);
        airTempValue->setObjectName(QString::fromUtf8("airTempValue"));
        airTempValue->setGeometry(QRect(250, 160, 61, 20));
        airTempValue->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        eBoxTempValue = new QLabel(weatherSFrame);
        eBoxTempValue->setObjectName(QString::fromUtf8("eBoxTempValue"));
        eBoxTempValue->setGeometry(QRect(260, 100, 51, 20));
        eBoxTempValue->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        label_8->raise();
        gridLayoutWidget->raise();
        DialWindDirection->raise();
        sLabel->raise();
        wLabel->raise();
        aerostatHeadingLabel->raise();
        nLabel->raise();
        eLabel->raise();
        DialAerostatHeading->raise();
        airTempLabel_2->raise();
        baroValue->raise();
        airTempValue->raise();
        eBoxTempValue->raise();
        BaroLabel->raise();
        label_9->raise();
        airTempLabel->raise();
        windAngleLabel->raise();
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 40, 301, 281));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Sunken);
        label_11 = new QLabel(frame_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 10, 231, 20));
        tensionLabel = new QLabel(frame_2);
        tensionLabel->setObjectName(QString::fromUtf8("tensionLabel"));
        tensionLabel->setGeometry(QRect(10, 250, 61, 20));
        gridLayoutWidget_2 = new QWidget(frame_2);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 30, 279, 219));
        CPTgridLayout = new QGridLayout(gridLayoutWidget_2);
        CPTgridLayout->setSpacing(6);
        CPTgridLayout->setContentsMargins(11, 11, 11, 11);
        CPTgridLayout->setObjectName(QString::fromUtf8("CPTgridLayout"));
        CPTgridLayout->setContentsMargins(0, 0, 0, 0);
        maxTensionLabel = new QLabel(frame_2);
        maxTensionLabel->setObjectName(QString::fromUtf8("maxTensionLabel"));
        maxTensionLabel->setGeometry(QRect(210, 230, 91, 21));
        maxTensionValue = new QLabel(frame_2);
        maxTensionValue->setObjectName(QString::fromUtf8("maxTensionValue"));
        maxTensionValue->setGeometry(QRect(210, 250, 81, 20));
        maxTensionValue->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        tensionValue = new QLabel(frame_2);
        tensionValue->setObjectName(QString::fromUtf8("tensionValue"));
        tensionValue->setGeometry(QRect(70, 250, 111, 20));
        tensionValue->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(10, 320, 301, 241));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Sunken);
        label_14 = new QLabel(frame_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(60, 10, 161, 20));
        heliumLabel = new QLabel(frame_3);
        heliumLabel->setObjectName(QString::fromUtf8("heliumLabel"));
        heliumLabel->setGeometry(QRect(40, 190, 91, 20));
        ballonetLabel = new QLabel(frame_3);
        ballonetLabel->setObjectName(QString::fromUtf8("ballonetLabel"));
        ballonetLabel->setGeometry(QRect(180, 190, 91, 20));
        gridLayoutWidget_4 = new QWidget(frame_3);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(150, 30, 141, 161));
        BallonetGridLayout = new QGridLayout(gridLayoutWidget_4);
        BallonetGridLayout->setSpacing(6);
        BallonetGridLayout->setContentsMargins(11, 11, 11, 11);
        BallonetGridLayout->setObjectName(QString::fromUtf8("BallonetGridLayout"));
        BallonetGridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_3 = new QWidget(frame_3);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 30, 139, 161));
        HeliumGridLayout = new QGridLayout(gridLayoutWidget_3);
        HeliumGridLayout->setSpacing(6);
        HeliumGridLayout->setContentsMargins(11, 11, 11, 11);
        HeliumGridLayout->setObjectName(QString::fromUtf8("HeliumGridLayout"));
        HeliumGridLayout->setContentsMargins(0, 0, 0, 0);
        heliumValue = new QLabel(frame_3);
        heliumValue->setObjectName(QString::fromUtf8("heliumValue"));
        heliumValue->setGeometry(QRect(50, 210, 61, 20));
        heliumValue->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        ballonetValue = new QLabel(frame_3);
        ballonetValue->setObjectName(QString::fromUtf8("ballonetValue"));
        ballonetValue->setGeometry(QRect(190, 210, 61, 20));
        ballonetValue->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        frame_4 = new QFrame(centralWidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(310, 320, 601, 241));
        frame_4->setStyleSheet(QString::fromUtf8("border-color: rgb(168, 168, 168);"));
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Sunken);
        label_21 = new QLabel(frame_4);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(340, 190, 51, 20));
        rollLabel = new QLabel(frame_4);
        rollLabel->setObjectName(QString::fromUtf8("rollLabel"));
        rollLabel->setGeometry(QRect(530, 190, 51, 20));
        label_16 = new QLabel(frame_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(250, 10, 141, 17));
        magHeadingLabel = new QLabel(frame_4);
        magHeadingLabel->setObjectName(QString::fromUtf8("magHeadingLabel"));
        magHeadingLabel->setGeometry(QRect(140, 190, 61, 20));
        label_6 = new QLabel(frame_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(100, 200, 21, 17));
        label_6->setFont(font);
        label_5 = new QLabel(frame_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(100, 10, 21, 17));
        label_5->setFont(font);
        gridLayoutWidget_6 = new QWidget(frame_4);
        gridLayoutWidget_6->setObjectName(QString::fromUtf8("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(400, 30, 191, 171));
        RollGridLayout = new QGridLayout(gridLayoutWidget_6);
        RollGridLayout->setSpacing(6);
        RollGridLayout->setContentsMargins(11, 11, 11, 11);
        RollGridLayout->setObjectName(QString::fromUtf8("RollGridLayout"));
        RollGridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_7 = new QWidget(frame_4);
        gridLayoutWidget_7->setObjectName(QString::fromUtf8("gridLayoutWidget_7"));
        gridLayoutWidget_7->setGeometry(QRect(210, 30, 189, 169));
        PitchGridLayout = new QGridLayout(gridLayoutWidget_7);
        PitchGridLayout->setSpacing(6);
        PitchGridLayout->setContentsMargins(11, 11, 11, 11);
        PitchGridLayout->setObjectName(QString::fromUtf8("PitchGridLayout"));
        PitchGridLayout->setContentsMargins(0, 0, 0, 0);
        DialHeading = new QwtDial(frame_4);
        DialHeading->setObjectName(QString::fromUtf8("DialHeading"));
        DialHeading->setGeometry(QRect(20, 30, 187, 167));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush3);
        QBrush brush4(QColor(0, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        QBrush brush5(QColor(255, 255, 220, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush4);
        DialHeading->setPalette(palette1);
        QFont font2;
        font2.setPointSize(8);
        DialHeading->setFont(font2);
        DialHeading->setLineWidth(4);
        label_10 = new QLabel(frame_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(200, 100, 16, 17));
        label_10->setFont(font);
        label_7 = new QLabel(frame_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 100, 16, 17));
        label_7->setFont(font);
        magentHeadingValue = new QLabel(frame_4);
        magentHeadingValue->setObjectName(QString::fromUtf8("magentHeadingValue"));
        magentHeadingValue->setGeometry(QRect(140, 210, 61, 20));
        magentHeadingValue->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        pitchValue = new QLabel(frame_4);
        pitchValue->setObjectName(QString::fromUtf8("pitchValue"));
        pitchValue->setGeometry(QRect(340, 210, 51, 20));
        pitchValue->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        rollValue = new QLabel(frame_4);
        rollValue->setObjectName(QString::fromUtf8("rollValue"));
        rollValue->setGeometry(QRect(530, 210, 51, 20));
        rollValue->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        label_16->raise();
        label_6->raise();
        label_5->raise();
        gridLayoutWidget_6->raise();
        gridLayoutWidget_7->raise();
        DialHeading->raise();
        label_10->raise();
        label_7->raise();
        magentHeadingValue->raise();
        pitchValue->raise();
        rollValue->raise();
        magHeadingLabel->raise();
        label_21->raise();
        rollLabel->raise();
        frame_6 = new QFrame(centralWidget);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(310, 560, 601, 131));
        frame_6->setFrameShape(QFrame::Box);
        frame_6->setFrameShadow(QFrame::Sunken);
        label_19 = new QLabel(frame_6);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(200, 10, 211, 20));
        logFileLabel_5 = new QLabel(frame_6);
        logFileLabel_5->setObjectName(QString::fromUtf8("logFileLabel_5"));
        logFileLabel_5->setGeometry(QRect(240, 40, 101, 20));
        comsStatus = new QLabel(frame_6);
        comsStatus->setObjectName(QString::fromUtf8("comsStatus"));
        comsStatus->setGeometry(QRect(340, 40, 21, 16));
        comsStatus->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
        comsTextEdit = new QTextEdit(frame_6);
        comsTextEdit->setObjectName(QString::fromUtf8("comsTextEdit"));
        comsTextEdit->setGeometry(QRect(240, 60, 121, 61));
        QFont font3;
        font3.setPointSize(9);
        comsTextEdit->setFont(font3);
        fan1GroupBox = new QGroupBox(frame_6);
        fan1GroupBox->setObjectName(QString::fromUtf8("fan1GroupBox"));
        fan1GroupBox->setGeometry(QRect(-11, 16, 131, 111));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fan1GroupBox->sizePolicy().hasHeightForWidth());
        fan1GroupBox->setSizePolicy(sizePolicy);
        fan1GroupBox->setFlat(true);
        verticalLayout = new QVBoxLayout(fan1GroupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        blower1Label = new QLabel(fan1GroupBox);
        blower1Label->setObjectName(QString::fromUtf8("blower1Label"));
        blower1Label->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(blower1Label);

        fan1Widget = new QLabel(fan1GroupBox);
        fan1Widget->setObjectName(QString::fromUtf8("fan1Widget"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Abyssinica SIL"));
        font4.setPointSize(6);
        fan1Widget->setFont(font4);
        fan1Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        verticalLayout->addWidget(fan1Widget);

        fan1OffBtn = new QRadioButton(fan1GroupBox);
        fan1OffBtn->setObjectName(QString::fromUtf8("fan1OffBtn"));
        QFont font5;
        font5.setPointSize(10);
        fan1OffBtn->setFont(font5);

        verticalLayout->addWidget(fan1OffBtn);

        fan1OnBtn = new QRadioButton(fan1GroupBox);
        fan1OnBtn->setObjectName(QString::fromUtf8("fan1OnBtn"));
        fan1OnBtn->setFont(font5);

        verticalLayout->addWidget(fan1OnBtn);

        fan1OffBtn->raise();
        fan1OnBtn->raise();
        blower1Label->raise();
        fan1Widget->raise();
        fan2GroupBox = new QGroupBox(frame_6);
        fan2GroupBox->setObjectName(QString::fromUtf8("fan2GroupBox"));
        fan2GroupBox->setGeometry(QRect(107, 16, 131, 111));
        fan2GroupBox->setFlat(true);
        verticalLayout_2 = new QVBoxLayout(fan2GroupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        blower1Label_2 = new QLabel(fan2GroupBox);
        blower1Label_2->setObjectName(QString::fromUtf8("blower1Label_2"));
        blower1Label_2->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(blower1Label_2);

        fan2Widget = new QLabel(fan2GroupBox);
        fan2Widget->setObjectName(QString::fromUtf8("fan2Widget"));
        fan2Widget->setFont(font4);
        fan2Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        verticalLayout_2->addWidget(fan2Widget);

        fan2OffBtn = new QRadioButton(fan2GroupBox);
        fan2OffBtn->setObjectName(QString::fromUtf8("fan2OffBtn"));
        fan2OffBtn->setFont(font5);

        verticalLayout_2->addWidget(fan2OffBtn);

        fan2OnBtn = new QRadioButton(fan2GroupBox);
        fan2OnBtn->setObjectName(QString::fromUtf8("fan2OnBtn"));
        fan2OnBtn->setFont(font5);

        verticalLayout_2->addWidget(fan2OnBtn);

        strobeGroupBox = new QGroupBox(frame_6);
        strobeGroupBox->setObjectName(QString::fromUtf8("strobeGroupBox"));
        strobeGroupBox->setGeometry(QRect(366, 17, 121, 111));
        strobeGroupBox->setFlat(true);
        verticalLayout_3 = new QVBoxLayout(strobeGroupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        blower1Label_3 = new QLabel(strobeGroupBox);
        blower1Label_3->setObjectName(QString::fromUtf8("blower1Label_3"));
        blower1Label_3->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(blower1Label_3);

        strobeWidget = new QLabel(strobeGroupBox);
        strobeWidget->setObjectName(QString::fromUtf8("strobeWidget"));
        strobeWidget->setFont(font4);
        strobeWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        verticalLayout_3->addWidget(strobeWidget);

        strobeOffBtn = new QRadioButton(strobeGroupBox);
        strobeOffBtn->setObjectName(QString::fromUtf8("strobeOffBtn"));
        strobeOffBtn->setFont(font5);

        verticalLayout_3->addWidget(strobeOffBtn);

        strobeOnBtn = new QRadioButton(strobeGroupBox);
        strobeOnBtn->setObjectName(QString::fromUtf8("strobeOnBtn"));
        strobeOnBtn->setFont(font5);

        verticalLayout_3->addWidget(strobeOnBtn);

        positionGroupBox = new QGroupBox(frame_6);
        positionGroupBox->setObjectName(QString::fromUtf8("positionGroupBox"));
        positionGroupBox->setGeometry(QRect(475, 17, 121, 111));
        positionGroupBox->setFlat(true);
        verticalLayout_4 = new QVBoxLayout(positionGroupBox);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        blower1Label_4 = new QLabel(positionGroupBox);
        blower1Label_4->setObjectName(QString::fromUtf8("blower1Label_4"));
        blower1Label_4->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(blower1Label_4);

        positionWidget = new QLabel(positionGroupBox);
        positionWidget->setObjectName(QString::fromUtf8("positionWidget"));
        positionWidget->setFont(font4);
        positionWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        verticalLayout_4->addWidget(positionWidget);

        positionOffBtn = new QRadioButton(positionGroupBox);
        positionOffBtn->setObjectName(QString::fromUtf8("positionOffBtn"));
        positionOffBtn->setFont(font5);

        verticalLayout_4->addWidget(positionOffBtn);

        positionOnBtn = new QRadioButton(positionGroupBox);
        positionOnBtn->setObjectName(QString::fromUtf8("positionOnBtn"));
        positionOnBtn->setFont(font5);

        verticalLayout_4->addWidget(positionOnBtn);

        logFileLabel_5->raise();
        comsStatus->raise();
        fan2GroupBox->raise();
        comsTextEdit->raise();
        positionGroupBox->raise();
        fan1GroupBox->raise();
        strobeGroupBox->raise();
        label_19->raise();
        dateTimeLabel = new QLabel(centralWidget);
        dateTimeLabel->setObjectName(QString::fromUtf8("dateTimeLabel"));
        dateTimeLabel->setGeometry(QRect(100, 10, 301, 17));
        dateTimeLabel->setFont(font);
        frame_7 = new QFrame(centralWidget);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setGeometry(QRect(10, 560, 301, 131));
        frame_7->setFrameShape(QFrame::Box);
        frame_7->setFrameShadow(QFrame::Sunken);
        label_20 = new QLabel(frame_7);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(100, 10, 121, 20));
        logFileLabel_12 = new QLabel(frame_7);
        logFileLabel_12->setObjectName(QString::fromUtf8("logFileLabel_12"));
        logFileLabel_12->setGeometry(QRect(20, 20, 71, 20));
        LogFileTextEdit = new QTextEdit(frame_7);
        LogFileTextEdit->setObjectName(QString::fromUtf8("LogFileTextEdit"));
        LogFileTextEdit->setGeometry(QRect(20, 40, 261, 41));
        LogFileTextEdit->setFont(font3);
        LogFileTextEdit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        browseBtn = new QPushButton(frame_7);
        browseBtn->setObjectName(QString::fromUtf8("browseBtn"));
        browseBtn->setGeometry(QRect(20, 90, 61, 27));
        QFont font6;
        font6.setPointSize(9);
        font6.setBold(true);
        font6.setWeight(75);
        browseBtn->setFont(font6);
        playBtn = new QPushButton(frame_7);
        playBtn->setObjectName(QString::fromUtf8("playBtn"));
        playBtn->setGeometry(QRect(100, 90, 61, 27));
        playBtn->setFont(font6);
        fwdBtn = new QPushButton(frame_7);
        fwdBtn->setObjectName(QString::fromUtf8("fwdBtn"));
        fwdBtn->setGeometry(QRect(160, 90, 61, 27));
        fwdBtn->setFont(font6);
        stopBtn = new QPushButton(frame_7);
        stopBtn->setObjectName(QString::fromUtf8("stopBtn"));
        stopBtn->setGeometry(QRect(220, 90, 61, 27));
        stopBtn->setFont(font6);
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, -20, 91, 71));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/img/adasi.png")));
        displayTypeLabel = new QLabel(centralWidget);
        displayTypeLabel->setObjectName(QString::fromUtf8("displayTypeLabel"));
        displayTypeLabel->setGeometry(QRect(600, 9, 311, 21));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(displayTypeLabel->sizePolicy().hasHeightForWidth());
        displayTypeLabel->setSizePolicy(sizePolicy1);
        displayTypeLabel->setFont(font);
        displayTypeLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);"));
        GCSMainWindow->setCentralWidget(centralWidget);
        frame_4->raise();
        dateTimeLabel->raise();
        label_12->raise();
        weatherSFrame->raise();
        frame_3->raise();
        frame_2->raise();
        displayTypeLabel->raise();
        frame_6->raise();
        frame_7->raise();
        statusBar = new QStatusBar(GCSMainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GCSMainWindow->setStatusBar(statusBar);

        retranslateUi(GCSMainWindow);

        QMetaObject::connectSlotsByName(GCSMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GCSMainWindow)
    {
        GCSMainWindow->setWindowTitle(QApplication::translate("GCSMainWindow", "Aerostat 200 GCS Telemetry (version 2.1)", 0, QApplication::UnicodeUTF8));
        actionAdsasilogo->setText(QApplication::translate("GCSMainWindow", "Adsasilogo", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Wind Speed</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#aa5500;\">Weather Station</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        airTempLabel->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Air Temp (c)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        BaroLabel->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Baro Pres (inHg)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        sLabel->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">S</p></body></html>", 0, QApplication::UnicodeUTF8));
        windAngleLabel->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:400; color:#0000ff;\">Wind Angle</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        wLabel->setText(QApplication::translate("GCSMainWindow", "W", 0, QApplication::UnicodeUTF8));
        aerostatHeadingLabel->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:400; color:#ff0000;\">Aerostat Heading</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        nLabel->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">N</p></body></html>", 0, QApplication::UnicodeUTF8));
        eLabel->setText(QApplication::translate("GCSMainWindow", "E", 0, QApplication::UnicodeUTF8));
        airTempLabel_2->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Box Temp (c)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        baroValue->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">__</p></body></html>", 0, QApplication::UnicodeUTF8));
        airTempValue->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">__</p></body></html>", 0, QApplication::UnicodeUTF8));
        eBoxTempValue->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">__</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#aa5500;\">Confluence Point Tension (kg)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        tensionLabel->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Tension:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        maxTensionLabel->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Max Tension</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        maxTensionValue->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">__</p></body></html>", 0, QApplication::UnicodeUTF8));
        tensionValue->setText(QApplication::translate("GCSMainWindow", "__", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#aa5500;\">Pressures (inWG)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        heliumLabel->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600;\">Hull Helium</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        ballonetLabel->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-weight:600;\">Ballonet Air</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        heliumValue->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">__</p></body></html>", 0, QApplication::UnicodeUTF8));
        ballonetValue->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">__</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Pitch</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        rollLabel->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Roll</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#aa5500;\">Magnetometer</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        magHeadingLabel->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Heading</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">S</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">N</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">E</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">W</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        magentHeadingValue->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">__</p></body></html>", 0, QApplication::UnicodeUTF8));
        pitchValue->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">__</p></body></html>", 0, QApplication::UnicodeUTF8));
        rollValue->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#0000ff;\">__</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#aa5500;\">Fans/Lights/Radio Link</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        logFileLabel_5->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Coms Status</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        comsStatus->setText(QString());
        fan1GroupBox->setTitle(QString());
        blower1Label->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Fan1</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        fan1Widget->setText(QString());
        fan1OffBtn->setText(QApplication::translate("GCSMainWindow", "Pressure", 0, QApplication::UnicodeUTF8));
        fan1OnBtn->setText(QApplication::translate("GCSMainWindow", "Continuous", 0, QApplication::UnicodeUTF8));
        fan2GroupBox->setTitle(QString());
        blower1Label_2->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Fan2</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        fan2Widget->setText(QString());
        fan2OffBtn->setText(QApplication::translate("GCSMainWindow", "Off", 0, QApplication::UnicodeUTF8));
        fan2OnBtn->setText(QApplication::translate("GCSMainWindow", "Continuous", 0, QApplication::UnicodeUTF8));
        strobeGroupBox->setTitle(QString());
        blower1Label_3->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Strobe</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        strobeWidget->setText(QString());
        strobeOffBtn->setText(QApplication::translate("GCSMainWindow", "Off", 0, QApplication::UnicodeUTF8));
        strobeOnBtn->setText(QApplication::translate("GCSMainWindow", "On", 0, QApplication::UnicodeUTF8));
        positionGroupBox->setTitle(QString());
        blower1Label_4->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Position</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        positionWidget->setText(QString());
        positionOffBtn->setText(QApplication::translate("GCSMainWindow", "Off", 0, QApplication::UnicodeUTF8));
        positionOnBtn->setText(QApplication::translate("GCSMainWindow", "On", 0, QApplication::UnicodeUTF8));
        dateTimeLabel->setText(QString());
        label_20->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#aa5500;\">Data Logging</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        logFileLabel_12->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Log File</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        browseBtn->setText(QApplication::translate("GCSMainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        playBtn->setText(QApplication::translate("GCSMainWindow", "Play", 0, QApplication::UnicodeUTF8));
        fwdBtn->setText(QApplication::translate("GCSMainWindow", "FWD", 0, QApplication::UnicodeUTF8));
        stopBtn->setText(QApplication::translate("GCSMainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        label_12->setText(QString());
        displayTypeLabel->setText(QApplication::translate("GCSMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:600; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">LIVE DATA</p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GCSMainWindow: public Ui_GCSMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GCSMAINWINDOW_H
