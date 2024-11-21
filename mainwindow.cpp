#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employee.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

// Constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::on_Ajouter_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::on_Afficher_clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::on_DeleteButton_clicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::on_EditButton_clicked);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_SaveButton_clicked);

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
    QDate DateH = QDate::fromString(ui->textEdit_9->toPlainText(), "yyyy-MM-dd");  // Convert to QDate

    date hireDate;
    hireDate.setdd(DateH.day());
    hireDate.setmm(DateH.month());
    hireDate.setyyyy(DateH.year());

    QString Status = ui->textEdit_7->toPlainText();

    Employee newEmployee(EmpID, LastName, FirstName, Role, Email, Phone, hireDate, Status);

    // Add to tableWidget
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(newEmployee.getEMPLOYEE_ID())));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(newEmployee.getLAST_NAME_EMPLOYEE()));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(newEmployee.getFIRST_NAME_EMPLOYEE()));
    ui->tableWidget->setItem(row, 3, new QTableWidgetItem(newEmployee.getROLE_EMPLOYEE()));
    ui->tableWidget->setItem(row, 4, new QTableWidgetItem(newEmployee.getEMAIL_EMPLOYEE()));
    ui->tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(newEmployee.getPHONE_EMPLOYEE())));
    ui->tableWidget->setItem(row, 6, new QTableWidgetItem(newEmployee.getHIRE_DATE_EMPLOYEE().toString("yyyy-MM-dd")));
    ui->tableWidget->setItem(row, 7, new QTableWidgetItem(newEmployee.getSTATUS_EMPLOYEE()));
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
    // Get the employee ID from the input field (e.g., a QLineEdit named `idLineEdit`)
    int id = ui->textEdit->toPlainText().toInt();


    Employee employee;
    if (employee.Supprimer(id)) {
        QMessageBox::information(this, "Delete", "Employee deleted successfully.");
    } else {
        QMessageBox::critical(this, "Delete", "Failed to delete employee. Check the ID or database connection.");
    }
}
void MainWindow::on_EditButton_clicked()
{
    // Get the selected row
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
    int row = ui->tableWidget->currentRow(); // Ensure you update the correct row
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


