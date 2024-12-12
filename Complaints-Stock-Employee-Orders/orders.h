#ifndef ORDERS_H
#define ORDERS_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QDate>
#include <QVector>

class Orders
{
public:
    Orders();
    Orders(int, int, const QDate, const QString,int,QDate);
    int getOrder_id() const { return order_id; }
    int getQuantity() const { return quantity; }
    int getOrder_cost() const { return order_cost; }
    QString getStatus_order() const { return status_order; }
    QDate getOrder_date() const { return order_date; }
    QDate getDelivery_date() const { return delivery_date; }
    void setOrder_id(int ID_ORD) { this->order_id = ID_ORD; }
    void setStatus_order(const QString& status_order);
    void setOrder_date(const QDate& order_date) { this->order_date = order_date; }
    void setDelivery_date(const QDate& delivery_date) { this->delivery_date = delivery_date; }
    void setQuantity(int QUANTITY) { this->quantity=QUANTITY; }
    void setOrder_cost(int COST_ORDER) {  this->order_cost = order_cost; }
    bool ajouter();
    QSqlQueryModel * afficher ();
    bool supprimer (int order_id);
    bool modifier(int order_id, int order_cost,  QString& status_order, QDate& order_date, int quantity, QDate& DELIV_DATE);
    QSqlQueryModel* rechercher(int order_id);
    bool verif_id(QString ch_id);
    bool verif_nom(QString nom);
    Orders findOrderByID(int id);
    static int getNextOrderID();



private :
    int order_id ;
    int order_cost;
    QDate order_date ;
    QString status_order ;
    int quantity;
    QDate delivery_date;

};




#endif // ORDERS_H
