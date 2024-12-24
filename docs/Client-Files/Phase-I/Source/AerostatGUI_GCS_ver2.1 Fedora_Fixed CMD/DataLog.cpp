/*
 * Copyright (c) 2012-2013, ADASI,
 * All rights reserved.
 *
 * Author Name: Eiman Al Shamisi
 */


#include "DataLog.h"
#include "Interface.h"



/*!
 * Constructor
 */
DataLog::DataLog(QObject *pParent, Interface *pInterface):
    QObject(pParent)
{
    // Instance of Interface class
    m_pInterface = pInterface;

    // Date and Time Format
    m_dateTimeFormat = "ddMMyyyy hh:mm:ss";

    // Log directory
    m_logDir = QDir("/var/log/gcs");

    // Log directory path
    m_logDirPath =  m_logDir.path() + "/";

}
//=================================================================================================

/*!
 * Destructor
 */
DataLog::~DataLog()
{
  delete m_pFile;
}
//=================================================================================================


/*!
 * Create and open a new file for logging data
 */
void DataLog::createFile()
{

    // File name
    m_fileName =  getCurrentDateTime() + ".txt" ;

    // Create File object
    m_pFile = new QFile( m_logDirPath + m_fileName );

    // Update log file path in the GUI
    m_pInterface->updateFileName(m_logDirPath + m_fileName);
    // Open the file to write
    if( m_pFile->open( QIODevice::WriteOnly | QIODevice::Append ) == false )
    {
        qDebug() << "Could not open" << m_pFile->fileName() << "for writing.";
    }

    else
    {
        qDebug() << "The file opened.";
    }
    //-----------------------------------------------------------------------

    connect(this, SIGNAL(fileNameChanged(QString)), m_pInterface, SLOT(updateFileName(QString)));
}

//=================================================================================================




/*! Get system current date and time
 \return QString Current date and time
 */
QString DataLog::getCurrentDateTime()
{
    // Get current date & time
    QDateTime currentDT = QDateTime::currentDateTime();

    // Convert dateTime to String
    QString result = currentDT.toString(m_dateTimeFormat);
    return result;
}
//=================================================================================================


/*! Write data in the log file
 \param QString Data to be logged
 */
void DataLog::LogMsgs(QString str)
{
   // Check the file size before writting new data
   checkFileSize();
   QTextStream in (m_pFile);
   in << "\n" << getCurrentDateTime() << "\t" << str;
}
//=================================================================================================


/*!
 * Check the file size if it reaches the max specefied size,
 * if yes, it closes the current file and opens new one
 */
void DataLog::checkFileSize()
{
    if(m_pFile->size() >= MAX_LOG_FILE_SIZE)
    {
       m_pFile->close();

       m_fileName =  getCurrentDateTime() + ".txt" ;
       m_pFile->setFileName(m_logDirPath + m_fileName);
       bool bIsOpen;
       bIsOpen = m_pFile->open(QIODevice::WriteOnly | QIODevice::Append);
       if (bIsOpen == false)
       {
          qDebug() << __LINE__;
       }
       else
       {
           QString filePath;
           filePath = m_logDir.absoluteFilePath(m_fileName);
           emit fileNameChanged(filePath);
       }
    }
}

