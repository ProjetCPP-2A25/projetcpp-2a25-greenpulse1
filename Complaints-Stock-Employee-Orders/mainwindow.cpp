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
#include <QStackedWidget>
#include <QPushButton>
#include <QEnterEvent> // For enterEvent
#include "stock.h"
#include <QSqlRecord>

void MainWindow::on_Ajouter_clicked()
{
    int EmpID = ui->textEdit->toPlainText().toInt();
    QString LastName = ui->textEdit_2->toPlainText();
    QString FirstName = ui->textEdit_3->toPlainText();
    QString Role = ui->textEdit_4->toPlainText();
    QString Email = ui->textEdit_5->toPlainText();
    int Phone = ui->textEdit_6->toPlainText().toInt();
    QDate DateH = QDate::fromString(ui->textEdit_9->toPlainText(), "yyyy-MM-dd");
    QString Status = ui->textEdit_7->toPlainText();

    // Correct the column names in this query as per the actual database schema
    QSqlQuery query;
    query.prepare("INSERT INTO employees (EMPLOYEE_ID,LAST_NAME_EMPLOYEE,FIRST_NAME_EMPLOYEE,ROLE_EMPLOYEE,EMAIL_EMPLOYEE,PHONE_EMPLOYEE,HIRE_DATE_EMPLOYEE,STATUS_EMPLOYEE)"
                  "VALUES (:EMPLOYEE_ID, :LAST_NAME_EMPLOYEE, :FIRST_NAME_EMPLOYEE, :ROLE_EMPLOYEE, :EMAIL_EMPLOYEE, :PHONE_EMPLOYEE, :HIRE_DATE_EMPLOYEE, :STATUS_EMPLOYEE)");
    query.bindValue(":EMPLOYEE_ID", EmpID);
    query.bindValue(":LAST_NAME_EMPLOYEE", LastName);
    query.bindValue(":FIRST_NAME_EMPLOYEE", FirstName);
    query.bindValue(":ROLE_EMPLOYEE", Role);
    query.bindValue(":EMAIL_EMPLOYEE", Email);
    query.bindValue(":PHONE_EMPLOYEE", Phone);
    query.bindValue(":HIRE_DATE_EMPLOYEE", DateH.toString("yyyy-MM-dd"));
    query.bindValue(":STATUS_EMPLOYEE", Status);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Employee added to the database.");

        // Add to tableWidget
        int row = ui->tableWidget_2->rowCount();
        ui->tableWidget_2->insertRow(row);
        ui->tableWidget_2->setItem(row, 0, new QTableWidgetItem(QString::number(EmpID)));
        ui->tableWidget_2->setItem(row, 1, new QTableWidgetItem(LastName));
        ui->tableWidget_2->setItem(row, 2, new QTableWidgetItem(FirstName));
        ui->tableWidget_2->setItem(row, 3, new QTableWidgetItem(Role));
        ui->tableWidget_2->setItem(row, 4, new QTableWidgetItem(Email));
        ui->tableWidget_2->setItem(row, 5, new QTableWidgetItem(QString::number(Phone)));
        ui->tableWidget_2->setItem(row, 6, new QTableWidgetItem(DateH.toString("yyyy-MM-dd")));
        ui->tableWidget_2->setItem(row, 7, new QTableWidgetItem(Status));

    } else {
        QMessageBox::critical(this, "Error", "Failed to add employee to database. " + query.lastError().text());
    }
}

void MainWindow::on_Afficher_clicked()
{
    // Assuming `model` is of type QSqlQueryModel and contains employee data
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("SELECT * FROM employees");  // Example query
    // Clear the table
    ui->tableWidget_2->setRowCount(0);

    // Populate `QTableWidget` with data from the model
    for (int row = 0; row < model->rowCount(); ++row) {
        ui->tableWidget_2->insertRow(row);  // Insert a new row

        for (int col = 0; col < model->columnCount(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(model->data(model->index(row, col)).toString());
            ui->tableWidget_2->setItem(row, col, item);
        }
    }
}

void MainWindow::on_DeleteButton_clicked()
{
    // Get the employee ID from the input field
    int id = ui->textEdit->toPlainText().toInt();

    // Check if ID is valid before proceeding
    if (id <= 0) {
        QMessageBox::warning(this, "Invalid ID", "Please enter a valid Employee ID.");
        return;
    }

    // Prepare the SQL DELETE query
    QSqlQuery query;
    query.prepare("DELETE FROM employees WHERE EMPLOYEE_ID = :empID");
    query.bindValue(":empID", id);

    // Execute the query and check for success
    if (query.exec()) {
        if (query.numRowsAffected() > 0) {
            QMessageBox::information(this, "Delete", "Employee deleted successfully.");

            // Remove the row from the QTableWidget for real-time UI update
            for (int row = 0; row < ui->tableWidget_2->rowCount(); ++row) {
                if (ui->tableWidget_2->item(row, 0)->text().toInt() == id) {
                    ui->tableWidget_2->removeRow(row);
                    break;
                }
            }
        } else {
            QMessageBox::warning(this, "Not Found", "Employee ID not found in the database.");
        }
    } else {
        QMessageBox::critical(this, "Delete Error", "Failed to delete employee. Error: " + query.lastError().text());
    }
}


void MainWindow::on_EditButton_clicked()
{
    int row = ui->tableWidget_2->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "No Selection", "Please select an employee row to edit.");
        return;
    }

    // Retrieve the current data from the selected row
    int EmpID = ui->tableWidget_2->item(row, 0)->text().toInt();
    QString LastName = ui->tableWidget_2->item(row, 1)->text();
    QString FirstName = ui->tableWidget_2->item(row, 2)->text();
    QString Role = ui->tableWidget_2->item(row, 3)->text();
    QString Email = ui->tableWidget_2->item(row, 4)->text();
    int Phone = ui->tableWidget_2->item(row, 5)->text().toInt();
    QString HireDate = ui->tableWidget_2->item(row, 6)->text();
    QString Status = ui->tableWidget_2->item(row, 7)->text();

    // Populate the input fields with the current values
    ui->textEdit->setPlainText(QString::number(EmpID));
    ui->textEdit_2->setPlainText(LastName);
    ui->textEdit_3->setPlainText(FirstName);
    ui->textEdit_4->setPlainText(Role);
    ui->textEdit_5->setPlainText(Email);
    ui->textEdit_6->setPlainText(QString::number(Phone));
    ui->textEdit_9->setPlainText(HireDate);
    ui->textEdit_7->setPlainText(Status);
}

