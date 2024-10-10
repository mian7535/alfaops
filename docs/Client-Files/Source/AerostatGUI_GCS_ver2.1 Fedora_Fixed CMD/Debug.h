/*
 * Copyright (c) 2011-2012, ADASI
 * All rights reserved.
 * This file contains proprietary information.
 * This file shall not be duplicated, used, modified,
 * or disclosed in whole or in part without
 * the express written consent of ADASI.
 *
 * Author Name: Gregory Horrigan
 * $Id: Debug.h 932 2012-02-23 05:49:50Z eiman.alshamisi $
 * $HeadURL: https://172.22.213.24/svn/TamkeenSvn/DevelopmentLibrary/GCS/GCU/GCU_CSCI/Code/Src/Common/Debug.h $
 * $LastChangedRevision: 932 $
 * $LastChangedDate: 2012-02-23 09:49:50 +0400 (Thu, 23 Feb 2012) $
 * $LastChangedBy: eiman.alshamisi $
 */

/*!
 * \file debug.h
 * This header file defines functions that provide output stream for debugging information purpose
 */


#ifndef INCLUDED_DEBUG
#define INCLUDED_DEBUG

#include <QDebug>

#ifndef QT_NO_DEBUG

//! Context string written for every trace message
#define CONTEXT(context) __FILE__ << __LINE__ << context

// Write a simple
#define TRACE(streamStuff) \
{ \
   qDebug() << CONTEXT("TRACE: ") << streamStuff; \
}

#define WARNING(streamStuff) \
{ \
   qWarning() << CONTEXT("WARNING: ") << streamStuff; \
}

#define ERROR(streamStuff) \
{ \
   qCritical() << CONTEXT("ERROR: ") << streamStuff; \
}

#define FATAL(streamStuff) \
{ \
   qCritical() << CONTEXT("FATAL: ") << streamStuff; \
   std::terminate(); \
}

#define ASSERT(condition, streamStuff) \
{ \
   if (condition == false) \
   { \
      FATAL("ASSERTION FAILED (("#condition")):" << streamStuff); \
   } \
}
#else

#define TRACE(stuff)    // nix
#define WARNING(stuff)  // nix
#define ERROR(stuff)    // nix
#define FATAL(stuff)    // nix
#define ASSERT(cond, stuff)   // nix

#endif

#endif // INCLUDED_DEBUG
