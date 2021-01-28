#ifndef PAWN_H
#define PAWN_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class Pawn : public QObject
{
    Q_OBJECT
public:
    QGraphicsScene *scene;
    QGraphicsPixmapItem* pixItem;
    int id;
    QPoint coord;

public:
    explicit Pawn(QGraphicsScene* _scene, QString _pixItem, float _posX = 0.f, float _posY = 0.f, int _id = 1, QPoint _coord = QPoint(0, 0));
    ~Pawn();

    void Draw();

signals:

};

#endif // PAWN_H
