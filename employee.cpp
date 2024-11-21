#include "employee.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

Employee::Employee(int EmpID, QString LastName, QString FirstName, QString Role, QString Email, int Phone, date DateH, QString Status)
{
    this->EMPLOYEE_ID = EmpID;
    this->LAST_NAME_EMPLOYEE = LastName;
    this->FIRST_NAME_EMPLOYEE = FirstName;
    this->ROLE_EMPLOYEE = Role;
    this->EMAIL_EMPLOYEE = Email;
    this->PHONE_EMPLOYEE = Phone;
    this->HIRE_DATE_EMPLOYEE = DateH;
    this->STATUS_EMPLOYEE = Status;
}
Employee::Employee()
    : EMPLOYEE_ID(0), PHONE_EMPLOYEE(0), LAST_NAME_EMPLOYEE(""), FIRST_NAME_EMPLOYEE(""),
    ROLE_EMPLOYEE(""), EMAIL_EMPLOYEE(""), STATUS_EMPLOYEE(""), HIRE_DATE_EMPLOYEE(date()) {
    // Default constructor initializes members with default values
}


bool Employee::Ajouter() {
    // Query declaration
    QSqlQuery EmpQuery;
    EmpQuery.prepare("INSERT INTO EMPLOYEES (EMPLOYEE_ID, LAST_NAME_EMPLOYEE, FIRST_NAME_EMPLOYEE, ROLE_EMPLOYEE, EMAIL_EMPLOYEE, PHONE_EMPLOYEE, HIRE_DATE_EMPLOYEE, STATUS_EMPLOYEE) "
                     "VALUES (:EMPLOYEE_ID, :LAST_NAME_EMPLOYEE, :FIRST_NAME_EMPLOYEE, :ROLE_EMPLOYEE, :EMAIL_EMPLOYEE, :PHONE_EMPLOYEE, :HIRE_DATE_EMPLOYEE, :STATUS_EMPLOYEE)");

    // Binding values
    EmpQuery.bindValue(":EMPLOYEE_ID", EMPLOYEE_ID);
    EmpQuery.bindValue(":LAST_NAME_EMPLOYEE", LAST_NAME_EMPLOYEE);
    EmpQuery.bindValue(":FIRST_NAME_EMPLOYEE", FIRST_NAME_EMPLOYEE);
    EmpQuery.bindValue(":ROLE_EMPLOYEE", ROLE_EMPLOYEE);
    EmpQuery.bindValue(":EMAIL_EMPLOYEE", EMAIL_EMPLOYEE);
    EmpQuery.bindValue(":PHONE_EMPLOYEE", PHONE_EMPLOYEE);
    EmpQuery.bindValue(":HIRE_DATE_EMPLOYEE", QDate(HIRE_DATE_EMPLOYEE.getyyyy(), HIRE_DATE_EMPLOYEE.getmm(), HIRE_DATE_EMPLOYEE.getdd()));
    EmpQuery.bindValue(":STATUS_EMPLOYEE", STATUS_EMPLOYEE);

    // Execute the insertion query
    if (!EmpQuery.exec()) {
        qDebug() << "Error adding employee:" << EmpQuery.lastError().text();
        return false; // Return false if the insertion fails
    }

    qDebug() << "Employee added successfully!";
    return true; // Return true if the insertion is successful
}
QSqlQueryModel* Employee::Afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query;

    query.prepare("SELECT EMPLOYEE_ID, LAST_NAME_EMPLOYEE, FIRST_NAME_EMPLOYEE, ROLE_EMPLOYEE, EMAIL_EMPLOYEE, PHONE_EMPLOYEE, HIRE_DATE_EMPLOYEE, STATUS_EMPLOYEE FROM employees");

    if (query.exec()) {
        model->setQuery(query);
    }
    return model;
}
bool Employee::Supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM employees WHERE EMPLOYEE_ID = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Error deleting employee:" << query.lastError().text();
        return false;
    }
    return true;
}



