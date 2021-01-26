#ifndef CASE_H
#define CASE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

class Case : public QObject
{
    Q_OBJECT

public:
    QGraphicsRectItem shape;
    bool isBlocked;


public:
    explicit Case(QObject *parent = nullptr, int _posX = 0, int _posY = 0, bool _isBlocked = true);
    ~Case();

signals:

};

#endif // CASE_H
