//*********************************************************************************************
//* Programme : meteo.cpp											date : 24/11/2021
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

#include "meteo2.h"

Timer::~Timer() {

}

Timer::Timer()
{
	this->db = db;
	db->ConnexionBDD();

	timer = new QTimer(this);

	connect(timer, SIGNAL(timeout()), this, SLOT(TimerSlot()));

	timer->start(300000);

}

void Timer::TimerSlot() {

	K8055Adapter * carteES = K8055Adapter::getInstance();

	carteES->OpenDevice(0);

	double numericalValue = carteES->ReadAnalogChannel( 2 );

	double voltageValue = numericalValue / 255.0 * 5.0;

	double temperatureValue = (voltageValue * 90 / 5) - 30;

	qDebug() << temperatureValue;

	db->InsertionBDD(temperatureValue, voltageValue);

	carteES->CloseDevice();
	K8055Adapter::freeInstance();
}