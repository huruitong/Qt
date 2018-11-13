#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMouseEvent>
#include<QPaintEvent>
#include<QtGui>
#include <qlineedit.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Paint();


protected:
    void paintEvent(QPaintEvent *){
        QPainter painter(this);
        painter.drawImage(0,0,image);
    }

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QImage image;
    QLineEdit* lineEdit;
};

#endif // MAINWINDOW_H
