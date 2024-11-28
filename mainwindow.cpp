#include "mainwindow.h"
#include "qsqlerror.h"
#include "ui_mainwindow.h"
#include "complaints.h"
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QDateTime>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QKeyEvent>
#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSlice>
#include <QVideoWidget>
#include <QProcess>
#include <QDesktopServices>
#include <QUrl>
#include <QAxObject>
#include <QMessageBox>
#include <QPrinter>
#include <QPageSize>
#include <QMargins>
#include <QScreen>
#include <QMainWindow>
#include <QPixmap>
#include <QLabel>
#include <QTextTable>
#include <QString>
#include <QTableWidget>
#include <QEasingCurve>
#include <QTimer>
#include <QAudioOutput>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSlice>
#include <QColor>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QEnterEvent> // For enterEvent



void MainWindow::setupBackgroundMusic() {
    // Create a media player and audio output for background music
    QMediaPlayer *player = new QMediaPlayer(this);
    QAudioOutput *audioOutput = new QAudioOutput(this);

    // Set the audio output to the player
    player->setAudioOutput(audioOutput);
    audioOutput->setVolume(0.5); // Set volume level

    // Set the music file
    player->setSource(QUrl::fromLocalFile("C:\\Users\\youss\\OneDrive\\Bureau\\Interfaces Ateliers\\Nouveau dossier\\Atelier_Connexion\\music.mp3"));

    // Connect the `mediaStatusChanged` signal to restart music when it ends
    connect(player, &QMediaPlayer::mediaStatusChanged, this, [player](QMediaPlayer::MediaStatus status) {
        if (status == QMediaPlayer::EndOfMedia) {
            player->play(); // Restart music
        }
    });

    // Start playing the music
    player->play();
}

void MainWindow::playButtonClickSound() {
    // Create a media player and audio output
    QMediaPlayer *player = new QMediaPlayer(this);
    QAudioOutput *audioOutput = new QAudioOutput(this);

    player->setAudioOutput(audioOutput);
    audioOutput->setVolume(1.0); // Volume is a float between 0.0 and 1.0

    // Set the audio file
    player->setSource(QUrl::fromLocalFile("C:\\Users\\youss\\OneDrive\\Bureau\\Interfaces Ateliers\\Nouveau dossier\\Atelier_Connexion\\click.wav"));

    // Start playing
    player->play();
    connect(player, &QMediaPlayer::errorOccurred, this, [](QMediaPlayer::Error error) {
        qDebug() << "MediaPlayer Error:" << error;
    });

    // Clean up after playback
    connect(player, &QMediaPlayer::playbackStateChanged, player, [player](QMediaPlayer::PlaybackState state) {
        if (state == QMediaPlayer::StoppedState) {
            player->deleteLater();
        }
    });
}
void MainWindow::playTypingSound() {
    // Create a media player and audio output
    QMediaPlayer *player = new QMediaPlayer(this);
    QAudioOutput *audioOutput = new QAudioOutput(this);

    player->setAudioOutput(audioOutput);
    audioOutput->setVolume(0.5);  // Adjust volume as needed

    // Set the audio file (typing sound effect)
    player->setSource(QUrl::fromLocalFile("C:\\Users\\youss\\OneDrive\\Bureau\\Interfaces Ateliers\\Nouveau dossier\\Atelier_Connexion\\click.wav"));

    // Start playing the sound
    player->play();

    // Clean up after playback
    connect(player, &QMediaPlayer::playbackStateChanged, player, [player](QMediaPlayer::PlaybackState state) {
        if (state == QMediaPlayer::StoppedState) {
            player->deleteLater();
        }
    });
}
void MainWindow::setupButtonClickSounds() {
    QList<QPushButton*> buttons = findChildren<QPushButton*>(); // Find all QPushButtons

    for (QPushButton *button : buttons) {
        connect(button, &QPushButton::clicked, this, &MainWindow::playButtonClickSound);
    }
}
void MainWindow::onFullScreen() {
    // Get the primary screen size
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();

    // Set the window to full-screen
    this->setGeometry(screenGeometry);
    this->showFullScreen();
}
bool MainWindow::eventFilter(QObject *watched, QEvent *event) {
    if (QPushButton *button = qobject_cast<QPushButton*>(watched)) {
        if (event->type() == QEvent::Enter) {
            // When the mouse enters the button, grow it
            animateButton(button, true);
            return true; // Event handled
        } else if (event->type() == QEvent::Leave) {
            // When the mouse leaves the button, shrink it
            animateButton(button, false);
            return true; // Event handled
        }
    }
    return QMainWindow::eventFilter(watched, event); // Default event processing
}

