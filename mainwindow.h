#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Ajouter_clicked();   // Declaration of slot for  "Ajouter"
    void on_Afficher_clicked();  // Declaration of slot for "Afficher"
    void on_DeleteButton_clicked(); //Declration of slot for "Supprimer"
    void on_EditButton_clicked(); //Declaration of slot for  "Modifier"
    void on_SaveButton_clicked();//Declaration of slot for "Sauvegarder"
private:
    Ui::MainWindow *ui;
    void refreshTable();
};

#endif // MAINWINDOW_H
