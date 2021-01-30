#include "case.h"

Case::Case(QObject *parent, int _posX, int _posY, bool _isBlocked, Pawn* _pawn, QPoint _gridCoord) : QObject(parent)
{
    //QPen outlinePen(Qt::blue);
    //outlinePen.setWidth(2);

    this->shape.setRect(0, 0, 95, 95);
    this->shape.setPos(_posX, _posY);
    //this->shape.setPen(outlinePen);

    this->isBlocked = _isBlocked;
    this->pawn = _pawn;
    this->isUsable = false;

}

Case::~Case()
{

}
