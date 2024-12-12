/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QPushButton *updateButton;
    QPushButton *afficherSimpleButton;
    QLabel *label_10;
    QComboBox *combobox;
    QLabel *label_7;
    QDateEdit *l0;
    QLineEdit *seearchLine_6;
    QLabel *label_6;
    QPushButton *exportButton_6;
    QLabel *label_8;
    QLineEdit *filePathLineEdit;
    QPushButton *afficherUrgentButton;
    QLabel *label_4;
    QPushButton *deleteButton;
    QLabel *label_5;
    QLineEdit *l2;
    QLineEdit *l3;
    QPushButton *searchButton;
    QPushButton *dscButton;
    QLineEdit *l5;
    QLabel *label_9;
    QPushButton *ascButton;
    QPushButton *backButton;
    QCheckBox *normalCheckBox;
    QTableWidget *tableWidget_6;
    QPushButton *statistique_6;
    QLineEdit *l7;
    QLineEdit *l4;
    QPushButton *refreshButton;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *toggleDarkModeButton;
    QLabel *label;
    QCheckBox *urgentCheckBox;
    QLineEdit *l1;
    QPushButton *Upload;
    QPushButton *addButton;
    QPushButton *sauvegarder;
    QWidget *page_4;
    QLabel *label_11;
    QLabel *label_15;
    QGroupBox *groupBox_9;
    QLineEdit *serch;
    QPushButton *showStatistics;
    QPushButton *exportToPDF;
    QComboBox *trierLine_6;
    QPushButton *searchButton1;
    QPushButton *deleteButton1;
    QPushButton *updateButton1;
    QPushButton *sort;
    QTableWidget *historyTable;
    QLabel *label_19;
    QLabel *label_22;
    QLabel *label_23;
    QPushButton *exportHistoryButton;
    QTableView *tableWidget;
    QGroupBox *groupBox_2;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *l1_2;
    QLineEdit *quant;
    QLabel *label_14;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *type;
    QLineEdit *l4_2;
    QLineEdit *idEmploye;
    QLabel *label_18;
    QLineEdit *prenomEmploye;
    QLineEdit *l1_3;
    QLabel *label_26;
    QPushButton *sauvegarder1;
    QPushButton *refr;
    QLabel *label_20;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *centralLayout;
    QLabel *label_21;
    QGroupBox *groupBox;
    QPushButton *pushButton_48;
    QPushButton *pushButton_49;
    QPushButton *pushButton_50;
    QPushButton *pushButton_51;
    QPushButton *pushButton_52;
    QPushButton *pushButton_53;
    QPushButton *pushButton_54;
    QPushButton *pushButton_55;
    QPushButton *pushButton_56;
    QToolBar *mainToolBar;
    QToolBar *toolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1920, 1080);
        MainWindow->setStyleSheet(QString::fromUtf8("background:white; \n"
""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 10, 1920, 1080));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        updateButton = new QPushButton(page_3);
        updateButton->setObjectName("updateButton");
        updateButton->setGeometry(QRect(1390, 570, 101, 61));
        QFont font;
        font.setPointSize(10);
        updateButton->setFont(font);
        updateButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        updateButton->setStyleSheet(QString::fromUtf8("background: #79d9b0;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/background/resources/modify.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        updateButton->setIcon(icon);
        afficherSimpleButton = new QPushButton(page_3);
        afficherSimpleButton->setObjectName("afficherSimpleButton");
        afficherSimpleButton->setGeometry(QRect(760, 50, 151, 41));
        afficherSimpleButton->setFont(font);
        afficherSimpleButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        afficherSimpleButton->setStyleSheet(QString::fromUtf8("background: #79d9b0;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/r1.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        afficherSimpleButton->setIcon(icon1);
        afficherSimpleButton->setIconSize(QSize(30, 30));
        label_10 = new QLabel(page_3);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(260, 30, 251, 31));
        label_10->setStyleSheet(QString::fromUtf8("font: 600 20px \"Sitka Display Semibold\";\n"
""));
        combobox = new QComboBox(page_3);
        combobox->addItem(QString());
        combobox->setObjectName("combobox");
        combobox->setGeometry(QRect(1310, 470, 181, 31));
        combobox->setStyleSheet(QString::fromUtf8("background: #79d9b0;"));
        label_7 = new QLabel(page_3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(1100, 350, 161, 31));
        l0 = new QDateEdit(page_3);
        l0->setObjectName("l0");
        l0->setGeometry(QRect(1300, 10, 201, 41));
        seearchLine_6 = new QLineEdit(page_3);
        seearchLine_6->setObjectName("seearchLine_6");
        seearchLine_6->setGeometry(QRect(530, 20, 201, 41));
        seearchLine_6->setStyleSheet(QString::fromUtf8(""));
        label_6 = new QLabel(page_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(1100, 300, 161, 31));
        exportButton_6 = new QPushButton(page_3);
        exportButton_6->setObjectName("exportButton_6");
        exportButton_6->setGeometry(QRect(1240, 650, 141, 61));
        exportButton_6->setFont(font);
        exportButton_6->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        exportButton_6->setStyleSheet(QString::fromUtf8("background: #79d9b0;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/background/resources/pdf.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        exportButton_6->setIcon(icon2);
        exportButton_6->setIconSize(QSize(30, 40));
        label_8 = new QLabel(page_3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(1100, 410, 161, 31));
        filePathLineEdit = new QLineEdit(page_3);
        filePathLineEdit->setObjectName("filePathLineEdit");
        filePathLineEdit->setGeometry(QRect(1300, 410, 201, 41));
        afficherUrgentButton = new QPushButton(page_3);
        afficherUrgentButton->setObjectName("afficherUrgentButton");
        afficherUrgentButton->setGeometry(QRect(910, 50, 151, 41));
        afficherUrgentButton->setFont(font);
        afficherUrgentButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        afficherUrgentButton->setStyleSheet(QString::fromUtf8("background: #79d9b0;"));
        afficherUrgentButton->setIcon(icon1);
        afficherUrgentButton->setIconSize(QSize(30, 30));
        label_4 = new QLabel(page_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(1100, 190, 171, 31));
        deleteButton = new QPushButton(page_3);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(1080, 570, 151, 61));
        deleteButton->setFont(font);
        deleteButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        deleteButton->setStyleSheet(QString::fromUtf8("background: #79d9b0;"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/background/resources/delete.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        deleteButton->setIcon(icon3);
        label_5 = new QLabel(page_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(1100, 250, 161, 21));
        l2 = new QLineEdit(page_3);
        l2->setObjectName("l2");
        l2->setGeometry(QRect(1300, 130, 201, 41));
        l3 = new QLineEdit(page_3);
        l3->setObjectName("l3");
        l3->setGeometry(QRect(1300, 180, 201, 41));
        searchButton = new QPushButton(page_3);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(760, 10, 151, 41));
        searchButton->setFont(font);
        searchButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        searchButton->setStyleSheet(QString::fromUtf8("background: #79d9b0;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/background/resources/search.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        searchButton->setIcon(icon4);
        searchButton->setIconSize(QSize(30, 30));
        dscButton = new QPushButton(page_3);
        dscButton->setObjectName("dscButton");
        dscButton->setGeometry(QRect(1410, 510, 81, 31));
        dscButton->setStyleSheet(QString::fromUtf8("background: #79d9b0;"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/background/resources/descend.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        dscButton->setIcon(icon5);
        dscButton->setIconSize(QSize(30, 20));
        l5 = new QLineEdit(page_3);
        l5->setObjectName("l5");
        l5->setGeometry(QRect(1300, 290, 201, 41));
        label_9 = new QLabel(page_3);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(1100, 460, 161, 31));
        ascButton = new QPushButton(page_3);
        ascButton->setObjectName("ascButton");
        ascButton->setGeometry(QRect(1310, 510, 81, 31));
        ascButton->setStyleSheet(QString::fromUtf8("background: #79d9b0;"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/background/resources/ascend.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        ascButton->setIcon(icon6);
        ascButton->setIconSize(QSize(30, 20));
        backButton = new QPushButton(page_3);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(1390, 740, 101, 71));
        backButton->setStyleSheet(QString::fromUtf8("background: #79d9b0;"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/background/resources/exit.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        backButton->setIcon(icon7);
        backButton->setIconSize(QSize(30, 40));
        normalCheckBox = new QCheckBox(page_3);
        normalCheckBox->setObjectName("normalCheckBox");
        normalCheckBox->setGeometry(QRect(1400, 660, 91, 24));
        tableWidget_6 = new QTableWidget(page_3);
        if (tableWidget_6->columnCount() < 9)
            tableWidget_6->setColumnCount(9);
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
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        tableWidget_6->setObjectName("tableWidget_6");
        tableWidget_6->setGeometry(QRect(250, 100, 821, 951));
        tableWidget_6->setStyleSheet(QString::fromUtf8("background:#79d9b0; \n"
""));
        statistique_6 = new QPushButton(page_3);
        statistique_6->setObjectName("statistique_6");
        statistique_6->setGeometry(QRect(1080, 740, 151, 71));
        QFont font1;
        font1.setPointSize(9);
        statistique_6->setFont(font1);
        statistique_6->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        statistique_6->setStyleSheet(QString::fromUtf8("background: #79d9b0;"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/background/resources/stats.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        statistique_6->setIcon(icon8);
        statistique_6->setIconSize(QSize(30, 40));
        l7 = new QLineEdit(page_3);
        l7->setObjectName("l7");
        l7->setGeometry(QRect(1300, 350, 201, 41));
        l4 = new QLineEdit(page_3);
        l4->setObjectName("l4");
        l4->setGeometry(QRect(1300, 240, 201, 41));
        refreshButton = new QPushButton(page_3);
        refreshButton->setObjectName("refreshButton");
        refreshButton->setGeometry(QRect(910, 10, 151, 41));
        refreshButton->setFont(font);
        refreshButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        refreshButton->setStyleSheet(QString::fromUtf8("background: #79d9b0;"));
        refreshButton->setIcon(icon1);
        refreshButton->setIconSize(QSize(30, 30));
        label_3 = new QLabel(page_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(1100, 140, 171, 21));
        label_2 = new QLabel(page_3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(1100, 80, 161, 21));
        toggleDarkModeButton = new QPushButton(page_3);
        toggleDarkModeButton->setObjectName("toggleDarkModeButton");
        toggleDarkModeButton->setGeometry(QRect(1080, 510, 151, 51));
        toggleDarkModeButton->setFont(font);
        toggleDarkModeButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        toggleDarkModeButton->setStyleSheet(QString::fromUtf8("background: #79d9b0;"));
        toggleDarkModeButton->setIconSize(QSize(30, 30));
        label = new QLabel(page_3);
        label->setObjectName("label");
        label->setGeometry(QRect(1100, 10, 191, 51));
        urgentCheckBox = new QCheckBox(page_3);
        urgentCheckBox->setObjectName("urgentCheckBox");
        urgentCheckBox->setGeometry(QRect(1400, 680, 131, 41));
        l1 = new QLineEdit(page_3);
        l1->setObjectName("l1");
        l1->setGeometry(QRect(1300, 70, 201, 41));
        Upload = new QPushButton(page_3);
        Upload->setObjectName("Upload");
        Upload->setGeometry(QRect(1240, 740, 141, 71));
        Upload->setStyleSheet(QString::fromUtf8("background: #79d9b0;"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/background/resources/upload.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Upload->setIcon(icon9);
        Upload->setIconSize(QSize(30, 40));
        addButton = new QPushButton(page_3);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(1240, 570, 141, 61));
        addButton->setStyleSheet(QString::fromUtf8("background: #79d9b0;"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/background/resources/add.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        addButton->setIcon(icon10);
        sauvegarder = new QPushButton(page_3);
        sauvegarder->setObjectName("sauvegarder");
        sauvegarder->setGeometry(QRect(1080, 650, 151, 61));
        sauvegarder->setStyleSheet(QString::fromUtf8("background: #79d9b0;"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/background/resources/save.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        sauvegarder->setIcon(icon11);
        sauvegarder->setIconSize(QSize(30, 30));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        label_11 = new QLabel(page_4);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(-10, 0, 1221, 561));
        label_11->setScaledContents(true);
        label_15 = new QLabel(page_4);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(950, 0, 61, 31));
        label_15->setPixmap(QPixmap(QString::fromUtf8(":/Downloads/sustainability_8100096.png")));
        label_15->setScaledContents(true);
        groupBox_9 = new QGroupBox(page_4);
        groupBox_9->setObjectName("groupBox_9");
        groupBox_9->setGeometry(QRect(230, -20, 1241, 941));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Perpetua")});
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setUnderline(true);
        groupBox_9->setFont(font2);
        groupBox_9->setStyleSheet(QString::fromUtf8(""));
        serch = new QLineEdit(groupBox_9);
        serch->setObjectName("serch");
        serch->setGeometry(QRect(260, 20, 331, 41));
        showStatistics = new QPushButton(groupBox_9);
        showStatistics->setObjectName("showStatistics");
        showStatistics->setGeometry(QRect(770, 420, 141, 51));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Perpetua")});
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setItalic(true);
        font3.setUnderline(true);
        showStatistics->setFont(font3);
        showStatistics->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        showStatistics->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"border-radius:10px;\n"
"background-color:#79d9b0;\n"
"color:black"));
        showStatistics->setIcon(icon8);
        showStatistics->setIconSize(QSize(30, 30));
        exportToPDF = new QPushButton(groupBox_9);
        exportToPDF->setObjectName("exportToPDF");
        exportToPDF->setGeometry(QRect(920, 420, 141, 51));
        exportToPDF->setFont(font3);
        exportToPDF->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        exportToPDF->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"border-radius:10px;\n"
"background-color:#79d9b0;\n"
"color:black"));
        exportToPDF->setIcon(icon2);
        exportToPDF->setIconSize(QSize(30, 30));
        trierLine_6 = new QComboBox(groupBox_9);
        trierLine_6->addItem(QString());
        trierLine_6->addItem(QString());
        trierLine_6->setObjectName("trierLine_6");
        trierLine_6->setGeometry(QRect(130, 70, 131, 41));
        trierLine_6->setStyleSheet(QString::fromUtf8("background: #79d9b0;"));
        searchButton1 = new QPushButton(groupBox_9);
        searchButton1->setObjectName("searchButton1");
        searchButton1->setGeometry(QRect(610, 70, 141, 41));
        searchButton1->setFont(font3);
        searchButton1->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        searchButton1->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"border-radius:10px;\n"
"background-color:#79d9b0;\n"
"color:black"));
        searchButton1->setIcon(icon4);
        deleteButton1 = new QPushButton(groupBox_9);
        deleteButton1->setObjectName("deleteButton1");
        deleteButton1->setGeometry(QRect(920, 490, 141, 51));
        deleteButton1->setFont(font3);
        deleteButton1->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        deleteButton1->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"border-radius:10px;\n"
"background-color:#79d9b0;\n"
"color:black"));
        deleteButton1->setIcon(icon3);
        deleteButton1->setIconSize(QSize(30, 30));
        updateButton1 = new QPushButton(groupBox_9);
        updateButton1->setObjectName("updateButton1");
        updateButton1->setGeometry(QRect(1070, 490, 141, 51));
        updateButton1->setFont(font3);
        updateButton1->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        updateButton1->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"border-radius:10px;\n"
"background-color:#79d9b0;\n"
"color:black"));
        updateButton1->setIcon(icon);
        updateButton1->setIconSize(QSize(30, 30));
        sort = new QPushButton(groupBox_9);
        sort->setObjectName("sort");
        sort->setGeometry(QRect(610, 20, 141, 41));
        sort->setFont(font3);
        sort->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        sort->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"border-radius:10px;\n"
"background-color:#79d9b0;\n"
"color:black"));
        historyTable = new QTableWidget(groupBox_9);
        historyTable->setObjectName("historyTable");
        historyTable->setGeometry(QRect(830, 550, 301, 251));
        historyTable->setStyleSheet(QString::fromUtf8("background-color:#79d9b0"));
        label_19 = new QLabel(groupBox_9);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(400, 160, 41, 31));
        label_19->setPixmap(QPixmap(QString::fromUtf8(":/Downloads/search_10023603.png")));
        label_19->setScaledContents(true);
        label_22 = new QLabel(groupBox_9);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(930, 60, 41, 21));
        label_22->setPixmap(QPixmap(QString::fromUtf8(":/Downloads/swap_5296690.png")));
        label_22->setScaledContents(true);
        label_23 = new QLabel(groupBox_9);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(610, 149, 63, 41));
        label_23->setPixmap(QPixmap(QString::fromUtf8(":/Downloads/trash_9058267.png")));
        label_23->setScaledContents(true);
        exportHistoryButton = new QPushButton(groupBox_9);
        exportHistoryButton->setObjectName("exportHistoryButton");
        exportHistoryButton->setGeometry(QRect(1070, 420, 141, 51));
        exportHistoryButton->setFont(font3);
        exportHistoryButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        exportHistoryButton->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"border-radius:10px;\n"
"background-color:#79d9b0;\n"
"color:black"));
        exportHistoryButton->setIcon(icon11);
        exportHistoryButton->setIconSize(QSize(30, 30));
        tableWidget = new QTableView(groupBox_9);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 120, 741, 691));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color:#79d9b0"));
        groupBox_2 = new QGroupBox(groupBox_9);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(780, 20, 461, 331));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Perpetua")});
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setItalic(false);
        font4.setUnderline(true);
        groupBox_2->setFont(font4);
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(50, 120, 81, 16));
        label_12->setFont(font4);
        label_12->setStyleSheet(QString::fromUtf8("color:#79d9b0;"));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(30, 160, 101, 16));
        label_13->setFont(font4);
        label_13->setStyleSheet(QString::fromUtf8("color:#79d9b0"));
        l1_2 = new QLineEdit(groupBox_2);
        l1_2->setObjectName("l1_2");
        l1_2->setGeometry(QRect(190, 290, 181, 31));
        quant = new QLineEdit(groupBox_2);
        quant->setObjectName("quant");
        quant->setGeometry(QRect(190, 150, 181, 31));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(50, 300, 61, 16));
        label_14->setFont(font4);
        label_14->setStyleSheet(QString::fromUtf8("color:#79d9b0"));
        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(30, 200, 131, 16));
        label_16->setFont(font4);
        label_16->setStyleSheet(QString::fromUtf8("color:#79d9b0"));
        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(30, 250, 141, 21));
        label_17->setFont(font4);
        label_17->setStyleSheet(QString::fromUtf8("color:#79d9b0"));
        type = new QLineEdit(groupBox_2);
        type->setObjectName("type");
        type->setGeometry(QRect(190, 110, 181, 31));
        l4_2 = new QLineEdit(groupBox_2);
        l4_2->setObjectName("l4_2");
        l4_2->setGeometry(QRect(190, 200, 181, 31));
        idEmploye = new QLineEdit(groupBox_2);
        idEmploye->setObjectName("idEmploye");
        idEmploye->setGeometry(QRect(190, 240, 181, 31));
        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(40, 80, 91, 20));
        label_18->setFont(font4);
        label_18->setStyleSheet(QString::fromUtf8("color:#79d9b0;"));
        prenomEmploye = new QLineEdit(groupBox_2);
        prenomEmploye->setObjectName("prenomEmploye");
        prenomEmploye->setGeometry(QRect(190, 70, 181, 31));
        l1_3 = new QLineEdit(groupBox_2);
        l1_3->setObjectName("l1_3");
        l1_3->setGeometry(QRect(190, 30, 181, 31));
        label_26 = new QLabel(groupBox_2);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(40, 40, 111, 21));
        label_26->setFont(font4);
        label_26->setStyleSheet(QString::fromUtf8("color:#79d9b0"));
        sauvegarder1 = new QPushButton(groupBox_9);
        sauvegarder1->setObjectName("sauvegarder1");
        sauvegarder1->setGeometry(QRect(770, 490, 141, 51));
        sauvegarder1->setFont(font3);
        sauvegarder1->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        sauvegarder1->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"border-radius:10px;\n"