// Slot to save the edited employee details
void MainWindow::on_SaveButton_clicked()
{
    // Get the updated data from the input fields
    int newEmpID = ui->textEdit->toPlainText().toInt();
    QString newLastName = ui->textEdit_2->toPlainText();
    QString newFirstName = ui->textEdit_3->toPlainText();
    QString newRole = ui->textEdit_4->toPlainText();
    QString newEmail = ui->textEdit_5->toPlainText();
    int newPhone = ui->textEdit_6->toPlainText().toInt();
    QString newHireDate = ui->textEdit_9->toPlainText();
    QString newStatus = ui->textEdit_7->toPlainText();

    // Update the table with new values
    int row = ui->tableWidget_2->currentRow();
    ui->tableWidget_2->item(row, 0)->setText(QString::number(newEmpID));
    ui->tableWidget_2->item(row, 1)->setText(newLastName);
    ui->tableWidget_2->item(row, 2)->setText(newFirstName);
    ui->tableWidget_2->item(row, 3)->setText(newRole);
    ui->tableWidget_2->item(row, 4)->setText(newEmail);
    ui->tableWidget_2->item(row, 5)->setText(QString::number(newPhone));
    ui->tableWidget_2->item(row, 6)->setText(newHireDate);
    ui->tableWidget_2->item(row, 7)->setText(newStatus);

    // Update the database with the new data
    QSqlQuery query;
    query.prepare("UPDATE employees SET LAST_NAME_EMPLOYEE = :lastName, FIRST_NAME_EMPLOYEE = :firstName, ROLE_EMPLOYEE = :role, EMAIL_EMPLOYEE = :email, PHONE_EMPLOYEE = :phone, HIRE_DATE_EMPLOYEE = :hireDate, STATUS_EMPLOYEE = :status WHERE Employee_ID = :empID");
    query.bindValue(":lastName", newLastName);
    query.bindValue(":firstName", newFirstName);
    query.bindValue(":role", newRole);
    query.bindValue(":email", newEmail);
    query.bindValue(":phone", newPhone);
    query.bindValue(":hireDate", newHireDate);
    query.bindValue(":status", newStatus);
    query.bindValue(":empID", newEmpID);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Employee details updated successfully.");
    } else {
        QMessageBox::critical(this, "Error", "Failed to update employee. " + query.lastError().text());
    }
}
void MainWindow::on_pushButton_6_clicked()
{
    if (chartWindow != nullptr) {
        qDebug() << "Chart window is already open.";
        return;
    }

    QBarSet *set = new QBarSet("Number Of Employees");
    *set << 3 << 4 << 5 << 2 << 10;

    double maxValue = 0;
    for (int i = 0; i < set->count(); ++i) {
        if (set->at(i) > maxValue) {
            maxValue = set->at(i);
        }
    }

    QBarSeries *series = new QBarSeries();
    series->append(set);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Employee Statistics");

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, maxValue);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QStringList categories;
    categories << "2020" << "2021" << "2022" << "2023" << "2024";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    chartWindow = new QWidget(this);
    chartWindow->setWindowTitle("Employee Statistics");
    QVBoxLayout *layout = new QVBoxLayout(chartWindow);
    layout->addWidget(chartView);

    // Set up shortcut for "Esc" key to close the window
   /* QShortcut *shortcut = new QShortcut(QKeySequence(Qt::Key_Escape), chartWindow);
    connect(shortcut, &QShortcut::activated, [this]() {
        if (chartWindow) {
            chartWindow->close();
            chartWindow = nullptr;
        }
    });*/

    chartWindow->resize(800, 600);
    chartWindow->show();
}


