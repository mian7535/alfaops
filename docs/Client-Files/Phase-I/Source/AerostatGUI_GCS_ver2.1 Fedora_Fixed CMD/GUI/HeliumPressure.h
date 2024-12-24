/*
 * Copyright (c) 2012, ADASI,
 * All rights reserved.
 *
 * Author Name: Eiman Al Shamisi
 */

#ifndef INCLUDED_HELIUMPRESSURE_H
#define INCLUDED_HELIUMPRESSURE_H

#include <qwt_dial.h>
#include <qwt_dial_needle.h>
#include <qpainter.h>
class HeliumPressure: public QwtDial
{
    Q_OBJECT

public:
    HeliumPressure(QWidget *parent = NULL);

protected:
    virtual void drawScaleContents( QPainter *painter,
                                    const QPointF &center, double radius ) const;
};

#endif // INCLUDED_HELIUMPRESSURE_H
