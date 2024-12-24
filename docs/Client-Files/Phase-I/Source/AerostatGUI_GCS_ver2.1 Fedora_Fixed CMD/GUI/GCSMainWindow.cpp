/*
 * Copyright (c) 2012, ADASI,
 * All rights reserved.
 *
 * Author Name: Eiman Al Shamisi
 */

#include<QFileDialog>
#include <qwt_dial_needle.h>
#include <qwt_analog_clock.h>
#include <qwt_dial.h>
#include <QDateTime>
#include<QMessageBox>
#include "Interface.h"
#include "DataLog.h"
#include "GCSMainWindow.h"
#include "ui_GCSMainWindow.h"

const char* FANS_OFF_OFF = "@01DO03\r";
const char* FANS_ON_OFF = "@01DO02\r";
const char* FANS_OFF_ON = "@01DO01\r";
const char* FANS_ON_ON = "@01DO00\r";

const char* LIGHTS_ON_ON = "@01DO10\r";
const char* LIGHTS_OFF_ON = "@01DO11\r";
const char* LIGHTS_ON_OFF = "@01DO12\r";
const char* LIGHTS_OFF_OFF = "@01DO13\r";

/*!
 * Constructor
 */
GCSMainWindow::GCSMainWindow(Interface *pInterface) :
    ui(new Ui::GCSMainWindow)
{
    ui->setupUi(this);

    // Transparent background
    ui->nLabel->setStyleSheet("background-color: transparent;");
    ui->wLabel->setStyleSheet("background-color: transparent;");
    ui->sLabel->setStyleSheet("background-color: transparent;");
    ui->eLabel->setStyleSheet("background-color: transparent;");
    ui->windAngleLabel->setStyleSheet("background-color: transparent;");
    ui->aerostatHeadingLabel->setStyleSheet("background-color: transparent;");
    ui->maxTensionLabel->setStyleSheet("background-color: transparent;");
    ui->ballonetLabel->setStyleSheet("background-color: transparent;");
    ui->magHeadingLabel->setStyleSheet("background-color: transparent;");
    ui->rollLabel->setStyleSheet("background-color: transparent;");

    // Instance of Interface class
    m_pInterface = pInterface;

    //Initialize Fans & Lights command
    m_pCmd = NULL;

    // Date and Time  format
    m_dateTimeFormat = "ddd, dd MMMM yyyy, hh:mm:ss";

    // Timer to update Date & time
    m_pTimer = new QTimer(this);
    m_pTimer->start(1000);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(updateTime()));

    m_pRecordedTimer = new QTimer(this);
    connect(m_pRecordedTimer, SIGNAL(timeout()), this, SLOT(updateDisplayType()));

    m_pClearDisplayTypeTimer = new QTimer(this);
    connect(m_pClearDisplayTypeTimer, SIGNAL(timeout()), this, SLOT(clearDisplayTypeText()));

    ui->displayTypeLabel->setAlignment(Qt::AlignRight);

    // Palette settings
    palette.setColor( QPalette::WindowText, Qt::transparent );
    palette.setColor( QPalette::Dark, Qt::darkGray );
    palette.setColor( QPalette::Text, Qt::black );
    palette.setBrush( QPalette::Text, Qt::SolidPattern);

    // Draw Panels
    drawCPTPanel();
    drawWeatherStationPanel();
    drawPressurePanel();
    drawMagnetometerPanel();

    // Font settings
    QFont font("Ubuntu");
    font.setPointSize(11);
    setFont(font);

    m_pCPTDial->setFont(font);
    m_pWindSpeedDial->setFont(font);
    m_pHeliumDial->setFont(font);
    m_pBallonetPressureDial->setFont(font);
    m_pPitch->setFont(font);
    m_pRoll->setFont(font);
    ui->DialAerostatHeading->setFont(font);
    ui->DialWindDirection->setFont(font);
    ui->DialHeading->setFont(font);

    // QLabel
    ui->tensionValue->setFont(font);
    ui->tensionLabel->setFont(font);
    ui->maxTensionValue->setFont(font);

    ui->airTempValue->setFont(font);
    ui->airTempValue->setAlignment(Qt::AlignHCenter);

    ui->eBoxTempValue->setFont(font);
    ui->eBoxTempValue->setAlignment(Qt::AlignHCenter);

    ui->baroValue->setFont(font);
    ui->baroValue->setAlignment(Qt::AlignCenter);

    ui->heliumValue->setFont(font);
    ui->heliumValue->setAlignment(Qt::AlignHCenter);

    ui->ballonetValue->setFont(font);
    ui->ballonetValue->setAlignment(Qt::AlignHCenter);

    ui->magentHeadingValue->setFont(font);
    ui->magentHeadingValue->setAlignment(Qt::AlignHCenter);

    ui->pitchValue->setFont(font);
    ui->pitchValue->setAlignment(Qt::AlignHCenter);

    ui->rollValue->setFont(font);
    ui->rollValue->setAlignment(Qt::AlignHCenter);

    ui->LogFileTextEdit->setReadOnly(true);
    ui->LogFileTextEdit->setAlignment(Qt::AlignTop);

    ui->comsTextEdit->setReadOnly(true);
    ui->comsTextEdit->setAlignment(Qt::AlignTop);

    // Buttons Signals & Slots
    connect(ui->fan1OffBtn , SIGNAL(clicked()), this, SLOT(handleFan1OffControl()));
    connect(ui->fan1OnBtn , SIGNAL(clicked()), this, SLOT(handleFan1OnControl()));

    connect(ui->fan2OffBtn , SIGNAL(clicked()), this, SLOT(handleFan2OffControl()));
    connect(ui->fan2OnBtn , SIGNAL(clicked()), this, SLOT(handleFan2OnControl()));

    connect(ui->strobeOffBtn , SIGNAL(clicked()), this, SLOT(handleStrobeOffControl()));
    connect(ui->strobeOnBtn , SIGNAL(clicked()), this, SLOT(handleStrobeOnControl()));

    connect(ui->positionOffBtn , SIGNAL(clicked()), this, SLOT(handlePositionOffControl()));
    connect(ui->positionOnBtn , SIGNAL(clicked()), this, SLOT(handlePositionOnControl()));

    // Playback log file components
    ui->stopBtn->setEnabled(false);
    ui->playBtn->setEnabled(false);
    ui->fwdBtn->setEnabled(false);
    ui->browseBtn->setEnabled(true);
    m_bStop = false;
    m_bIsFwd = false;
    m_uDelay = 1000; // 1000 msec = 1 sec

    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browseFile()));
    connect(ui->stopBtn, SIGNAL(clicked()), this, SLOT(stop()));
    connect(ui->playBtn, SIGNAL(clicked()), this, SLOT(startPlaying()));
    connect(ui->fwdBtn, SIGNAL(clicked()), this, SLOT(FWDData()));

    connect(this, SIGNAL(done()),this, SLOT(finishReading()));

    this->setFixedSize(this->width(),this->height());
}

