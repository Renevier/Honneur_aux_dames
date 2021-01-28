#include "pawn.h"

Pawn::Pawn(QGraphicsScene* _scene, QString _pixItem,float _posX, float _posY, int _id, QPoint _coord)
{
    this->scene = _scene;
    this->pixItem = new QGraphicsPixmapItem(QPixmap(_pixItem));

    this->pixItem->setPos(_posX + this->pixItem->boundingRect().width() / 2, _posY + this->pixItem->boundingRect().height() / 2);

    this->id = _id;
    this->coord = _coord;
}

Pawn::~Pawn()
{
    delete this->pixItem;
}

void Pawn::Draw()
{
    this->scene->addItem(this->pixItem);
}
