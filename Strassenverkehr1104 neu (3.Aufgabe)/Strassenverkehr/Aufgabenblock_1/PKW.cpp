#include "PKW.h"

extern double dGlobaleZeit;


PKW::PKW():Fahrzeug()
{
	p_dTankvolumen = 55;    //1.2.2
	p_dTankinhalt = 0.5*p_dTankvolumen;  //1.2.2
}

PKW::PKW(string sName, double p_dMaxGeschwindigkeit):Fahrzeug(sName, p_dMaxGeschwindigkeit)
{
	p_dTankvolumen = 55;    //1.2.2
	p_dTankinhalt = 0.5*p_dTankvolumen;  //1.2.2
}

PKW::PKW(string sName,double p_dMaxGeschwindigkeit,double a):Fahrzeug(sName, p_dMaxGeschwindigkeit)//1.2.2 (Einbeziehung)
{
	p_dTankvolumen = 55;    //1.2.2
	p_dTankinhalt = 0.5*p_dTankvolumen;  //1.2.2
	p_dVerbrauch = a;
}


PKW::~PKW()
{

}


double PKW::dVerbrauch()    //1.2.2 (eine Methode dVerbrauch ,die den bisherigen Gesamtverbrauch ermittelt)
{
	return (p_dGesamtStrecke*p_dVerbrauch) / 100.0;   //1.2.2 
}


double PKW::dTanken(double dMenge)   //1.2.2
{
	double needmenge = p_dTankvolumen - p_dTankinhalt;  //p_dTankvolumen 55 ,p_dTankinhalt ist derzeitige Inhalt
	if (needmenge < dMenge) {
		p_dTankinhalt = p_dTankvolumen;        //wird voll 
		return needmenge;                    //tatsächlich getantkte menge gegeben
	}
	else if (dMenge<0.0)//Defaultparameter! vollgetankt
	{
		needmenge = p_dTankvolumen - p_dTankinhalt;
		p_dTankinhalt = p_dTankvolumen;
		return needmenge;
	}
	else  {
		p_dTankinhalt += dMenge;				//nur dMenge getankt
		return dMenge;                         //tatsächlich getantkte menge gegeben
	}

}

void PKW::vAusgabe() {
	Fahrzeug::vAusgabe();  //1.2.2
	cout<< ""<< dVerbrauch() << " "<< p_dTankinhalt << endl; //1.2.2
}

void PKW::vAbfertigung()
{
	if (p_dTankinhalt > 0)
	{
		/*if ((p_dMaxGeschwindigkeit*(dGlobaleZeit - p_dZeit)) > (100 * (p_dTankinhalt / p_dVerbrauch)))
		{
			p_dGesamtStrecke += 100 * (p_dTankinhalt / p_dVerbrauch);
			b += (100 * (p_dTankinhalt / p_dVerbrauch)) / p_dMaxGeschwindigkeit;
			p_dTankinhalt = 0;
			p_dZeit = dGlobaleZeit;
		}*/
		
	
			double a = p_dGesamtStrecke;
			Fahrzeug::vAbfertigung();								//PKW hat noch Benzin und darf jetzt abfertigt werden 
			p_dTankinhalt -= ((p_dGesamtStrecke - a)*p_dVerbrauch/100.0);
			if (p_dTankinhalt < 0)
			{
				p_dTankinhalt = 0;                                                  //wenn die letzte strecke zu lang ist ,muss der Tankinhalt auf 0 gesetzt wird      
		
		}
	}
	else
	{
		cout << "Das PKW " << p_sName << "hat kein Benzin mehr" << endl;
	}
}

double PKW::dGeschwindigkeit() {
	return p_dMaxGeschwindigkeit;
}

//Überladen

PKW& PKW::operator=( PKW &Car)
{
	Fahrzeug::operator=(Car);
	p_dTankinhalt = Car.p_dTankinhalt;
	p_dTankvolumen = Car.p_dTankvolumen;
	p_dVerbrauch = Car.p_dVerbrauch;
	return *this;
}

ostream& PKW::ostreamAusgabe(ostream& out)
{
	Fahrzeug::ostreamAusgabe(out)
		<< setw(12) << dVerbrauch()
		<< p_dTankinhalt << endl;
	return out;
}