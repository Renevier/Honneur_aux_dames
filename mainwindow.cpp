#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsPixmapItem>

void MainWindow::InitBoard()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++ )
        {
            if(i%2 == 0)
            {
                if(j % 2 != 0)
                    this->board[i][j] = new Case(nullptr, j * 95, i * 95, false);
                else
                    this->board[i][j] = new Case(nullptr, j * 95, i * 95, true);
            }
            else
            {
                if(j % 2 == 0)
                    this->board[i][j] = new Case(nullptr, j * 95, i * 95, false);
                else
                    this->board[i][j] = new Case(nullptr, j * 95, i * 95, true);
            }
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
            if(this->board[i][j]->isBlocked == false && i <= 3)
            {
                this->pawns[k] = new Pawn(this->scene, ":/Ressources/Red_pawn.png",j * 95, i * 95, 1, QPoint(i, j));
                this->board[i][j]->pawn = this->pawns[k];
                k++;
            }
            else if(this->board[i][j]->isBlocked == false && i >= 6)
            {
                this->pawns[k] = new Pawn(this->scene, ":/Ressources/Yellow_pawn.png",j * 95, i * 95, 2, QPoint(i, j));
                this->board[i][j]->pawn = this->pawns[k];
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

    this->turn = 1;
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

    for(int i = 0; i < 40; i++)
    {
        delete pawns[i];
    }

    delete this->scene;

    delete this->ui;
}

bool MainWindow::CanMove()
{
    //Check arround annd i+1 arround
    return true;
}

void MainWindow::PlayablePawn()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++ )
        {
            if(this->board[i][j]->pawn != nullptr)
            {
                if(this->board[i][j]->pawn->id == this->turn)
                {
                    this->board[i][j]->SetColor(Qt::yellow);
                }
            }
        }
    }
}

void MainWindow::Update()
{
    this->PlayablePawn();

}

void MainWindow::DrawBackground()
{
    QGraphicsPixmapItem* pixItem = new QGraphicsPixmapItem(QPixmap(":/Ressources/Board.png"));
    this->scene->addItem(pixItem);
}

void MainWindow::DrawBoard()
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
    for(int i = 0; i < 40; i++)
        this->pawns[i]->Draw();
}

void MainWindow::Draw()
{
    this->DrawBackground();
    this->DrawBoard();
    this->DrawPawns();

    ui->graphicsView->setScene(scene);
}