void MainWindow::animateButton(QPushButton *button, bool grow) {
    // Store the button's original size in a static variable or a property map
    static QMap<QPushButton*, QRect> originalGeometries;

    if (!originalGeometries.contains(button)) {
        originalGeometries[button] = button->geometry();  // Save the original geometry
    }

    QRect startGeometry = button->geometry();
    QRect endGeometry;

    if (grow) {
        // Enlarge the button slightly, but only if it hasn't already grown
        endGeometry = originalGeometries[button].adjusted(-10, -10, 10, 10);  // Maximum grown size
    } else {
        // Shrink back to the original size
        endGeometry = originalGeometries[button];  // Restore the original geometry
    }

    // Create an animation to grow or shrink the button
    QPropertyAnimation *animation = new QPropertyAnimation(button, "geometry");
    animation->setDuration(200);  // Duration for the grow/shrink effect
    animation->setStartValue(startGeometry);
    animation->setEndValue(endGeometry);
    animation->setEasingCurve(QEasingCurve::InOutQuad);  // Smooth easing
    animation->start();
}
void MainWindow::animateLabel(QLabel* label, const QString& animationType) {
    if (animationType == "fade") {
        // Apply a fade-in or fade-out effect

        QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(label);
        label->setGraphicsEffect(opacityEffect);

        QPropertyAnimation* fadeAnimation = new QPropertyAnimation(opacityEffect, "opacity");
        fadeAnimation->setDuration(1000); // Duration in milliseconds
        fadeAnimation->setStartValue(0.0); // Start fully transparent
        fadeAnimation->setEndValue(1.0); // End fully visible
        fadeAnimation->setEasingCurve(QEasingCurve::InOutQuad);
        fadeAnimation->start(QAbstractAnimation::DeleteWhenStopped);

    } else if (animationType == "slide") {
        // Slide the label from off-screen
        QRect startGeometry = label->geometry();
        QRect endGeometry = startGeometry;
        startGeometry.moveLeft(-label->width()); // Start from the left (off-screen)

        QPropertyAnimation* slideAnimation = new QPropertyAnimation(label, "geometry");
        slideAnimation->setDuration(2000); // Duration in milliseconds
        slideAnimation->setStartValue(startGeometry); // Start position
        slideAnimation->setEndValue(endGeometry); // End position
        slideAnimation->setEasingCurve(QEasingCurve::OutBounce); // Smooth easing curve
        slideAnimation->start(QAbstractAnimation::DeleteWhenStopped);
    }
}

