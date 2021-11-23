//*********************************************************************************************
//* Programme : BDD.cpp											date : 24/11/2021
//*---------------------------------------------------------------------------------------------------------
//* 
//*
//*Programmeurs : LUSSIEZ Julien										classe : BTSSN2
//*				  COLSON Baptiste
//*				  LARIDANT Julien
//*--------------------------------------------------------------------------------------------------------
//* BUT :
//*Programmes associes : 
//*********************************************************************************************

#include "BDD.h"

BDD::BDD(QObject *parent)
	: QObject(parent) {
}

BDD::~BDD() {
}

//Connexion à la BDD

void BDD::ConnexionBDD()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("192.168.64.204");
	db.setDatabaseName("station_meteo");
	db.setUserName("user");
	db.setPassword("root");
	bool ok = db.open();

}

//Insertion dans la BDD avec la température et la tension

void BDD::InsertionBDD(double temperature, double tension)
{
	QSqlQuery request;
	request.prepare("INSERT INTO `sonde`(`temperature`, `tension`) VALUES(?, ?)");
	request.addBindValue(temperature);
	request.addBindValue(tension);

	request.exec();
}