// Event filter to close the chart window on "Esc"
/*bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == chartWindow && event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Escape) {
            chartWindow->close();
            chartWindow = nullptr; // Reset pointer after closing
            return true; // Event is handled
        }
    }
    return QMainWindow::eventFilter(obj, event); // Call base class for unhandled events
}/*


/*void MainWindow::on_pushButton_8_clicked()
{
    if (chartWindow) {
        qDebug() << "Closing chart window";  // Debug line to confirm the slot is triggered
        chartWindow->close();  // Close the chart window
        chartWindow = nullptr; // Reset the pointer
    } else {
        qDebug() << "No chart window to close";  // Debug line to see if chart window is null
    }
}*/
void MainWindow::on_pushButton_9_clicked()
{
    // Get the employee ID from the plainTextEdit (or whichever widget you're using for input)
    QString employeeID = ui->plainTextEdit->toPlainText().trimmed(); // Use toPlainText() to get the content of QPlainTextEdit

    // Check if the employee ID is empty
    if (employeeID.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid Employee ID.");
        return;
    }

    // Create a query to search for the employee based on the entered ID
    QSqlQuery query;
    query.prepare("SELECT * FROM employees WHERE EMPLOYEE_ID = :employeeID"); // Correct column name for ID
    query.bindValue(":employeeID", employeeID);

    // Execute the query
    if (query.exec()) {
        if (query.next()) {
            // Employee found, display details in the form
            QString lastName = query.value("LAST_NAME_EMPLOYEE").toString();
            QString firstName = query.value("FIRST_NAME_EMPLOYEE").toString();
            QString role = query.value("ROLE_EMPLOYEE").toString();
            QString email = query.value("EMAIL_EMPLOYEE").toString();
            QString phone = query.value("PHONE_EMPLOYEE").toString();
            QString hireDate = query.value("HIRE_DATE_EMPLOYEE").toString();
            QString status = query.value("STATUS_EMPLOYEE").toString();

            // Set the employee details in the QTextEdit widgets in your "Add Employee" form
            ui->textEdit_2->setPlainText(lastName); // Last name
            ui->textEdit_3->setPlainText(firstName); // First name
            ui->textEdit_4->setPlainText(role); // Role
            ui->textEdit_5->setPlainText(email); // Email
            ui->textEdit_6->setPlainText(phone); // Phone
            ui->textEdit_9->setPlainText(hireDate); // Hire Date
            ui->textEdit_7->setPlainText(status); // Status
        } else {
            // No employee found with that ID
            QMessageBox::information(this, "No Results", "No employee found with the provided ID.");
        }
    } else {
        // Error in executing the query
        qDebug() << "Error executing query: " << query.lastError();
        QMessageBox::critical(this, "Database Error", "Failed to retrieve employee information.");
    }
}
void MainWindow::on_pushButton_10_clicked()
{
    // Use a file dialog to allow the user to choose where to save the PDF
    QString filePath = QFileDialog::getSaveFileName(this, "Save PDF", "", "PDF Files (*.pdf);;All Files (*)");

    // If the user cancels the dialog, return early
    if (filePath.isEmpty()) {
        return;
    }

    // Create a QPrinter object to specify the PDF settings
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);  // Set the file path chosen by the user

    // Create a QPainter object to render the content
    QPainter painter;
    if (!painter.begin(&printer)) {
        QMessageBox::critical(this, "Error", "Failed to create PDF file.");
        return;
    }

    // Render the entire window (or a specific widget) to the painter
    this->render(&painter);  // Render the whole window content into the PDF

    // Finalize the painter and save the PDF
    painter.end();

    QMessageBox::information(this, "Success", "MainWindow exported to PDF successfully.");
}
void MainWindow::on_pushButton_11_clicked()
{
    // Create a new dialog for Leave Management Login
    leaveManagementDialog = new QDialog(this);
    leaveManagementDialog->setWindowTitle("Leave Management Login");
    leaveManagementDialog->resize(300, 200);

    // Create layout and widgets for the dialog
    QVBoxLayout* layout = new QVBoxLayout(leaveManagementDialog);

    QLabel* labelFirstName = new QLabel("First Name:", leaveManagementDialog);
    QLineEdit* lineEditFirstName = new QLineEdit(leaveManagementDialog);

    QLabel* labelEmployeeID = new QLabel("Employee ID:", leaveManagementDialog);
    QLineEdit* lineEditEmployeeID = new QLineEdit(leaveManagementDialog);
    lineEditEmployeeID->setEchoMode(QLineEdit::Password); // Hide password input

    QPushButton* buttonLogin = new QPushButton("Login", leaveManagementDialog);

    // Add widgets to the layout
    layout->addWidget(labelFirstName);
    layout->addWidget(lineEditFirstName);
    layout->addWidget(labelEmployeeID);
    layout->addWidget(lineEditEmployeeID);
    layout->addWidget(buttonLogin);

    leaveManagementDialog->setLayout(layout);

    // Connect login button to validation logic
    connect(buttonLogin, &QPushButton::clicked, [=]() {
        QString firstName = lineEditFirstName->text();
        QString employeeID = lineEditEmployeeID->text();

        // Prepare a query to check if the employee exists in the database and get their role
        QSqlQuery query;
        query.prepare("SELECT \"ROLE_EMPLOYEE\" FROM employees WHERE \"FIRST_NAME_EMPLOYEE\" = :firstName AND \"EMPLOYEE_ID\" = :employeeID");
        query.bindValue(":firstName", firstName);
        query.bindValue(":employeeID", employeeID);

        if (query.exec()) {
            if (query.next()) {
                QString role = query.value(0).toString(); // Get the role of the employee

                if (!role.isEmpty()) {
                    // Employee found
                    if (role == "manager") {
                        // If the employee is a Manager, show the Manager window
                        QMessageBox::information(leaveManagementDialog, "Login Success", "Welcome Manager!");

                        // Open the Manager-specific leave request window
                        QWidget* managerLeaveRequestWindow = new QWidget();
                        managerLeaveRequestWindow->setWindowTitle("Manager Leave Request Form");

                        // Example of a Manager leave request form with absence form included
                        QVBoxLayout* managerFormLayout = new QVBoxLayout(managerLeaveRequestWindow);

                        QLabel* leaveTypeLabel = new QLabel("Leave Type:");
                        QComboBox* leaveTypeComboBox = new QComboBox();
                        leaveTypeComboBox->addItem("Sick Leave");
                        leaveTypeComboBox->addItem("Vacation");
                        leaveTypeComboBox->addItem("None");

                        QLabel* absenceFormLabel = new QLabel("Absence Without Leave:");
                        QLineEdit* absenceFormInput = new QLineEdit();  // New input for absence form

                        QLabel* startDateLabel = new QLabel("Start Date:");
                        QDateEdit* startDateEdit = new QDateEdit(QDate::currentDate());

                        QLabel* endDateLabel = new QLabel("End Date:");
                        QDateEdit* endDateEdit = new QDateEdit(QDate::currentDate());

                        QPushButton* submitButton = new QPushButton("Submit Leave Request");

                        // Add widgets to the manager's form layout
                        managerFormLayout->addWidget(leaveTypeLabel);
                        managerFormLayout->addWidget(leaveTypeComboBox);
                        managerFormLayout->addWidget(absenceFormLabel);
                        managerFormLayout->addWidget(absenceFormInput); // Absence input
                        managerFormLayout->addWidget(startDateLabel);
                        managerFormLayout->addWidget(startDateEdit);
                        managerFormLayout->addWidget(endDateLabel);
                        managerFormLayout->addWidget(endDateEdit);
                        managerFormLayout->addWidget(submitButton);

                        managerLeaveRequestWindow->setLayout(managerFormLayout);

                        // Connect the submit button to save the leave request data
                        connect(submitButton, &QPushButton::clicked, [=]() {
                            // Capture the data from the form
                            QString leaveType = leaveTypeComboBox->currentText();
                            QString absenceReason = absenceFormInput->text();  // Get absence reason
                            QString startDate = startDateEdit->date().toString("yyyy-MM-dd");
                            QString endDate = endDateEdit->date().toString("yyyy-MM-dd");

                            // Open a file dialog to ask the user where to save the leave request
                            QString filePath = QFileDialog::getSaveFileName(this, "Save Manager Leave Request", "", "Text Files (*.txt)");

                            if (!filePath.isEmpty()) {
                                // Save the data to the selected file
                                QFile file(filePath);
                                if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                                    QTextStream out(&file);
                                    out << "Role: Manager\n";
                                    out << "Leave Type: " << leaveType << "\n";
                                    out << "Absence Reason: " << absenceReason << "\n";
                                    out << "Start Date: " << startDate << "\n";
                                    out << "End Date: " << endDate << "\n";
                                    file.close();

                                    // Show success message
                                    QMessageBox::information(managerLeaveRequestWindow, "Success", "Manager Leave Request Submitted Successfully!");
                                } else {
                                    // If file opening fails
                                    QMessageBox::critical(managerLeaveRequestWindow, "Error", "Failed to save the leave request.");
                                }
                            }
                        });

                        managerLeaveRequestWindow->show();
                    } else {
                        // Employee is not a manager, show regular leave request form
                        QMessageBox::information(leaveManagementDialog, "Login Success", "Welcome Employee!");

                        QWidget* leaveRequestWindow = new QWidget();  // Regular employee window
                        leaveRequestWindow->setWindowTitle("Leave Request Form");

                        // Regular employee leave request form (same as before)
                        QVBoxLayout* formLayout = new QVBoxLayout(leaveRequestWindow);

                        QLabel* leaveTypeLabel = new QLabel("Leave Type:");
                        QComboBox* leaveTypeComboBox = new QComboBox();
                        leaveTypeComboBox->addItem("Sick Leave");
                        leaveTypeComboBox->addItem("Vacation");

                        QLabel* startDateLabel = new QLabel("Start Date:");
                        QDateEdit* startDateEdit = new QDateEdit(QDate::currentDate());

                        QLabel* endDateLabel = new QLabel("End Date:");
                        QDateEdit* endDateEdit = new QDateEdit(QDate::currentDate());

                        QPushButton* submitButton = new QPushButton("Submit Leave Request");

                        // Add widgets to the form layout
                        formLayout->addWidget(leaveTypeLabel);
                        formLayout->addWidget(leaveTypeComboBox);
                        formLayout->addWidget(startDateLabel);
                        formLayout->addWidget(startDateEdit);
                        formLayout->addWidget(endDateLabel);
                        formLayout->addWidget(endDateEdit);
                        formLayout->addWidget(submitButton);

                        leaveRequestWindow->setLayout(formLayout);

                        // Connect the submit button to save the leave request data
                        connect(submitButton, &QPushButton::clicked, [=]() {
                            // Capture the data from the form
                            QString leaveType = leaveTypeComboBox->currentText();
                            QString startDate = startDateEdit->date().toString("yyyy-MM-dd");
                            QString endDate = endDateEdit->date().toString("yyyy-MM-dd");

                            // Open a file dialog to ask the user where to save the leave request
                            QString filePath = QFileDialog::getSaveFileName(this, "Save Leave Request", "", "Text Files (*.txt)");

                            if (!filePath.isEmpty()) {
                                // Save the data to the selected file
                                QFile file(filePath);
                                if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                                    QTextStream out(&file);
                                    out << "Leave Type: " << leaveType << "\n";
                                    out << "Start Date: " << startDate << "\n";
                                    out << "End Date: " << endDate << "\n";
                                    file.close();

                                    // Show success message
                                    QMessageBox::information(leaveRequestWindow, "Success", "Leave Request Submitted Successfully!");
                                } else {
                                    // If file opening fails
                                    QMessageBox::critical(leaveRequestWindow, "Error", "Failed to save the leave request.");
                                }
                            }
                        });

                        leaveRequestWindow->show();
                    }

                    // Close the login dialog
                    leaveManagementDialog->accept();
                } else {
                    // Employee not found, show error message
                    QMessageBox::warning(leaveManagementDialog, "Login Failed", "Invalid First Name or Employee ID.");
                }
            } else {
                // Employee not found, show error message
                QMessageBox::warning(leaveManagementDialog, "Login Failed", "Invalid First Name or Employee ID.");
            }
        } else {
            // Error with the query execution
            QMessageBox::critical(leaveManagementDialog, "Database Error", "Error while querying the database: " + query.lastError().text());
        }
    });

    leaveManagementDialog->exec(); // Show the dialog as a modal window
}
void MainWindow::on_pushButton_12_clicked()
{
    // Create the chat login dialog
    QDialog* chatLoginDialog = new QDialog(this);
    chatLoginDialog->setWindowTitle("Chat Login");
    chatLoginDialog->resize(300, 200);

    // Create layout and widgets for the dialog
    QVBoxLayout* layout = new QVBoxLayout(chatLoginDialog);

    QLabel* labelFirstName = new QLabel("First Name:", chatLoginDialog);
    QLineEdit* lineEditFirstName = new QLineEdit(chatLoginDialog);

    QLabel* labelEmployeeID = new QLabel("Employee ID:", chatLoginDialog);
    QLineEdit* lineEditEmployeeID = new QLineEdit(chatLoginDialog);
    lineEditEmployeeID->setEchoMode(QLineEdit::Password); // Hide password input

    QPushButton* buttonLogin = new QPushButton("Login", chatLoginDialog);

    // Add widgets to the layout
    layout->addWidget(labelFirstName);
    layout->addWidget(lineEditFirstName);
    layout->addWidget(labelEmployeeID);
    layout->addWidget(lineEditEmployeeID);
    layout->addWidget(buttonLogin);

    chatLoginDialog->setLayout(layout);

    // Connect login button to validation logic
    connect(buttonLogin, &QPushButton::clicked, [=]() {
        QString firstName = lineEditFirstName->text();
        QString employeeID = lineEditEmployeeID->text();

        // Prepare a query to check if the employee exists in the database and get their role
        QSqlQuery query;
        query.prepare("SELECT \"FIRST_NAME_EMPLOYEE\", \"EMPLOYEE_ID\", \"ROLE_EMPLOYEE\" FROM employees WHERE \"FIRST_NAME_EMPLOYEE\" = :firstName AND \"EMPLOYEE_ID\" = :employeeID");
        query.bindValue(":firstName", firstName);
        query.bindValue(":employeeID", employeeID);

        if (query.exec()) {
            if (query.next()) {
                // Employee found
                QString role = query.value(2).toString(); // Get the employee's role
                QMessageBox::information(chatLoginDialog, "Login Success", "Welcome to the Chat!");

                // Proceed to chat interface
                QWidget* chatWindow = new QWidget();
                chatWindow->setWindowTitle("Employee Chat");

                // Example of chat interface
                QVBoxLayout* chatLayout = new QVBoxLayout(chatWindow);

                // Message box to show chat history (load chat history from file)
                QTextEdit* messageBox = new QTextEdit(chatWindow);
                messageBox->setReadOnly(true);  // Only view the messages

                // Load chat history from the text file
                QFile file("chat_history.txt");
                if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                    QTextStream in(&file);
                    QString line;
                    while (!in.atEnd()) {
                        line = in.readLine();
                        messageBox->append(line);  // Append each line to the message box
                    }
                    file.close();
                }

                // Input for new messages
                QLineEdit* messageInput = new QLineEdit(chatWindow);

                // Send button
                QPushButton* sendButton = new QPushButton("Send", chatWindow);

                // Layout setup for the chat window
                chatLayout->addWidget(messageBox);
                chatLayout->addWidget(messageInput);
                chatLayout->addWidget(sendButton);

                // Save messages to a file on send
                connect(sendButton, &QPushButton::clicked, [=]() {
                    QString message = messageInput->text();
                    if (!message.isEmpty()) {
                        // Format the message with the name in blue
                        QString formattedMessage = "<font color='blue'>" + firstName + " (" + role + ")</font>: " + message;

                        // Display message with role in parentheses and name in blue
                        messageBox->append(formattedMessage);

                        // Save the message to a text file
                        QFile file("chat_history.txt");
                        if (file.open(QIODevice::Append | QIODevice::Text)) {
                            QTextStream out(&file);
                            out << firstName << " (" << role << "): " << message << "\n";
                            file.close();
                        }
                    }
                    messageInput->clear();  // Clear input field after sending
                });

                chatWindow->setLayout(chatLayout);
                chatWindow->show();

                // Close the login dialog
                chatLoginDialog->accept();
            } else {
                // Employee not found
                QMessageBox::warning(chatLoginDialog, "Login Failed", "Invalid First Name or Employee ID.");
            }
        } else {
            // Error with the query execution
            QMessageBox::critical(chatLoginDialog, "Database Error", "Error while querying the database: " + query.lastError().text());
        }
    });

    // Show the login dialog for the chat system
    chatLoginDialog->exec();
}


