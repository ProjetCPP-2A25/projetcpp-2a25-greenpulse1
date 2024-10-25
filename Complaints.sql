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
