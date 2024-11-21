#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QLabel>
#include <QWidget>
#include <QDialog>
#include <QWidget>
#include <QPainter>
#include <QImage>


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
    void on_Ajouter_clicked();   // Declaration of slot for  "Add"
    void on_Afficher_clicked();  // Declaration of slot for "Display"
    void on_DeleteButton_clicked(); //Declration of slot for "Delete"
    void on_EditButton_clicked(); //Declaration of slot for  "Modify"
    void on_SaveButton_clicked();//Declaration of slot for "Save"
    void on_pushButton_6_clicked();//Declaration of slot for "Statistics"
    void on_pushButton_7_clicked(); //Declaration of slot for "Sort"
    void on_pushButton_8_clicked(); //Declaration of slot for "Close statistics window"
    void on_pushButton_9_clicked(); //Declaration of slot for "Search"
    void on_pushButton_10_clicked(); //Declaration of slot for "PDF Export"
    void on_pushButton_11_clicked();//Declaration of slot for "Leave and Absence management"
    void on_pushButton_12_clicked();//Declaration of slot for "Chatbox"
private:


    Ui::MainWindow *ui;
    void refreshTable();
    QLabel *label_Name;  // To show employee name
    QLabel *label_Department;  // To show employee department
    QLabel *label_Position;  // To show employee position
    QWidget *chartWindow = nullptr;  // Declare the pointer as a member variable
    QDialog* leaveManagementDialog; // New dialog for Leave Management
    QDialog* chatDialog;  // Declare chatDialog here
    QString employeeFirstName;


};

#endif // MAINWINDOW_H
