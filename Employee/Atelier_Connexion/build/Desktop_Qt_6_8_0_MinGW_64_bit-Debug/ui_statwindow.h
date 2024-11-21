/********************************************************************************
** Form generated from reading UI file 'statwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATWINDOW_H
#define UI_STATWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>

QT_BEGIN_NAMESPACE

class Ui_StatWindow
{
public:

    void setupUi(QGroupBox *StatWindow)
    {
        if (StatWindow->objectName().isEmpty())
            StatWindow->setObjectName("StatWindow");
        StatWindow->resize(240, 320);

        retranslateUi(StatWindow);

        QMetaObject::connectSlotsByName(StatWindow);
    } // setupUi

    void retranslateUi(QGroupBox *StatWindow)
    {
        StatWindow->setWindowTitle(QCoreApplication::translate("StatWindow", "GroupBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StatWindow: public Ui_StatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATWINDOW_H
