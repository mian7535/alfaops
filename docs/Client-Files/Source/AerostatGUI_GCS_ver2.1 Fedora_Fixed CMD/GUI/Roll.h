/*
 * Copyright (c) 2012, ADASI,
 * All rights reserved.
 *
 * Author Name: Eiman Al Shamisi
 */

#ifndef INCLUDED_ROLL_H
#define INCLUDED_ROLL_H

#include <qwt_dial.h>
#include <qwt_dial_needle.h>
#include <qpainter.h>

class Roll: public QwtDial
{
    Q_OBJECT

public:
    Roll(QWidget *parent = NULL);

protected:
    virtual void drawScaleContents( QPainter *painter,
                                    const QPointF &center, double radius ) const;
};


#endif // INCLUDED_ROLL_H