//=================================================================================================

/*!
 * Destructor
 */
GCSMainWindow::~GCSMainWindow()
{
    delete ui;
}
//=================================================================================================


/*!
 * Update Date and Time field
 */
void GCSMainWindow::updateTime()
{
    QString dateTimeString = QDateTime::currentDateTime().toString(m_dateTimeFormat);
    ui->dateTimeLabel->setText(dateTimeString);
}
//=================================================================================================


/*!
 * Determine the command that should be sent when Fan1 Button is clicked
 */
void GCSMainWindow::handleFan1OffControl()
{
    bool status = getBlower2Status();
    if( status == true) //ON
    {
        qDebug() << "TRUE: ";
        m_pCmd = FANS_OFF_ON;
    }
    else
    {
        m_pCmd = FANS_OFF_OFF;
    }
    m_pInterface->sendCommands(m_pCmd);
}
//=================================================================================================


void GCSMainWindow::handleFan1OnControl()
{
    bool status = getBlower2Status();
    if( status == true) //ON
    {
        m_pCmd = FANS_ON_ON;
    }
    else
    {
        m_pCmd = FANS_ON_OFF;
    }

    m_pInterface->sendCommands(m_pCmd);
}

/*!
 * Determine the command that should be sent when Fan2 Button is clicked
 */
