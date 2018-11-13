/********************************************************************************
** Form generated from reading UI file 'namenew.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAMENEW_H
#define UI_NAMENEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_nameNew
{
public:

    void setupUi(QDialog *nameNew)
    {
        if (nameNew->objectName().isEmpty())
            nameNew->setObjectName(QStringLiteral("nameNew"));
        nameNew->resize(400, 300);

        retranslateUi(nameNew);

        QMetaObject::connectSlotsByName(nameNew);
    } // setupUi

    void retranslateUi(QDialog *nameNew)
    {
        nameNew->setWindowTitle(QApplication::translate("nameNew", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class nameNew: public Ui_nameNew {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAMENEW_H
