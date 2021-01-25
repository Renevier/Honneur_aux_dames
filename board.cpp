#include "board.h"

Board::Board(QObject *parent) : QObject(parent)
{
    QBrush blackBrush(Qt::black);
    this->shape->setRect(0, 0, 600, 800);
    this->shape->setBrush(blackBrush);
}
