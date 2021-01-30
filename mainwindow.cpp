#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::InitBoard()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++ )
        {
            if(i%2 == 0)
            {
                if(j % 2 != 0)
                    this->board[i][j] = new Case(nullptr, j * 95, i * 95, false, nullptr, QPoint(i, j));
                else
                    this->board[i][j] = new Case(nullptr, j * 95, i * 95, true, nullptr, QPoint(i, j));
            }
            else
            {
                if(j % 2 == 0)
                    this->board[i][j] = new Case(nullptr, j * 95, i * 95, false, nullptr, QPoint(i, j));
                else
                    this->board[i][j] = new Case(nullptr, j * 95, i * 95, true, nullptr, QPoint(i, j));
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
                this->pawns.push_back(new Pawn(this->scene, ":/Ressources/Red_pawn.png",j * 95, i * 95, 1, QPoint(i, j)));
                this->board[i][j]->pawn = this->pawns.at(k);
                k++;
            }
            else if(this->board[i][j]->isBlocked == false && i >= 6)
            {
                this->pawns.push_back(new Pawn(this->scene, ":/Ressources/Yellow_pawn.png",j * 95, i * 95, 2, QPoint(i, j)));
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
    this->isPawnSelected = false;
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

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++ )
        {
            if(event->button() == Qt::LeftButton)
            {
                //Selectionne une piece et indique au joueur les differentes possibilitées que la piece séléctionnée peut faire
                if((event->pos().x() >= this->board[i][j]->shape.pos().x() &&
                    event->pos().x() <= this->board[i][j]->shape.pos().x() + 95 &&
                    event->pos().y() >= this->board[i][j]->shape.pos().y() &&
                    event->pos().y() <= this->board[i][j]->shape.pos().y() + 95) &&
                        this->board[i][j]->isUsable &&
                        this->isPawnSelected == false)
                {

                    this->selected = this->board[i][j]->pawn; //On copie la piece
                    this->isPawnSelected = true;

                    for (int i = 0; i < 10; i++)
                    {
                        for (int j = 0; j < 10; j++ )
                        {
                            if(this->board[i][j]->isUsable)
                                this->board[i][j]->isUsable = false;


                            if(this->board[i][j]->isUsable == false)
                                this->board[i][j]->SetColor(Qt::transparent);
                        }
                    }

                    if(this->board[i - 1][j - 1]->pawn == nullptr && (i > 0 && j > 0))
                    {
                        this->board[i-1][j-1]->SetColor(Qt::yellow);
                        this->board[i-1][j-1]->isUsable = true;
                    }


                    if(this->board[i - 1][j + 1]->pawn == nullptr && (i > 0 && j < 9))
                    {
                        this->board[i-1][j+1]->SetColor(Qt::yellow);
                        this->board[i-1][j+1]->isUsable = true;
                    }

                    if(this->board[i + 1][j - 1]->pawn == nullptr && (i < 9 && j > 0))
                    {
                        this->board[i+1][j-1]->SetColor(Qt::yellow);
                        this->board[i+1][j-1]->isUsable = true;
                    }

                    if(this->board[i + 1][j + 1]->pawn == nullptr && (i < 9 && j < 9))
                    {
                        this->board[i+1][j+1]->SetColor(Qt::yellow);
                        this->board[i+1][j+1]->isUsable = true;
                    }
                }

                if(this->isPawnSelected && this->selected != nullptr)
                {

                    if((event->pos().x() >= this->board[i][j]->shape.pos().x() &&
                        event->pos().x() <= this->board[i][j]->shape.pos().x() + 95 &&
                        event->pos().y() >= this->board[i][j]->shape.pos().y() &&
                        event->pos().y() <= this->board[i][j]->shape.pos().y() + 95) &&
                            this->board[i][j]->isUsable)
                    {

                        //On bouge la piece
                        this->board[i][j]->pawn = this->selected;

                        int xToDelete = this->selected->coord.x();
                        int yToDelete = this->selected->coord.y();


                        this->selected->coord = QPoint(i, j);

                        //On delete l'ancienne
                        for (int x = 0; x < 10; x++)
                        {
                            for (int y = 0; y < 10; y++ )
                            {
                                if(x == xToDelete && y == yToDelete)
                                    delete this->board[x][y]->pawn;
                            }
                        }

                        this->pawns.push_back(this->selected);
                    }
                }
            }
        }
    }
}

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
                    this->board[i][j]->isUsable = true;
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
    for(int i = 0; i < pawns.size(); i++)
        this->pawns[i]->Draw();
}

void MainWindow::Draw()
{
    this->DrawBackground();
    this->DrawBoard();
    this->DrawPawns();

    ui->graphicsView->setScene(scene);
}