void MainWindow::showEvent(QShowEvent *event) {
    QMainWindow::showEvent(event);
    setupButtonClickSounds();

    // Fade-in animation for the main window
    QPropertyAnimation *windowAnimation = new QPropertyAnimation(this, "windowOpacity");
    windowAnimation->setDuration(1000); // Duration in milliseconds
    windowAnimation->setStartValue(0.0); // Fully transparent
    windowAnimation->setEndValue(1.0); // Fully visible
    windowAnimation->setEasingCurve(QEasingCurve::InOutQuad); // Smooth easing
    windowAnimation->start(QAbstractAnimation::DeleteWhenStopped); // Auto-delete after completion

    // Pop-up and zoom animations for QPushButtons
    QList<QPushButton*> buttons = findChildren<QPushButton*>(); // Find all QPushButtons
    int delay = 0; // Initial delay for staggering animations

    for (QPushButton *button : buttons) {
        // Create a QTimer to handle the delay for each button
        QTimer::singleShot(delay, [button]() {
            // Pop-up animation for the button
            QRect startGeometry = button->geometry();
            QRect endGeometry = startGeometry;

            startGeometry.setSize(QSize(0, 0)); // Start with zero size
            startGeometry.moveCenter(endGeometry.center()); // Keep it centered

            QPropertyAnimation *popAnimation = new QPropertyAnimation(button, "geometry");
            popAnimation->setDuration(200); // Duration of the animation
            popAnimation->setStartValue(startGeometry); // Start value
            popAnimation->setEndValue(endGeometry); // End value
            popAnimation->setEasingCurve(QEasingCurve::OutBounce); // Easing curve for "pop"
            popAnimation->start(QAbstractAnimation::DeleteWhenStopped); // Auto-delete after completion

            // Zoom-in and zoom-out animation
            QPropertyAnimation *zoomAnimation = new QPropertyAnimation(button, "geometry");
            zoomAnimation->setDuration(600); // Duration of zoom effect
            zoomAnimation->setStartValue(endGeometry); // Normal size
            QRect zoomedGeometry = endGeometry.adjusted(-10, -10, 20, 20); // Slightly zoomed size
            zoomAnimation->setKeyValueAt(0.5, zoomedGeometry); // At midpoint, zoomed size
            zoomAnimation->setEndValue(endGeometry); // Back to normal size
            zoomAnimation->setEasingCurve(QEasingCurve::InOutQuad); // Smooth easing
            zoomAnimation->start(QAbstractAnimation::DeleteWhenStopped); // Auto-delete after completion
        });

        delay += 100; // Increment delay for the next button
    }

    // Pop-up animation for the QTableWidget
    QTableWidget *tableWidget = findChild<QTableWidget*>(); // Find the QTableWidget

    if (tableWidget) {
        // Get the current geometry of the table widget
        QRect startGeometry = tableWidget->geometry();
        QRect endGeometry = startGeometry;

        // Start with zero size for the pop-up effect
        startGeometry.setSize(QSize(0, 0)); // Start with zero size
        startGeometry.moveCenter(endGeometry.center()); // Keep it centered

        // Create the pop-up animation for the table widget
        QPropertyAnimation *popAnimation = new QPropertyAnimation(tableWidget, "geometry");
        popAnimation->setDuration(700); // Duration of the pop-up animation
        popAnimation->setStartValue(startGeometry); // Start value (zero size)
        popAnimation->setEndValue(endGeometry); // End value (original size)
        popAnimation->setEasingCurve(QEasingCurve::OutBounce); // Easing curve for the "pop"
        popAnimation->start(QAbstractAnimation::DeleteWhenStopped); // Auto-delete after completion
    }

    // Pop-up animation for QLineEdits
    QList<QLineEdit*> lineEdits = findChildren<QLineEdit*>(); // Find all QLineEdits
    delay = 0; // Reset delay for line edits

    for (QLineEdit *lineEdit : lineEdits) {
        // Create a QTimer to handle the delay for each QLineEdit
        QTimer::singleShot(delay, [lineEdit]() {
            // Pop-up animation for QLineEdit
            QRect startGeometry = lineEdit->geometry();
            QRect endGeometry = startGeometry;

            startGeometry.setSize(QSize(0, 0)); // Start with zero size
            startGeometry.moveCenter(endGeometry.center()); // Keep it centered

            // Create the pop-up animation for QLineEdit
            QPropertyAnimation *popAnimation = new QPropertyAnimation(lineEdit, "geometry");
            popAnimation->setDuration(600); // Duration of the pop-up animation
            popAnimation->setStartValue(startGeometry); // Start value (zero size)
            popAnimation->setEndValue(endGeometry); // End value (original size)
            popAnimation->setEasingCurve(QEasingCurve::OutBounce); // Easing curve for the "pop"
            popAnimation->start(QAbstractAnimation::DeleteWhenStopped); // Auto-delete after completion
        });

        delay += 200; // Increment delay for the next QLineEdit
    }}void MainWindow::on_backButton_clicked() {
    connect(ui->backButton, &QPushButton::clicked, this, &MainWindow::on_backButton_clicked);

    this->close();
}
void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Escape) {
        on_backButton_clicked();
    }
    // Call the base class implementation
    QMainWindow::keyPressEvent(event);
}

