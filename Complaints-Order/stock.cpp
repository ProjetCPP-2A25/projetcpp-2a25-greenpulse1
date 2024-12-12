#include "stock.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVariant>
#include <QDebug>
#include <QSqlError>
#include <QDateTime>
#include "mainwindow.h"
#include "qapplication.h"

Stock::Stock() : stockId(5), quantity(0), employeeId(0) {}

Stock::~Stock() {}

int Stock::getStockId() const { return stockId; }
void Stock::setStockId(int id) { stockId = id; }

QString Stock::getName() const { return name; }
void Stock::setName(const QString &name) { this->name = name; }

int Stock::getQuantity() const { return quantity; }
void Stock::setQuantity(int quantity) { this->quantity = quantity; }

QString Stock::getType() const { return type; }
void Stock::setType(const QString &type) { this->type = type; }

QString Stock::getConditions() const { return conditions; }
void Stock::setConditions(const QString &conditions) { this->conditions = conditions; }

QDate Stock::getEntryDate() const { return entryDate; }
void Stock::setEntryDate(const QDate &date) { this->entryDate = date; }

int Stock::getEmployeeId() const { return employeeId; }
void Stock::setEmployeeId(int employeeId) { this->employeeId = employeeId; }

QString Stock::getPrenom() const { return prenom; }
void Stock::setPrenom(const QString &prenom) { this->prenom = prenom; }

bool Stock::addStock()
{
    QSqlQuery query;
    query.prepare("INSERT INTO STOCKS (STOCK_ID, NAME_STOCK, QUANTITY_STOCK, TYPE_STOCK, CONDITION_STOCK, ENTRY_DATE_STOCK, EMPLOYEE_ID, PRENOM) "
                  "VALUES (:stock_id, :name, :quantity, :type, :conditions, :entry_date, :employee_id, :prenom)");
    query.bindValue(":stock_id", stockId);
    query.bindValue(":name", name);
    query.bindValue(":quantity", quantity);
    query.bindValue(":type", type);
    query.bindValue(":conditions", conditions);
    query.bindValue(":entry_date", entryDate);
    query.bindValue(":employee_id", employeeId);
    query.bindValue(":prenom", prenom);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout du stock : " << query.lastError().text();
        return false;
    }

    return true;
}

bool Stock::updateStock()
{
    QSqlQuery query;
    QSqlQuery oldQuery;
    oldQuery.prepare("SELECT quantity FROM STOCKS WHERE stock_id = :stock_id");
    oldQuery.bindValue(":stock_id", stockId);
    oldQuery.exec();
    oldQuery.next();
    int oldQuantity = oldQuery.value(0).toInt();

    query.prepare("UPDATE STOCKS SET name = :name, quantity = :quantity, type = :type, "
                  "conditions = :conditions, entry_date = :entry_date, employee_id = :employee_id, prenom = :prenom "
                  "WHERE stock_id = :stock_id");

    query.bindValue(":stock_id", stockId);
    query.bindValue(":name", name);
    query.bindValue(":quantity", quantity);
    query.bindValue(":type", type);
    query.bindValue(":conditions", conditions);
    query.bindValue(":entry_date", entryDate.toString("yyyy-MM-dd"));
    query.bindValue(":employee_id", employeeId);
    query.bindValue(":prenom", prenom);

    if (query.exec()) {
        QSqlQuery historyQuery;
        historyQuery.prepare("INSERT INTO stock_history (stock_id, action_type, old_quantity, new_quantity, action_date, description) "
                             "VALUES (:stock_id, :action_type, :old_quantity, :new_quantity, :action_date, :description)");
        historyQuery.bindValue(":stock_id", stockId);
        historyQuery.bindValue(":action_type", "mise à jour");
        historyQuery.bindValue(":old_quantity", oldQuantity);
        historyQuery.bindValue(":new_quantity", quantity);
        historyQuery.bindValue(":action_date", QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
        historyQuery.bindValue(":description", "Mise à jour de la quantité");

        if (!historyQuery.exec()) {
            qDebug() << "Erreur lors de l'insertion de l'historique : " << historyQuery.lastError();
        }

        return true;
    }
    return false;
}

bool Stock::deleteStock(int stockId)
{
    QSqlQuery query;
    QSqlQuery oldQuery;
    oldQuery.prepare("SELECT quantity FROM STOCKS WHERE stock_id = :stock_id");
    oldQuery.bindValue(":stock_id", stockId);
    oldQuery.exec();
    oldQuery.next();
    int oldQuantity = oldQuery.value(0).toInt();

    query.prepare("DELETE FROM STOCKS WHERE stock_id = :stock_id");
    query.bindValue(":stock_id", stockId);

    if (query.exec()) {
        QSqlQuery historyQuery;
        historyQuery.prepare("INSERT INTO stock_history (stock_id, action_type, old_quantity, new_quantity, action_date, description) "
                             "VALUES (:stock_id, :action_type, :old_quantity, :new_quantity, :action_date, :description)");
        historyQuery.bindValue(":stock_id", stockId);
        historyQuery.bindValue(":action_type", "suppression");
        historyQuery.bindValue(":old_quantity", oldQuantity);
        historyQuery.bindValue(":new_quantity", 0);
        historyQuery.bindValue(":action_date", QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
        historyQuery.bindValue(":description", "Suppression du stock");

        if (!historyQuery.exec()) {
            qDebug() << "Erreur de suppression dans l'historique : " << historyQuery.lastError().text();
        }

        return true;
    } else {
        qDebug() << "Erreur de suppression : " << query.lastError().text();
        return false;
    }
}

QSqlQueryModel* Stock::displayStocks()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query("SELECT STOCK_ID, NAME_STOCK, QUANTITY_STOCK, TYPE_STOCK, CONDITION_STOCK, ENTRY_DATE_STOCK, EMPLOYEE_ID FROM STOCKS");
    if (!query.exec()) {
        qDebug() << "Erreur lors de la récupération des stocks : " << query.lastError().text();
        delete model;
        return nullptr;
    }
    model->setQuery(query);
    return model;
}

QSqlQueryModel* Stock::searchStock(int id)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM STOCKS WHERE stock_id = :stock_id");
    query.bindValue(":stock_id", id);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();
        return nullptr;
    }

    model->setQuery(query);
    return model;
}

void Stock::logNotification(const QString &title, const QString &message)
{
    QSqlQuery query;
    query.prepare("INSERT INTO notifications (title, message) VALUES (:title, :message)");
    query.bindValue(":title", title);
    query.bindValue(":message", message);
    query.exec();
}

QSqlQueryModel* Stock::getNotifications()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query("SELECT * FROM notifications ORDER BY timestamp DESC");
    model->setQuery(query);
    return model;
}
