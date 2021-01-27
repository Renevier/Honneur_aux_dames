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
private:
    QGraphicsScene *scene;
    QGraphicsPixmapItem* pixItem;

public:
    explicit Pawn(QGraphicsScene* _scene, QString _pixItem, float _posX = 0.f, float _posY = 0.f);
    ~Pawn();

    void Draw();

signals:

};

#endif // PAWN_H
