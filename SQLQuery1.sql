USE [Praktika]
GO

SELECT [Имя]
      ,[Возраст]
  FROM [dbo].[Zadaniye_1]
GO


BULK INSERT Zadaniye_1 FROM 'C:\Users\ASUS\Documents\Visual Studio 2012\Projects\Проект1\Проект1\file.txt' 
WITH (DATAFILETYPE = 'char',FIELDTERMINATOR = '	', ROWTERMINATOR = '\n')