void MainWindow::on_pushButton_7_clicked()
{
    // Clear the tableWidget
    ui->tableWidget_2->setRowCount(0);

    // Query the database to fetch sorted employee data by ID
    QSqlQuery query;
    query.prepare("SELECT EMPLOYEE_ID, LAST_NAME_EMPLOYEE, FIRST_NAME_EMPLOYEE, ROLE_EMPLOYEE, EMAIL_EMPLOYEE, PHONE_EMPLOYEE, HIRE_DATE_EMPLOYEE, STATUS_EMPLOYEE "
                  "FROM employees ORDER BY EMPLOYEE_ID ASC");

    if (query.exec()) {
        int row = 0;

        // Populate the QTableWidget with sorted data
        while (query.next()) {
            ui->tableWidget_2->insertRow(row);

            for (int col = 0; col < query.record().count(); ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                ui->tableWidget_2->setItem(row, col, item);
            }
            row++;
        }

        QMessageBox::information(this, "Sort Success", "Employee records sorted by ID.");
    } else {
        QMessageBox::critical(this, "Sort Error", "Failed to sort employees by ID. " + query.lastError().text());
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::on_refrech_er_clicked() {
    refreshTable();
}

void MainWindow::setupConnections()

{
    ui->mailLogin->setPlaceholderText("E-Mail");  // Set placeholder text
    ui->lineEdit_2->setPlaceholderText("**********");  // Set placeholder text




    // Connect the button to the stacked widget page change
    connect(ui->pushButton_48, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(1); // Set the current page to 2
        ui->groupBox->setVisible(true);
        ui->backButton->setVisible(true);
        ui->pushButton_12->setVisible(true);
        ui->toggleDarkModeButton->setVisible(true);
    });
    connect(ui->pushButton_52, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(0); // Set the current page to 2
        ui->groupBox->setVisible(true);
        ui->backButton->setVisible(true);
        ui->pushButton_12->setVisible(true);
        ui->toggleDarkModeButton->setVisible(true);

    });
    connect(ui->pushButton_53, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(2); // Set the current page to 2
        ui->groupBox->setVisible(true);
        ui->backButton->setVisible(true);
        ui->pushButton_12->setVisible(true);
        ui->toggleDarkModeButton->setVisible(true);

    });
    connect(ui->pushButton_50, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(3); // Set the current page to 2
        ui->groupBox->setVisible(false);
        ui->backButton->setVisible(false);
        ui->pushButton_12->setVisible(false);
        ui->toggleDarkModeButton->setVisible(false);


    });
}
void MainWindow::on_updateButton1_clicked()
{
    // Récupérer les données de l'interface utilisateur (champs de texte)
    int stockId = ui->l1_3->text().toInt(); // Assurez-vous que l'ID est correctement récupéré
    QString name = ui->l1_2->text();
    int quantity = ui->quant->text().toInt();
    QString type = ui->type->text();  // À ajuster selon votre interface
    QString conditions = ui->l4_2->text(); // Si vous avez un champ de conditions
    QDate entryDate = QDate::currentDate();  // Date d'entrée, peut être ajustée si nécessaire
    int employeeId = ui->idEmploye->text().toInt(); // ID de l'employé

    // Mettre à jour les données du stock dans la base de données
    QSqlQuery query;

    query.prepare("UPDATE STOCKS SET NAME_STOCK = :name, QUANTITY_STOCK = :quantity, TYPE_STOCK = :type, CONDITION_STOCK = :conditions, ENTRY_DATE_STOCK = :entryDate, EMPLOYEE_ID = :employeeId WHERE STOCK_ID = :stockId");
    query.addBindValue(name);
    query.addBindValue(quantity);
    query.addBindValue(type);
    query.addBindValue(conditions);
    query.addBindValue(entryDate);
    query.addBindValue(employeeId);
    query.addBindValue(stockId);  // L'ID du stock à mettre à jour

    if (query.exec()) {
        // Si la mise à jour réussit, afficher une notification et rafraîchir la table
        QMessageBox::information(this, "Mise à jour réussie", "Le stock a été mis à jour avec succès.");
        refreshTable();  // Rafraîchir la table après la mise à jour

        // Ajouter à l'historique
        QString details = QString("Produit : %1, Quantité : %2, ID Employé : %3")
                              .arg(name)
                              .arg(quantity)
                              .arg(employeeId);

        historyList.append(qMakePair("Mise à jour", details)); // Ajout à l'historique
        updateHistoryTable(); // Met à jour l'affichage de l'historique
    } else {
        // Si la mise à jour échoue, afficher un message d'erreur
        QMessageBox::warning(this, "Erreur", "Échec de la mise à jour du stock.");
    }
}