void MainWindow::on_statistique_6_clicked() {
    // Create a pie series for complaints statistics
    QPieSeries *series = new QPieSeries();

    // Query the database to get the complaints data
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) AS count, COMPLAINT_DATE FROM complaints GROUP BY COMPLAINT_DATE"); // Modify this query if needed
    if (!query.exec()) {
        qDebug() << "Database query failed:" << query.lastError();
        return;
    }

    // Colors for pie slices
    QColor colors[] = {Qt::red, Qt::green, Qt::blue, Qt::yellow, Qt::cyan, Qt::magenta, Qt::darkGray};

    int colorIndex = 0;

    // Iterate over the query results and add them to the pie series
    while (query.next()) {
        int count = query.value("count").toInt();  // Get the count from the query result
        QString date = query.value("COMPLAINT_DATE").toString();  // Get the complaint date (used for slice label)

        // Add a slice to the pie chart (label and value)
        QPieSlice *slice = series->append(date + ": " + QString::number(count) + " complaints", count);

        // Customize slice appearance
        slice->setLabelVisible(true);  // Display the label on the slice
        slice->setBrush(colors[colorIndex % 7]);  // Assign colors to slices
        slice->setPen(QPen(Qt::black));  // Set a border around slices

        // Increase colorIndex to pick the next color
        colorIndex++;
    }

    // Create a chart to display the pie series
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Complaints Statistics by Date");

    // Customize the chart appearance
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);  // Move legend to the bottom
    chart->setBackgroundBrush(QBrush(Qt::lightGray));  // Set a light gray background for the chart

    // Enable chart animation
    chart->setAnimationOptions(QChart::AllAnimations);  // Enable all animations (for the entire chart)
    chart->setAnimationDuration(1000);  // Set animation duration to 1 second (1000 ms)

    // Create chart view and set it to a fixed size
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);  // Enable anti-aliasing for smoother rendering
    chartView->setFixedSize(500, 500);  // Set the fixed size for the pie chart

    // Show the chart in a pop-up window or as part of the layout
    QDialog *chartDialog = new QDialog(this);  // Create a dialog to display the chart
    QVBoxLayout *layout = new QVBoxLayout(chartDialog);  // Add layout to dialog
    layout->addWidget(chartView);  // Add the chart view to the layout
    chartDialog->setFixedSize(550, 550);  // Set the dialog size to fit the chart
    chartDialog->exec();  // Show the dialog
}

void extractThumbnail(const QString &videoPath, const QString &imagePath) {
    QProcess process;
    QStringList arguments;
    arguments << "-i" << videoPath << "-vf" << "thumbnail,scale=320:240" << "-frames:v" << "1" << imagePath;
    process.start("ffmpeg", arguments);
    process.waitForFinished();
}

