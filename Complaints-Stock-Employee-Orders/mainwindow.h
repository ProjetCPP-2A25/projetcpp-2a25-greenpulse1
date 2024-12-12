#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "complaints.h"
#include "qboxlayout.h"
#include "stock.h"
#include <QSystemTrayIcon>
#include <QTableWidget>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <QListWidget>
#include <QLineEdit>
#include <QList>
#include <QPair>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    void keyPressEvent(QKeyEvent *event) override;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString getHistorique();
    QLabel* getHistoriqueLabel();  // Function to get the QLabel that displays the history
    QLabel *historique;  //
    void appendHistorique(const QString &historiqueText);   // Make it public
    void updateHistorique(const QString &historiqueText);
    bool isAuthenticated=false;
     bool isPasswordVisible = false;
private:
    QList<QPair<QString, QString>> historyList;

    Stock stock;
    QSystemTrayIcon *trayIcon;
    QListWidget *notificationHistory;
private slots:

    void on_btn_eye_clicked();
    void on_addButton_clicked(); // Slot for handling add button clicks
    void on_updateButton_clicked();
    void on_deleteButton_clicked();
    void on_searchButton_clicked();
    void on_sauvegarder_clicked();
    void on_exportButton_6_clicked();
    void on_statistique_6_clicked();
    void on_backButton_clicked();
    void on_refreshButton_clicked();
    void on_combobox_activated();
    void on_ascButton_clicked();
    void on_dscButton_clicked();
    void on_Upload_Clicked();
    void onFullScreen();
    void on_pushButton_Confirmer_clicked();

    void showEvent(QShowEvent *event);
    void playButtonClickSound();
    void setupButtonClickSounds();
    void playTypingSound();
    void setupBackgroundMusic();
    void on_normalCheckBox_clicked(bool checked);
    void on_urgentCheckBox_clicked(bool checked);
    void on_afficherSimpleButton_clicked();
    void on_afficherUrgentButton_clicked();
    void animateButton(QPushButton *button, bool grow);
    bool eventFilter(QObject *watched, QEvent *event);
    void animateLabel(QLabel* label, const QString& animationType);
    void onToggleDarkModeClicked();
///////////////////////////////////////////
    void refreshTable4();
    void setupConnections();
    void on_sauvegarder1_clicked();
    void on_modifyButton_clicked();
    void onRowSelected(const QModelIndex &current, const QModelIndex &previous);
    void updateHistoryTable();
    void showNotificationInLayout(const QString &title, const QString &message);
    void checkLowStock(const QString &productName, int stockLevel);
    void notifyUser(const QString &title, const QString &message, QSystemTrayIcon::MessageIcon icon);
    void showStatistics();
    void exportToPDF();
    void on_sort_clicked();
    void on_trierLine_6_currentTextChanged();
    void on_searchButton1_clicked();
    void on_deleteButton1_clicked();
    void on_updateButton1_clicked();
    void on_refrech_er_clicked();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

private slots:
    void on_Ajouter_clicked();   // Declaration of slot for  "Add"
    void on_Afficher_clicked();  // Declaration of slot for "Display"
    void on_DeleteButton_clicked(); //Declration of slot for "Delete"
    void on_EditButton_clicked(); //Declaration of slot for  "Modify"
    void on_SaveButton_clicked();//Declaration of slot for "Save"
    //bool eventFilter(QObject *obj, QEvent *event);
    void on_pushButton_6_clicked();//Declaration of slot for "Statistics"
    void on_pushButton_7_clicked(); //Declaration of slot for "Sort"
    //void on_pushButton_8_clicked(); //Declaration of slot for "Close statistics window"
    void on_pushButton_9_clicked(); //Declaration of slot for "Search"
    void on_pushButton_10_clicked(); //Declaration of slot for "PDF Export"
    void on_pushButton_11_clicked();//Declaration of slot for "Leave and Absence management"
    void on_pushButton_12_clicked();//Declaration of slot for "Chatbox"
private:


   // Ui::MainWindow *ui;
   // void refreshTable();
    QLabel *label_Name;  // To show employee name
    QLabel *label_Department;  // To show employee department
    QLabel *label_Position;  // To show employee position
    QWidget *chartWindow = nullptr;  // Declare the pointer as a member variable
    QDialog* leaveManagementDialog; // New dialog for Leave Management
    QDialog* chatDialog;  // Declare chatDialog here
    QString employeeFirstName;
















private:
    bool isAscending = true;  // True for ASC, False for DSC
    QVBoxLayout *videoLayout;
    QString currentMediaPath; // Store the selected media file path
    int currentComplaintId; // Par exemple
    COMPLAINTS currentComplaint;  // Declare as a COMPLAINTS object
    bool isDarkMode = false; // Keeps track of the current mode





private:
    Ui::MainWindow *ui;

    // Helper functions
    void refreshTable(); // Function to refresh the table after adding a reservation
};

#endif // MAINWINDOW_H