void MainWindow::on_deleteButton1_clicked() {
    // Récupérer l'index de la ligne sélectionnée dans le QTableWidget
    QModelIndex selectedIndex = ui->tableWidget->selectionModel()->currentIndex();

    // Vérifier si une ligne a été sélectionnée
    if (selectedIndex.isValid()) {
        // Récupérer l'ID et le nom du stock à supprimer
        int stockId = ui->tableWidget->model()->index(selectedIndex.row(), 0).data().toInt(); // Supposons que l'ID est dans la première colonne
        QString stockName = ui->tableWidget->model()->index(selectedIndex.row(), 1).data().toString(); // Nom dans la deuxième colonne

        // Tenter de supprimer le stock en appelant la méthode deleteStock
        if (stock.deleteStock(stockId)) {
            // Mise à jour du tableau principal
            refreshTable();

            // Notification de réussite
            showNotificationInLayout("Suppression réussie", QString("Le stock '%1' a été supprimé avec succès.").arg(stockName));
            QMessageBox::information(this, "Suppression réussie", QString("Le stock '%1' a été supprimé avec succès.").arg(stockName));

            // Enregistrement dans l'historique
            QString details = QString("Produit : %1, ID : %2").arg(stockName).arg(stockId);
            historyList.append(qMakePair("Suppression", details)); // Ajout à l'historique
            updateHistoryTable(); // Met à jour l'affichage de l'historique

            qDebug() << "Historique mis à jour : " << details;

        } else {
            // Si la suppression échoue, afficher un message d'erreur
            QMessageBox::warning(this, "Erreur", "Échec de la suppression du stock.");
        }
    } else {
        // Si aucune ligne n'est sélectionnée, afficher un message d'erreur
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une ligne à supprimer.");
    }
}