void MainWindow::on_exportButton_6_clicked() {
    // 1. Choose a location and file name for the PDF
    QString listofcomplaints = QFileDialog::getSaveFileName(this, "Save PDF", "", "*.pdf");
    if (listofcomplaints.isEmpty()) {
        return; // User canceled the dialog
    }

    // Add ".pdf" if the user did not specify it
    if (!listofcomplaints.endsWith(".pdf", Qt::CaseInsensitive)) {
        listofcomplaints += ".pdf";
    }

    // 2. Create a QPdfWriter instance
    QPdfWriter pdfWriter(listofcomplaints);
    pdfWriter.setPageSize(QPageSize(QPageSize::A3));
    pdfWriter.setPageMargins(QMargins(30, 30, 30, 30));

    QTextDocument textDoc;
    QTextCursor cursor(&textDoc);

    // 3. Add Title: Center-aligned
    QTextBlockFormat titleFormat;
    titleFormat.setAlignment(Qt::AlignCenter);
    QTextCharFormat titleCharFormat;
    titleCharFormat.setFontPointSize(24); // Set font size for title
    titleCharFormat.setFontWeight(QFont::Bold);
    cursor.insertBlock(titleFormat, titleCharFormat);
    cursor.insertText("Complaints Report\n\n");

    // 4. Add Date: Left-aligned
    QTextBlockFormat dateFormat;
    dateFormat.setAlignment(Qt::AlignLeft);
    QTextCharFormat dateCharFormat;
    dateCharFormat.setFontPointSize(18);
    cursor.insertBlock(dateFormat, dateCharFormat);
    cursor.insertText("Generated on: " + QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") + "\n\n");

    // 5. Retrieve Complaints Data
    QSqlQuery query;
    query.prepare("SELECT COMPLAINT_ID, FILE_PATH FROM complaints");

    if (!query.exec()) {
        QMessageBox::warning(this, "Error", "Failed to retrieve complaints from the database.");
        return;
    }

    // 6. Add a list of complaints (optional)
    while (query.next()) {
        int complaintID = query.value(0).toInt();
        QString filePath = query.value(1).toString();

        cursor.insertHtml(QString("<b>Complaint ID: %1</b><br>").arg(complaintID));
        if (!filePath.isEmpty()) {
            cursor.insertHtml(QString("<a href=\"%1\">Click here to view the video</a><br><br>")
                                  .arg(QUrl::fromLocalFile(filePath).toString()));
        } else {
            cursor.insertHtml("<i>No video available for this complaint.</i><br><br>");
        }
    }

    // 7. Add Table: Bigger with uniform spacing
    QAbstractItemModel* model = ui->tableWidget_6->model();
    int rows = model->rowCount();
    int columns = model->columnCount();

    // Define table format
    QTextTableFormat tableFormat;
    tableFormat.setBorder(1); // Table border
    tableFormat.setCellPadding(6); // Increase cell padding
    tableFormat.setCellSpacing(4); // Space between cells
    tableFormat.setAlignment(Qt::AlignCenter);

    // Distribute column widths evenly
    QVector<QTextLength> columnWidths;
    for (int col = 0; col < columns; ++col) {
        columnWidths.append(QTextLength(QTextLength::PercentageLength, 100.0 / columns));
    }
    tableFormat.setColumnWidthConstraints(columnWidths);

    // Create the table
    QTextTable* table = cursor.insertTable(rows + 1, columns, tableFormat);

    // Add headers
    for (int col = 0; col < columns; ++col) {
        QTextTableCell cell = table->cellAt(0, col);
        QTextCursor cellCursor = cell.firstCursorPosition();
        QTextCharFormat headerFormat;
        headerFormat.setFontWeight(QFont::Bold);
        cellCursor.insertText(model->headerData(col, Qt::Horizontal).toString(), headerFormat);
    }

    // Add data
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < columns; ++col) {
            QTextTableCell cell = table->cellAt(row + 1, col);
            QTextCursor cellCursor = cell.firstCursorPosition();
            cellCursor.insertText(model->data(model->index(row, col)).toString());
        }
    }

    // 8. Export to PDF
    textDoc.print(&pdfWriter);

    QMessageBox::information(this, "Export Successful", "PDF file has been successfully created.");
}
void MainWindow::on_afficherSimpleButton_clicked() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM COMPLAINTS WHERE COMPLAINT_TYPE = 1");

    ui->tableWidget_6->clearContents();
    ui->tableWidget_6->setRowCount(model->rowCount());
    ui->tableWidget_6->setColumnCount(model->columnCount());

    for (int row = 0; row < model->rowCount(); ++row) {
        for (int column = 0; column < model->columnCount(); ++column) {
            ui->tableWidget_6->setItem(row, column, new QTableWidgetItem(model->data(model->index(row, column)).toString()));
        }
    }
    delete model;
}
void MainWindow::on_afficherUrgentButton_clicked() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM COMPLAINTS WHERE COMPLAINT_TYPE = 2");

    ui->tableWidget_6->clearContents();
    ui->tableWidget_6->setRowCount(model->rowCount());
    ui->tableWidget_6->setColumnCount(model->columnCount());

    for (int row = 0; row < model->rowCount(); ++row) {
        for (int column = 0; column < model->columnCount(); ++column) {
            ui->tableWidget_6->setItem(row, column, new QTableWidgetItem(model->data(model->index(row, column)).toString()));
        }
    }
    delete model;
}



void MainWindow::on_addButton_clicked() {
    // Ensure one of the checkboxes is selected
    if (!ui->normalCheckBox->isChecked() && !ui->urgentCheckBox->isChecked()) {
        QMessageBox::warning(this, "Error", "You must select either 'Simple' or 'Urgent' for the complaint type.");
        return; // Do not proceed if no checkbox is selected
    }

    COMPLAINTS res;
    res.setID_COMPLAINT(ui->l3->text().toInt());
    res.setORDER_ID(ui->l4->text().toInt());
    res.setEMPLOYEE_ID(ui->l5->text().toInt());
    res.setSUPPLIER_ID(ui->l7->text().toInt());
    res.setDESCRIPTION_COMPLAINT(ui->l1->text());
    res.setACTIONS_COMPLAINT(ui->l2->text());
    res.setCOMPLAINT_DATE(datee(ui->l0->date().day(), ui->l0->date().month(), ui->l0->date().year()));
    res.setFILE_PATH(ui->filePathLineEdit->text());

    // Set the COMPLAINT_TYPE based on the selected checkbox
    if (ui->normalCheckBox->isChecked()) {
        res.setCOMPLAINT_TYPE(1); // Simple
    } else if (ui->urgentCheckBox->isChecked()) {
        res.setCOMPLAINT_TYPE(2); // Simple
    }

    if (res.ajouter()) {
        QMessageBox::information(this, "Success", "Complaint added successfully!");
        refreshTable();
    } else {
        QMessageBox::warning(this, "Error", "Failed to add complaint.");
    }
}


