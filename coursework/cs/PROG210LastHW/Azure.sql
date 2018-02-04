-- JK: No create database here; using the free account, we stayed on a single database

CREATE TABLE Product (
	ProductID		INT				IDENTITY(1,1),
	ProductName		NVARCHAR(100)	NOT NULL,
	Price			MONEY			NOT NULL,
	QuantityOnHand	INT				NOT NULL
)

ALTER TABLE Product
ADD CONSTRAINT PK_ProductID
	PRIMARY KEY (ProductID ASC)

INSERT INTO Product (ProductName, Price, QuantityOnHand) VALUES
	('Lucky Charms',    2.00, 10),
	('Frosted Flakes',  2.50,  1),
	('Fruit Loops',     3.00, 10)
	('Golden Crisp',   20.01, 10)