void MainWindow::on_searchButton1_clicked()
{
    int stockId = ui->serch->text().toInt();
    QSqlQueryModel *model = stock.searchStock(stockId);
    ui->tableWidget->setModel(model);
}

void MainWindow::on_trierLine_6_currentTextChanged()
{
    refreshTable(); // Add sorting logic here if necessary
}
void MainWindow::on_sort_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);

    QSqlQuery query;
    query.prepare("SELECT STOCK_ID, NAME_STOCK, QUANTITY_STOCK, TYPE_STOCK, CONDITION_STOCK, ENTRY_DATE_STOCK, EMPLOYEE_ID,PRENOM "
                  "FROM STOCKS ORDER BY STOCK_ID ASC");

    if (query.exec()) {
        model->setQuery(query);
        ui->tableWidget->setModel(model);
        //QMessageBox::information(this, "Sort Success", "Stock records sorted by ID.");

        // Ajouter dans l'historique
        QString details = "Tri effectué par ID";
        historyList.append(qMakePair("Tri", details));
        updateHistoryTable(); // Mettre à jour l'affichage de l'historique

    } else {
        QMessageBox::critical(this, "Sort Error", "Failed to sort stocks by ID. " + query.lastError().text());
    }
}


void MainWindow::exportToPDF()
{
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save PDF"), "", tr("PDF Files (*.pdf)"));
    if (filePath.isEmpty()) {
        return;
    }

    if (!filePath.endsWith(".pdf", Qt::CaseInsensitive)) {
        filePath += ".pdf";
    }

    QPdfWriter pdfWriter(filePath);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setResolution(300);

    QPainter painter(&pdfWriter);

    // Marges et tailles par défaut
    int margin = 50;
    int x = margin;
    int y = margin;
    int rowHeight = 40; // Hauteur par défaut des lignes
    int colWidth = 120; // Largeur par défaut des colonnes
    int pageWidth = pdfWriter.width();
    int pageHeight = pdfWriter.height();

    // Titre
    painter.setFont(QFont("Arial", 14, QFont::Bold));
    painter.drawText(x, y, "Stock Report");
    y += rowHeight * 2;

    QAbstractItemModel *model = ui->tableWidget->model();
    if (!model) {
        QMessageBox::warning(this, "Export Failed", "No data to export.");
        return;
    }

    int totalCols = model->columnCount();
    int totalRows = model->rowCount();

    // Calcul de la largeur dynamique des colonnes
    QVector<int> colWidths(totalCols, colWidth); // Initialisation des largeurs par défaut
    QFontMetrics metrics(painter.font());

    for (int col = 0; col < totalCols; ++col) {
        // Trouver la largeur maximale pour chaque colonne
        int maxWidth = metrics.horizontalAdvance(model->headerData(col, Qt::Horizontal).toString()) + 20;
        for (int row = 0; row < totalRows; ++row) {
            int dataWidth = metrics.horizontalAdvance(model->data(model->index(row, col)).toString()) + 20;
            maxWidth = qMax(maxWidth, dataWidth);
        }
        colWidths[col] = qMin(maxWidth, (pageWidth - 2 * margin) / totalCols); // Limiter la largeur par colonne
    }

    // Dessiner les en-têtes
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    for (int col = 0; col < totalCols; ++col) {
        QRect cellRect(x, y, colWidths[col], rowHeight);
        painter.drawRect(cellRect);
        painter.drawText(cellRect, Qt::AlignCenter, model->headerData(col, Qt::Horizontal).toString());
        x += colWidths[col];
    }
    y += rowHeight;

    // Dessiner les lignes de données
    painter.setFont(QFont("Arial", 10));
    for (int row = 0; row < totalRows; ++row) {
        x = margin; // Réinitialiser la position x à la marge gauche
        for (int col = 0; col < totalCols; ++col) {
            QRect cellRect(x, y, colWidths[col], rowHeight);
            painter.drawRect(cellRect);

            QString data = model->data(model->index(row, col)).toString();
            painter.drawText(cellRect, Qt::AlignCenter, data);

            x += colWidths[col];
        }
        y += rowHeight;

        // Passer à une nouvelle page si nécessaire
        if (y + rowHeight > pageHeight - margin) {
            pdfWriter.newPage();
            y = margin;

            // Redessiner les en-têtes sur la nouvelle page
            x = margin;
            for (int col = 0; col < totalCols; ++col) {
                QRect cellRect(x, y, colWidths[col], rowHeight);
                painter.drawRect(cellRect);
                painter.drawText(cellRect, Qt::AlignCenter, model->headerData(col, Qt::Horizontal).toString());
                x += colWidths[col];
            }
            y += rowHeight;
        }
    }

    painter.end();

    QMessageBox::information(this, "Export Success", "The PDF was saved successfully.");

    // Ajouter dans l'historique
    QString details = "Export des stocks au format PDF vers " + filePath;
    historyList.append(qMakePair("Export PDF", details));
    updateHistoryTable(); // Mettre à jour l'affichage de l'historique
}





