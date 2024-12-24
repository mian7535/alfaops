/*
 * Copyright (c) 2012-2014, ADASI,
 * All rights reserved.
 *
 * Author Name: Eiman Al Shamisi
 */


#include <QSettings>
#include <cmath>
#include "Interface.h"
#include "DataLog.h"


// The command used to send tension request
const char* TENSION_REQ_MSG = "#01\r";


/*!
 * Constructor
 */
Interface::Interface()
{
    // Instance of GUI class
    m_pGUI = new GCSMainWindow(this);
    m_pGUI->show();


    // Instance of Data Log class
    m_pDataLog = new DataLog(this, this);

    // QThread to check connection with MOXA
    m_pCheckConnThread = new QThread(this);
    connect(m_pCheckConnThread, SIGNAL(started()), this, SLOT(startConnTimer()), Qt::DirectConnection);
    m_pCheckConnThread->start();

    connect(this, SIGNAL(connIsupdated(bool)), m_pGUI, SLOT(updateConnStatus(bool)));
    connect(this, SIGNAL(onConnectedMode()), this, SLOT(handleOnConnectedMode()));

    // Initialize sockets
    m_pWxSocket4002 = new QTcpSocket(this);
    m_pHMRSocket4003 = new QTcpSocket(this);
    m_pBalSocket4004 = new QTcpSocket(this);
    m_pHeSocket4005 = new QTcpSocket(this);
    m_pADAMSocket4006 = new QTcpSocket(this);
    m_pSocket4008 = new QTcpSocket(this);

    // Max tension
    m_dMaxTension = 0.0;
    // Read ports & IP address configuration from ini file
    parseIniFile();

    //MAG
    ::memset(m_magBuffer, 0, BUFFER_SIZE);
    m_MagBytesRead = 0;
    //Ballonet pressure
    ::memset(m_BalPreBuffer,0,BUFFER_SIZE);
    m_BalPreBytesRead = 0;
    //Helium Pressure
    ::memset(m_HelPreBuffer,0,BUFFER_SIZE);
    m_HelPreBytesRead = 0;
    //ADAM
    ::memset(m_ADAMBuffer,0,BUFFER_SIZE);
    m_ADAMBytesRead = 0;
    // PDU
    ::memset(m_PDUBuffer,0,BUFFER_SIZE);
    m_PDUBytesRead = 0;
    // WX
    ::memset(m_WXBuffer, 0, BUFFER_SIZE);
    m_WXBytesRead = 0;


}
//=================================================================================================


/*!
 * Destructor
 */
Interface::~Interface()
{
    qDebug() << "Delete Thread";
    //    m_pCheckGcsConnTimer->stop();
    //    delete m_pCheckGcsConnTimer;
    //    m_pCheckConnThread->exit(0);
    //    delete m_pCheckConnThread;

}
//=================================================================================================

/*!
 * Connect readyRead signal of TCP Sockets to Slot that handles reading received packets
 */
void Interface::connectSockets()

{
    // Connect Sockets with Moxa IP address & ports
    m_pReadAddr = new QHostAddress(m_ipAddr);
    m_pWxSocket4002->connectToHost(m_ipAddr, m_uPort4002);
    m_pHMRSocket4003->connectToHost(m_ipAddr, m_uPort4003);
    m_pBalSocket4004->connectToHost(m_ipAddr, m_uPort4004);
    m_pHeSocket4005->connectToHost(m_ipAddr, m_uPort4005);
    m_pADAMSocket4006->connectToHost(m_ipAddr, m_uPort4006);
    m_pSocket4008->connectToHost(m_ipAddr, m_uPort4008);


    // Timer to send Tension request
    m_pADAMReqTimer = new QTimer();
    connect(m_pADAMSocket4006, SIGNAL(connected()), this, SLOT(startTimer()));

    // Connect readyRead() signal of socket with reading data function
    connect(m_pWxSocket4002, SIGNAL(readyRead()), this, SLOT(readWeatherSData()));
    connect(m_pHMRSocket4003, SIGNAL(readyRead()), this, SLOT(readDigitalCompassSData()));
    connect(m_pBalSocket4004, SIGNAL(readyRead()), this, SLOT(readBallonetSData()));
    connect(m_pHeSocket4005, SIGNAL(readyRead()), this, SLOT(readHeliumSData()));
    connect(m_pADAMSocket4006, SIGNAL(readyRead()), this, SLOT(readADAMSData()));
    connect(m_pSocket4008, SIGNAL(readyRead()), this, SLOT(readEBoxData()));
    connect(m_pADAMReqTimer, SIGNAL(timeout()), this, SLOT(sendTensionReq()));


    // To start with a clean data
    m_pWxSocket4002->readAll();
    m_pHMRSocket4003->readAll();
    m_pBalSocket4004->readAll();
    m_pHeSocket4005->readAll();
    m_pADAMSocket4006->readAll();
    m_pSocket4008->readAll();

}
//=================================================================================================

