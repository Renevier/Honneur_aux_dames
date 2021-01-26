#include "pawn.h"

Pawn::Pawn(QObject *parent, float _posX, float _posY) : QObject(parent)
{
    //QBrush whiteBrush(Qt::white);

    this->shape.setRect(0, 0, 90, 90);
    this->shape.setPos(_posX, _posY);
    this->shape.brush();
}
