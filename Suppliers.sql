CREATE TABLE Suppliers(
 Id_supp NUMBER NOT NULL,
 Name_supp VARCHAR(20),
 Type_supp VARCHAR(20),
 Contact_supp VARCHAR(15),
 Phone_supp NUMBER,
 Email_supp VARCHAR(15),
)

ALTER TABLE Suppliers ADD CONSTRAINT pk_suppliers PRIMARY KEY(Id_supp) UNIQUE