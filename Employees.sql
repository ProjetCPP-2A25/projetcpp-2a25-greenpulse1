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
ALTER TABLE Employees 
ADD CONSTRAINT pk_employees PRIMARY KEY (Id_emp)