void GCSMainWindow::handleFan2OffControl()
{
    bool status = getBlower1Status();
    if( status == true) //ON
    {
        m_pCmd = FANS_ON_OFF;
    }
    else
    {
        m_pCmd = FANS_OFF_OFF;
    }

    m_pInterface->sendCommands(m_pCmd);
}


void GCSMainWindow::handleFan2OnControl()
{
    bool status = getBlower1Status();
    if( status == true) //ON
    {
        m_pCmd = FANS_ON_ON;
    }
    else
    {
        m_pCmd = FANS_OFF_ON;
    }
    m_pInterface->sendCommands(m_pCmd);
}
//=================================================================================================


/*!
 * Determine the command that should be sent when strobe Button is clicked
 */
void GCSMainWindow::handleStrobeOffControl()
{
    bool status = getPositionLightStatus();
    if( status == true) //ON
    {
        m_pCmd = LIGHTS_OFF_ON;
    }
    else
    {
        m_pCmd = LIGHTS_OFF_OFF;
    }
    m_pInterface->sendCommands(m_pCmd);
}


void GCSMainWindow::handleStrobeOnControl()
{
    bool status = getPositionLightStatus();
    if( status == true) //ON
    {
        m_pCmd = LIGHTS_ON_ON;
    }
    else
    {
        m_pCmd = LIGHTS_ON_OFF;
    }
    m_pInterface->sendCommands(m_pCmd);
}
//=================================================================================================

/*!
 * Determine the command that should be sent when Position Light Button is clicked
 */
void GCSMainWindow::handlePositionOffControl()
{
    bool status = getStrobeLightStatus();
    if( status == true) //ON
    {
        m_pCmd = LIGHTS_ON_OFF;
    }
    else
    {
        m_pCmd = LIGHTS_OFF_OFF;
    }

    m_pInterface->sendCommands(m_pCmd);
}

void GCSMainWindow::handlePositionOnControl()
{
    bool status = getStrobeLightStatus();
    if( status == true) //ON
    {
        m_pCmd = LIGHTS_ON_ON;
    }
    else
    {
        m_pCmd = LIGHTS_OFF_ON;
    }
    m_pInterface->sendCommands(m_pCmd);
}
//=================================================================================================

/*!
 * Draw Confluence Point Tension Dial
 */
void GCSMainWindow::drawCPTPanel()
{
    m_pCPTDial = new ConfluencePointTension();
    m_pCPTDial->setLineWidth(4);
    m_pCPTDial->setFrameShadow(QwtDial::Plain);
    m_pCPTDial->setPalette( palette );
    ui->CPTgridLayout->addWidget(m_pCPTDial);
}
//=================================================================================================

/*!
 * Draw Weather Station Panel
 */
void GCSMainWindow::drawWeatherStationPanel()
{
    // Draw wind speed ---------------------------------------------------------------------
    m_pWindSpeedDial = new WindSpeed();
    m_pWindSpeedDial->setLineWidth(4);
    m_pWindSpeedDial->setFrameShadow(QwtDial::Plain);
    m_pWindSpeedDial->setPalette( palette );
    ui->WindSpeedgridLayout->addWidget(m_pWindSpeedDial);

    // Draw Wind Angle ---------------------------------------------------------------------
    QwtDialSimpleNeedle *windNeedle = new QwtDialSimpleNeedle(QwtDialSimpleNeedle::Arrow, true, Qt::blue,QColor(Qt::gray).light(130));
    ui->DialWindDirection->setNeedle(windNeedle );

    ui->DialWindDirection->setRange(0,360);
    ui->DialWindDirection->setOrigin(270);
    ui->DialWindDirection->setScale( 0, 3, 30 ); // 2nd argument to draw inner line between 2 defined numbers . 3rd steps #

    ui->DialWindDirection->setDirection(QwtDial::Clockwise);
    ui->DialWindDirection->setMode(QwtDial::RotateNeedle);
    ui->DialWindDirection->setReadOnly(true);
    ui->DialWindDirection->setFrameShadow(QwtDial::Plain);
    ui->DialWindDirection->setPalette( palette );

    ui->DialWindDirection->setValue(250);


    // Draw Aerostat Heading --------------------------------------------------------------
    QwtDialSimpleNeedle *headingNeedle = new QwtDialSimpleNeedle(QwtDialSimpleNeedle::Arrow, true, Qt::red, QColor(Qt::gray).light(130));
    ui->DialAerostatHeading->setNeedle(headingNeedle);

    ui->DialAerostatHeading->setRange(0,360);
    ui->DialAerostatHeading->setOrigin(270);
    ui->DialAerostatHeading->setScale( 0, 3, 30 ); // 2nd argument to draw inner line between 2 defined numbers . 3rd steps #

    ui->DialAerostatHeading->setDirection(QwtDial::Clockwise);
    ui->DialAerostatHeading->setMode(QwtDial::RotateNeedle);
    ui->DialAerostatHeading->setFrameShadow(QwtDial::Plain);
    ui->DialAerostatHeading->setReadOnly(true);

    QPalette HeadingPalette;
    HeadingPalette.setColor( QPalette::Dark, Qt::transparent );
    HeadingPalette.setColor( QPalette::Text, Qt::transparent );
    HeadingPalette.setColor( QPalette::Base, Qt::transparent );
    HeadingPalette.setColor( QPalette::WindowText, Qt::transparent );
    ui->DialAerostatHeading->setPalette(HeadingPalette);
    ui->DialAerostatHeading->setStyleSheet("background-color: transparent;");
}
//=================================================================================================

