USE [Praktika]
GO

/****** Object:  Table [dbo].[Zadaniye_1]    Script Date: 08.07.2018 15:00:05 ******/
DROP TABLE [dbo].[Zadaniye_1]
GO

/****** Object:  Table [dbo].[Zadaniye_1]    Script Date: 08.07.2018 15:00:05 ******/
SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

CREATE TABLE [dbo].[Zadaniye_1](
	[���] [nvarchar](20) NOT NULL,
	[�������] [nvarchar](20) NOT NULL
) ON [PRIMARY]

GO

BULK INSERT Zadaniye_1 FROM 'C:\Users\ASUS\Documents\Visual Studio 2012\Projects\������1\������1\file.txt' 
WITH (DATAFILETYPE = 'char',FIELDTERMINATOR = '	', ROWTERMINATOR = '\n')
