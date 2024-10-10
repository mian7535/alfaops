/*
 * Copyright (c) 2012, ADASI,
 * All rights reserved.
 *
 * Author Name: Eiman Al Shamisi
 */


#ifndef INCLUDED_PITCH_H
#define INCLUDED_PITCH_H

#include <qwt_dial.h>
#include <qwt_dial_needle.h>
#include <qpainter.h>


class Pitch: public QwtDial
{
    Q_OBJECT

public:
    Pitch(QWidget *parent = NULL);

protected:
    virtual void drawScaleContents( QPainter *painter,
                                    const QPointF &center, double radius ) const;
};

#endif // INCLUDED_PITCH_H