/*!
 * Draw Helium Pressure & Ballonet Pressure Dials
 */
void GCSMainWindow::drawPressurePanel()
{
    // Draw Helium Pressure ----------------------------------------------------------------
    m_pHeliumDial = new HeliumPressure();
    m_pHeliumDial->setLineWidth(4);
    m_pHeliumDial->setFrameShadow(QwtDial::Plain);
    m_pHeliumDial->setPalette( palette );
    m_pHeliumDial->setPalette( palette );
    ui->HeliumGridLayout->addWidget(m_pHeliumDial);

    // Draw Ballonet Pressure ----------------------------------------------------------------
    m_pBallonetPressureDial = new BallonetPressure();
    m_pBallonetPressureDial->setLineWidth(4);
    m_pBallonetPressureDial->setFrameShadow(QwtDial::Plain);
    m_pBallonetPressureDial->setPalette( palette );
    m_pBallonetPressureDial->setPalette( palette );
    ui->BallonetGridLayout->addWidget(m_pBallonetPressureDial);
}
//=================================================================================================

/*!
 * Draw Heading, Pitch and Roll Dials
 */
void GCSMainWindow::drawMagnetometerPanel()
{
    // Draw Heading --------------------------------------------------------------------------
    ui->DialHeading->setRange(0,360);
    ui->DialHeading->setDirection(QwtDial::Clockwise);
    ui->DialHeading->setMode(QwtDial::RotateNeedle);
    ui->DialHeading->setOrigin(270);
    ui->DialHeading->setScale( 0, 0, 45 ); // 2nd argument to draw inner line between 2 defined numbers . 3rd steps #

    QwtDialSimpleNeedle *headingNeedle = new QwtDialSimpleNeedle(QwtDialSimpleNeedle::Arrow, true, Qt::black, QColor( Qt::gray ).light(130));

    ui->DialHeading->setNeedle(headingNeedle);
    ui->DialHeading->setReadOnly(true);
    ui->DialHeading->setValue(100);
    ui->DialHeading->setFrameShadow(QwtDial::Plain);
    ui->DialHeading->setPalette( palette );

    // Draw Pitch----------------------------------------------------------------------------
    m_pPitch = new Pitch();
    m_pPitch->setLineWidth(4);
    m_pPitch->setFrameShadow(QwtDial::Plain);
    m_pPitch->setPalette( palette );
    ui->PitchGridLayout->addWidget(m_pPitch);

    // Draw Roll-----------------------------------------------------------------------------
    m_pRoll = new Roll();
    m_pRoll->setLineWidth(4);
    m_pRoll->setFrameShadow(QwtDial::Plain);
    m_pRoll->setPalette( palette );
    ui->RollGridLayout->addWidget(m_pRoll);
}
//=================================================================================================


//-------------------------------------------------------------------------------------------------
// ------------------------------------------- Update Fields --------------------------------------
//-------------------------------------------------------------------------------------------------
/*!
 * Update the path of Log file
 */
