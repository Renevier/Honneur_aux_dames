#ifndef CASE_H
#define CASE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include "pawn.h"

class Case : public QObject
{
    Q_OBJECT

public:
    QGraphicsRectItem shape;
    bool isBlocked;
    Pawn* pawn;
    QPoint gridCoord;


public:
    explicit Case(QObject *parent = nullptr, int _posX = 0, int _posY = 0, bool _isBlocked = true, Pawn* _pawn = nullptr, QPoint _gridCoord = QPoint(0, 0));
    ~Case();

    inline void SetColor(QColor _color){ this->shape.setBrush(_color);}
signals:

};

#endif // CASE_H
