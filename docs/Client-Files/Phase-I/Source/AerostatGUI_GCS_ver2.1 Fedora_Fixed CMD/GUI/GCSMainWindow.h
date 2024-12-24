/*
 * Copyright (c) 2012, ADASI,
 * All rights reserved.
 *
 * Author Name: Eiman Al Shamisi
 */


#ifndef INCLUDED_GCSMAINWINDOW_H
#define INCLUDED_GCSMAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "ConfluencePointTension.h"
#include "WindSpeed.h"
#include "HeliumPressure.h"
#include "BallonetPressure.h"
#include "Pitch.h"
#include "Roll.h"


extern const char* FANS_OFF_OFF;
extern const char* FANS_ON_OFF;
extern const char* FANS_OFF_ON;
extern const char* FANS_ON_ON;

extern const char* LIGHTS_OFF_OFF;
extern const char* LIGHTS_ON_OFF;
extern const char* LIGHTS_OFF_ON;
extern const char* LIGHTS_ON_ON;

// Forward declaration
class Interface;
class DataLog;

namespace Ui {
class GCSMainWindow;
}


class GCSMainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit GCSMainWindow(Interface *pInterface);
    ~GCSMainWindow();

    // Functions to update field
    void updateTension(double tension, double maxTension);

    void updateAerostatHeading(double heading);

    void updateBaroPresAndTemp(double baroPres, double temp);
    void updateWindDirAndSpeed(double windDir, double windSpeed);

    void updateHeliumPres(double pres);
    void updateBallonetPres(double pres);

    void updateMagnetometerValues(double heading, double pitch, double roll);

    void updateLogFilePath(QString);

    void updateFansAndLights(double temp, QString fan1, QString fan2, QString strobe, QString position);

public slots:
    void updateConnStatus(bool status);

private:
    // User Interface components
    Ui::GCSMainWindow *ui;

    // Fans & Lights command
    const char* m_pCmd;

    // Timer to update Data & Time
    QTimer* m_pTimer;

    // Timer for display type (display recoreded data)
    QTimer* m_pRecordedTimer;

    QTimer* m_pClearDisplayTypeTimer;

    // Format used to display Date and Time
    QString m_dateTimeFormat;

    // Store data after reading it from the log file
    QString m_dataLog;

    // List to group data by lines
    QList<QString> m_allLinesList;

    // List to group lines by time
    QList<int> m_timeBreakPointList;

    // List of fields within line
    QStringList m_fields ;

    // Time to sleep in playing-back data
    quint16 m_uDelay;

    // FWD Action flag
    bool m_bIsFwd;

    // STOP Actoion flag
    bool m_bStop;

    // Palette used to format widgets
    QPalette palette;

    // Instance of dial widget classes
    ConfluencePointTension *m_pCPTDial;
    WindSpeed *m_pWindSpeedDial;
    HeliumPressure *m_pHeliumDial;
    BallonetPressure *m_pBallonetPressureDial;
    Pitch *m_pPitch;
    Roll *m_pRoll;
    Interface *m_pInterface;

    // Functions to draw dial widgets
    void drawCPTPanel();
    void drawWeatherStationPanel();
    void drawPressurePanel();
    void drawMagnetometerPanel();

    // Functions to get the current status of Fans & Lights
    bool getPositionLightStatus();
    bool getStrobeLightStatus();
    bool getBlower1Status();
    bool getBlower2Status();

private slots:
    void updateTime();
    void handleFan1OffControl();
    void handleFan1OnControl();
    void handleFan2OffControl();
    void handleFan2OnControl();
    void handleStrobeOffControl();
    void handleStrobeOnControl();
    void handlePositionOffControl();
    void handlePositionOnControl();
    void browseFile();
    void startPlaying();
    void FWDData();
    void stop();
    void emptyFields();
    void updateDisplayType();
    void clearDisplayTypeText();
    void finishReading();
    void updateGUIFromLog();

 signals:
    void done();
};

#endif // INCLUDED_GCSMAINWINDOW_H