void GCSMainWindow::updateLogFilePath(QString name)
{
    ui->LogFileTextEdit->setText(name);
}
//=================================================================================================

/*!
 * Update Tension field
 */
void GCSMainWindow::updateTension(double tension, double maxTension)
{
    ui->tensionValue->setText(QString::number(tension));
    m_pCPTDial->setValue(tension);

    ui->maxTensionValue->setText(QString::number((maxTension)));
}
//=================================================================================================


/*!
 * Update Aerostat Heading field
 */
void GCSMainWindow::updateAerostatHeading(double heading)
{
    ui->DialAerostatHeading->setValue(heading);
}
//=================================================================================================

/*!
 * Update Baro pressure and temperature fields
 */
void GCSMainWindow::updateBaroPresAndTemp(double baroPres, double temp)
{
    // Barometric Pressure
    ui->baroValue->setText(QString::number(baroPres));

    // Air temperature
    ui->airTempValue->setText(QString::number(temp));
}
//=================================================================================================

/*!
 * Update Wind Direction and Wind speed fields
 */
void GCSMainWindow::updateWindDirAndSpeed(double windDir, double windSpeed)
{
    // Wind Direction
    ui->DialWindDirection->setValue(windDir);

    // Wind Speed
    m_pWindSpeedDial->setValue(windSpeed);
}
//=================================================================================================

/*!
 * Update Helium Pressure field
 */
void GCSMainWindow::updateHeliumPres(double pres)
{
    m_pHeliumDial->setValue(pres);
    ui->heliumValue->setText(QString::number(pres));
}
//=================================================================================================

/*!
 * Update Ballonet Pressure field
 */
void GCSMainWindow::updateBallonetPres(double pres)
{
    m_pBallonetPressureDial->setValue(pres);
    ui->ballonetValue->setText(QString::number(pres));
}
//=================================================================================================

/*!
 * Update Magnetometer fields
 */
void GCSMainWindow::updateMagnetometerValues(double heading, double pitch, double roll)
{
    // Heading
    ui->DialHeading->setValue(heading);
    ui->magentHeadingValue->setText(QString::number(heading));

    // Pitch
    m_pPitch->setValue(pitch);
    ui->pitchValue->setText(QString::number(pitch));

    // Roll
    m_pRoll->setValue(roll);
    ui->rollValue->setText(QString::number(roll));
}
//=================================================================================================

/*!
 * Update Internal Temperature, Fans and Lights status
 */

void GCSMainWindow::updateFansAndLights(double temp, QString fan1, QString fan2, QString strobe, QString position)
{
    // Temp----------
    ui->eBoxTempValue->setText(QString::number(temp));

    // Fan1----------
    if(fan1.compare("1") == 0)
    {
        ui->fan1Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 0);"));// Green
        ui->fan1OnBtn->setChecked(true);
    }
    else
    {
        ui->fan1Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));// red
        ui->fan1OffBtn->setChecked(true);
    }

    // Fan2----------
    if(fan2.compare("1") == 0)
    {
        ui->fan2Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 0);"));// Green
        ui->fan2OnBtn->setChecked("true");
    }
    else
    {
        ui->fan2Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));// red
        ui->fan2OffBtn->setChecked("true");
    }

    // Strobe----------
    if(strobe.compare("1") == 0)
    {
        ui->strobeWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 0);"));// Green
        ui->strobeOnBtn->setChecked(true);
    }
    else
    {
        ui->strobeWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));// red
        ui->strobeOffBtn->setChecked(true);
    }

    // Position----------
    if(position.compare("1") == 0)
    {
        ui->positionWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 0);"));// Green
        ui->positionOnBtn->setChecked(true);
    }
    else
    {
        ui->positionWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));// red
        ui->positionOffBtn->setChecked(true);
    }
}
//=================================================================================================

/*!
 * Update connection status field
 */
void GCSMainWindow::updateConnStatus(bool status)
{
    if (status == true)
    {
        ui->comsStatus->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 0);"));// Green
        ui->comsTextEdit->setText("Connected...");
    }
    else
    {
        ui->comsStatus->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);")); // red
        ui->comsTextEdit->setText("Disconnected...");
    }
}
//=================================================================================================

