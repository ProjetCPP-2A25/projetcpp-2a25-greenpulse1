#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class date {
private:
    int dd;
    int mm;
    int yyyy;

public:
    // Default constructor
    date() : dd(0), mm(0), yyyy(0) {}  // Initializes date to a default of 0-0-0

    // Parameterized constructor
    date(int dd, int mm, int yyyy) : dd(dd), mm(mm), yyyy(yyyy) {}

    QString toString(const QString& format) const {
        if (format == "yyyy-mm-dd") {
            return QString("%1-%2-%3").arg(yyyy).arg(mm, 2, 10, QChar('0')).arg(dd, 2, 10, QChar('0'));
        }
        return QString();
    }

    int getdd() const { return dd; }
    int getmm() const { return mm; }
    int getyyyy() const { return yyyy; }

    // Setter methods
    void setdd(int jj) { this->dd = jj; }
    void setmm(int mm) { this->mm = mm; }
    void setyyyy(int y) { this->yyyy = y; }
};

class Employee {
private:
    int EMPLOYEE_ID;
    QString LAST_NAME_EMPLOYEE;
    QString FIRST_NAME_EMPLOYEE;
    QString ROLE_EMPLOYEE;
    QString EMAIL_EMPLOYEE;
    int PHONE_EMPLOYEE;
    date HIRE_DATE_EMPLOYEE;
    QString STATUS_EMPLOYEE;
public:
    // Constructors
    Employee();
    Employee(int, QString, QString, QString, QString, int, date, QString);

    // Getters
    int getEMPLOYEE_ID() { return EMPLOYEE_ID; }
    QString getLAST_NAME_EMPLOYEE() { return LAST_NAME_EMPLOYEE;}
    QString getFIRST_NAME_EMPLOYEE() { return FIRST_NAME_EMPLOYEE; }
    QString getROLE_EMPLOYEE() { return ROLE_EMPLOYEE; }
    QString getEMAIL_EMPLOYEE() { return EMAIL_EMPLOYEE; }
    int getPHONE_EMPLOYEE() { return PHONE_EMPLOYEE; }
    date getHIRE_DATE_EMPLOYEE() { return HIRE_DATE_EMPLOYEE; }
    QString getSTATUS_EMPLOYEE() { return STATUS_EMPLOYEE; }

    // Setters
    void setEMPLOYEE_ID(int EmpID) { EMPLOYEE_ID = EmpID; }
    void setLAST_NAME_EMPLOYEE(QString LastName) { LAST_NAME_EMPLOYEE = LastName; }
    void setFIRST_NAME_EMPLOYEE(QString FirstName) { FIRST_NAME_EMPLOYEE = FirstName; }
    void setROLE_EMPLOYEE(QString Role) { ROLE_EMPLOYEE = Role; }
    void setEMAIL_EMPLOYEE(QString Email) { EMAIL_EMPLOYEE = Email; }
    void setPHONE_EMPLOYEE(int Phone) { PHONE_EMPLOYEE = Phone; }
    void setHIRE_DATE_EMPLOYEE(date DateH) { HIRE_DATE_EMPLOYEE = DateH; }
    void setSTATUS_EMPLOYEE(QString Status) { STATUS_EMPLOYEE = Status; }

    bool Ajouter();
    QSqlQueryModel* Afficher();
    bool Modifier(int EmpID, QString LastName, QString FirstName, QString Role, QString Email, int Phone, date DateH, QString Status);
    bool Supprimer(int);
    // QSqlQueryModel* Rechercher(int);
};

#endif // EMPLOYEE_H
