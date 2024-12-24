/*
 * Copyright (c) 2012, ADASI,
 * All rights reserved.
 *
 * Author Name: Eiman Al Shamisi
 */

#include "Pitch.h"

Pitch::Pitch(QWidget *parent ):
    QwtDial(parent)
{

    QwtDialSimpleNeedle *needle = new QwtDialSimpleNeedle(QwtDialSimpleNeedle::Arrow, true, Qt::black, QColor( Qt::gray ).light(130));
    setNeedle(needle);

    // Pitch range [-12, 24]
    setRange(-12,24);

    setDirection(QwtDial::Clockwise);
    setMode(QwtDial::RotateNeedle);
    setReadOnly(true);

    setOrigin(130);
    setScale( 0, 6, 6 ); // 2nd argument to draw inner line between 2 defined numbers . 3rd steps #
    setScaleArc( 0.0, 145.0);

    setValue(6);
}
//=================================================================================================

void Pitch::drawScaleContents( QPainter *painter,
                               const QPointF &, double ) const
{

    const QColor redColor(Qt::red);
    const QColor yellowColor(Qt::yellow);
    const QColor greenColor(Qt::green);

    // Red range [-12, -6]
    painter->setPen(redColor);
    painter->setBrush( redColor );
    painter->drawPie( scaleInnerRect(),(130 * -16), (24 * -16));

    // Yellow range [-6, 0]
    painter->setPen(yellowColor);
    painter->setBrush( yellowColor );
    painter->drawPie( scaleInnerRect(), (154 * -16 ), (24.5 * -16));

    // Green range [0, 10]
    painter->setPen(greenColor);
    painter->setBrush( greenColor );
    painter->drawPie( scaleInnerRect(), (178.5 * -16 ), (40 * -16));

    // Yellow range [10, 15]
    painter->setPen(yellowColor);
    painter->setBrush( yellowColor );
    painter->drawPie( scaleInnerRect(),(218.5 * -16), (20.5 * -16));

    // Red range [15, 24]
    painter->setPen(redColor);
    painter->setBrush( redColor );
    painter->drawPie( scaleInnerRect(),(239 * -16), (36 * -16));
}
//=================================================================================================
