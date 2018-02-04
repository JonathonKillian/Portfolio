/*******************************************************************************
* This is a copy of the EmployeeModel.edmx.sql file, modified to just create the
* database and add some departments (the assignment had us manually enter them).
*
* In Visual Studio, the Entity Framework, when asked to generate the database
* from the model creates the database prior to building the SQL file. Thus, the
* SQL file is set up to assume the database already exists.
*
* Feel free to just highlight the create database, F5, then execute the
* "original" generated SQL file; you can then return to this file, highlight and
* execute the insert statements at the bottom.
*
* Jonathon Killian, 1/7/2018
*******************************************************************************/
USE master;
GO

--DROP DATABASE EmployeeEFDB;
CREATE DATABASE [EmployeeEFDB];
GO

USE [EmployeeEFDB];
GO
IF SCHEMA_ID(N'dbo') IS NULL EXECUTE(N'CREATE SCHEMA [dbo]');
GO

-- --------------------------------------------------
-- Creating all tables
-- --------------------------------------------------

-- Creating table 'Employees'
CREATE TABLE [dbo].[Employees] (
    [EmployeeID] int IDENTITY(1,1) NOT NULL,
    [FirstName] nvarchar(max)  NOT NULL,
    [LastName] nvarchar(max)  NOT NULL,
    [Age] int  NOT NULL,
    [DepartmentID] int  NOT NULL,
    [Department_DepartmentID] int  NOT NULL
);
GO

-- Creating table 'Departments'
CREATE TABLE [dbo].[Departments] (
    [DepartmentID] int IDENTITY(1,1) NOT NULL,
    [DeptName] nvarchar(max)  NOT NULL
);
GO

-- --------------------------------------------------
-- Creating all PRIMARY KEY constraints
-- --------------------------------------------------

-- Creating primary key on [EmployeeID] in table 'Employees'
ALTER TABLE [dbo].[Employees]
ADD CONSTRAINT [PK_Employees]
    PRIMARY KEY CLUSTERED ([EmployeeID] ASC);
GO

-- Creating primary key on [DepartmentID] in table 'Departments'
ALTER TABLE [dbo].[Departments]
ADD CONSTRAINT [PK_Departments]
    PRIMARY KEY CLUSTERED ([DepartmentID] ASC);
GO

-- --------------------------------------------------
-- Creating all FOREIGN KEY constraints
-- --------------------------------------------------

-- Creating foreign key on [Department_DepartmentID] in table 'Employees'
ALTER TABLE [dbo].[Employees]
ADD CONSTRAINT [FK_DepartmentEmployee]
    FOREIGN KEY ([Department_DepartmentID])
    REFERENCES [dbo].[Departments]
        ([DepartmentID])
    ON DELETE NO ACTION ON UPDATE NO ACTION;
GO

-- Creating non-clustered index for FOREIGN KEY 'FK_DepartmentEmployee'
CREATE INDEX [IX_FK_DepartmentEmployee]
ON [dbo].[Employees]
    ([Department_DepartmentID]);
GO

--USE EmployeeEFDB;			-- For just executing the insert

-- Fill in the departments table so the program can be executed that much faster
INSERT INTO [dbo].[Departments] (DeptName) VALUES
	('Personnel'),
	('Engineering'),
	('Finance')
GO

INSERT INTO [dbo].[Employees] (FirstName, LastName, Age, Department_DepartmentID, DepartmentID)
VALUES
	('Janine',	'Melnitz',	32, 1, 0),
	('Egon',	'Spengler',	40, 2, 0),
	('Louis',	'Tully',	31, 3, 0)
