/*
 * Copyright (c) 2012-2013, ADASI,
 * All rights reserved.
 *
 * Author Name: Eiman Al Shamisi
 */

#ifndef INCLUDED_DATALOG_H
#define INCLUDED_DATALOG_H

#include <QObject>
#include <QDateTime>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include "Debug.h"


//! Mega Byte value in Bytes
const quint64 MB = 1048576LL;

//! Maximum log file size = 10 Megabytes = 10485760 Bytes
const qint64 MAX_LOG_FILE_SIZE = 20 * MB;

//! Forward declaration of Interface class
class Interface;


class DataLog: public QObject
{
    Q_OBJECT

public:
    DataLog(QObject*pParent, Interface *pInterface);
    ~DataLog();
    void LogMsgs(QString str);
    void createFile();
signals:
    void fileNameChanged(QString filePath);


private:

    //! Instance of Interface class
    Interface *m_pInterface;

    //! File used to write log
    QFile *m_pFile;

    //! Directory of log files
    QDir m_logDir;

    //! Logging directory path
    QString m_logDirPath;

    //! The preferred format of DateTime object
    QString m_dateTimeFormat;

    //! Name of log file
    QString m_fileName;

    // Methods
    QString getCurrentDateTime();
    void checkFileSize();
};

#endif // INCLUDED_DATALOG_H