"background-color:#79d9b0;\n"
"color:black"));
        sauvegarder1->setIcon(icon10);
        sauvegarder1->setIconSize(QSize(30, 30));
        refr = new QPushButton(groupBox_9);
        refr->setObjectName("refr");
        refr->setGeometry(QRect(920, 360, 141, 51));
        refr->setStyleSheet(QString::fromUtf8("border:1px solid black;\n"
"border-radius:10px;\n"
"background-color:#79d9b0;\n"
"color:black;"));
        refr->setIcon(icon1);
        refr->setIconSize(QSize(40, 30));
        label_20 = new QLabel(groupBox_9);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(40, 20, 191, 31));
        label_20->setStyleSheet(QString::fromUtf8("font: 600 20px \"Sitka Display Semibold\";\n"
""));
        verticalLayoutWidget = new QWidget(groupBox_9);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(290, 70, 281, 41));
        centralLayout = new QVBoxLayout(verticalLayoutWidget);
        centralLayout->setSpacing(6);
        centralLayout->setContentsMargins(11, 11, 11, 11);
        centralLayout->setObjectName("centralLayout");
        centralLayout->setContentsMargins(0, 0, 0, 0);
        label_21 = new QLabel(groupBox_9);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(30, 70, 91, 31));
        label_21->setStyleSheet(QString::fromUtf8("font: 600 20px \"Sitka Display Semibold\";\n"
""));
        stackedWidget->addWidget(page_4);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 0, 231, 1141));
        groupBox->setStyleSheet(QString::fromUtf8("background:#79d9b0; \n"
"width:150px;"));
        pushButton_48 = new QPushButton(groupBox);
        pushButton_48->setObjectName("pushButton_48");
        pushButton_48->setGeometry(QRect(10, 270, 211, 71));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Sitka Display Semibold")});
        font5.setWeight(QFont::DemiBold);
        font5.setItalic(false);
        pushButton_48->setFont(font5);
        pushButton_48->setStyleSheet(QString::fromUtf8("          background-color:white;\n"
"font: 600 25px \"Sitka Display Semibold\";\n"
" QPushButton {\n"
"        background-color:blue; // Green background\n"
"        color: white;             // White text\n"
"        border: none;            // No border\n"
"        border-radius: 10px;      // Rounded corners\n"
"        padding: 10px 20px;       // Padding inside the button\n"
"        font-size: 16px;          // Font size\n"
"        font-weight: bold;        // Bold text\n"
"font: 600 25px \"Sitka Display Semibold\";\n"
"    }\n"
"    QPushButton:hover {\n"
"       background-color: green;// Darker green on hover\n"
"    }\n"
"    QPushButton:pressed {\n"
"       background-color: #3e8e41; // Even darker green when pressed\n"
"    }\n"
" "));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/resources/stock.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_48->setIcon(icon12);
        pushButton_48->setIconSize(QSize(65, 100));
        pushButton_49 = new QPushButton(groupBox);
        pushButton_49->setObjectName("pushButton_49");
        pushButton_49->setGeometry(QRect(10, 350, 211, 71));
        pushButton_49->setFont(font5);
        pushButton_49->setStyleSheet(QString::fromUtf8("          background-color:white;\n"
"font: 600 25px \"Sitka Display Semibold\";\n"
" QPushButton {\n"
"        background-color:blue; // Green background\n"
"        color: white;             // White text\n"
"        border: none;            // No border\n"
"        border-radius: 10px;      // Rounded corners\n"
"        padding: 10px 20px;       // Padding inside the button\n"
"        font-size: 16px;          // Font size\n"
"        font-weight: bold;        // Bold text\n"
"font: 600 25px \"Sitka Display Semibold\";\n"
"    }\n"
"    QPushButton:hover {\n"
"       background-color: #45a049;// Darker green on hover\n"
"    }\n"
"    QPushButton:pressed {\n"
"       background-color: #3e8e41; // Even darker green when pressed\n"
"    }\n"
" "));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/background/resources/supplier.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_49->setIcon(icon13);
        pushButton_49->setIconSize(QSize(65, 90));
        pushButton_50 = new QPushButton(groupBox);
        pushButton_50->setObjectName("pushButton_50");
        pushButton_50->setGeometry(QRect(10, 760, 211, 61));
        pushButton_50->setFont(font5);
        pushButton_50->setStyleSheet(QString::fromUtf8("          background-color:white;\n"
"font: 600 25px \"Sitka Display Semibold\";\n"
" QPushButton {\n"
"        background-color:blue; // Green background\n"
"        color: white;             // White text\n"
"        border: none;            // No border\n"
"        border-radius: 10px;      // Rounded corners\n"
"        padding: 10px 20px;       // Padding inside the button\n"
"        font-size: 16px;          // Font size\n"
"        font-weight: bold;        // Bold text\n"
"font: 600 25px \"Sitka Display Semibold\";\n"
"    }\n"
"    QPushButton:hover {\n"
"       background-color: #45a049;// Darker green on hover\n"
"    }\n"
"    QPushButton:pressed {\n"
"       background-color: #3e8e41; // Even darker green when pressed\n"
"    }\n"
" "));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/background/resources/signout.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_50->setIcon(icon14);
        pushButton_50->setIconSize(QSize(65, 50));
        pushButton_51 = new QPushButton(groupBox);
        pushButton_51->setObjectName("pushButton_51");
        pushButton_51->setGeometry(QRect(10, 430, 211, 71));
        pushButton_51->setFont(font5);
        pushButton_51->setStyleSheet(QString::fromUtf8("          background-color:white;\n"
"font: 600 25px \"Sitka Display Semibold\";\n"
" QPushButton {\n"
"        background-color:blue; // Green background\n"
"        color: white;             // White text\n"
"        border: none;            // No border\n"
"        border-radius: 10px;      // Rounded corners\n"
"        padding: 10px 20px;       // Padding inside the button\n"
"        font-size: 16px;          // Font size\n"
"        font-weight: bold;        // Bold text\n"
"font: 600 25px \"Sitka Display Semibold\";\n"
"    }\n"
"    QPushButton:hover {\n"
"       background-color: #45a049;// Darker green on hover\n"
"    }\n"
"    QPushButton:pressed {\n"
"       background-color: #3e8e41; // Even darker green when pressed\n"
"    }\n"
" "));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/background/resources/profil.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_51->setIcon(icon15);
        pushButton_51->setIconSize(QSize(65, 90));
        pushButton_52 = new QPushButton(groupBox);
        pushButton_52->setObjectName("pushButton_52");
        pushButton_52->setGeometry(QRect(10, 590, 211, 71));
        pushButton_52->setFont(font5);
        pushButton_52->setStyleSheet(QString::fromUtf8("          background-color:white;\n"
"font: 600 25px \"Sitka Display Semibold\";\n"
" QPushButton {\n"
"        background-color:blue; // Green background\n"
"        color: white;             // White text\n"
"        border: none;            // No border\n"
"        border-radius: 10px;      // Rounded corners\n"
"        padding: 10px 20px;       // Padding inside the button\n"
"        font-size: 16px;          // Font size\n"
"        font-weight: bold;        // Bold text\n"
"font: 600 25px \"Sitka Display Semibold\";\n"
"    }\n"
"    QPushButton:hover {\n"
"       background-color: #45a049;// Darker green on hover\n"
"    }\n"
"    QPushButton:pressed {\n"
"       background-color: #3e8e41; // Even darker green when pressed\n"
"    }\n"
" "));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/background/resources/complaint.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_52->setIcon(icon16);
        pushButton_52->setIconSize(QSize(65, 90));
        pushButton_53 = new QPushButton(groupBox);
        pushButton_53->setObjectName("pushButton_53");
        pushButton_53->setGeometry(QRect(10, 510, 211, 71));
        pushButton_53->setFont(font5);
        pushButton_53->setStyleSheet(QString::fromUtf8("          background-color:white;\n"
"font: 600 25px \"Sitka Display Semibold\";\n"
" QPushButton {\n"
"        background-color:blue; // Green background\n"
"        color: white;             // White text\n"
"        border: none;            // No border\n"
"        border-radius: 10px;      // Rounded corners\n"
"        padding: 10px 20px;       // Padding inside the button\n"
"        font-size: 16px;          // Font size\n"
"        font-weight: bold;        // Bold text\n"
"font: 600 25px \"Sitka Display Semibold\";\n"
"    }\n"
"    QPushButton:hover {\n"
"       background-color: #45a049;// Darker green on hover\n"
"    }\n"
"    QPushButton:pressed {\n"
"       background-color: #3e8e41; // Even darker green when pressed\n"
"    }\n"
" "));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/background/resources/employee.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_53->setIcon(icon17);
        pushButton_53->setIconSize(QSize(65, 90));
        pushButton_54 = new QPushButton(groupBox);
        pushButton_54->setObjectName("pushButton_54");
        pushButton_54->setGeometry(QRect(10, 670, 211, 71));
        pushButton_54->setFont(font5);
        pushButton_54->setStyleSheet(QString::fromUtf8("          background-color:white;\n"
"font: 600 25px \"Sitka Display Semibold\";\n"
" QPushButton {\n"
"        background-color:blue; // Green background\n"
"        color: white;             // White text\n"
"        border: none;            // No border\n"
"        border-radius: 10px;      // Rounded corners\n"
"        padding: 10px 20px;       // Padding inside the button\n"
"        font-size: 16px;          // Font size\n"
"        font-weight: bold;        // Bold text\n"
"font: 600 25px \"Sitka Display Semibold\";\n"
"    }\n"
"    QPushButton:hover {\n"
"       background-color: #45a049;// Darker green on hover\n"
"    }\n"
"    QPushButton:pressed {\n"
"       background-color: #3e8e41; // Even darker green when pressed\n"
"    }\n"
" "));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/background/resources/purchases.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_54->setIcon(icon18);
        pushButton_54->setIconSize(QSize(65, 70));
        pushButton_55 = new QPushButton(groupBox);
        pushButton_55->setObjectName("pushButton_55");
        pushButton_55->setGeometry(QRect(10, 190, 211, 71));
        pushButton_55->setFont(font5);
        pushButton_55->setStyleSheet(QString::fromUtf8("          background-color:white;\n"
"font: 600 25px \"Sitka Display Semibold\";\n"
" QPushButton {\n"
"        background-color:blue; // Green background\n"
"        color: white;             // White text\n"
"        border: none;            // No border\n"
"        border-radius: 10px;      // Rounded corners\n"
"        padding: 10px 20px;       // Padding inside the button\n"
"        font-size: 16px;          // Font size\n"
"        font-weight: bold;        // Bold text\n"
"font: 600 25px \"Sitka Display Semibold\";\n"
"    }\n"
"    QPushButton:hover {\n"
"       background-color: green;// Darker green on hover\n"
"    }\n"
"    QPushButton:pressed {\n"
"       background-color: #3e8e41; // Even darker green when pressed\n"
"    }\n"
" "));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/background/resources/dashboard.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_55->setIcon(icon19);
        pushButton_55->setIconSize(QSize(65, 100));
        pushButton_56 = new QPushButton(groupBox);
        pushButton_56->setObjectName("pushButton_56");
        pushButton_56->setGeometry(QRect(30, 0, 181, 181));
        pushButton_56->setFont(font5);
        pushButton_56->setStyleSheet(QString::fromUtf8("          background-color:white;\n"
"font: 600 25px \"Sitka Display Semibold\";\n"
" QPushButton {\n"
"        background-color:blue; // Green background\n"
"        color: white;             // White text\n"
"        border: none;            // No border\n"
"        border-radius: 10px;      // Rounded corners\n"
"        padding: 10px 20px;       // Padding inside the button\n"
"        font-size: 16px;          // Font size\n"
"        font-weight: bold;        // Bold text\n"
"font: 600 25px \"Sitka Display Semibold\";\n"
"    }\n"
"    QPushButton:hover {\n"
"       background-color: green;// Darker green on hover\n"
"    }\n"
"    QPushButton:pressed {\n"
"       background-color: #3e8e41; // Even darker green when pressed\n"
"    }\n"
" "));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/background/resources/logo.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_56->setIcon(icon20);
        pushButton_56->setIconSize(QSize(250, 280));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Clients", nullptr));
        updateButton->setText(QCoreApplication::translate("MainWindow", "Modify", nullptr));
        afficherSimpleButton->setText(QCoreApplication::translate("MainWindow", "Show Simple", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Search a Complaint By ID :", nullptr));
        combobox->setItemText(0, QCoreApplication::translate("MainWindow", "Select", nullptr));

        label_7->setText(QCoreApplication::translate("MainWindow", "Supplier_ID", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Employee_ID", nullptr));
        exportButton_6->setText(QCoreApplication::translate("MainWindow", "Export PDF", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "File Path", nullptr));
        afficherUrgentButton->setText(QCoreApplication::translate("MainWindow", "Show Urgent", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Complaint_ID", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Order_ID", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        dscButton->setText(QCoreApplication::translate("MainWindow", "DSC", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Order By :", nullptr));
        ascButton->setText(QCoreApplication::translate("MainWindow", "ASC", nullptr));
        backButton->setText(QCoreApplication::translate("MainWindow", "EXIT", nullptr));
        normalCheckBox->setText(QCoreApplication::translate("MainWindow", "Normal", nullptr));
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
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_6->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "COMPLAINT_TYPE", nullptr));
        statistique_6->setText(QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        refreshButton->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Actions Taken", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        toggleDarkModeButton->setText(QCoreApplication::translate("MainWindow", "DarkMode", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Complaint_Date", nullptr));
        urgentCheckBox->setText(QCoreApplication::translate("MainWindow", "Urgent", nullptr));
        Upload->setText(QCoreApplication::translate("MainWindow", "Upload", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "ADD", nullptr));
        sauvegarder->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        label_11->setText(QString());
        label_15->setText(QString());
        groupBox_9->setTitle(QCoreApplication::translate("MainWindow", "LIST OF STOCKS:", nullptr));
        showStatistics->setText(QCoreApplication::translate("MainWindow", "STATISTICS", nullptr));
        exportToPDF->setText(QCoreApplication::translate("MainWindow", "EXPORT PDF", nullptr));
        trierLine_6->setItemText(0, QCoreApplication::translate("MainWindow", "Selectionner", nullptr));
        trierLine_6->setItemText(1, QCoreApplication::translate("MainWindow", "COMPLAINT_DATE", nullptr));

        searchButton1->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        deleteButton1->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        updateButton1->setText(QCoreApplication::translate("MainWindow", "Modify", nullptr));
        sort->setText(QCoreApplication::translate("MainWindow", "Sort", nullptr));
        label_19->setText(QString());
        label_22->setText(QString());
        label_23->setText(QString());
        exportHistoryButton->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Add a Stock", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "TYPE:", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "QUANTITY:", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "NAME:", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "CONDITIONS:", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "EMPLOYEE_ID", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "PRENOM:", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "STOCK_ID", nullptr));
        sauvegarder1->setText(QCoreApplication::translate("MainWindow", "ADD", nullptr));
        refr->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Search a Stock By ID :", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Order By :", nullptr));
        groupBox->setTitle(QString());
        pushButton_48->setText(QCoreApplication::translate("MainWindow", "Stock", nullptr));
        pushButton_49->setText(QCoreApplication::translate("MainWindow", "Providers", nullptr));
        pushButton_50->setText(QCoreApplication::translate("MainWindow", "Sign Out", nullptr));
        pushButton_51->setText(QCoreApplication::translate("MainWindow", "Profile", nullptr));
        pushButton_52->setText(QCoreApplication::translate("MainWindow", "Complaints", nullptr));
        pushButton_53->setText(QCoreApplication::translate("MainWindow", "Employers", nullptr));
        pushButton_54->setText(QCoreApplication::translate("MainWindow", "Purchases", nullptr));
        pushButton_55->setText(QCoreApplication::translate("MainWindow", "DashBoard", nullptr));
        pushButton_56->setText(QString());
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
