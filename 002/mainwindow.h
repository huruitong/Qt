#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPainter>
#include <QTextEdit>
#include <QPushButton>

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

private:
    Ui::MainWindow *ui;
    QImage image;

};

#endif // MAINWINDOW_H
