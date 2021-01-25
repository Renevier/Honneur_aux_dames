#include "case.h"

Case::Case(QObject *parent) : QObject(parent)
{
    this->shape.setRect(0,0,100,100);
}
