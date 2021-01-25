#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QVector>

#include <case.h>

class Board : public QObject
{
    Q_OBJECT

private:
    QGraphicsRectItem* shape;
    QVector<Case*> cases;

public:
    explicit Board(QObject *parent = nullptr);

signals:

};

#endif // BOARD_H
