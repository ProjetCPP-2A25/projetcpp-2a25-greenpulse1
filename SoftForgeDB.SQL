CREATE TABLE Stock( 
   Stock_ID number NOT NULL;
   Name_St varchar(20),
   Quantity_st number,
   type_st varchar(20),
   Condition_st varchar(20),
   Entry_Date Date,
 
   
);
ALTER TABLE Stock ADD CONSTRAINT pk_stock   PRIMARY KEY(Stock_ID) UNIQUE
CREATE TABLE Suppliers(
 Id_supp NUMBER NOT NULL,
 Name_supp VARCHAR(20),
 Type_supp VARCHAR(20),
 Contact_supp VARCHAR(15),
 Phone_supp NUMBER,
 Email_supp VARCHAR(15),
)

ALTER TABLE Suppliers ADD CONSTRAINT pk_suppliers PRIMARY KEY(Id_supp) UNIQUE
CREATE TABLE complaints(
id_comp number NOT NULL,
id_order number,
id_supp number,
Complaint_Date date,
DescriptionDesc VARCHAR(75),
Status_comp VARCHAR(10),
Actions VARCHAR(20),
)
ALTER TABLE complaints ADD CONSTRAINT pk_complaints primary key(id_comp) UNIQUE 
ALTER TABLE complaints ADD CONSTRAINT fk_complaints foreign key(id_order,id_supp)
CREATE TABLE Employees (
    Id_emp NUMBER NOT NULL,
    Last_name VARCHAR(20),
    First_name VARCHAR(20),
    Role VARCHAR(15),
    Email VARCHAR(25),
    Phone NUMBER,
    Hire_date DATE,
    Status VARCHAR(9),
)
ALTER TABLE Employees (
ADD CONSTRAINT pk_employees PRIMARY KEY (Id_emp)
CREATE TABLE Orders(
 Order_id NUMBER NOT NULL,
 Order_date DATE,
 exp_delivery_date DATE,
 Quantity_ord NUMBER,
 Status_ord varchar(10),
 total_cost float,  
)
ALTER TABLE Orders ADD CONSTRAINT pk_orders PRIMARY KEY(Order_id) UNIQUE
alter table orders add constraint customer_id_fk foreign key (customerid)  references customer (customerid) on delete CASCADE;