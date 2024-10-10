/*
 * Copyright (c) 2012, ADASI,
 * All rights reserved.
 *
 * Author Name: Eiman Al Shamisi
 */


#include "ConfluencePointTension.h"


ConfluencePointTension::ConfluencePointTension(QWidget *parent ):
    QwtDial(parent)
{

    QwtDialSimpleNeedle *needle = new QwtDialSimpleNeedle(QwtDialSimpleNeedle::Arrow, true, Qt::black, QColor(Qt::gray).light(130));
    setNeedle(needle);

    // Confluence Point Tension range [0,750]
    setRange(0,750);

    setDirection(QwtDial::Clockwise);
    setMode(QwtDial::RotateNeedle);
    setReadOnly(true);

    setOrigin(115);
    setScale( 0, 5, 50 ); // 2nd argument to draw inner line between 2 defined numbers . 3rd steps #
    setScaleArc( 0.0, 310.0);

    setValue(275);
}
//=================================================================================================


void ConfluencePointTension::drawScaleContents( QPainter *painter, const QPointF &, double ) const
{
    const QColor redColor(Qt::red);
    const QColor yellowColor(Qt::yellow);
    const QColor greenColor(Qt::green);

    // Red range [0,15]
    painter->setPen(redColor);
    painter->setBrush( redColor );
    painter->drawPie( scaleInnerRect(),(115 * -16), (6.5* -16));

    // Yellow range [15, 30]
    painter->setPen(yellowColor);
    painter->setBrush( yellowColor );
    painter->drawPie( scaleInnerRect(),(121 * -16), (6.5 * -16));

    // Green range [30, 350]
    painter->setPen(greenColor);
    painter->setBrush( greenColor );
    painter->drawPie( scaleInnerRect(),(127.5 * -16), (141 * -16));

    // Yellow range [350, 500]
    painter->setPen(yellowColor);
    painter->setBrush( yellowColor );
    painter->drawPie( scaleInnerRect(), (260 * -16 ), (62 * -16));

    // Red range [500, 750]
    painter->setPen(redColor);
    painter->setBrush( redColor );
    painter->drawPie( scaleInnerRect(), (322 * -16 ), (103 * -16));
}
//=================================================================================================
