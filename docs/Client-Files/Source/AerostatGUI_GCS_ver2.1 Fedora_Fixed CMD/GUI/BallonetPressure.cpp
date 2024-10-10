/*
 * Copyright (c) 2012-2013, ADASI,
 * All rights reserved.
 *
 * Author Name: Eiman Al Shamisi
 */

#include "BallonetPressure.h"

BallonetPressure::BallonetPressure(QWidget *parent ):
    QwtDial(parent)
{

    QwtDialSimpleNeedle *needle = new QwtDialSimpleNeedle(QwtDialSimpleNeedle::Arrow, true, Qt::black, QColor(Qt::gray).light(130));
    setNeedle(needle);

    // Ballonet pressure range [0 - 6]
    setRange(0,6);

    setDirection(QwtDial::Clockwise);
    setMode(QwtDial::RotateNeedle);
    setReadOnly(true);

    setOrigin(115);
    setScale( 0, 2, 1 ); // 2nd argument to draw inner line between 2 defined numbers . 3rd steps #
    setScaleArc( 0.0, 310.0);

    setValue(2.3);
}
//=================================================================================================


void BallonetPressure::drawScaleContents( QPainter *painter, const QPointF &, double ) const
{
    const QColor redColor(Qt::red);
    const QColor yellowColor(Qt::yellow);
    const QColor greenColor(Qt::green);

    // Red range [0 - 0.5]
    painter->setPen(redColor);
    painter->setBrush( redColor );
    painter->drawPie( scaleInnerRect(), (115 * -16), (26 * -16)); //(start point * -16), (band * -16)

    // Yellow range [0.5 - 1.5]
    painter->setPen(yellowColor);
    painter->setBrush( yellowColor );
    painter->drawPie( scaleInnerRect(), (141 * -16 ), (51.5 * -16));

    // Green range [1.5 - 2.5]
    painter->setPen(greenColor);
    painter->setBrush( greenColor );
    painter->drawPie( scaleInnerRect(), (192.5 * -16 ), (52 * -16));

    // Yellow range [2.5 - 4.5]
    painter->setPen(yellowColor);
    painter->setBrush( yellowColor );
    painter->drawPie( scaleInnerRect(), (244.5 * -16 ), (103 * -16));

    // Red range [4.5 - 6]
    painter->setPen(redColor);
    painter->setBrush( redColor );
    painter->drawPie( scaleInnerRect(), (347.5 * -16), (77.5 * -16));

}
//=================================================================================================
