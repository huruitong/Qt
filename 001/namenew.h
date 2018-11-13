#ifndef NAMENEW_H
#define NAMENEW_H

#include <QDialog>

namespace Ui {
class nameNew;
}

class nameNew : public QDialog
{
    Q_OBJECT

public:
    explicit nameNew(QWidget *parent = nullptr);
    ~nameNew();

private:
    Ui::nameNew *ui;
};

#endif // NAMENEW_H