/*!
 * Retreive the status of Position Light
 \return bool false(OFF), True(ON)
 */
bool GCSMainWindow::getPositionLightStatus()
{
    bool status;
    if(ui->positionOffBtn->isChecked() == true)
    {
        status = false;
    }
    else
    {
        status =true;
    }
    return status;
}
//=================================================================================================

/*!
 * Retreive the status of Strobe Light
 \return bool false(OFF), True(ON)
 */
bool GCSMainWindow::getStrobeLightStatus()
{
    bool status;
    if(ui->strobeOffBtn->isChecked() == true)
    {
        status = false;
    }
    else
    {
        status =true;
    }
    return status;
}
//=================================================================================================

/*!
 * Retreive the status of Position Light
 \return bool false(Pressure), True(Continuous)
 */
bool GCSMainWindow::getBlower1Status()
{
    bool status;
    if(ui->fan1OffBtn->isChecked() == true)
    {
        status = false;
    }
    else
    {
        status =true;
    }
    return status;
}
//=================================================================================================

/*!
 * Retreive the status of Position Light
 \return bool false(OFF), True(Continuous)
 */
bool GCSMainWindow::getBlower2Status()
{
    bool status;

    if( ui->fan2OffBtn->isChecked() == true)
    {
        status = false;
    }
    else
    {
        status =true;
    }
    return status;
}
//=================================================================================================

/*!
 * Browse files & get the selected file for playing-back
 */
void GCSMainWindow::browseFile()
{
    ui->LogFileTextEdit->setText("");

    QFileDialog s;
    QString fileName = s.getOpenFileName(this, tr("Open File"),
                                         "/var/log/gcs",
                                         tr("Files (*.txt*)"));

    if(fileName.length()!= 0)
    {
        ui->LogFileTextEdit->setText(fileName);
        ui->playBtn->setEnabled(true);
    }
    else
    {
        ui->playBtn->setEnabled(false);
        ui->stopBtn->setEnabled(false);
        ui->fwdBtn->setEnabled(false);
        ui->browseBtn->setEnabled(true);
    }
}
//=================================================================================================

/*!
 * Set Display Type text (Used while playing back log file)
 */
void GCSMainWindow::updateDisplayType()
{
    ui->displayTypeLabel->setText("<font color='red'>PLAYING BACK RECORDED DATA</font>");
}
//=================================================================================================
/*!
 * Clear Display Type text
 */
void GCSMainWindow::clearDisplayTypeText()
{
    ui->displayTypeLabel->setText("");
}
//=================================================================================================
/*!
 * Stop playing back data
 */
void GCSMainWindow::stop()
{
    m_bStop = true;

    ui->playBtn->setEnabled(false);
    ui->stopBtn->setEnabled(false);
    ui->browseBtn->setEnabled(true);
    ui->fwdBtn->setEnabled(false);
    // m_pInterface->connectSockets();
}
//=================================================================================================

/*!
 * Start the action needed to playback data
 */
void GCSMainWindow::startPlaying()
{
    ui->displayTypeLabel->setText("<font color='red'>PLAYING BACK RECORDED DATA</font>");
    m_pRecordedTimer->start(500);
    m_pClearDisplayTypeTimer->start(750);
    m_pInterface->disconnectSockets();
    m_bStop = false;
    ui->stopBtn->setEnabled(true);
    ui->playBtn->setEnabled(false);
    ui->browseBtn->setEnabled(false);
    ui->fwdBtn->setEnabled(true);
    emptyFields();

    updateGUIFromLog();
}
//=================================================================================================

/*!
  * PlayBack data faster than normal play
  */
void GCSMainWindow::FWDData()
{
    m_bIsFwd = true;
    m_uDelay = m_uDelay * 0.5;
    if(m_uDelay < 125)
    {
        m_uDelay = 125; //FWD speed not less than 125
        ui->fwdBtn->setEnabled(false);
    }
}
//=================================================================================================

/*!
  * Read logged file & update related fields
  */
