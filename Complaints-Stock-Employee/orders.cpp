#include "Orders.h"
#include <QString>
#include<ui_mainwindow.h>
#include<mainwindow.h>
#include<QSqlDatabase>
#include <QSqlError>
#include<QDebug>
#include <QMessageBox>

Orders::Orders()
{
    order_id=0;
    order_cost=0;
    order_date=QDate(0,0,0);
    status_order="";
    delivery_date=QDate(0,0,0);
    quantity=0;

}
Orders::Orders(int order_id,int order_cost,QDate ORD_DATE,QString status_order,int quantity,QDate DELIV_DATE)
{
    this->order_id=order_id;
    this->order_cost=order_cost;
    this->order_date=ORD_DATE;
    this->status_order=status_order;
    this->quantity=quantity;
    this->delivery_date=DELIV_DATE;
}

Orders Orders::findOrderByID(int order_id) {
    Orders order;

    // Create a QSqlQuery to find the order by its ID
    QSqlQuery query;
    query.prepare("SELECT * FROM orders WHERE order_id = :order_id");
    query.bindValue(":order_id", order_id);

    if (query.exec() && query.next()) {
        // If an order is found, populate the `Orders` object with data
        order.setOrder_id(query.value("order_id").toInt());
        order.setOrder_cost(query.value("order_cost").toInt());
        order.setOrder_date(query.value("order_date").toDate());
        order.setStatus_order(query.value("status_order").toString());
        order.setQuantity(query.value("quantity").toInt());
        order.setDelivery_date(query.value("delivery_date").toDate());
    } else {
        // If no order is found, return a default Orders object
        order.setOrder_id(-1);  // Indicate that no valid order was found
    }

    return order;
}

void Orders::setStatus_order(const QString &status_order) {
    this->status_order = status_order;
}
bool Orders::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO ORDERS (ORDER_ID, TOTAL_COST_ORDER, ORDER_DATE, STATUS_ORDER, QUANTITY_ORDERED_ORDER, EXPECTED_DELIVERY_DATE) "
                  "VALUES (:order_id, :order_cost, :order_date, :status_order, :quantity, :delivery_date)");
    query.bindValue(":order_id", order_id);
    query.bindValue(":order_cost", order_cost);
    query.bindValue(":order_date",order_date);
    query.bindValue(":status_order", status_order);
    query.bindValue(":quantity", quantity);
    query.bindValue(":delivery_date", delivery_date);


    return query.exec();
}
QSqlQueryModel * Orders::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select order_id, order_date, status_order, order_cost, quantity, delivery_date from ORDERS");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("order_id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("status_order "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("order_date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("order_cost"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("quantity"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("delivery_date"));

    return model;
}

bool Orders::supprimer(int order_id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Orders WHERE ORDER_ID = :order_id");
    query.bindValue(":order_id", order_id); // Ensure the case matches exactly

    return query.exec();
}

bool Orders::modifier(int order_id, int order_cost, QString& status_order, QDate& order_date, int quantity, QDate& delivery_date) {
    QSqlQuery query;

    // Prepare the query with placeholders
    query.prepare("UPDATE ORDERS SET ORDER_DATE = :order_date, EXPECTED_DELIVERY_DATE = :delivery_date, STATUS_ORDER = :status_order, QUANTITY_ORDERED_ORDER = :quantity, TOTAL_COST_ORDER = :order_cost WHERE ORDER_ID = :order_id;");

    // Bind the values to the placeholders
    query.bindValue(":order_id", order_id);
    query.bindValue(":order_date", order_date);
    query.bindValue(":status_order", status_order);
    query.bindValue(":order_cost", order_cost);
    query.bindValue(":quantity", quantity);
    query.bindValue(":delivery_date", delivery_date);

    // Execute the query and handle errors
    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text(); // Debugging error
        return false;
    }

    return true;
}




QSqlQueryModel* Orders::rechercher(int order_id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM Orders WHERE ORDER_ID = :order_id");
    query.bindValue(":order_id", order_id);

    if (!query.exec()) {
        qDebug() << "Query execution failed:" << query.lastError().text();
        return nullptr;
    }

    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);

    return model;
}

bool Orders::verif_id(QString ch_id){
    bool test=true;
    int i;
    if(ch_id.length()!=8){
        test=false;
        return  test;
    }else{
        for(i=0;i<ch_id.length();i++){
            if(!((ch_id[i]>='0')&&(ch_id[i]<='9'))){
                test=false;
                return  test;
            }
        }
    }
    return test;}

bool Orders::verif_nom(QString nom){
    bool test=true;
    int i;
    if(nom.length()>20){
        test=false;
        return  test;
    }else{
        for(i=0;i<nom.length();i++){
            if(!(((nom[i]>='A')&&(nom[i]<='Z'))||((nom[i]>='a')&&(nom[i]<='z')))){
                test=false;
                return  test;
            }
        }
    }
    return  test;
}
int Orders::getNextOrderID() {
    QSqlQuery query;
    query.prepare("SELECT MAX(ORDER_ID) FROM orders");  // Assuming your table is named 'orders'
    if (query.exec()) {
        if (query.next()) {
            int maxOrderID = query.value(0).toInt();
            return maxOrderID + 1;  // Return the next ID (max + 1)
        }
    }
    return 1;  // If no orders exist, return 1 as the starting order ID
}
