#include "complaints.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QRegularExpression>
#include <QProcess>

// Default constructor, now includes FILE_PATH
COMPLAINTS::COMPLAINTS()
    : COMPLAINT_ID(0),
    DESCRIPTION_COMPLAINT(""),
    ACTIONS_COMPLAINT(""),
    ORDER_ID(0),
    EMPLOYEE_ID(0),
    SUPPLIER_ID(0),
    COMPLAINT_DATE(datee(QDate::currentDate().year(), QDate::currentDate().month(), QDate::currentDate().day())),
    FILE_PATH(""), // Initialize FILE_PATH to an empty string
    COMPLAINT_TYPE(0)
{
}

// Parameterized constructor, includes FILE_PATH
COMPLAINTS::COMPLAINTS(int id, QString description, QString actions, int idorder, int idemployee, int idsupplier, datee datecomp, QString filePath,int typ)
    : COMPLAINT_ID(id),
    DESCRIPTION_COMPLAINT(description),
    ACTIONS_COMPLAINT(actions),
    ORDER_ID(idorder),
    EMPLOYEE_ID(idemployee),
    SUPPLIER_ID(idsupplier),
    COMPLAINT_DATE(datecomp),
    FILE_PATH(filePath),
COMPLAINT_TYPE(typ)// Initialize FILE_PATH with the passed value

{
}
QSqlQueryModel* COMPLAINTS::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM COMPLAINTS");
    return model;
}
// Ajouter function, now includes FILE_PATH in the SQL insertion
bool COMPLAINTS::ajouter() {
    // Vérification que COMPLAINT_ID est un nombre de 8 chiffres
    QString idStr = QString::number(COMPLAINT_ID);
    if (idStr.length() != 8 || !idStr.contains(QRegularExpression("^[0-9]{8}$"))) {
        qDebug() << "Invalid COMPLAINT_ID: It must be exactly 8 digits.";
        return false; // Retourne faux si la vérification échoue
    }

    // Vérifier que le SUPPLIER_ID existe
    QSqlQuery checkSupplier;
    checkSupplier.prepare("SELECT COUNT(*) FROM SUPPLIERS WHERE SUPPLIER_ID = :supplier_id");
    checkSupplier.bindValue(":supplier_id", SUPPLIER_ID);

    if (!checkSupplier.exec() || !checkSupplier.next() || checkSupplier.value(0).toInt() == 0) {
        qDebug() << "Supplier ID does not exist:" << SUPPLIER_ID;
        return false; // Retourner ou gérer l'erreur selon les besoins
    }

    // Préparation de la requête d'insertion, including FILE_PATH
    QSqlQuery query;
    query.prepare("INSERT INTO COMPLAINTS (COMPLAINT_ID, DESCRIPTION_COMPLAINT, ACTIONS_COMPLAINT, ORDER_ID, EMPLOYEE_ID, SUPPLIER_ID, COMPLAINT_DATE, FILE_PATH,COMPLAINT_TYPE) "
                  "VALUES (:COMPLAINT_ID, :DESCRIPTION_COMPLAINT, :ACTIONS_COMPLAINT, :ORDER_ID, :EMPLOYEE_ID, :SUPPLIER_ID, :COMPLAINT_DATE, :FILE_PATH,:COMPLAINT_TYPE)");

    // Liaison des valeurs
    query.bindValue(":COMPLAINT_ID", COMPLAINT_ID);
    query.bindValue(":DESCRIPTION_COMPLAINT", DESCRIPTION_COMPLAINT);
    query.bindValue(":ACTIONS_COMPLAINT", ACTIONS_COMPLAINT);
    query.bindValue(":COMPLAINT_DATE", QDate(COMPLAINT_DATE.getaaaa(), COMPLAINT_DATE.getmm(), COMPLAINT_DATE.getjj()));
    query.bindValue(":ORDER_ID", ORDER_ID);
    query.bindValue(":EMPLOYEE_ID", EMPLOYEE_ID);
    query.bindValue(":SUPPLIER_ID", SUPPLIER_ID);
    query.bindValue(":FILE_PATH", FILE_PATH); // Bind the FILE_PATH value
    query.bindValue(":COMPLAINT_TYPE", COMPLAINT_TYPE); // Bind the FILE_PATH value


    // Exécuter la requête d'insertion
    if (!query.exec()) {
        qDebug() << "Error adding complaint:" << query.lastError().text();
        return false; // Retourne false si l'insertion échoue
    }

    return true; // Retourne true si l'insertion réussit
}

// Modifier function, includes FILE_PATH in the SQL update
bool COMPLAINTS::modifier(int id, const QString& actions, const QString& description, int orderid, int supplierid, int employeeid, const datee& datt,const QString& filePath) {
    QSqlQuery query;
    query.prepare("UPDATE COMPLAINTS SET ACTIONS_COMPLAINT = :actions, DESCRIPTION_COMPLAINT = :description, ORDER_ID = :orderid, EMPLOYEE_ID = :employeeid, SUPPLIER_ID = :supplierid, COMPLAINT_DATE = :datt, FILE_PATH = :filePath WHERE COMPLAINT_ID = :id");

    query.bindValue(":id", id);
    query.bindValue(":orderid", orderid);
    query.bindValue(":employeeid", employeeid);
    query.bindValue(":supplierid", supplierid);
    query.bindValue(":datt", QDate(datt.getaaaa(), datt.getmm(), datt.getjj()));
    query.bindValue(":actions", actions);
    query.bindValue(":description", description);
    query.bindValue(":filePath", filePath);


    if (!query.exec()) {
        qDebug() << "Error updating complaint:" << query.lastError().text();
        return false;
    }

    return true; // Return true if the update is successful
}

// Supprimer function (no changes needed for FILE_PATH)
bool COMPLAINTS::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM COMPLAINTS WHERE COMPLAINT_ID = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Error deleting complaint:" << query.lastError().text();
        return false;
    }
    return true;
}

// Rechercher function (no changes needed for FILE_PATH)
QSqlQueryModel* COMPLAINTS::rechercher(int id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM COMPLAINTS WHERE COMPLAINT_ID = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Query execution failed:" << query.lastError().text();
        return nullptr;
    }

    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);

    return model;
}
