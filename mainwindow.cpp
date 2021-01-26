#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>

void MainWindow::InitBoard()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++ )
        {
            if(j % 2 == 0)
                this->board[i][j] = new Case(nullptr, j * 95, i * 95, false);
            else
                this->board[i][j] = new Case(nullptr, j * 95, i * 95, true);
        }
    }
}

void MainWindow::InitPawns()
{
    int k = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++ )
        {
            if(this->board[i][j]->isBlocked == false && i <= 4)
            {
                this->pawns[k] = new Pawn(j * 95, i * 95, 0);
                k++;
            }
            else if(this->board[i][j]->isBlocked == false && i >= 7)
            {
                this->pawns[k] = new Pawn(j * 95, i * 95, 1);
                k++;
            }
        }
    }
}

void MainWindow::InitBackground()
{
    ui->setupUi(this);

    this->scene = new QGraphicsScene(this);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->InitBoard();
    this->InitBackground();
    this->InitPawns();
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

    for(int i = 0; i <= 40; i++)
    {
        delete pawns[i];
    }

    delete this->scene;

    delete this->ui;
}

void MainWindow::Update()
{

}

void MainWindow::DrawScene()
{
    QGraphicsPixmapItem* pixItem = new QGraphicsPixmapItem(QPixmap(":/Ressources/Board.png"));
    this->scene->addItem(pixItem);
}

void MainWindow::DrawBackground()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++ )
        {
            this->scene->addItem(&this->board[i][j]->shape);
        }
    }
}

void MainWindow::DrawPawns()
{
    for(int i = 0; i <= 40; i++)
        this->scene->addItem(this->pawns[i]);
}

void MainWindow::Draw()
{
    this->DrawScene();
    this->DrawBackground();
    this->DrawPawns();

    ui->graphicsView->setScene(scene);
}

