#include "namenew.h"
#include "ui_namenew.h"

nameNew::nameNew(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nameNew)
{
    ui->setupUi(this);
}

nameNew::~nameNew()
{
    delete ui;
}
