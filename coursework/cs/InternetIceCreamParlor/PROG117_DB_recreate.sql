----------------------------------------
-- DELETE TABLE & USER IF EXISTS
----------------------------------------
USE master
GO

-- These should already be on
SET ANSI_NULLS ON
SET QUOTED_IDENTIFIER ON
GO

--------------------------------------
-- WE WANT TO START FROM A CLEAN SLATE
--------------------------------------
IF EXISTS (SELECT * FROM sys.database_principals WHERE name = N'PROG117_web_user')
	DROP USER PROG117_web_user
--GO

IF EXISTS (SELECT * FROM syslogins WHERE name = N'PROG117_web_user')
	DROP LOGIN PROG117_web_user
--GO

IF DB_ID('PROG117DB') IS NOT NULL
	DROP DATABASE PROG117DB;
GO

----------------------------------------
-- CREATE A NEW DATABASE
----------------------------------------
CREATE DATABASE PROG117DB
	CONTAINMENT = NONE
GO

 -- Make this DB compatible to SQL Server 2012 through SQL Server 2016
 -- more info on this link --> https://msdn.microsoft.com/en-us/library/bb510680.aspx
ALTER DATABASE PROG117DB SET COMPATIBILITY_LEVEL = 110

---------------------------------------
-- CREATE THE LOGIN
---------------------------------------
CREATE LOGIN PROG117_web_user WITH PASSWORD='abc123',
	DEFAULT_DATABASE=PROG117DB,
	DEFAULT_LANGUAGE=us_english,
	CHECK_EXPIRATION=OFF,
	CHECK_POLICY=OFF

----------------------------------------
-- CREATE THE PERSON TABLE
----------------------------------------
use PROG117DB

CREATE TABLE dbo.person
(
	firstName		VARCHAR(50)		NOT NULL,
	lastName		VARCHAR(50)		NOT NULL,
	userName		VARCHAR(50)		NOT NULL
		CONSTRAINT IX_PROG117_person_userName	UNIQUE,
	password		VARCHAR(50)		NOT NULL,
	address			VARCHAR(50)		NOT NULL,
	email			VARCHAR(50)		NOT NULL
		CONSTRAINT IX_PROG117_person_email		UNIQUE,
	phone			VARCHAR(50)		NOT NULL,
	id				INT				NOT NULL IDENTITY(1,1)
		CONSTRAINT PK_PROG117_person			PRIMARY KEY CLUSTERED,
)

----------------------------------------
-- CREATE THE PRODUCT TABLE
----------------------------------------
CREATE TABLE dbo.products
(
	productName		VARCHAR(50)		NOT NULL,
	description		VARCHAR(250)	NOT NULL,
	price			FLOAT			NOT NULL,
	currentAmount	INT				NOT NULL,
	pid				INT				NOT NULL IDENTITY(1,1)
		CONSTRAINT	PK_products					PRIMARY KEY CLUSTERED
)

------------------------------------
-- CREATE THE USER
------------------------------------
USE PROG117DB

CREATE USER PROG117_web_user FOR LOGIN PROG117_web_user WITH DEFAULT_SCHEMA=dbo
ALTER ROLE db_datareader ADD MEMBER PROG117_web_user
ALTER ROLE db_datawriter ADD MEMBER PROG117_web_user
GO