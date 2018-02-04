CREATE DATABASE TxCustomers;
GO

USE TxCustomers;

CREATE TABLE CustBankBalance (
	CustomerID	INT				PRIMARY KEY IDENTITY(5000,50) NOT NULL,
	FirstName	NVARCHAR(50)	NOT NULL,
	LastName	NVARCHAR(50)	NOT NULL,
	Balance		MONEY			NOT NULL
);

INSERT INTO CustBankBalance (FirstName, LastName, Balance) VALUES
	('Mickey', 'Mouse', 20.00),
	('Minnie', 'Mouse', 20.00),
	('Donald', 'Duck',  20.00),
	('Goofy',  'Dog',   20.00)
