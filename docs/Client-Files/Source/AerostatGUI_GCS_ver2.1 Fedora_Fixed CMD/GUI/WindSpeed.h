/*
 * Copyright (c) 2012, ADASI,
 * All rights reserved.
 *
 * Author Name: Eiman Al Shamisi
 */


#ifndef INCLUDED_WINDSPEED_H
#define INCLUDED_WINDSPEED_H

#include <qwt_dial.h>
#include <qwt_dial_needle.h>
#include <qpainter.h>

class WindSpeed: public QwtDial
{
    Q_OBJECT

public:
    WindSpeed(QWidget *parent = NULL);

protected:
    virtual void drawScaleContents( QPainter *painter,
                                    const QPointF &center, double radius ) const;
};

#endif // INCLUDED_WINDSPEED_H
