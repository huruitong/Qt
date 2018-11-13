#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPushButton button("Quite");
    QObject::connect(&button, &QPushButton::clicked, &QApplication::quit);
    button.show();
    return a.exec();

}
