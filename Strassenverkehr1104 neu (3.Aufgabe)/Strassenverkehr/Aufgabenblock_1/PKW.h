#pragma once
#include "Fahrzeug.h"
class PKW :
	public Fahrzeug
{
public:
	PKW(void);
	PKW(string ,double );
	PKW(string ,double , double );





	virtual ~PKW();


	double  p_dVerbrauch;  //1.2.2
	double 	p_dTankinhalt;	//1.2.2
	double 	p_dTankvolumen; //1.2.2
	double	dVerbrauch();  //1.2.2
	double dTanken(double dMenge); //1.2.2
	virtual void vAbfertigung(); //1.2.2
	virtual void vAusgabe();  //1.2.2
	virtual double dGeschwindigkeit();//1.2.3

									  //Ausgabeoperator überladen
	virtual ostream& ostreamAusgabe(ostream& out);//Aufgabe 3.1
	virtual PKW& operator=( PKW& Car);//Aufgabe 3.3
	
};