void GCSMainWindow::updateGUIFromLog()
{
    // Disconnect date time display
    disconnect(m_pTimer, SIGNAL(timeout()), this, SLOT(updateTime()));

    // Open file
    QString fileName = ui->LogFileTextEdit->toPlainText();
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly) && !fileName.isNull() && fileName.endsWith(".txt")) {
        QMessageBox::information(0, "error", file.errorString());
    }

    // Read Log data
    QTextStream in(&file);
    m_dataLog = in.readAll();
    file.close();

    // Get data line by line
    m_allLinesList = m_dataLog.split("\n");
    qDebug() << "No. of lines = " << m_allLinesList.size();

    // Group lines by time
    for(int i = 0; i< m_allLinesList.size(); i++)
    {
        QStringList s = m_allLinesList.at(i).split("\t");
        if(i != 0)
        {
            QStringList prevLine = m_allLinesList.at(i-1).split("\t");
            if (s.at(0).compare(prevLine.at(0)) != 0)
            {
                m_timeBreakPointList.append(i);
            }
        }
    }

    // Playback data & update GUI
    for(int i = 0; i< m_allLinesList.size(); i++)
    {
        // If STOP button is pressed
        if(m_bStop == true)
        {
            break;
        }

        // Read non-empty lines
        m_fields = m_allLinesList.at(i).split("\t");
        qDebug() << "FIELD SIZE:::" << m_fields.size() ;

        if(m_fields.size() > 1)
        {
            if(m_fields.at(1).isNull() == false)
            {
                // Check if the time is changed
                if( m_timeBreakPointList.contains(i) == true)
                {
                    if(m_bIsFwd  == true)
                    {
                        QTime dieTime= QTime::currentTime().addMSecs(m_uDelay);
                        while( QTime::currentTime() < dieTime )
                        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
                    }
                    else
                    {
                        QTime dieTime= QTime::currentTime().addSecs(1);
                        while( QTime::currentTime() < dieTime )
                        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
                    }

                    qDebug() << "------------------------------------------------";

                }

                // Update GUI Fields
                ui->dateTimeLabel->setText(m_fields.at(0));
                bool ok;
                for (int i = 1; i < m_fields.size(); i++)
                {
                    if(m_fields.at(i).isNull() == false)
                    {
                        QStringList value = m_fields.at(i).split(":");
                        qDebug()  << m_fields.at(0) << value.at(0) << " : " << value.at(1);

                        if(value.at(0).compare("Aerostat Heading") == 0)
                        {
                            ui->DialAerostatHeading->setValue(value.at(1).toDouble(&ok));
                        }
                        else if(value.at(0).compare("Air Temp") == 0)
                        {
                            ui->airTempValue->setText(value.at(1));
                        }
                        else if(value.at(0).compare("Baro Pres") == 0)
                        {
                            ui->baroValue->setText(value.at(1));
                        }
                        else if(value.at(0).compare("Wind Angle") == 0)
                        {
                            ui->DialWindDirection->setValue(value.at(1).toDouble(&ok));
                        }
                        else if(value.at(0).compare("Wind Speed") == 0)
                        {
                            m_pWindSpeedDial->setValue(value.at(1).toDouble(&ok));
                        }
                        else if(value.at(0).compare("Helium Pressure") == 0)
                        {
                            m_pHeliumDial->setValue(value.at(1).toDouble(&ok));
                            ui->heliumValue->setText(value.at(1));
                        }
                        else if(value.at(0).compare("Ballonet Pressure") == 0)
                        {
                            m_pBallonetPressureDial->setValue(value.at(1).toDouble(&ok));
                            ui->ballonetValue->setText(value.at(1));
                        }
                        else if(value.at(0).compare("MagHeading") == 0)
                        {
                            ui->DialHeading->setValue(value.at(1).toDouble(&ok));
                            ui->magentHeadingValue->setText(value.at(1));
                        }
                        else if(value.at(0).compare("Pitch") == 0)
                        {
                            m_pPitch->setValue(value.at(1).toDouble(&ok));
                            ui->pitchValue->setText(value.at(1));
                        }
                        else if(value.at(0).compare("Roll") == 0)
                        {
                            m_pRoll->setValue(value.at(1).toDouble(&ok));
                            ui->rollValue->setText(value.at(1));
                        }
                        else if(value.at(0).compare("Tension") == 0)
                        {
                            ui->tensionValue->setText(value.at(1));
                            m_pCPTDial->setValue(value.at(1).toDouble(&ok));
                        }
                        else if(value.at(0).compare("Max Tension") == 0)
                        {
                            ui->maxTensionValue->setText(value.at(1));
                        }
                        else if(value.at(0).compare("Internal temperature") == 0)
                        {
                            ui->eBoxTempValue->setText(value.at(1));
                        }
                        else if(value.at(0).compare("Blower1 Status") == 0)
                        {
                            QString status = value.at(1);
                            status = status.replace(" ","");

                            if(status.compare("1") == 0)
                            {
                                ui->fan1OnBtn->setChecked(true);
                                ui->fan1Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 0);"));// Green
                            }
                            else
                            {
                                ui->fan1OffBtn->setChecked(true);
                                ui->fan1Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));// red
                            }
                        }
                        else if(value.at(0).compare("Blower2 Status") == 0)
                        {
                            QString status = value.at(1);
                            status = status.replace(" ","");

                            if(status.compare("1") == 0)
                            {
                                ui->fan2OnBtn->setChecked(true);
                                ui->fan2Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 0);"));// Green
                            }
                            else
                            {
                                ui->fan2OffBtn->setChecked(true);
                                ui->fan2Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));// red
                            }
                        }
                        else if(value.at(0).compare("Strobe Light Status") == 0)
                        {
                            QString status = value.at(1);
                            status = status.replace(" ","");

                            if(status.compare("1") == 0)
                            {
                                ui->strobeOnBtn->setChecked(true);
                                ui->strobeWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 0);"));// Green
                            }
                            else
                            {
                                ui->strobeOffBtn->setChecked(true);
                                ui->strobeWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));// red
                            }
                        }
                        else if(value.at(0).compare("Position Light Status") == 0)
                        {
                            QString status = value.at(1);
                            status = status.replace(" ","");

                            if(status.compare("1") == 0)
                            {
                                ui->positionOnBtn->setChecked(true);
                                ui->positionWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 0);"));// Green
                            }
                            else
                            {
                                ui->positionOffBtn->setChecked(true);
                                ui->positionWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));// red
                            }
                        }
                        else
                        {
                            qDebug() << "****************** NOT recognized **************************";
                        }
                    }
                }
            }
        }
    }// For Loop

    emit done();//
}
//=================================================================================================

