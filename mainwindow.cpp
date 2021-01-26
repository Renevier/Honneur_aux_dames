#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //Fill my board
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++ )
        {
            if(j % 2 == 0)
            {
                this->board[i][j] = new Case(nullptr, j * 95, i * 95, false);
            }
            else
            {
                this->board[i][j] = new Case(nullptr, j * 95, i * 95, true);
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++ )
        {
            qDebug() << "PosX: " << this->board[i][j]->shape.pos().x() << "\n"
                << "PosY: " << this->board[i][j]->shape.pos().y() << "\n"
                << "height: " << this->board[i][j]->shape.rect().height()<< "\n"
                << "width: " << this->board[i][j]->shape.rect().width() << "\n"
                << "bool: " << this->board[i][j]->isBlocked;

        }
    }

   ui->setupUi(this);

   this->scene = new QGraphicsScene(this);

   /*QGraphicsPixmapItem* pixItem = new QGraphicsPixmapItem(QPixmap(":/Ressources/Board.png"));
   this->scene->addItem(pixItem);*/

   for (int i = 0; i < 10; i++)
   {
       for (int j = 0; j < 10; j++ )
       {
           this->scene->addItem(&this->board[i][j]->shape);
       }
   }

   this->scene->addItem(&this->pawn->shape);

   ui->graphicsView->setScene(scene);

}

MainWindow::~MainWindow()
{
    for (int i = 0; i < 10; i++)
       {
           for (int j = 0; j < 10; j++ )
           {
               delete this->board[i][j];
           }
       }

    delete this->scene;

    delete this->ui;
}

