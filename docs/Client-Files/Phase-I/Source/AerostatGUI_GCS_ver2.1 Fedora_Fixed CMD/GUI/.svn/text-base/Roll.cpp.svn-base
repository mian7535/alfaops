/*
 * Copyright (c) 2012, ADASI,
 * All rights reserved.
 *
 * Author Name: Eiman Al Shamisi
 */

#include "Roll.h"

Roll::Roll(QWidget *parent ):
    QwtDial(parent)
{

    QwtDialSimpleNeedle *needle = new QwtDialSimpleNeedle(QwtDialSimpleNeedle::Arrow, true, Qt::black, QColor(Qt::gray).light(130));
    setNeedle(needle);

    // Roll range [-18,18]
    setRange(-18,18);

    setOrigin(180);
    setScale( 0, 6, 6 ); // 2nd argument to draw inner line between 2 defined numbers . 3rd steps #
    setScaleArc( 0.0, 180.0);

    setDirection(QwtDial::Clockwise);
    setMode(QwtDial::RotateNeedle);
    setReadOnly(true);

    setValue(6);
}
//=================================================================================================


void Roll::drawScaleContents( QPainter *painter, const QPointF &, double ) const
{

    const QColor redColor(Qt::red);
    const QColor yellowColor(Qt::yellow);
    const QColor greenColor(Qt::green);

    // Red range [-18, -7]
    painter->setPen(redColor);
    painter->setBrush( redColor );
    painter->drawPie( scaleInnerRect(),(180 * -16), (55 * -16));

    // Yellow range [-7,-3]
    painter->setPen(yellowColor);
    painter->setBrush( yellowColor );
    painter->drawPie( scaleInnerRect(), (235 * -16 ), (20 * -16));

    // Green range [-3,3]
    painter->setPen(greenColor);
    painter->setBrush( greenColor );
    painter->drawPie( scaleInnerRect(), (255 * -16 ), (30 * -16));

    // Yellow range [3,7]
    painter->setPen(yellowColor);
    painter->setBrush( yellowColor );
    painter->drawPie( scaleInnerRect(),(285 * -16), (20 * -16));

    // Red range [7,18]
    painter->setPen(redColor);
    painter->setBrush( redColor );
    painter->drawPie( scaleInnerRect(),(305 * -16), (55 * -16));
}
//=================================================================================================
