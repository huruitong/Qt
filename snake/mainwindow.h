#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>

namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *){
        QPainter painter(this);
        painter.drawImage(0,0,image);
    }

private:
    Ui::MainWindow *ui;
    QImage image;

    void MainWindow::Paint() {
    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing, true);//设置反锯齿模式，好看一点
    int pointx=35,pointy=280;//确定坐标轴起点坐标，这里定义(35,280)
    int width=580-pointx,height=260;//确定坐标轴宽度跟高度 上文定义画布为600X300，宽高依此而定。
    //绘制坐标轴 坐标轴原点(35，280)
    painter.drawRect(5,5,600-10,300-10);//外围的矩形，从(5,5)起，到(590,290)结束，周围留了5的间隙。
    painter.drawLine(pointx,pointy,width+pointx,pointy);//坐标轴x宽度为 width
    painter.drawLine(pointx,pointy-height,pointx,pointy);//坐标轴y高度为 height
    }

};

#endif // MAINWINDOW_H
