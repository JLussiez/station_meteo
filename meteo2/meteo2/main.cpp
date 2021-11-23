#include <QtCore/QCoreApplication>
#include "K8055Adapter.h"
#include "BDD.h"
#include "meteo2.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Timer timer;

	K8055Adapter * carteES = K8055Adapter::getInstance();

	carteES->OpenDevice(0);

	return a.exec();
}