void MainWindow::refreshTable() {
    COMPLAINTS res;
    QSqlQueryModel *model = res.afficher();

    ui->tableWidget_6->setRowCount(0);
    while (model->canFetchMore()) {
        model->fetchMore();
    }

    ui->tableWidget_6->setRowCount(model->rowCount());
    ui->tableWidget_6->setColumnCount(model->columnCount());

    for (int row = 0; row < model->rowCount(); ++row) {
        for (int column = 0; column < model->columnCount(); ++column) {
            QTableWidgetItem *newItem = new QTableWidgetItem(model->data(model->index(row, column)).toString());
            ui->tableWidget_6->setItem(row, column, newItem);
        }
    }
}

void MainWindow::on_updateButton_clicked() {
    connect(ui->updateButton, &QPushButton::clicked, this, &MainWindow::on_updateButton_clicked);

    qDebug() << "Update button clicked";

    int id = ui->seearchLine_6->text().toInt();
    COMPLAINTS res;
    QSqlQueryModel* model = res.rechercher(id);

    if (model && model->rowCount() > 0) {
        ui->l3->setText(model->data(model->index(0, 3)).toString());
        QString dateArrStr = model->data(model->index(0, 1)).toString();
        QDate COMPLAINT_DATE = QDate::fromString(dateArrStr, "yyyy-MM-dd");
        ui->l0->setDate(COMPLAINT_DATE);
        ui->l1->setText(model->data(model->index(0, 1)).toString());
        ui->l2->setText(model->data(model->index(0, 2)).toString());
        ui->l4->setText(model->data(model->index(0, 4)).toString());
        ui->l5->setText(model->data(model->index(0, 5)).toString());
        ui->l7->setText(model->data(model->index(0, 6)).toString());
        ui->filePathLineEdit->setText(model->data(model->index(0, 7)).toString());


        delete model;
    } else {
        QMessageBox::warning(this, "Not Found", "No COMPLAINT found with that ID.");
        delete model;
    }
}


void MainWindow::on_sauvegarder_clicked() {
    int id = ui->l3->text().toInt();
    int orderid = ui->l4->text().toInt();
    int employeeid = ui->l5->text().toInt();
    int supplierid = ui->l7->text().toInt();
    QDate datt = ui->l0->date();
    QString description = ui->l1->text();
    QString actions = ui->l2->text();
    QString filePath= ui->filePathLineEdit->text();

    COMPLAINTS res;

    // Pass the day, month, and year explicitly to the datee constructor
    if (res.modifier(id, actions, description, orderid, supplierid, employeeid, datee(datt.day(), datt.month(), datt.year()),filePath)) {
        QMessageBox::information(this, "Success", "COMPLAINT updated successfully.");

        refreshTable();
    } else {
        QMessageBox::warning(this, "Update Failed", "Failed to update COMPLAINT.");
    }
}


void MainWindow::on_deleteButton_clicked() {
    int id = ui->seearchLine_6->text().toInt();
    COMPLAINTS res;
    if (res.supprimer(id)) {
        QMessageBox::information(this, "Success", "COMPLAINT deleted successfully!");
        refreshTable();
    } else {
        QMessageBox::warning(this, "Error", "Failed to delete COMPLAINT.");
    }
}

void MainWindow::on_searchButton_clicked() {
    int id = ui->seearchLine_6->text().toInt();

    COMPLAINTS res;
    QSqlQueryModel* model = res.rechercher(id);

    if (model) {
        ui->tableWidget_6->clear();
        ui->tableWidget_6->setRowCount(0);

        ui->tableWidget_6->setColumnCount(model->columnCount());
        for (int i = 0; i < model->columnCount(); ++i) {
            ui->tableWidget_6->setHorizontalHeaderItem(i, new QTableWidgetItem(model->headerData(i, Qt::Horizontal).toString()));
        }

        for (int row = 0; row < model->rowCount(); ++row) {
            ui->tableWidget_6->insertRow(row);
            for (int column = 0; column < model->columnCount(); ++column) {
                ui->tableWidget_6->setItem(row, column, new QTableWidgetItem(model->data(model->index(row, column)).toString()));
            }
        }
    } else {
        QMessageBox::warning(this, "Not Found", "No COMPLAINT found with that ID.");
    }
}

