#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    image = QImage(600,300,QImage::Format_RGB32); //画布的初始化大小设为600*500，使用32位颜色
    QColor backColor = qRgb(255,255,255); //画布初始化背景色使用白色
    image.fill(backColor);//对画布进行填充
    Paint();
}

MainWindow::~MainWindow()
{
    delete ui;
}

