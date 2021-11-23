//*********************************************************************************************
//* Programme : Meteo.h			date : 24/11/2021
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

#pragma once

#include "K8055Adapter.h"
#include "BDD.h"
#include <QTimer>
#include <QDebug>

class Timer : public QObject
{
	Q_OBJECT

public: 

	Timer(QObject *parent, BDD * db);

	Timer();
	~Timer();

	QTimer *timer;

private:

	BDD * db;
	K8055Adapter * carteES;

public slots:

	void TimerSlot();
};