void MainWindow::showStatistics()
{
    QSqlQuery query;
    query.prepare("SELECT TYPE_STOCK, COUNT(*) FROM STOCKS GROUP BY TYPE_STOCK");
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les statistiques : " + query.lastError().text());
        return;
    }

    QBarSeries *series = new QBarSeries();
    QStringList categories;

    while (query.next()) {
        QString type = query.value(0).toString();
        int count = query.value(1).toInt();

        QBarSet *set = new QBarSet(type);
        *set << count;
        series->append(set);

        categories << type;
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des stocks par type");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 10);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow *statsWindow = new QMainWindow(this);
    statsWindow->setCentralWidget(chartView);
    statsWindow->resize(800, 600);
    statsWindow->setWindowTitle("Statistiques");
    statsWindow->show();

    // Ajouter dans l'historique
    QString details = "Affichage des statistiques des stocks";
    historyList.append(qMakePair("Statistiques", details));
    updateHistoryTable(); // Mettre à jour l'affichage de l'historique
}



void MainWindow::notifyUser(const QString &title, const QString &message, QSystemTrayIcon::MessageIcon icon)
{
    stock.logNotification(title, message);
    trayIcon->showMessage(title, message, icon, 5000);
    notificationHistory->addItem(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss") + " - " + title + ": " + message);
}
void MainWindow::checkLowStock(const QString &productName, int stockLevel)
{
    int lowStockThreshold = 5;  // Seuil pour un stock faible
    if (stockLevel <= lowStockThreshold) {
        QString title = "Alerte Stock Faible";
        QString message = QString("Le stock de %1 est faible. Il ne reste que %2 unités.").arg(productName).arg(stockLevel);
        notifyUser(title, message, QSystemTrayIcon::Warning);
    }
}

void MainWindow::showNotificationInLayout(const QString &title, const QString &message)
{
    // Créez un QLabel pour le message
    QLabel *notificationLabel = new QLabel(message, this);
    notificationLabel->setStyleSheet("color: green; font-size: 14px;");

    // Ajoutez le QLabel au layout principal
    ui->centralLayout->addWidget(notificationLabel);

    // Mettre à jour l'affichage
    ui->centralLayout->update();

    // Supprimez automatiquement le QLabel après 5 secondes
    QTimer::singleShot(5000, notificationLabel, &QLabel::deleteLater);

    // Afficher une notification dans la zone système
    if (trayIcon) {
        trayIcon->showMessage(title, message, QSystemTrayIcon::Information, 5000);
    } else {
        qDebug() << "TrayIcon non initialisé.";
    }
}
void MainWindow::updateHistoryTable() {
    ui->historyTable->setRowCount(0); // Vide la table d’historique

    for (int i = 0; i < historyList.size(); ++i) {
        ui->historyTable->insertRow(i);

        // Colonne 1 : Action (Ajout ou Suppression)
        ui->historyTable->setItem(i, 0, new QTableWidgetItem(historyList[i].first));
        // Colonne 2 : Détails
        ui->historyTable->setItem(i, 1, new QTableWidgetItem(historyList[i].second));
    }
}
void MainWindow::onRowSelected(const QModelIndex &current, const QModelIndex &previous)
{
    // Vérifiez si la ligne sélectionnée est valide
    if (current.isValid()) {
        // Récupérer les données de la ligne sélectionnée
        int stockId = ui->tableWidget->model()->index(current.row(), 0).data().toInt();  // ID dans la première colonne
        QString name = ui->tableWidget->model()->index(current.row(), 1).data().toString(); // Nom dans la deuxième colonne
        int quantity = ui->tableWidget->model()->index(current.row(), 2).data().toInt();   // Quantité dans la troisième colonne
        QString type = ui->tableWidget->model()->index(current.row(), 3).data().toString(); // Type dans la quatrième colonne
        QString conditions = ui->tableWidget->model()->index(current.row(), 4).data().toString(); // Conditions

        // Remplir les champs d'entrée avec les valeurs de la ligne sélectionnée
        ui->type->setText(name);
        ui->quant->setText(QString::number(quantity));
        ui->idEmploye->setText(QString::number(stockId)); // Si nécessaire
        ui->l4_2->setText(conditions); // Ajouter un champ pour les conditions si nécessaire

        // Activer le bouton "Modifier"
        ui->updateButton->setEnabled(true);
    } else {
        // Désactiver le bouton "Modifier" si aucune ligne n'est sélectionnée
        ui->updateButton->setEnabled(false);
    }
}

void MainWindow::on_modifyButton_clicked() {
    // Vérification de la ligne sélectionnée
    QModelIndex selectedIndex = ui->tableWidget->selectionModel()->currentIndex();
    if (selectedIndex.isValid()) {
        // Récupération des informations de la ligne sélectionnée
        int stockId = ui->tableWidget->model()->index(selectedIndex.row(), 0).data().toInt();  // ID du stock
        QString newName = ui->type->text();  // Nouveau nom
        int newQuantity = ui->quant->text().toInt();  // Nouvelle quantité
        QString newConditions = ui->l4_2->text();  // Nouvelles conditions
        int employeeId = ui->idEmploye->text().toInt();  // Champ pour l'ID de l'employé (ajustez selon votre UI)

        // Validation des champs avant la mise à jour
        if (newName.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Le nom ne peut pas être vide.");
            return;
        }
        if (newQuantity <= 0) {
            QMessageBox::warning(this, "Erreur", "La quantité doit être positive.");
            return;
        }
        if (newConditions.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Les conditions ne peuvent pas être vides.");
            return;
        }
        if (employeeId <= 0) {
            QMessageBox::warning(this, "Erreur", "L'ID de l'employé doit être valide.");
            return;
        }

        // Vérification de l'existence de l'employé dans la table des employés
        QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM EMPLOYEES WHERE EMPLOYEE_ID = :employeeId");
        query.bindValue(":employeeId", employeeId);

        if (query.exec() && query.next() && query.value(0).toInt() == 0) {
            // L'employé n'existe pas
            QMessageBox::warning(this, "Erreur", "L'employé associé n'existe pas.");
            return;
        }

        // Création de l'objet Stock et mise à jour
        stock.setStockId(stockId);
        stock.setName(newName);
        stock.setQuantity(newQuantity);
        stock.setConditions(newConditions);
        stock.setEmployeeId(employeeId);  // Assurez-vous que cet ID est utilisé correctement

        // Mise à jour dans la base de données
        if (stock.updateStock()) {
            refreshTable();  // Rafraîchissement de la table après la mise à jour
            showNotificationInLayout("Mise à jour réussie", "Les informations du stock ont été mises à jour avec succès.");
        } else {
            QMessageBox::warning(this, "Erreur", "Échec de la mise à jour du stock.");
        }
    } else {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une ligne à modifier.");
    }
}

void MainWindow::on_sauvegarder1_clicked() {
    qDebug() << "Début de l'ajout de stock.";

    // Récupération des données de l'interface

    stock.setStockId(ui->l1_3->text().toInt());
    stock.setName(ui->l1_2->text());
    stock.setQuantity(ui->quant->text().toInt());
    stock.setType(ui->type->text());  // Remplacez par la valeur correcte
    stock.setConditions(ui->l4_2->text());
    stock.setEntryDate(QDate::currentDate());
    stock.setEmployeeId(ui->idEmploye->text().toInt());
    stock.setPrenom(ui->prenomEmploye->text());

    qDebug() << "Données récupérées : " << stock.getName() << stock.getQuantity()<<stock.getStockId()<<stock.getPrenom()<<stock.getConditions()<<stock.getEntryDate()<<stock.getEmployeeId()<<stock.getType()<<stock.getNotifications();

    if (stock.addStock()) {
        // Mise à jour du tableau principal
        refreshTable();
        showNotificationInLayout("Succès", "Stock ajouté avec succès !");

        // Enregistrement dans l'historique
        QString details = QString("Produit : %1, Quantité : %2, Employé : %3,Prenom: %4")
                              .arg(stock.getName())
                              .arg(stock.getQuantity())
                              .arg(stock.getEmployeeId())
                              .arg(stock.getPrenom());
        historyList.append(qMakePair("Ajout", details)); // Ajout à l'historique
        updateHistoryTable(); // Met à jour l'affichage de l'historique

        qDebug() << "Historique mis à jour : " << details;

    } else {
        showNotificationInLayout("Erreur", "Erreur lors de l'ajout du stock.");
    }
}
void MainWindow::refreshTable()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    // Requête SQL pour récupérer tous les stocks
    QSqlQuery query;
    query.prepare("SELECT STOCK_ID, NAME_STOCK, QUANTITY_STOCK, TYPE_STOCK, CONDITION_STOCK, ENTRY_DATE_STOCK, EMPLOYEE_ID,PRENOM FROM STOCKS");

    if (query.exec()) {
        model->setQuery(query);
        ui->tableWidget->setModel(model); // Associe le modèle à l'affichage
        qDebug() << "Table rafraîchie avec succès.";
    } else {
        qDebug() << "Erreur lors du rafraîchissement de la table : " << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Impossible de rafraîchir les stocks : " + query.lastError().text());
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::setupBackgroundMusic() {
    // Create a media player and audio output for background music
    QMediaPlayer *player = new QMediaPlayer(this);
    QAudioOutput *audioOutput = new QAudioOutput(this);

    // Set the audio output to the player
    player->setAudioOutput(audioOutput);
    audioOutput->setVolume(0.5); // Set volume level

    // Set the music file
    player->setSource(QUrl::fromLocalFile("C:\\Users\\youss\\OneDrive\\Bureau\\Interfaces Ateliers\\Nouveau dossier\\Atelier_Connexion\\.mp3"));

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
        refreshTable4();
    } else {
        QMessageBox::warning(this, "Error", "Failed to add complaint.");
    }
}


void MainWindow::refreshTable4() {
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

        refreshTable4();
    } else {
        QMessageBox::warning(this, "Update Failed", "Failed to update COMPLAINT.");
    }
}


