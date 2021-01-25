#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
   ui->setupUi(this);

   scene = new QGraphicsScene(this);
   ui->graphicsView->setScene(scene);


   this->board = new Board();
   this->board = this->scene->addItem(this->board);
}

MainWindow::~MainWindow()
{
    delete ui;
}

