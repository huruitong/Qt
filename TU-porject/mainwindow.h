#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPainter>
#include <QTextEdit>
#include <QPushButton>
#include <QTimer>
#include <QTime>
#include <QApplication>

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

    void sleep(unsigned int msec){
        QTime reachTime = QTime::currentTime().addMSecs(msec);
        while (QTime::currentTime() < reachTime) {
            QCoreApplication::processEvents(QEventLoop::AllEvents,100);
        }
    }

};

#endif // MAINWINDOW_H
