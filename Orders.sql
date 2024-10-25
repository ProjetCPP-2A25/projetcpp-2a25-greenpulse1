CREATE TABLE Orders(
 Order_id NUMBER NOT NULL,
 Order_date DATE,
 exp_delivery_date DATE,
 Quantity_ord NUMBER,
 Status_ord varchar(10),
 total_cost float,  
)
ALTER TABLE Orders ADD CONSTRAINT pk_orders PRIMARY KEY(Order_id) UNIQUE