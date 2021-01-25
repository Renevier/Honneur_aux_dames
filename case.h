#ifndef CASE_H
#define CASE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

class Case : public QObject
{
    Q_OBJECT

private:
    QGraphicsRectItem shape;

public:
    explicit Case(QObject *parent = nullptr);

signals:

};

#endif // CASE_H
