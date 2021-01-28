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

    delete this->ui;}

bool MainWindow::CanMove(int _i, int _j)
{
    //if corner top/left
    if(_i == 0 && _j == 0){
        if(this->board[_i + 1][_j + 1]->pawn == nullptr) //bot-right
            return true;}
    //if top
    else if (_j == 0 && (_i >= 1 && _i <= 8)){
        if(this->board[_i - 1][_j + 1]->pawn == nullptr|| // bot-left
                this->board[_i + 1][_j + 1]->pawn == nullptr) // bot-right
            return true;}
    //if corner top/right
    else if(_i == 0 && _j == 9){
        if(this->board[_i + 1][_j - 1]->pawn == nullptr || this->board[_i + 2][_j - 2]->pawn == nullptr)// bot-left
            return true;}
    //right
    else if(_i == 9 && (_j >= 1 && _j <= 8)){
        if(this->board[_i - 1][_j + 1]->pawn == nullptr|| // bot-left
                this->board[_i - 1][_j - 1]->pawn == nullptr) // top-left
            return true;}
    //if corner bot/left
    else if(_i == 9 && _j == 0){
        if(this->board[_i - 1][_j + 1]->pawn == nullptr)// top-right
            return true;}
    //bot
    else if(_j == 9 && (_i >= 1 && _i <= 8)){
        if(this->board[_i - 1][_j - 1]->pawn == nullptr|| // bot-left
                this->board[_i + 1][_j - 1]->pawn == nullptr) // bot-right
            return true;}
    //if corner bot/right
    else if(_i == 9 && _j == 9){
        if(this->board[_i - 1][_j - 1]->pawn == nullptr)//top-left
            return true;}
    //left
    else if(_i == 0 && (_j >= 1 && _j <= 8)){
        if(this->board[_i + 1][_j - 1]->pawn == nullptr|| // bot-left
                this->board[_i + 1][_j + 1]->pawn == nullptr) // bot-right
            return true;}

    //if corner top + 1/left + 1
    else if(_i == 1 && _j == 1){
        if(this->board[_i - 1][_j - 1]->pawn == nullptr || //top-left
                this->board[_i - 1][_j + 1]->pawn == nullptr ||// top-right
                this->board[_i + 1][_j - 1]->pawn == nullptr ||// bot-left
                this->board[_i + 1][_j + 1]->pawn == nullptr) //bot-right
            return true;}
    //if corner top + 1/right - 1
    else if(_i == 1 && _j == 8){
        if(this->board[_i - 1][_j - 1]->pawn == nullptr || //top-left
                this->board[_i - 1][_j + 1]->pawn == nullptr ||// top-right
                this->board[_i + 1][_j - 1]->pawn == nullptr ||// bot-left
                this->board[_i + 1][_j + 1]->pawn == nullptr) //bot-right
            return true;}
    //if corner bot - 1/left + 1
    else if(_i == 8 && _j == 1){
        if(this->board[_i - 1][_j - 1]->pawn == nullptr ||//top-left
                this->board[_i - 1][_j + 1]->pawn == nullptr ||// top-right
                this->board[_i + 1][_j - 1]->pawn == nullptr ||// bot-left
                this->board[_i + 1][_j + 1]->pawn == nullptr) //bot-right
            return true;}
    //if corner bot - 1/right - 1
    else if(_i == 8 && _j == 8){
        if(this->board[_i - 1][_j - 1]->pawn == nullptr ||//top-left
                this->board[_i - 1][_j + 1]->pawn == nullptr ||// top-right
                this->board[_i + 1][_j - 1]->pawn == nullptr ||// bot-left
                this->board[_i + 1][_j + 1]->pawn == nullptr) //bot-right
            return true;}
    else
    {
        if(this->board[_i - 1][_j - 1]->pawn == nullptr || //top-left
                this->board[_i - 1][_j + 1]->pawn == nullptr || // top-right
                this->board[_i + 1][_j - 1]->pawn == nullptr || // bot-left
                this->board[_i + 1][_j + 1]->pawn == nullptr) //bot-right
            return true;
    }
    return false;
}

void MainWindow::PlayablePawn()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++ )
        {
            if(this->board[i][j]->pawn != nullptr)
            {
                if(this->board[i][j]->pawn->id == this->turn && CanMove(i, j))
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
