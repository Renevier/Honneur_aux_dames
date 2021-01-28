#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

#include <case.h>
#include <pawn.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    Case* board[10][10];
    Pawn* pawns[40]; //20 white, 20 black

    int turn;

    void InitBoard();
    void InitPawns();
    void InitBackground();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool CanMove(int _i, int _j);
    void PlayablePawn();
    void Update();

    void DrawBackground();
    void DrawBoard();
    void DrawPawns();
    void Draw();


};
#endif // MAINWINDOW_H
