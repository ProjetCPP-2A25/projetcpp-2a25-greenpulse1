#ifndef SUPPLIER_H
#define SUPPLIER_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>


class supplier
{

private:
    int SUPPLIER_ID;
    QString NAME_SUPPLIER;
    QString TYPE_SUPPLIER;
    QString CONTACT_SUPPLIER;
    QString PHONE_SUPPLIER;
    QString EMAIL_SUPPLIER;
    int RATING;


public:
    supplier();
    supplier(int ,  QString,  QString,  QString ,
                  QString ,  QString );

        // Getter et Setter
    int getSUPPLIER_ID() const {return SUPPLIER_ID ;}
        QString getNAME_SUPPLIER() const{return NAME_SUPPLIER ;}
        QString getTYPE_SUPPLIER() const{return TYPE_SUPPLIER ;}
        QString getCONTACT_SUPPLIER() const{return CONTACT_SUPPLIER ;}
        QString getPHONE_SUPPLIER() const{return PHONE_SUPPLIER ;}
        QString getEMAIL_SUPPLIER() const{return EMAIL_SUPPLIER;}
        int getRating() const{return RATING ;}



        void setSUPPLIER_ID(int id){ this->SUPPLIER_ID =id; }
        void setNAME_SUPPLIER(const QString &name){ NAME_SUPPLIER = name; }
        void setTYPE_SUPPLIER(const QString &type){ TYPE_SUPPLIER = type; }
        void setCONTACT_SUPPLIER(const QString &contact){ CONTACT_SUPPLIER = contact; }
        void setPHONE_SUPPLIER(const QString &phone){ PHONE_SUPPLIER = phone;}
        void setEMAIL_SUPPLIER(const QString &email){ EMAIL_SUPPLIER = email; }
        void setRating(int rating){ this->RATING =rating; }

        bool ajouter();
        QSqlQueryModel* afficher();
        bool modifier(int id, QString &email, const QString &phone);
        bool supprimer(int id  );
        QSqlQueryModel* rechercher(int);
        bool modifierRating(int id, int rating);
        QSqlQueryModel* afficherSortedByRating(int rating);
        QSqlQueryModel* afficherSortedByRatingDescending();
        QSqlQueryModel* afficherSortedByRatingAscending();




};

#endif // SUPPLIER_H
