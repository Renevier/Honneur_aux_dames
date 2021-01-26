#ifndef PAWN_H
#define PAWN_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class Pawn : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    int id;

public:
    explicit Pawn(float _posX = 0.f, float _posY = 0.f, int _id = 0);
    ~Pawn();

signals:

};

#endif // PAWN_H