/*!
  * Handle the actions that have to be done after finish reading the log file
  */
void GCSMainWindow::finishReading()
{
    m_pRecordedTimer->stop();
    m_pClearDisplayTypeTimer->stop();
    ui->displayTypeLabel->setText("<font color='green'>LIVE DATA</font>");
    ui->stopBtn->setEnabled(false);
    ui->playBtn->setEnabled(true);
    ui->browseBtn->setEnabled(true);
    ui->fwdBtn->setEnabled(false);
    // m_pInterface->connectSockets();
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(updateTime()));
    m_uDelay = 1000;
    m_bIsFwd = false;
    emptyFields();
}
//=================================================================================================

/*!
  * Clear GUI fields
  */
void GCSMainWindow::emptyFields()
{
    ui->tensionValue->setText("_");
    ui->maxTensionValue->setText("_");
    m_pCPTDial->setValue(0);

    ui->DialAerostatHeading->setValue(0);
    ui->DialWindDirection->setValue(0);
    m_pWindSpeedDial->setValue(0);
    ui->eBoxTempValue->setText("_");
    ui->airTempValue->setText("_");
    ui->baroValue->setText("_");

    ui->heliumValue->setText("_");
    m_pHeliumDial->setValue(0);
    ui->ballonetValue->setText("_");
    m_pBallonetPressureDial->setValue(0);

    ui->DialHeading->setValue(0);
    ui->magentHeadingValue->setText("_");

    m_pPitch->setValue(0);
    ui->pitchValue->setText("_");

    m_pRoll->setValue(0);
    ui->rollValue->setText("_");

    ui->fan1Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));// Gray
    ui->fan2Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));// Gray
    ui->strobeWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));// Gray
    ui->positionWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));// Gray
    ui->fan1OffBtn->setChecked(true);
    ui->fan2OffBtn->setChecked(true);
    ui->strobeOffBtn->setChecked(true);
    ui->positionOffBtn->setChecked(true);
}


