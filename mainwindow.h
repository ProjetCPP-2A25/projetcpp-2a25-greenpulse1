#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "complaints.h"
#include "qboxlayout.h"

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

private slots:
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
