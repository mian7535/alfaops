/*
 * Copyright (c) 2012, ADASI,
 * All rights reserved.
 *
 * Author Name: Eiman Al Shamisi
 */
#include <QtGui/QApplication>
#include "GUI/GCSMainWindow.h"
#include "Interface.h"
#include <QtCore/QObject>

#include "GUI/ConfluencePointTension.h"
#include "GUI/WindSpeed.h"
#include "GUI/HeliumPressure.h"
#include "GUI/BallonetPressure.h"
#include "GUI/Pitch.h"
#include "GUI/Roll.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // GCSMainWindow w;
   //  ConfluencePointTension w;
    // WindSpeed w;
    // HeliumPressure w;
   // BallonetPressure w;
    // Pitch w;
    // Roll w;
    // w.show();
    Interface c;

    return a.exec();
}
