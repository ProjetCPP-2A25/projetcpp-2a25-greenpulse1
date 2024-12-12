/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *l1;
    QLineEdit *l2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *l3;
    QLineEdit *l4;
    QLineEdit *l5;
    QLineEdit *l7;
    QDateEdit *l0;
    QPushButton *sauvegarder;
    QPushButton *addButton;
    QPushButton *backButton;
    QPushButton *Upload;
    QLineEdit *filePathLineEdit;
    QGroupBox *groupBox_9;
    QLabel *label_39;
    QLineEdit *seearchLine_6;
    QPushButton *statistique_6;
    QPushButton *exportButton_6;
    QLabel *label_40;
    QComboBox *combobox;
    QTableWidget *tableWidget_6;
    QPushButton *searchButton;
    QPushButton *deleteButton;
    QPushButton *updateButton;
    QPushButton *refreshButton;
    QPushButton *ascButton;
    QPushButton *dscButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1920, 1080);
        MainWindow->setStyleSheet(QString::fromUtf8("background:#FFFF; \n"
""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 30, 451, 1001));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 50, 121, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 90, 81, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 130, 101, 16));
        l1 = new QLineEdit(groupBox);
        l1->setObjectName("l1");
        l1->setGeometry(QRect(120, 80, 321, 31));
        l2 = new QLineEdit(groupBox);
        l2->setObjectName("l2");
        l2->setGeometry(QRect(120, 120, 321, 31));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 170, 111, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 210, 111, 16));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 250, 111, 21));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 290, 111, 21));
        l3 = new QLineEdit(groupBox);
        l3->setObjectName("l3");
        l3->setGeometry(QRect(120, 160, 321, 31));
        l4 = new QLineEdit(groupBox);
        l4->setObjectName("l4");
        l4->setGeometry(QRect(120, 200, 321, 31));
        l5 = new QLineEdit(groupBox);
        l5->setObjectName("l5");
        l5->setGeometry(QRect(120, 240, 321, 31));
        l7 = new QLineEdit(groupBox);
        l7->setObjectName("l7");
        l7->setGeometry(QRect(120, 280, 321, 31));
        l0 = new QDateEdit(groupBox);
        l0->setObjectName("l0");
        l0->setGeometry(QRect(120, 40, 321, 26));
        sauvegarder = new QPushButton(groupBox);
        sauvegarder->setObjectName("sauvegarder");
        sauvegarder->setGeometry(QRect(180, 350, 81, 41));
        addButton = new QPushButton(groupBox);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(350, 350, 81, 41));
        backButton = new QPushButton(groupBox);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(10, 350, 91, 41));
        Upload = new QPushButton(groupBox);
        Upload->setObjectName("Upload");
        Upload->setGeometry(QRect(260, 400, 83, 29));
        filePathLineEdit = new QLineEdit(groupBox);
        filePathLineEdit->setObjectName("filePathLineEdit");
        filePathLineEdit->setGeometry(QRect(50, 490, 321, 31));
        groupBox_9 = new QGroupBox(centralWidget);
        groupBox_9->setObjectName("groupBox_9");
        groupBox_9->setGeometry(QRect(470, 30, 1161, 711));
        QFont font;
        font.setFamilies({QString::fromUtf8("Perpetua")});
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setUnderline(true);
        groupBox_9->setFont(font);
        label_39 = new QLabel(groupBox_9);
        label_39->setObjectName("label_39");
        label_39->setGeometry(QRect(10, 30, 241, 21));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Perpetua")});
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setUnderline(false);
        label_39->setFont(font1);
        label_39->setStyleSheet(QString::fromUtf8("color:black"));
        seearchLine_6 = new QLineEdit(groupBox_9);
        seearchLine_6->setObjectName("seearchLine_6");
        seearchLine_6->setGeometry(QRect(250, 30, 141, 28));
        statistique_6 = new QPushButton(groupBox_9);
        statistique_6->setObjectName("statistique_6");
        statistique_6->setGeometry(QRect(460, 30, 141, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Perpetua")});
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setUnderline(true);
        statistique_6->setFont(font2);
        statistique_6->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        statistique_6->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"border-radius:20px;\n"
"background-color:#030C54;\n"
"color:white"));
        exportButton_6 = new QPushButton(groupBox_9);
        exportButton_6->setObjectName("exportButton_6");
        exportButton_6->setGeometry(QRect(610, 30, 141, 41));
        exportButton_6->setFont(font2);
        exportButton_6->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        exportButton_6->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"border-radius:20px;\n"
