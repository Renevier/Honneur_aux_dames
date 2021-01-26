#ifndef PAWN_H
#define PAWN_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

class Pawn : public QObject
{
    Q_OBJECT

public:
    QGraphicsEllipseItem shape;


public:
    explicit Pawn(QObject *parent = nullptr, float _posX = 0.f, float _posY = 0.f);

signals:

};

#endif // PAWN_H
