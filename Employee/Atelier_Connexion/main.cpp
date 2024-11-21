#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Apply a global style fix for QMessageBox to ensure text readability
    a.setStyleSheet(
        "QMessageBox { background-color: white; color: black; } "
        "QMessageBox QLabel { color: black; } "
        "QMessageBox QPushButton { background-color: lightgray; color: black; border: 1px solid gray; padding: 5px; }"
        );

    MainWindow w;
    Connection c;
    bool test = c.createconnection();
    if (test) {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("Database is Open"),
                                 QObject::tr("Connection successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    } else {
        // If the connection fails, show an error message
        QMessageBox::critical(nullptr, QObject::tr("Database is Not Open"),
                              QObject::tr("Connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }

    return a.exec();
}
