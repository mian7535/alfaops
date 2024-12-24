/*
 * Copyright (c) 2012-2013, ADASI,
 * All rights reserved.
 *
 * Author Name: Eiman Al Shamisi
 */

#ifndef INCLUDED_INTERFACE_H
#define INCLUDED_INTERFACE_H


#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>
#include <QtCore/QThread>
#include "GUI/GCSMainWindow.h"

#define BUFFER_SIZE 4096

//! Forward declaration of DataLog class
class DataLog;

//! Defination of tension request
extern const char* TENSION_REQ_MSG;


class Interface: public QObject
{
    Q_OBJECT

public:
    Interface();
    ~Interface();
    void connectSockets();
    void disconnectSockets();
public slots:
    void updateFileName(QString);
    void sendCommands(const char* data);

private:
    // Sockets
    QTcpSocket* m_pWxSocket4002;
    QTcpSocket* m_pHMRSocket4003;
    QTcpSocket* m_pBalSocket4004;
    QTcpSocket* m_pHeSocket4005;
    QTcpSocket* m_pADAMSocket4006;
    QTcpSocket* m_pSocket4008;

    // Ports
    quint16 m_uPort4002;
    quint16 m_uPort4003;
    quint16 m_uPort4004;
    quint16 m_uPort4005;
    quint16 m_uPort4006;
    quint16 m_uPort4008;

    // IP Address
    //! Moxa IP address
    QString m_ipAddr;
    //! Moxa Host Address
    QHostAddress *m_pReadAddr;

    // Class Instance
    //! Instance of GUI class
    GCSMainWindow *m_pGUI;
    //! Instance of DataLog class
    DataLog *m_pDataLog;

    // Timers
    //! Timer to check connection with Moxa
    QTimer *m_pCheckGcsConnTimer ;
    //! Timer to send tension request
    QTimer* m_pADAMReqTimer;

    // Thread used to handle the connection check with Moxa
    QThread *m_pCheckConnThread ;

    // Max Tension
    double m_dMaxTension;

    // MAG
    char m_magBuffer[BUFFER_SIZE];
    unsigned int m_MagBytesRead;
    // Ballonet Pressure
    char m_BalPreBuffer[BUFFER_SIZE];
    unsigned int m_BalPreBytesRead;
    // Helium pressure
    char m_HelPreBuffer[BUFFER_SIZE];
    unsigned int m_HelPreBytesRead;
    // ADAM
    char m_ADAMBuffer[BUFFER_SIZE];
    unsigned int m_ADAMBytesRead;
    // PDU
    char m_PDUBuffer[BUFFER_SIZE];
    unsigned int m_PDUBytesRead;

    //Weather station
    char m_WXBuffer[BUFFER_SIZE];
    unsigned int m_WXBytesRead;
    // Method used to read configuration from .ini file
    void parseIniFile();

private slots:
    void handleOnConnectedMode();
    void startConnTimer();
    void checkGCSConnState();
    void startTimer();
    void sendTensionReq();
    void readDigitalCompassSData();
    void readHeliumSData();
    void readBallonetSData();
    void readWeatherSData();
    void readADAMSData();
    void readEBoxData();

signals:
    void connIsupdated(bool);
    void onConnectedMode();
};

#endif // INCLUDED_INTERFACE_H
