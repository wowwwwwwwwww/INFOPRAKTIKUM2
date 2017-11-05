#pragma once
#include "Fahrzeug.h"
class Fahrrad :
	public Fahrzeug
{
public:
	Fahrrad();
	Fahrrad(string, double);
	virtual ~Fahrrad();
	virtual double dTanken(double dMenge); //1.2.2 warum virtual??
	virtual double dGeschwindigkeit();//1.2.3
	virtual void vAusgabe();



	//Ausgabeoperator überladen
	virtual ostream& ostreamAusgabe(ostream& out);//Aufgabe 3.1

};




