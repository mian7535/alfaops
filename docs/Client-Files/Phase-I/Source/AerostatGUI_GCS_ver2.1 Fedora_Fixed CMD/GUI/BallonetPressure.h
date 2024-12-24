/*
 * Copyright (c) 2012-2013, ADASI,
 * All rights reserved.
 *
 * Author Name: Eiman Al Shamisi
 */

#ifndef INCLUDED_BALLONETPRESSURE_H
#define INCLUDED_BALLONETPRESSURE_H

#include <qwt_dial.h>
#include <qwt_dial_needle.h>
#include <qpainter.h>

/*!
  * This class is used to draw Ballonet Pressure Dial
  */
class BallonetPressure: public QwtDial
{
    Q_OBJECT
public:
    BallonetPressure(QWidget *parent = NULL);

protected:
    virtual void drawScaleContents( QPainter *painter,
                                    const QPointF &center, double radius ) const;
};

#endif // INCLUDED_BALLONETPRESSURE_H
