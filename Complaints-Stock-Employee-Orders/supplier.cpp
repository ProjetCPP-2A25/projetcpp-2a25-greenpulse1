#include "supplier.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QString>
supplier::supplier()
    :
    SUPPLIER_ID(1),
    NAME_SUPPLIER(""),
    TYPE_SUPPLIER(""),
    PHONE_SUPPLIER(""),
    EMAIL_SUPPLIER(""),
    RATING(1)
{}
bool supplier::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO SUPPLIERS (SUPPLIER_ID, NAME_SUPPLIER, TYPE_SUPPLIER, PHONE_SUPPLIER, EMAIL_SUPPLIER) "
                  "VALUES (:SUPPLIER_ID, :NAME_SUPPLIER, :TYPE_SUPPLIER, :PHONE_SUPPLIER, :EMAIL_SUPPLIER ,RATING(rating))");

    query.bindValue(":SUPPLIER_ID", SUPPLIER_ID);
    query.bindValue(":NAME_SUPPLIER", NAME_SUPPLIER);
    query.bindValue(":TYPE_SUPPLIER", TYPE_SUPPLIER);
    query.bindValue(":PHONE_SUPPLIER", PHONE_SUPPLIER);
    query.bindValue(":EMAIL_SUPPLIER", EMAIL_SUPPLIER);
    query.bindValue(":RATING", RATING);
    if (!query.exec()) {
        qDebug() << "Erreur d'ajout du fournisseur:" << query.lastError().text();
        return false;
    }



    return true;
}


QSqlQueryModel *supplier::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query;
    query.prepare("SELECT * FROM suppliers"); // Ajustez votre requête
    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();
        return nullptr;
    }
    model->setQuery(query);
    return model;
}



bool supplier::modifier(int id, QString &email, const QString &phone)
{
    QSqlQuery query;
    query.prepare("UPDATE SUPPLIERS SET  "
                  "PHONE_SUPPLIER = :phone, EMAIL_SUPPLIER = :email WHERE SUPPLIER_ID = :id");

    query.bindValue(":id", id);

    query.bindValue(":phone", phone);  // Ici, 'phone' est un QString
    query.bindValue(":email", email);

    if (!query.exec()) {
        qDebug() << "Error updating supplier:" << query.lastError().text();
        return false;
    }
    return true;
}


bool supplier::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM SUPPLIERS WHERE SUPPLIER_ID = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Error deleting supplier:" << query.lastError().text();
        return false;
    }
    return true;
}
QSqlQueryModel* supplier::rechercher(int id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM SUPPLIERS WHERE SUPPLIER_ID = :id"); // Requête pour rechercher un fournisseur par ID
    query.bindValue(":id", id);  // Bind de l'ID au paramètre

    if (!query.exec()) {
        // Si la requête échoue, afficher une erreur
        qDebug() << "Query execution failed:" << query.lastError().text();
        return nullptr;  // Retourner null en cas d'erreur
    }

    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);  // Affecter les résultats de la requête à un modèle
    return model;  // Retourner le modèle contenant les résultats
}


bool supplier::modifierRating(int id, int rating) {
    QSqlQuery query;
    query.prepare("UPDATE SUPPLIERS SET RATING = :rating WHERE SUPPLIER_ID = :id");
    query.bindValue(":id", id);
    query.bindValue(":rating", rating);
    if (rating < 1 || rating > 5) {
        qDebug() << "Rating must be between 1 and 5!";
        return false;
    }


    if (!query.exec()) {
        qDebug() << "Error updating rating:" << query.lastError().text();
        return false;
    }
    return true;
}

QSqlQueryModel* supplier::afficherSortedByRating(int rating) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    // Requête SQL pour récupérer les fournisseurs avec un rating spécifique
    query.prepare("SELECT * FROM SUPPLIERS WHERE RATING = :rating ORDER BY RATING DESC");
    query.bindValue(":rating", rating);

    if (!query.exec()) {
        qDebug() << "Error fetching suppliers by rating:" << query.lastError().text();
        return nullptr;
    }

    model->setQuery(query);
    return model;
}

QSqlQueryModel* supplier::afficherSortedByRatingDescending()
{
    // Créer un modèle pour afficher les résultats de la requête
    QSqlQueryModel* model = new QSqlQueryModel();

    // Requête SQL pour récupérer les suppliers triés par rating décroissant
    QString query = "SELECT * FROM suppliers ORDER BY rating DESC"; // Assurez-vous que 'rating' est la bonne colonne
    model->setQuery(query);

    // Vérifier si la requête a échoué
    if (model->lastError().isValid()) {
        qDebug() << "Erreur SQL: " << model->lastError();
    }

    return model;
}
QSqlQueryModel* supplier::afficherSortedByRatingAscending()
{
    // Créer un modèle pour afficher les résultats de la requête
    QSqlQueryModel* model = new QSqlQueryModel();

    // Requête SQL pour récupérer les suppliers triés par rating croissant
    QString query = "SELECT * FROM suppliers ORDER BY rating ASC"; // Tri par rating croissant
    model->setQuery(query);

    // Vérifier si la requête a échoué
    if (model->lastError().isValid()) {
        qDebug() << "Erreur SQL: " << model->lastError();
    }

    return model;
}

