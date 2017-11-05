#include "Fahrrad.h"



Fahrrad::Fahrrad()
{
}

Fahrrad::Fahrrad(string sName, double dGeschwindigkeit):Fahrzeug(sName, p_dMaxGeschwindigkeit)
{
	p_dMaxGeschwindigkeit = dGeschwindigkeit;
}

Fahrrad::~Fahrrad()
{
}

double Fahrrad::dTanken(double dMenge) {
	return 0;
}


double Fahrrad::dGeschwindigkeit() {

	double i, bikespeed = p_dMaxGeschwindigkeit;
	if (bikespeed > 12)
	{
		for (i = p_dGesamtStrecke; i >= 20; i = i - 20)
		{
			bikespeed = bikespeed*0.9;
			if (bikespeed <= 12.0)
				return 12.0;
		}
		return bikespeed;
	}
	return 12;
}
	
	
	
	
	/*if (bikespeed > 12) {
	for (int i = 0; i < (p_dGesamtStrecke/20); i++){
		

	
		double bikespeed = 0.9*bikespeed;
                                    }
	return  bikespeed;
	
	}
	return 12;



	*/

void Fahrrad::vAusgabe()
{
	Fahrzeug::vAusgabe();
	cout << endl;
}



ostream& Fahrrad::ostreamAusgabe(ostream& out)
{
	return Fahrzeug::ostreamAusgabe(out) << endl;
}