/*!
 * Disconnect readyRead signal of TCP Sockets from Slot that handles reading received packets
 */
void Interface::disconnectSockets()
{
    // Connect readyRead() signal of socket with reading data function
    disconnect(m_pWxSocket4002, SIGNAL(readyRead()), this, SLOT(readWeatherSData()));
    disconnect(m_pHMRSocket4003, SIGNAL(readyRead()), this, SLOT(readDigitalCompassSData()));
    disconnect(m_pBalSocket4004, SIGNAL(readyRead()), this, SLOT(readBallonetSData()));
    disconnect(m_pHeSocket4005, SIGNAL(readyRead()), this, SLOT(readHeliumSData()));
    disconnect(m_pADAMSocket4006, SIGNAL(readyRead()), this, SLOT(readADAMSData()));
    disconnect(m_pSocket4008, SIGNAL(readyRead()), this, SLOT(readEBoxData()));
    disconnect(m_pADAMReqTimer, SIGNAL(timeout()), this, SLOT(sendTensionReq()));
}
//=================================================================================================

/*!
 * Parses .ini file to get stored data
 * \pre The ini file shall be in the correct path
 */
void Interface::parseIniFile()
{
    // Parse .ini file for port and IP address settings
    QSettings iniComms("AerostatGCS.ini", QSettings::IniFormat);

    // Port used to read incoming data from Weather Station sensor
    m_uPort4002 = iniComms.value("readPortWeatherStation/port","4002").toInt();

    // Port used to read incoming data from HMR_3000 sensor
    m_uPort4003 = iniComms.value("readPortHMR/port","4003").toInt();

    // Port used to read incoming data from Ballonet pressure sensor
    m_uPort4004 = iniComms.value("readPortBallonetPres/port","4004").toInt();

    // Port used to read incoming data from Helium pressure sensor
    m_uPort4005 = iniComms.value("readPortHeliumPres/port","4005").toInt();

    // Port used to write and read incoming data from ADAM sensor
    m_uPort4006 = iniComms.value("readPortADAM/port", "4006").toInt();

    // Port used to write and read incoming data from EBox
    m_uPort4008 = iniComms.value("readPortEBox/port", "4007").toInt();

    // GCU address to read messages sent by MOXA
    m_ipAddr = iniComms.value("readAddrGCS/ip","192.168.0.102").toString();
}
//=================================================================================================

/*!
 * Start Timer to check connection with Moxa
 */
void Interface::startConnTimer()
{
  //  qDebug()<< "START CONN timer..........";
    m_pCheckGcsConnTimer = new QTimer();
    m_pCheckGcsConnTimer->start(1000);
    QObject::connect(m_pCheckGcsConnTimer, SIGNAL(timeout()), this, SLOT(checkGCSConnState()), Qt::DirectConnection);
}
//=================================================================================================


/*!
 * Check connection with Moxa
 */
void Interface::checkGCSConnState()
{
    int status ;
    QString s = "ping -w 1 " + m_ipAddr + " > /tmp/ping_res.txt" ;
    status = system(s.toLocal8Bit().data());
    if(status != 0)
    {
        emit connIsupdated(false);
        connect(this, SIGNAL(onConnectedMode()), this, SLOT(handleOnConnectedMode()));
    }
    else
    {
        emit connIsupdated(true);
        emit onConnectedMode();

    }
    //qDebug() << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO CONN Status " << status << s.toLocal8Bit().data();
}
//=================================================================================================

/*!
 * Update log file name in GUI
 */