// In MainWindow constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    COMPLAINTS currentComplaint;  // Declare as a COMPLAINTS object
    currentComplaint = COMPLAINTS();



    ui->tableWidget_6->setSortingEnabled(true);
    connect(ui->combobox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_combobox_activated()));
    ui->combobox->addItem("Complaint Date");
    ui->combobox->addItem("Employee ID");
    ui->combobox->addItem("Complaint ID");
    ui->combobox->addItem("Supplier ID");
    ui->combobox->addItem("Order ID");
    ui->combobox->addItem("Description");
    ui->combobox->addItem("Actions");
    ui->combobox->addItem("FILEPATH");
    connect(ui->ascButton, &QPushButton::clicked, this, &MainWindow::on_ascButton_clicked);
    connect(ui->dscButton, &QPushButton::clicked, this, &MainWindow::on_dscButton_clicked);
    ui->tableWidget_6->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(ui->Upload, &QPushButton::clicked, this, &MainWindow::on_Upload_Clicked);
    setupBackgroundMusic();
    connect(ui->normalCheckBox, &QCheckBox::clicked, this, &MainWindow::on_normalCheckBox_clicked);
    connect(ui->urgentCheckBox, &QCheckBox::clicked, this, &MainWindow::on_urgentCheckBox_clicked);
    connect(ui->afficherSimpleButton, &QPushButton::clicked, this, &MainWindow::on_afficherSimpleButton_clicked);
    connect(ui->afficherUrgentButton, &QPushButton::clicked, this, &MainWindow::on_afficherUrgentButton_clicked);
    connect(ui->toggleDarkModeButton, &QPushButton::clicked, this, &MainWindow::onToggleDarkModeClicked);

    QList<QPushButton*> buttons = findChildren<QPushButton*>();
    for (QPushButton *button : buttons) {
        button->installEventFilter(this); // Install event filter for hover detection
    }




    // Connect the textChanged signal to a slot to play sound
    // Apply stylesheet for styling
    QString styleSheet = R"(
QTableWidget {
    border: 1px solid black;
    gridline-color: #79d9b0;
;
    background-color: #79d9b0;
;
}

QTableWidget::item {
    padding: 5px;
    border: 1px solid black;
}

QTableWidget::item:selected {
    background-color: black;
    color: white;
}

QHeaderView::section {
    background-color:   #79d9b0;
    padding: 5px;
    border: 1px solid   #79d9b0;
    font-weight: bold;
}
QPushButton {
    background: #79d9b0; /* Even darker blue on press */


}

/* Style for line edits (text input fields) */
QLineEdit {
    background-color: white;
    border: 1px solid #666;
    border-radius: 3px;
    padding: 5px;
    color: black;
    font-size: 14px;
}
QLabel {
    color: #79d9b0;        /* Text color */
    font-weight: bold;   /* Bold font */
    font-size: 20px;
font: 600 25px "Sitka Display Semibold";
     /* Adjust the size as needed */
}


)";

    // Set stylesheet to QTableWidget
    ui->tableWidget_6->setStyleSheet(styleSheet);

    // Set column widths programmatically
    ui->tableWidget_6->setColumnWidth(0, 100); // Set width of column 0 to 150 pixels
    ui->tableWidget_6->setColumnWidth(1, 150); // Set width of column 1 to 200 pixels
    ui->tableWidget_6->setColumnWidth(2, 150); // Set width of column 1 to 200 pixels
    ui->tableWidget_6->setColumnWidth(3, 150); // Set width of column 1 to 200 pixels
    ui->tableWidget_6->setColumnWidth(4, 100); // Set width of column 1 to 200 pixels
    ui->tableWidget_6->setColumnWidth(5, 100); // Set width of column 1 to 200 pixels
    ui->tableWidget_6->setColumnWidth(6, 100); // Set width of column 1 to 200 pixels
    ui->tableWidget_6->setColumnWidth(7, 150); // Set width of column 1 to 200 pixels

    qApp->setStyleSheet(styleSheet);


}
void MainWindow::on_Upload_Clicked() {
    // Open file dialog to choose image/video
    QString filePath = QFileDialog::getOpenFileName(this, "Select Image or Video", "", "Images (*.png *.jpg *.jpeg);;Videos (*.mp4 *.avi)");

    if (!filePath.isEmpty()) {
        // Save the file path to the current complaint object
        currentComplaint.setFilePath(filePath);

        // Optionally, show the file path in the UI for the user
        ui->filePathLineEdit->setText(filePath);
    }
}

void MainWindow::on_refreshButton_clicked() {
    connect(ui->refreshButton, &QPushButton::clicked, this, &MainWindow::on_refreshButton_clicked);
    refreshTable();
}

