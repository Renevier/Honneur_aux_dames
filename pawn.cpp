#include "pawn.h"

Pawn::Pawn(float _posX, float _posY, int _id)
{
    QGraphicsPixmapItem* pixItem;

    if(this->id == 0)
        pixItem = new QGraphicsPixmapItem(QPixmap(":/Ressources/Red_pawn.png"));
    else if(this->id == 1)
        pixItem = new QGraphicsPixmapItem(QPixmap(":/Ressources/Yellow_pawn.png"));

    //Redefine the origine of our pixmap
    QPainter p;
    p.translate(this->pixmap().width() / 2,
                this->pixmap().height() / 2);

    this->setPos(_posX - this->pixmap().width() / 2,
                 _posY - this->pixmap().height() / 2);
}

Pawn::~Pawn()
{

}