void MainWindow::on_deleteButton_clicked() {
    int id = ui->seearchLine_6->text().toInt();
    COMPLAINTS res;
    if (res.supprimer(id)) {
        QMessageBox::information(this, "Success", "COMPLAINT deleted successfully!");
        refreshTable4();
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
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon("C:\\Users\\msi\\Downloads\\search_10023603")); // Remplacez par le chemin de votre icône
    trayIcon->show();


    notificationHistory = new QListWidget(this); // Créez l'objet
    ui->centralLayout->addWidget(notificationHistory);
    ui->historyTable->setColumnCount(2);
    ui->historyTable->setHorizontalHeaderLabels(QStringList() << "Action" << "Détails");

    setupConnections();
    connect(ui->sort, &QPushButton::clicked, this, &MainWindow::on_sort_clicked);
    connect(ui->exportToPDF, &QPushButton::clicked, this, &MainWindow::exportToPDF);
    connect(ui->showStatistics, &QPushButton::clicked, this, &MainWindow::showStatistics);
    connect(ui->tableWidget->selectionModel(), &QItemSelectionModel::currentChanged,
            this, &MainWindow::onRowSelected);
    connect(ui->updateButton, &QPushButton::clicked, this, &MainWindow::on_modifyButton_clicked);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_SaveButton_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::on_Ajouter_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::on_Afficher_clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::on_DeleteButton_clicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::on_EditButton_clicked);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::on_pushButton_6_clicked);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::on_pushButton_7_clicked);
    //connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::on_pushButton_8_clicked);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::on_pushButton_9_clicked);
    connect(ui->pushButton_10, &QPushButton::clicked, this, &MainWindow::on_pushButton_10_clicked);
    connect(ui->pushButton_11, &QPushButton::clicked, this, &MainWindow::on_pushButton_11_clicked);
    //connect(ui->pushButton_12, &QPushButton::clicked, this, &MainWindow::on_pushButton_12_clicked);

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
    //setupBackgroundMusic();
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
    //border: 1px solid #666;
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
    refreshTable4();
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
void MainWindow::on_pushButton_Confirmer_clicked()
{
    QString email = ui->mailLogin->text();
    QString mot_de_passe = ui->lineEdit_2->text();
    ui->groupBox->setVisible(false);

    // Vérification des identifiants codés en dur
    if (email == "oracle" && mot_de_passe == "oracle") {
        isAuthenticated = true; // Définir le drapeau d'authentification
            ui->groupBox->setVisible(true);
        // Afficher la fenêtre principale (ou le contenu en bas)
        //ui->label_27->show();

        // Afficher le premier onglet du QTabWidget
        ui->stackedWidget->setCurrentIndex(1); // Change to the first tab (index 0)
    } else {
        QMessageBox::warning(this, "Échec de la connexion", "Email ou mot de passe invalide. Veuillez réessayer.");

    }
}



void MainWindow::on_btn_eye_clicked() {
        isPasswordVisible = true;

    if (isPasswordVisible) {
        ui->lineEdit_2->setEchoMode(QLineEdit::Password); // Masquer les caractères
        isPasswordVisible = false;
    } else {
        ui->lineEdit_2->setEchoMode(QLineEdit::Normal); // Afficher les caractères
        isPasswordVisible = true;
    }
}


MainWindow::~MainWindow() {
    delete ui;
}