"background-color:#030C54;\n"
"color:white"));
        label_40 = new QLabel(groupBox_9);
        label_40->setObjectName("label_40");
        label_40->setGeometry(QRect(10, 80, 81, 21));
        label_40->setFont(font);
        label_40->setStyleSheet(QString::fromUtf8("color:#030C54"));
        combobox = new QComboBox(groupBox_9);
        combobox->addItem(QString());
        combobox->setObjectName("combobox");
        combobox->setGeometry(QRect(100, 80, 131, 28));
        tableWidget_6 = new QTableWidget(groupBox_9);
        if (tableWidget_6->columnCount() < 8)
            tableWidget_6->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableWidget_6->setObjectName("tableWidget_6");
        tableWidget_6->setGeometry(QRect(90, 140, 1001, 491));
        tableWidget_6->setStyleSheet(QString::fromUtf8("font: 800 9pt \"Segoe UI\";\n"
"background:#79d9b0; \n"
"width:150px;\n"
"border: 3px solid #79d9b0;\n"
"border-radius: 20px;\n"
"color:pink;"));
        searchButton = new QPushButton(groupBox_9);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(240, 90, 141, 41));
        searchButton->setFont(font2);
        searchButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        searchButton->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"border-radius:20px;\n"
"background-color:#030C54;\n"
"color:white"));
        deleteButton = new QPushButton(groupBox_9);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(390, 90, 141, 41));
        deleteButton->setFont(font2);
        deleteButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        deleteButton->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"border-radius:20px;\n"
"background-color:#030C54;\n"
"color:white"));
        updateButton = new QPushButton(groupBox_9);
        updateButton->setObjectName("updateButton");
        updateButton->setGeometry(QRect(550, 90, 141, 41));
        updateButton->setFont(font2);
        updateButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        updateButton->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"border-radius:20px;\n"
"background-color:#030C54;\n"
"color:white"));
        refreshButton = new QPushButton(groupBox_9);
        refreshButton->setObjectName("refreshButton");
        refreshButton->setGeometry(QRect(700, 90, 141, 41));
        refreshButton->setFont(font2);
        refreshButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        refreshButton->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"border-radius:20px;\n"
"background-color:#030C54;\n"
"color:white"));
        ascButton = new QPushButton(groupBox_9);
        ascButton->setObjectName("ascButton");
        ascButton->setGeometry(QRect(10, 110, 81, 41));
        dscButton = new QPushButton(groupBox_9);
        dscButton->setObjectName("dscButton");
        dscButton->setGeometry(QRect(0, 160, 81, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1920, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Clients", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "ADD a Complaint", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Complaint_Date", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Actions Taken", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Complaint_ID", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Order_ID", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Employee_ID", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Supplier_ID", nullptr));
        sauvegarder->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "ADD", nullptr));
        backButton->setText(QCoreApplication::translate("MainWindow", "EXIT", nullptr));
        Upload->setText(QCoreApplication::translate("MainWindow", "Upload", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("MainWindow", "LIST OF COMPLAINTS", nullptr));
        label_39->setText(QCoreApplication::translate("MainWindow", "Search a Complaint by ID:", nullptr));
        statistique_6->setText(QCoreApplication::translate("MainWindow", "STATISTICS", nullptr));
        exportButton_6->setText(QCoreApplication::translate("MainWindow", "EXPORT PDF", nullptr));
        label_40->setText(QCoreApplication::translate("MainWindow", "Order By :", nullptr));
        combobox->setItemText(0, QCoreApplication::translate("MainWindow", "Selectionner", nullptr));

        QTableWidgetItem *___qtablewidgetitem = tableWidget_6->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "COMPLAINT_ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_6->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "DESCRIPTION_COMPLAINT", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_6->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "ACTIONS_COMPLAINT", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_6->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "COMPLAINT_DATE", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_6->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "ORDER_ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_6->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "EMPLOYEE_ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_6->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "SUPPLIER_ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_6->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "FILE_PATH", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        updateButton->setText(QCoreApplication::translate("MainWindow", "Modify", nullptr));
        refreshButton->setText(QCoreApplication::translate("MainWindow", "REFRESH", nullptr));
        ascButton->setText(QCoreApplication::translate("MainWindow", "ASC", nullptr));
        dscButton->setText(QCoreApplication::translate("MainWindow", "DSC", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
