#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
   ui->setupUi(this);

   this->scene = new QGraphicsScene(this);
   this->scene->setSceneRect(-600, -300, 1200, 600);

   QGraphicsPixmapItem* pixItem = new QGraphicsPixmapItem(QPixmap(":/Ressources/Board.png"));
   this->scene->addItem(pixItem);
   pixItem->setPos(QPointF(0, 0) - QPointF(pixItem->boundingRect().width() / 2,
                                           pixItem->boundingRect().height() / 2));

   ui->graphicsView->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
}

