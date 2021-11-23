//*********************************************************************************************
//* Programme : BDD.h											date : 24/11/2021
//*---------------------------------------------------------------------------------------------------------
//* 
//*
//*Programmeurs : LUSSIEZ Julien										classe : BTSSN2
//*				  COLSON Baptiste
//*				  LARIDANT Julien
//*--------------------------------------------------------------------------------------------------------
//* BUT :
//*Programmes associes: 
//*********************************************************************************************

#pragma once

#include <QtSql/QtSql>
#include <qsqldatabase.h>

class BDD : public QObject
{
	Q_OBJECT

private:

	QSqlDatabase * db;

public:
	BDD(QObject *parent = Q_NULLPTR);
	~BDD();

	void ConnexionBDD();
	void InsertionBDD(double temperature, double tension);
};
