#ifndef STOCK_H
#define STOCK_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>

class Stock
{
public:
    Stock();
    ~Stock();

    int getStockId() const;
    void setStockId(int id);

    QString getName() const;
    void setName(const QString &name);

    int getQuantity() const;
    void setQuantity(int quantity);

    QString getType() const;
    void setType(const QString &type);

    QString getConditions() const;
    void setConditions(const QString &conditions);

    QDate getEntryDate() const;
    void setEntryDate(const QDate &date);

    int getEmployeeId() const;
    void setEmployeeId(int employeeId);

    QString getPrenom() const;
    void setPrenom(const QString &prenom);

    bool addStock();
    bool updateStock();
    bool deleteStock(int stockId);
    QSqlQueryModel* displayStocks();
    QSqlQueryModel* searchStock(int id);

    void logNotification(const QString &title, const QString &message);  // Enregistrer une notification
    QSqlQueryModel* getNotifications();  // Récupérer l'historique des notifications
    void addToHistory_recherch(const QString &action, int id);  // Ajouter à l'historique

private:
    int stockId;
    QString name;
    int quantity;
    QString type;
    QString conditions;
    QDate entryDate;
    int employeeId;
    QString prenom;
};

#endif // STOCK_H