void MainWindow::on_combobox_activated()
{
    QString selectedAttribute = ui->combobox->currentText();

    QSqlQueryModel *model = new QSqlQueryModel();
    QString queryStr = "SELECT * FROM complaints"; // Base query to fetch complaints

    // Add sorting column based on the combobox selection
    if (selectedAttribute == "Complaint Date") {
        queryStr += " ORDER BY COMPLAINT_DATE";
    } else if (selectedAttribute == "Employee ID") {
        queryStr += " ORDER BY EMPLOYEE_ID";
    } else if (selectedAttribute == "Complaint ID") {
        queryStr += " ORDER BY COMPLAINT_ID";
    } else if (selectedAttribute == "Supplier ID") {
        queryStr += " ORDER BY SUPPLIER_ID";
    } else if (selectedAttribute == "Order ID") {
        queryStr += " ORDER BY ORDER_ID";
    } else if (selectedAttribute == "Description") {
        queryStr += " ORDER BY DESCRIPTION_COMPLAINT";
    } else if (selectedAttribute == "Actions") {
        queryStr += " ORDER BY ACTIONS_COMPLAINT";
    }

    // Append ASC or DESC based on the button clicked
    if (isAscending) {
        queryStr += " ASC";  // Sort ascending
    } else {
        queryStr += " DESC";  // Sort descending
    }

    // Execute the query
    model->setQuery(queryStr);

    // Check for any SQL errors
    if (model->lastError().isValid()) {
        qDebug() << "Query Error: " << model->lastError().text();
        return;
    }

    // Clear the table widget before inserting new data
    ui->tableWidget_6->clearContents();
    ui->tableWidget_6->setRowCount(0);
    ui->tableWidget_6->setColumnCount(model->columnCount());

    // Set table headers based on query result
    for (int i = 0; i < model->columnCount(); ++i) {
        ui->tableWidget_6->setHorizontalHeaderItem(i, new QTableWidgetItem(model->headerData(i, Qt::Horizontal).toString()));
    }

    // Populate the table with data from the query result
    for (int row = 0; row < model->rowCount(); ++row) {
        ui->tableWidget_6->insertRow(row);
        for (int column = 0; column < model->columnCount(); ++column) {
            ui->tableWidget_6->setItem(row, column, new QTableWidgetItem(model->data(model->index(row, column)).toString()));
        }
    }
}

void MainWindow::on_normalCheckBox_clicked(bool checked) {
    if (checked) {
        ui->urgentCheckBox->setChecked(false); // Uncheck the other box
        currentComplaint.setCOMPLAINT_TYPE(1); // Assuming 1 represents Simple
    }
}

void MainWindow::on_urgentCheckBox_clicked(bool checked) {
    if (checked) {
        ui->normalCheckBox->setChecked(false); // Uncheck the other box
        currentComplaint.setCOMPLAINT_TYPE(2); // Assuming 2 represents Complex
    }
}

void MainWindow::on_ascButton_clicked() {
    isAscending = true;  // Set the sort order to ascending
    on_combobox_activated();  // Re-run the sorting
}

void MainWindow::on_dscButton_clicked() {
    isAscending = false;  // Set the sort order to descending
    on_combobox_activated();  // Re-run the sorting
}
void MainWindow::onToggleDarkModeClicked() {
    if (!isDarkMode) {
        // Apply dark mode stylesheet
        QString darkModeStyle = R"(
            QMainWindow {
                background-color: #2E2E2E; /* Dark gray */
                color: black; /* White text */
            }
            QPushButton {
                background-color: #555555; /* Button dark gray */
                color: black; /* White text */
                border: 1px solid #888888;
                padding: 5px;
                border-radius: 5px;
            }
            QPushButton:hover {
                background-color: #777777; /* Hover color */
            }
            QTableWidget {
                background-color: #3C3C3C; /* Table background */
                color: black; /* Text color */
                gridline-color: #AAAAAA; /* Grid lines */
                border: 1px solid #555555;
            }
            QHeaderView::section {
                background-color: #444444; /* Header background */
                color: black; /* Header text */
                font-weight: bold;
            }
            QLineEdit, QTextEdit {
                background-color: #444444; /* Input background */
                color: black; /* Input text */
                border: 1px solid #888888;
            }
        )";
        qApp->setStyleSheet(darkModeStyle);
    } else {
        // Reset to default (light mode)
        qApp->setStyleSheet("");
    }
    isDarkMode = !isDarkMode; // Toggle the mode
}

MainWindow::~MainWindow() {
    delete ui;
}
