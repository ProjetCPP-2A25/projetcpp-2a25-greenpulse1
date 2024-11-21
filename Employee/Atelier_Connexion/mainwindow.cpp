#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employee.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QGraphicsView>
#include <QtCharts>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QVBoxLayout>
#include <QPainter>
#include <QPrinter>
#include <QLabel>
#include <QPixmap>

// Constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString style = "QMessageBox {"
                    "background-color: #2E2E2E;"   // Dark background color
                    "color: black;"                 // White text color
                    "font: bold 14px;"              // Bold text, 14px font size
                    "border-radius: 5px;"           // Rounded corners for the box
                    "padding: 10px;"                // Padding inside the box
                    "}"
                    "QMessageBox QLabel {"
                    "color: black;"                 // Ensure the label text is white too
                    "}"
                    "QMessageBox QPushButton {"
                    "background-color: #3C3F41;"    // Button background color
                    "color: black;"                 // Button text color
                    "border: 1px solid #2A2D2F;"    // Button border color
                    "border-radius: 3px;"           // Rounded corners for buttons
                    "padding: 5px;"                 // Padding for buttons
                    "}";
    // Apply the style to the application
    qApp->setStyleSheet(style);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_SaveButton_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::on_Ajouter_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::on_Afficher_clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::on_DeleteButton_clicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::on_EditButton_clicked);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::on_pushButton_6_clicked);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::on_pushButton_7_clicked);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::on_pushButton_8_clicked);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::on_pushButton_9_clicked);
    connect(ui->pushButton_10, &QPushButton::clicked, this, &MainWindow::on_pushButton_10_clicked);
    connect(ui->pushButton_11, &QPushButton::clicked, this, &MainWindow::on_pushButton_11_clicked);
    connect(ui->pushButton_12, &QPushButton::clicked, this, &MainWindow::on_pushButton_12_clicked);


    ui->label_11->setStyleSheet("QLabel { background-image: url('file:///C:/Users/Lenovo-PC/Desktop/Atelier_Connexion/SearchIcon.jpg'); }");



    ui->tableWidget->setColumnCount(8);  // 8 columns for all employee details
    ui->tableWidget->setHorizontalHeaderLabels({"Employee ID", "Last Name", "First Name", "Role", "Email", "Phone", "Hire Date", "Status"});
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Slot for adding an employee
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
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(EmpID)));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(LastName));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(FirstName));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(Role));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(Email));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(Phone)));
        ui->tableWidget->setItem(row, 6, new QTableWidgetItem(DateH.toString("yyyy-MM-dd")));
        ui->tableWidget->setItem(row, 7, new QTableWidgetItem(Status));

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
    ui->tableWidget->setRowCount(0);

    // Populate `QTableWidget` with data from the model
    for (int row = 0; row < model->rowCount(); ++row) {
        ui->tableWidget->insertRow(row);  // Insert a new row

        for (int col = 0; col < model->columnCount(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(model->data(model->index(row, col)).toString());
            ui->tableWidget->setItem(row, col, item);
        }
    }
}
#include <QMessageBox>

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
            for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
                if (ui->tableWidget->item(row, 0)->text().toInt() == id) {
                    ui->tableWidget->removeRow(row);
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
    int row = ui->tableWidget->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "No Selection", "Please select an employee row to edit.");
        return;
    }

    // Retrieve the current data from the selected row
    int EmpID = ui->tableWidget->item(row, 0)->text().toInt();
    QString LastName = ui->tableWidget->item(row, 1)->text();
    QString FirstName = ui->tableWidget->item(row, 2)->text();
    QString Role = ui->tableWidget->item(row, 3)->text();
    QString Email = ui->tableWidget->item(row, 4)->text();
    int Phone = ui->tableWidget->item(row, 5)->text().toInt();
    QString HireDate = ui->tableWidget->item(row, 6)->text();
    QString Status = ui->tableWidget->item(row, 7)->text();

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
    int row = ui->tableWidget->currentRow();
    ui->tableWidget->item(row, 0)->setText(QString::number(newEmpID));
    ui->tableWidget->item(row, 1)->setText(newLastName);
    ui->tableWidget->item(row, 2)->setText(newFirstName);
    ui->tableWidget->item(row, 3)->setText(newRole);
    ui->tableWidget->item(row, 4)->setText(newEmail);
    ui->tableWidget->item(row, 5)->setText(QString::number(newPhone));
    ui->tableWidget->item(row, 6)->setText(newHireDate);
    ui->tableWidget->item(row, 7)->setText(newStatus);

    // Update the database with the new data
    QSqlQuery query;
    query.prepare("UPDATE employees SET LastName = :lastName, FirstName = :firstName, Role = :role, Email = :email, Phone = :phone, HireDate = :hireDate, Status = :status WHERE EmployeeID = :empID");
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
    // Check if chart window is already open
    if (chartWindow != nullptr) {
        qDebug() << "Chart window is already open.";  // Debugging line
        return;  // Prevent creating another chart window if one is already open
    }

    // Create bar set and populate it with data
    QBarSet *set = new QBarSet("Number Of Employees");
    *set << 3 << 4 << 5 << 2 << 10; // Example data

    // Calculate maximum value
    double maxValue = 0;
    for (int i = 0; i < set->count(); ++i) {
        if (set->at(i) > maxValue) {
            maxValue = set->at(i);
        }
    }

    // Create a bar series and add the data set to it
    QBarSeries *series = new QBarSeries();
    series->append(set);

    // Create the chart
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Employee Statistics");

    // Set up Y axis range
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, maxValue);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Set up categories on X axis if desired
    QStringList categories;
    categories << "2020" << "2021" << "2022" << "2023" << "2024";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Create QChartView for the new window
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Create a new QWidget to display the chart (New window)
    chartWindow = new QWidget(this);  // Make sure to assign to chartWindow
    chartWindow->setWindowTitle("Employee Statistics");
    QVBoxLayout *layout = new QVBoxLayout(chartWindow);
    layout->addWidget(chartView);

    // Show the new window
    chartWindow->resize(800, 600); // You can adjust the size as per your preference
    chartWindow->show();
}
void MainWindow::on_pushButton_8_clicked()
{
    if (chartWindow) {
        qDebug() << "Closing chart window";  // Debug line to confirm the slot is triggered
        chartWindow->close();  // Close the chart window
        chartWindow = nullptr; // Reset the pointer
    } else {
        qDebug() << "No chart window to close";  // Debug line to see if chart window is null
    }
}
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
    ui->tableWidget->setRowCount(0);

    // Query the database to fetch sorted employee data by ID
    QSqlQuery query;
    query.prepare("SELECT EMPLOYEE_ID, LAST_NAME_EMPLOYEE, FIRST_NAME_EMPLOYEE, ROLE_EMPLOYEE, EMAIL_EMPLOYEE, PHONE_EMPLOYEE, HIRE_DATE_EMPLOYEE, STATUS_EMPLOYEE "
                  "FROM employees ORDER BY EMPLOYEE_ID ASC");

    if (query.exec()) {
        int row = 0;

        // Populate the QTableWidget with sorted data
        while (query.next()) {
            ui->tableWidget->insertRow(row);

            for (int col = 0; col < query.record().count(); ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                ui->tableWidget->setItem(row, col, item);
            }
            row++;
        }

        QMessageBox::information(this, "Sort Success", "Employee records sorted by ID.");
    } else {
        QMessageBox::critical(this, "Sort Error", "Failed to sort employees by ID. " + query.lastError().text());
    }
}




