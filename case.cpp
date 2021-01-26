#include "case.h"

Case::Case(QObject *parent, int _posX, int _posY, bool _isBlocked) : QObject(parent)
{
    //QBrush transparentBrush(Qt::transparent);
    QPen outlinePen(Qt::blue);
    outlinePen.setWidth(2);

    this->shape.setRect(0, 0, 95, 95);
    this->shape.setPos(_posX, _posY);
    this->shape.setPen(outlinePen);

    this->isBlocked = _isBlocked;

}
