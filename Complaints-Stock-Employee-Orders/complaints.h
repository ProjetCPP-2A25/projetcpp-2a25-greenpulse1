#ifndef COMPLAINTS_H
#define COMPLAINTS_H

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QDate>

class datee {
private:
    int jj; // Day
    int mm; // Month
    int aaaa; // Year
public:
    // Constructor with parameters
    datee(int jj, int mm, int aaaa) : jj(jj), mm(mm), aaaa(aaaa) {}

    QString toString(const QString& format) const {
        // Format the date based on the desired output
        if (format == "yyyy-MM-dd") {
            return QString("%1-%2-%3").arg(aaaa).arg(mm, 2, 10, QChar('0')).arg(jj, 2, 10, QChar('0'));
        }
        return QString();
    }

    // Getter methods
    int getjj() const { return jj; }
    int getmm() const { return mm; }
    int getaaaa() const { return aaaa; }

    // Setter methods
    void setjj(int jj) { this->jj = jj; }
    void setmm(int mm) { this->mm = mm; }
    void setaaaa(int a) { this->aaaa = a; }
};

class COMPLAINTS {
private:
    int COMPLAINT_ID;
    QString DESCRIPTION_COMPLAINT;
    QString ACTIONS_COMPLAINT;
    int ORDER_ID;
    int EMPLOYEE_ID;
    int SUPPLIER_ID;
    datee COMPLAINT_DATE;
    QString FILE_PATH; // Add FILE_PATH as a new member variable
    int COMPLAINT_TYPE;

public:
    COMPLAINTS();
    COMPLAINTS(int, QString, QString, int, int, int, datee, QString,int); // Modify constructor to include FILE_PATH

    // Getter methods
    int getID_COMPLAINT() const { return COMPLAINT_ID; }
    int getORDER_ID() const { return ORDER_ID; }
    int getEMPLOYEE_ID() const { return EMPLOYEE_ID; }
    int getSUPPLIER_ID() const { return SUPPLIER_ID; }
    QString getDESCRIPTION_COMPLAINT() const { return DESCRIPTION_COMPLAINT; }
    QString getACTIONS_COMPLAINT() const { return ACTIONS_COMPLAINT; }
    datee getCOMPLAINT_DATE() const { return COMPLAINT_DATE; }
    QString getFILE_PATH() const { return FILE_PATH; } // Getter for FILE_PATH
    int getCOMPLAINT_TYPE() const { return COMPLAINT_TYPE; }


    // Setter methods
    void setID_COMPLAINT(int ID_COMP) { this->COMPLAINT_ID = ID_COMP; }
    void setORDER_ID(int ID_ORD) { this->ORDER_ID = ID_ORD; }
    void setEMPLOYEE_ID(int ID_EMP) { this->EMPLOYEE_ID = ID_EMP; }
    void setSUPPLIER_ID(int ID_SUP) { this->SUPPLIER_ID = ID_SUP; }
    void setDESCRIPTION_COMPLAINT(const QString& DESCRIP) { DESCRIPTION_COMPLAINT = DESCRIP; }
    void setACTIONS_COMPLAINT(const QString& ACTION) { ACTIONS_COMPLAINT = ACTION; }
    void setCOMPLAINT_DATE(const datee& COMP_DATE) { COMPLAINT_DATE = COMP_DATE; }
    void setFILE_PATH(const QString& filePath) { FILE_PATH = filePath; } // Setter for FILE_PATH
    void extractThumbnail(const QString &videoPath, const QString &imagePath);
    void setCOMPLAINT_TYPE(int typ) { this->COMPLAINT_TYPE = typ; }


    // Member functions
    bool ajouter();
    QSqlQueryModel* afficher();
    bool modifier(int id, const QString& actions, const QString& description, int orderid, int supplierid, int employeeid, const datee& datt,const QString& filePath);
    bool supprimer(int);
    QSqlQueryModel* rechercher(int);
    QSqlQueryModel* trierCOMPLAINT(QString test);

    void setFilePath(const QString& filePath) {
        FILE_PATH = filePath;
    }

};

#endif // COMPLAINTS_H
