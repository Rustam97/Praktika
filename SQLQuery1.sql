USE [Praktika]
GO

SELECT [���]
      ,[�������]
  FROM [dbo].[Zadaniye_1]
GO


BULK INSERT Zadaniye_1 FROM 'C:\Users\ASUS\Documents\Visual Studio 2012\Projects\������1\������1\file.txt' 
WITH (DATAFILETYPE = 'char',FIELDTERMINATOR = '	', ROWTERMINATOR = '\n')