#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "qscreen.h"
#include <QPropertyAnimation>
#include <QGraphicsDropShadowEffect>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;

    // Attempt to connect to the database
    bool test = c.createconnect();
    if (test) {
        // Make the main window fullscreen
        w.showFullScreen();

        // Apply explosion animation to the main window
        QRect screenGeometry = QApplication::primaryScreen()->geometry(); // Fullscreen geometry
        QRect centerGeometry(screenGeometry.center(), QSize(0, 0));       // Start in the center

        QPropertyAnimation *explodeAnimation = new QPropertyAnimation(&w, "geometry");
        explodeAnimation->setDuration(800);  // Set the duration of the explosion (800 ms)
        explodeAnimation->setStartValue(centerGeometry);                 // Start from the center with size 0
        explodeAnimation->setEndValue(screenGeometry);                   // End at fullscreen geometry
        explodeAnimation->start();

        // Add a shadow effect during the explosion to make it visually appealing
        QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect();
        shadowEffect->setBlurRadius(15);  // Set the blur radius for the shadow
        shadowEffect->setOffset(0, 0);   // No offset
        shadowEffect->setColor(Qt::yellow); // Set shadow color to yellow for explosion effect
        w.setGraphicsEffect(shadowEffect);  // Apply the shadow effect to the main window

        // Optional: Remove the shadow effect after the animation completes (if desired)
        QObject::connect(explodeAnimation, &QPropertyAnimation::finished, [&]() {
            // After the explosion animation finishes, remove the shadow effect
            w.setGraphicsEffect(nullptr);
        });

        // Show success message

    } else {
        // Show failure message
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                              QObject::tr("Connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }

    return a.exec();
}
