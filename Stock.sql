CREATE TABLE Stock( 
   Stock_ID number NOT NULL;
   Name_St varchar(20),
   Quantity_st number,
   type_st varchar(20),
   Condition_st varchar(20),
   Entry_Date Date,
 
   
);
ALTER TABLE Stock ADD CONSTRAINT pk_stock   PRIMARY KEY(Stock_ID) UNIQUE