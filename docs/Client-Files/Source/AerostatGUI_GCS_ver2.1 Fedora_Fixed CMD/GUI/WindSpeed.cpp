/*
 * Copyright (c) 2012, ADASI,
 * All rights reserved.
 *
 * Author Name: Eiman Al Shamisi
 */

#include "WindSpeed.h"


WindSpeed::WindSpeed(QWidget *parent ):
    QwtDial(parent)
{

    QwtDialSimpleNeedle *needle = new QwtDialSimpleNeedle(QwtDialSimpleNeedle::Arrow, true, Qt::black, QColor(Qt::gray).light(130));
    setNeedle(needle);

    // Wind speed range [0 - 70]
    setRange(0,70);

    setDirection(QwtDial::Clockwise);
    setMode(QwtDial::RotateNeedle);
    setReadOnly(true);

    setOrigin(115);
    setScale( 0, 5, 5 ); // 2nd argument to draw inner line between 2 defined numbers . 3rd steps #
    setScaleArc( 0.0, 310.0);

    setValue(60);
}
//=================================================================================================



void WindSpeed::drawScaleContents( QPainter *painter, const QPointF &, double ) const
{
    const QColor redColor(Qt::red);
    const QColor yellowColor(Qt::yellow);
    const QColor greenColor(Qt::green);

    // Green range [0 - 30]
    painter->setPen(greenColor);
    painter->setBrush( greenColor );
    painter->drawPie( scaleInnerRect(),(115 * -16), (133 * -16));

    // Yellow range [30 - 40]
    painter->setPen(yellowColor);
    painter->setBrush( yellowColor );
    painter->drawPie( scaleInnerRect(), (248 * -16 ), (44 * -16));

    // Red range [40 - 70]
    painter->setPen(redColor);
    painter->setBrush( redColor );
    painter->drawPie( scaleInnerRect(), (292 * -16 ), (133 * -16));
}
//=================================================================================================