void Interface::updateFileName(QString name)
{
    m_pGUI->updateLogFilePath(name);
}
//=================================================================================================


/*!
 * Call createFile() method in case there is a connection with MOXA
 */
void Interface::handleOnConnectedMode()
{
    m_pDataLog->createFile();

    // Connect Sockets for reading packets
    connectSockets();
    disconnect(this, SIGNAL(onConnectedMode()), this, SLOT(handleOnConnectedMode()));
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++ Sending ++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*!
 * Start Timer to send tension request message
 */
void Interface::startTimer()
{
    m_pADAMReqTimer = new QTimer();
    QObject::connect(m_pADAMReqTimer, SIGNAL(timeout()), this, SLOT(sendTensionReq()));
    m_pADAMReqTimer->start(1000);
}
//=================================================================================================


/*!
 * Send Tension request
 */
void Interface::sendTensionReq()
{
    qint64 result = m_pADAMSocket4006->write(TENSION_REQ_MSG);
    if(result == -1 )
    {
        qDebug() << "Unable to send the request";
    }
    else
    {
        //qDebug() << "Tension req is sent... # of bytes:" << result;
    }
}
//=================================================================================================

/*!
 * Send Lights & Fans command
 */
void Interface::sendCommands(const char* data)
{
    qint64 result = m_pADAMSocket4006->write(data);
    if(result == -1 )
    {
        qDebug() << "Unable to send command";
    }
    else
    {
       // qDebug() << "command is sent... # of bytes:" << result;
    }
}
//=================================================================================================


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++ Receiving +++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



//-------------------------------------------------------------------------------------------------
// -------------------------------------- Weather Station -----------------------------------------
//-------------------------------------------------------------------------------------------------
/*!
 * Read incoming packets from Weather station sensor port
 */
void Interface::readWeatherSData()
{

    qint64 availabeBytes = m_pWxSocket4002->bytesAvailable();
    qint64 bytesRead =  m_pWxSocket4002->read(m_WXBuffer+m_WXBytesRead, availabeBytes);
    //qDebug() << "availabeBytes:: " << availabeBytes << "  Bytes Read:: " << bytesRead << " " << m_WXBytesRead;

    if(bytesRead != -1)
    {
        // Update bytes read
        m_WXBytesRead = m_WXBytesRead + bytesRead;

        // Check if '\n' is received
        bool foundEnd = false;
        qint64 crOffset = 0;
        qint64 msgEndOffset = 0;
        for(unsigned int i = (m_WXBytesRead); i > 0 ; i--)
        {
            if(m_WXBuffer[i] == '\r')
            {
                //qDebug() << "CR at: " << i;
                crOffset = i;
                foundEnd = true;
                break;
            }
        }//for
        msgEndOffset =  crOffset + 2;

        if(foundEnd == true && m_WXBytesRead >= msgEndOffset)
        {
            // Try to find the start character '$'
            bool foundStart = false;
            int msgStartOffset = 0;
            while(msgStartOffset < (crOffset - 1))
            {
               // qDebug() << "SEARCHING " << m_WXBuffer[msgStartOffset];
                if( m_WXBuffer[msgStartOffset] == '$')
                {
                    // qDebug() << "start at: " << msgStartOffset;
                    foundStart = true;
                    break;
                }
                msgStartOffset++;
            }//while

            if(foundStart == false)
            {
                // qDebug() << "start NOT found: " ;
                m_WXBytesRead = m_WXBytesRead - msgEndOffset;
                ::memmove(m_WXBuffer, m_WXBuffer+(msgEndOffset+1),m_WXBytesRead );
            }
            else
            {
                // qDebug() << "msgEndOffset " << msgEndOffset;
                // qDebug() << "msgStartOffset " << msgStartOffset;
                quint16 msgSize = (msgEndOffset-msgStartOffset);
                // qDebug() << "MSG SIZE=== " << msgSize;
                QByteArray datagram = QByteArray::fromRawData(m_WXBuffer,msgSize);

                QList<QByteArray>  msgsList = datagram.split('\n');
                QString m_msgStr = "";
                for(int i= 0; i< (msgsList.size()-1); i++)
                {
                    QString msg = msgsList.value(i);
                    QList<QString> msgData = msg.split(',');
                    QString msgHeader = msgData.value(0);
                    if(msgHeader.compare("$HCHDT") == 0 )
                    {
                        QString h = msgData.value(1);
                        if(h.length() != 0)
                        {
                            bool ok;
                            double headingV = h.toDouble(&ok);
                            if(ok == true)
                            {
                                m_pGUI->updateAerostatHeading(headingV);
                                m_msgStr = m_msgStr + "Aerostat Heading: " + h + "\t" ;
                            }
                        }
                    }
                    else if(msgHeader.compare("$WIMDA") == 0)
                    {
                        /** Msg format:Header, Baro pressure, Air temp, Wind dir, Wind speed **/

                        QString baroPresStr = msgData.value(1);
                        QString airTempStr = msgData.value(5);

                        bool baroOk;
                        bool airOk;
                        double baroPres = baroPresStr.toDouble(&baroOk);
                        double airTemp = airTempStr.toDouble(&airOk);

                        if(baroOk == true && airOk == true)
                        {
                            baroPres = floor(baroPres * 10.0 + 0.5 ) / 10.0;

                            m_pGUI->updateBaroPresAndTemp(baroPres, airTemp);
                            m_msgStr =  m_msgStr + "Air Temp: " + airTempStr + "\t" + "Baro Pres: " + baroPresStr + "\t";
                        }
                    }
                    else if(msgHeader.compare("$WIMWV") == 0)
                    {
                        QString windDirectionStr = msgData.value(1);
                        QString windSpeedStr = msgData.value(3);
                        bool dirOk;
                        bool speedOk;
                        double windDirection = windDirectionStr.toDouble(&dirOk);
                        double windSpeed = windSpeedStr.toDouble(&speedOk);
                        if(dirOk == true && speedOk == true )
                        {
                            m_pGUI->updateWindDirAndSpeed(windDirection, windSpeed);
                            m_msgStr = m_msgStr + "Wind Angle: " + windDirectionStr + "\t" + "Wind Speed: "+ windSpeedStr + "\t";
                        }
                    }
                }//for
                if(m_msgStr.length() != 0)
                {
                    m_pDataLog->LogMsgs(m_msgStr);
                }
                m_WXBytesRead = m_WXBytesRead - msgEndOffset;
                // qDebug() << "UPDATE BYTEST READ " << m_WXBytesRead;
                ::memmove(m_WXBuffer, m_WXBuffer+(msgEndOffset+1),m_WXBytesRead );
            }//found start = true
        }//found end = true
    } //bytes read != 1
}



//-------------------------------------------------------------------------------------------------
// --------------------------------------- Helium Pressure ----------------------------------------
//-------------------------------------------------------------------------------------------------

/*!
 * Read incoming packets from Helium sensor port
 */
void Interface::readHeliumSData()
{
    qint64 availabeBytes = m_pHeSocket4005->bytesAvailable();
    qint64 bytesRead =  m_pHeSocket4005->read(m_HelPreBuffer+m_HelPreBytesRead, availabeBytes);
    // qDebug() << "availabeBytes:: " << availabeBytes << "  Bytes Read:: " << bytesRead << " " << m_HelPreBytesRead;
    if(bytesRead != -1)
    {
        // Update bytes read
        m_HelPreBytesRead = m_HelPreBytesRead + bytesRead;

        // Check if '\r' is received
        bool foundEnd = false;
        qint64 crOffset = 0;
        qint64 msgEndOffset = 0;
        for(unsigned int i = 0; i < m_HelPreBytesRead; i++)
        {
            if(m_HelPreBuffer[i] == '\r')
            {
                // qDebug() << "CR at: " << i;
                crOffset = i;
                foundEnd = true;
                break;
            }
        }//for
        msgEndOffset =  crOffset + 1;
        if(foundEnd == true && m_HelPreBytesRead >= msgEndOffset)
        {
            // Try to find the start character '?'
            bool foundStart = false;
            int msgStartOffset = 0;
            while(msgStartOffset < (crOffset - 1))
            {
                if( m_HelPreBuffer[msgStartOffset] == '?')
                {
                    foundStart = true;
                    break;
                }
                msgStartOffset++;
            }//while

            if(foundStart == false)
            {
                m_HelPreBytesRead = m_HelPreBytesRead - msgEndOffset;
                ::memmove(m_HelPreBuffer, m_HelPreBuffer+(msgEndOffset+1),m_HelPreBytesRead );
            }
            else
            {
                quint16 msgSize = (msgEndOffset-msgStartOffset);
                // qDebug() << "MSG SIZE=== " << msgSize;
                QByteArray datagram = QByteArray::fromRawData(m_HelPreBuffer,msgSize);
                QList<QByteArray>  dataList = datagram.split('=');
                // qDebug() << dataList.value(0) << "," << dataList.value(1);
                QString header = dataList.value(0);
                // qDebug() << "__" << header;
                if(header.compare("?01CP")== 0)
                {
                    QString pressure = dataList.value(1);
                    bool ok;
                    pressure = pressure.replace(" ","");
                    // qDebug() << "pressure" << "," << pressure;
                    double pressureValue = pressure.toDouble(&ok);
                    if(ok == true)
                    {
                        QString m_msgStr = "";
                        // qDebug() << "===================================";
                        pressureValue = floor(pressureValue * 1000.0 + 0.5 ) / 1000.0;
                        m_pGUI->updateHeliumPres(pressureValue);
                        m_msgStr =  "Helium Pressure: " + pressure;
                        // Log received message
                        m_pDataLog->LogMsgs(m_msgStr);
                    }
                    else
                    {
                        // qDebug() << "Helium Pressure msg is not logged: " << ok;
                    }
                } //header
                m_HelPreBytesRead = m_HelPreBytesRead - msgEndOffset;
                // qDebug() << "UPDATE BYTEST READ " << m_HelPreBytesRead;
                ::memmove(m_HelPreBuffer, m_HelPreBuffer+(msgEndOffset+1),m_HelPreBytesRead );
            }//found start = true
        }//found end = true
    } //bytes read != 1
}



//-------------------------------------------------------------------------------------------------
//-------------------------------------Ballonet Station -------------------------------------------
//-------------------------------------------------------------------------------------------------
/*!
 * Read incoming packets from Ballonet sensor port
 */
void Interface::readBallonetSData()
{
    qint64 availabeBytes = m_pBalSocket4004->bytesAvailable();
    qint64 bytesRead =  m_pBalSocket4004->read(m_BalPreBuffer+m_BalPreBytesRead, availabeBytes);
    // qDebug() << "availabeBytes:: " << availabeBytes << "  Bytes Read:: " << bytesRead << " " << m_BalPreBytesRead;
    if(bytesRead != -1)
    {
        // Update bytes read
        m_BalPreBytesRead = m_BalPreBytesRead + bytesRead;

        // Check if '\r' is received
        bool foundEnd = false;
        qint64 crOffset = 0;
        qint64 msgEndOffset = 0;
        for(unsigned int i = 0; i < m_BalPreBytesRead; i++)
        {
            if(m_BalPreBuffer[i] == '\r')
            {
                // qDebug() << "CR at: " << i;
                crOffset = i;
                foundEnd = true;
                break;
            }
        }//for
        msgEndOffset =  crOffset + 1;
        if(foundEnd == true && m_BalPreBytesRead >= msgEndOffset)
        {
            // Try to find the start character '?'
            bool foundStart = false;
            int msgStartOffset = 0;
            while(msgStartOffset < (crOffset - 1))
            {
                if( m_BalPreBuffer[msgStartOffset] == '?')
                {
                    foundStart = true;
                    break;
                }
                msgStartOffset++;
            }//while

            if(foundStart == false)
            {
                // qDebug() << "Start NOT found!!!!!";
                m_BalPreBytesRead = m_BalPreBytesRead - msgEndOffset;
                ::memmove(m_BalPreBuffer, m_BalPreBuffer+(msgEndOffset+1),m_BalPreBytesRead );
            }
            else
            {
                quint16 msgSize = (msgEndOffset-msgStartOffset);
                // qDebug() << "MSG SIZE=== " << msgSize;
                QByteArray datagram = QByteArray::fromRawData(m_BalPreBuffer,msgSize);
                QList<QByteArray>  dataList = datagram.split('=');
                QString header = dataList.value(0);
                // qDebug() << "__" << header;
                if(header.compare("?01CP")== 0)
                {
                    QString pressure = dataList.value(1);
                    bool ok;
                    pressure = pressure.replace(" ","");
                    // qDebug() << "pressure" << pressure;
                    double pressureValue = pressure.toDouble(&ok);
                    // qDebug() << "pressureValue" << pressureValue;
                    if(ok == true)
                    {
                        QString m_msgStr = "";
                        pressureValue = floor(pressureValue * 1000.0 + 0.5 ) / 1000.0;
                        m_pGUI->updateBallonetPres(pressureValue);
                        m_msgStr =  "Ballonet Pressure: " + pressure;
                        // Log received message
                        m_pDataLog->LogMsgs(m_msgStr);
                    }
                    else
                    {
                        // qDebug() << "Ballonet Pressure msg is not logged: " << ok;
                    }
                } //header
                m_BalPreBytesRead = m_BalPreBytesRead - msgEndOffset;
                // qDebug() << "UPDATE BYTEST READ " << m_BalPreBytesRead;
                ::memmove(m_BalPreBuffer, m_BalPreBuffer+(msgEndOffset+1),m_BalPreBytesRead );
            }//found start = true
        }//found end = true
    } //bytes read != 1
}




//-------------------------------------------------------------------------------------------------
//------------------------------------- Magnetometer-----------------------------------------------
//-------------------------------------------------------------------------------------------------
/*!
 * Read incoming packets from Magnetometer sensor port
 */
void Interface::readDigitalCompassSData()
{
    qint64 availabeBytes = m_pHMRSocket4003->bytesAvailable();
    qint64 bytesRead =  m_pHMRSocket4003->read(m_magBuffer+m_MagBytesRead, availabeBytes);
    // qDebug() << "availabeBytes:: " << availabeBytes << "  Bytes Read:: " << bytesRead << " " << m_MagBytesRead;

    if(bytesRead != -1)
    {
        // Update bytes read
        m_MagBytesRead = m_MagBytesRead + bytesRead;

        // Check if '\r' is received
        bool foundEnd = false;
        qint64 crOffset = 0;
        qint64 msgEndOffset = 0;
        for(unsigned int i = 0; i < m_MagBytesRead; i++)
        {
            if(m_magBuffer[i] == '\r')
            {
                // qDebug() << "CR at: " << i;
                crOffset = i;
                foundEnd = true;
                break;
            }
        }
        msgEndOffset =  crOffset + 2;
        if(foundEnd == true && m_MagBytesRead>= msgEndOffset)
        {

            // Try to find the start character '$'
            bool foundStart = false;
            int msgStartOffset = 0;
            while(msgStartOffset < (crOffset - 1))
            {
                if( m_magBuffer[msgStartOffset] == '$')
                {
                    // qDebug() << "FOUND ($) @: " << msgStartOffset;
                    foundStart = true;
                    break;
                }
                msgStartOffset++;
            }
            if(foundStart == false)
            {
                // qDebug() << "($) not FOUND";
                m_MagBytesRead = m_MagBytesRead - msgEndOffset;
                ::memmove(m_magBuffer, m_magBuffer+(msgEndOffset+1),m_MagBytesRead );
            }
            else
            {
                quint16 msgSize = (msgEndOffset-msgStartOffset);
                QByteArray datagram = QByteArray::fromRawData(m_magBuffer,msgSize);
                // qDebug() << "Datagram size::: " << datagram.size();
                QString m_msgStr = "";
                QList<QByteArray>  data = datagram.split(',');
                QString header = data.value(0);
                //qDebug()<<  data.value(0) << ", " <<  data.value(1) << " " << data.value(2)  << " " << data.value(3) << " " << data.value(4) << " " << data.value(5) << " " << data.value(6);
                if(header.compare("$PTNTHPR")== 0)
                {
                    // Msg format:$PTNTHPR,heading,a,pitch,a,roll,a*hh<cr><lf>
                   // qDebug() << "Magnetometer msg #4:" <<  data.value(1) << " " << data.value(2)  << " " << data.value(3) << " " << data.value(3);
                    QString h = data.value(1);
                    QString p = data.value(3);
                    QString r = data.value(5);
                    bool hOk;
                    bool pOk;
                    bool rOk;
                    double headingV = h.toDouble(&hOk);
                    double pitchV = p.toDouble(&pOk);
                    double rollV = r.toDouble(&rOk);
                    if(hOk == true && pOk == true && rOk == true)
                    {
                        // qDebug() << "_________________________________________________________ ";
                        m_pGUI->updateMagnetometerValues(headingV, pitchV, rollV );
                        // Log received message
                        m_msgStr =  "MagHeading: " + h + "\t" + "Pitch: " + p + "\t" + "Roll: " + r;
                        m_pDataLog->LogMsgs(m_msgStr);
                    }
                    else
                    {
                        // qDebug() << "Magnetometer msg is not logged: " << hOk << ", " << pOk << ", " << rOk;
                    }
                } //header
                m_MagBytesRead = m_MagBytesRead - msgEndOffset;
                // qDebug() << "UPDATE BYTEST READ " << m_MagBytesRead;
                ::memmove(m_magBuffer, m_magBuffer+(msgEndOffset+1),m_MagBytesRead );
            }//found start = true
        }//found end = true
    } //bytes read != 1
}


//-------------------------------------------------------------------------------------------------
//--------------------------------------------- ADAM ----------------------------------------------
//-------------------------------------------------------------------------------------------------

/*!
 * Read incoming packets from ADAM sensor port
 */
void Interface::readADAMSData()
{
    qint64 availabeBytes = m_pADAMSocket4006->bytesAvailable();
    qint64 bytesRead =  m_pADAMSocket4006->read(m_ADAMBuffer+m_ADAMBytesRead, availabeBytes);
    // qDebug() << "availabeBytes:: " << availabeBytes << "  Bytes Read:: " << bytesRead << " " << m_ADAMBytesRead;

    if(bytesRead != -1)
    {
        // Update bytes read
        m_ADAMBytesRead = m_ADAMBytesRead + bytesRead;

        // Check if '\r' is received
        bool foundEnd = false;
        qint64 crOffset = 0;
        qint64 msgEndOffset = 0;
        for(unsigned int i = 0; i < m_ADAMBytesRead; i++)
        {
            if(m_ADAMBuffer[i] == '\r')
            {
                // qDebug() << "CR at: " << i;
                crOffset = i;
                foundEnd = true;
                break;
            }
        }//for
        msgEndOffset =  crOffset + 1;
        if(foundEnd == true && m_ADAMBytesRead >= msgEndOffset)
        {
            // Try to find the start character '>'
            bool foundStart = false;
            int msgStartOffset = 0;
            while(msgStartOffset < (crOffset - 1))
            {
                if( m_ADAMBuffer[msgStartOffset] == '>')
                {
                    foundStart = true;
                    break;
                }
                msgStartOffset++;
            }//while

            if(foundStart == false)
            {
                m_ADAMBytesRead = m_ADAMBytesRead - msgEndOffset;
                ::memmove(m_ADAMBuffer, m_ADAMBuffer+(msgEndOffset+1),m_ADAMBytesRead );
            }
            else
            {
                QString m_msgStr = "";
                quint16 msgSize = (msgEndOffset-msgStartOffset);
                // qDebug() << "MSG SIZE=== " << msgSize;
                QByteArray datagram = QByteArray::fromRawData(m_ADAMBuffer,msgSize);
                QList<QByteArray>  dataList = datagram.split('>');
                // qDebug() << dataList.value(0) << "," << dataList.value(1);

                QString tension = dataList.value(1);

                bool ok;
                double tensionValue = tension.toDouble(&ok);
                if(ok == true)
                {
                    tensionValue = (tensionValue * 271.0279) /9.8;
                    tensionValue = floor(tensionValue * 10.0 + 0.5 ) / 10.0; //decimals = 1 digit
                    if(tensionValue > m_dMaxTension)
                    {
                        m_dMaxTension = tensionValue;
                    }
                    m_pGUI->updateTension(tensionValue, m_dMaxTension);
                    m_msgStr =  "Tension: " + QString::number(tensionValue)  + "\t" + "Max Tension: " + QString::number(m_dMaxTension);
                    // Log received message
                    m_pDataLog->LogMsgs(m_msgStr);
                }
                else
                {
                    // qDebug() << "ADAM msg is not logged: " << ok ;
                }
                m_ADAMBytesRead = m_ADAMBytesRead - msgEndOffset;
                // qDebug() << "UPDATE BYTEST READ " << m_ADAMBytesRead;
                ::memmove(m_ADAMBuffer, m_ADAMBuffer+(msgEndOffset+1),m_ADAMBytesRead );
            }//found start = true
        }//found end = true
    } //bytes read != 1
}


//-------------------------------------------------------------------------------------------------
// -------------------------------------------- EBox ----------------------------------------------
//-------------------------------------------------------------------------------------------------
/*!
 * Read incoming packets from PDU port
 */
void Interface::readEBoxData()
{

    qint64 availabeBytes = m_pSocket4008->bytesAvailable();
    qint64 bytesRead =  m_pSocket4008->read(m_PDUBuffer+m_PDUBytesRead, availabeBytes);
    // qDebug() << "availabeBytes:: " << availabeBytes << "  Bytes Read:: " << bytesRead << " " << m_PDUBytesRead;

    if(bytesRead != -1)
    {
        // Update bytes read
        m_PDUBytesRead = m_PDUBytesRead + bytesRead;

        // Check if '\r' is received
        bool foundEnd = false;
        qint64 crOffset = 0;
        qint64 msgEndOffset = 0;
        for(unsigned int i = 0; i < m_PDUBytesRead; i++)
        {
            if(m_PDUBuffer[i] == '\r')
            {
                // qDebug() << "CR at: " << i;
                crOffset = i;
                foundEnd = true;
                break;
            }
        }//for
        msgEndOffset =  crOffset + 1;
        if(foundEnd == true && m_PDUBytesRead >= msgEndOffset)
        {
            // Try to find the start character '@'
            bool foundStart = false;
            int msgStartOffset = 0;
            while(msgStartOffset < (crOffset - 1))
            {
                if( m_PDUBuffer[msgStartOffset] == '@')
                {
                    foundStart = true;
                    break;
                }
                msgStartOffset++;
            }//while

            if(foundStart == false)
            {
                m_PDUBytesRead = m_PDUBytesRead - msgEndOffset;
                ::memmove(m_PDUBuffer, m_PDUBuffer+(msgEndOffset+1),m_PDUBytesRead );
            }
            else
            {
                QString m_msgStr = "";
                quint16 msgSize = (msgEndOffset-msgStartOffset);
                // qDebug() << "MSG SIZE=== " << msgSize;
                QByteArray datagram = QByteArray::fromRawData(m_PDUBuffer,msgSize);
                QList<QByteArray>  data = datagram.split(',');
                QString header = data.value(0);
                if(header.compare("@A01") == 0) // From E-Box sensor
                {
                   // qDebug() << "@A01: Internal temp msg";
                    bool ok;
                    //qDebug() << "temp" << data.value(1);
                    QString temp = data.value(1);
                    double tempV = temp.toDouble(&ok);

                    qDebug() << "temp" << data.value(1) << "__" << ok << "__" << tempV;

                    qDebug() << "fan1" << data.value(2);
                    QString fan1Status = data.value(2);

                    qDebug() << "fan2" << data.value(3);
                    QString fan2Status = data.value(3);

                    qDebug() << "strobe" << data.value(4);
                    QString strobeStatus = data.value(4);

                    qDebug() << "position" << data.value(3);
                    QString positionStatus = data.value(5);
                    m_pGUI->updateFansAndLights(tempV, fan1Status, fan2Status, strobeStatus, positionStatus.at(0));
                    m_msgStr =  "Internal temperature: " + temp + "\t" + "Blower1 Status: " + fan1Status + "\t" + "Blower2 Status: " + fan2Status + "\t" + "Strobe Light Status: " + strobeStatus + "\t" + "Position Light Status: " + positionStatus;
                    m_pDataLog->LogMsgs(m_msgStr);
                } //header
                m_PDUBytesRead = m_PDUBytesRead - msgEndOffset;
                // qDebug() << "UPDATE BYTEST READ " << m_PDUBytesRead;
                ::memmove(m_PDUBuffer, m_PDUBuffer+(msgEndOffset+1),m_PDUBytesRead );
            }//found start = true
        }//found end = true
    } //bytes read != 1
}

