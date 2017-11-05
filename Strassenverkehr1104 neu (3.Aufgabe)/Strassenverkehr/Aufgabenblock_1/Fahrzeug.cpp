#include "Fahrzeug.h"


extern double dGlobaleZeit;


int Fahrzeug::p_iMaxID=1;    //Globalevariable ,ansonten kann nicht kompiliert werden  
                               //Ein nicht statischer Datenmember darf nicht auﬂerhalb seiner Klasse definiert werden

Fahrzeug::Fahrzeug()            //Standardkonstruktor,mit einer leeren Zeichenkette("") initialisiert  1.1.2
{
	vInitialisierung();             
	//p_sName = "";                       //1.1.2
	//p_iID = p_iMaxID;                                     //1.1.2
	//p_iMaxID++;
	//cout << "STANDARDKonstruktor des Fahrzeugs" << p_iID << endl;    //Meldung  1.1.2

}

Fahrzeug::Fahrzeug(string sName)  //Konstruktor ,der einen Namen als string bekommt   1.1.2
{
	vInitialisierung();
	p_sName = sName;                        //1.1.2
	//p_iID = p_iMaxID;
	//p_iMaxID++;
	//cout << "Konstruktor des Fahrzeugs " << p_iID << "und" << p_sName << endl;	//Meldung   1.1.2
}


Fahrzeug::Fahrzeug(string sName,double dMaxGeschwindigkeit)  //Konstruktor ,der einen Namen als string und noch Geschwindigkeit bekommt   1.1.4
{
	vInitialisierung();
	p_sName = sName;  
	p_dMaxGeschwindigkeit = dMaxGeschwindigkeit;
	//p_iID = p_iMaxID;
	//p_iMaxID++;
	//cout << "Konstruktor des Fahrzeugs " << p_iID << "und" << p_sName << endl;	//Meldung   1.1.2
}


Fahrzeug::~Fahrzeug(void)        //1.1.2 
{
	//cout << "Destruktor des Fahrzeugs" << p_iID << "und" << p_sName<<endl;
}

void Fahrzeug::vAusgabe()     //1.1.5
{ 
	cout<<setiosflags(ios::fixed); //  ?????why
	cout.precision(2); //Nachkommastellen   ?????why   
	cout << setiosflags(ios::left) << setw(3) << p_iID
		<< setw(6) << p_sName <<
		setw(10) << p_dMaxGeschwindigkeit
		<< setw(12) << p_dGesamtStrecke
		<< setw(14) << dGeschwindigkeit() ;

		

}

void Fahrzeug::vInitialisierung()     //1.1.4
{
	
	p_iID = p_iMaxID; //1.1.2
	p_sName = "";  //1.1.2                                             
	p_iMaxID++;	  //1.1.2
	p_dGesamtStrecke = 0.0;  //1.1.4
	p_dGesamtZeit = 0.0;	//1.1.4
	p_dZeit = 0.0;  //1.1.4
	p_dMaxGeschwindigkeit =0.0 ; //1.1.4
	
}

void Fahrzeug::vAbfertigung()      //1.1.8
{	
	double dGeschwindigkeitTmp = dGeschwindigkeit();//Aufgabe 2.3 
	if (dGlobaleZeit>p_dZeit){
	
	p_dGesamtStrecke += (dGlobaleZeit - p_dZeit)*dGeschwindigkeitTmp;
	p_dGesamtZeit += (dGlobaleZeit - p_dZeit);
	p_dZeit = dGlobaleZeit;
	}
}

double Fahrzeug::dGeschwindigkeit()
{
	return p_dMaxGeschwindigkeit;
}

double Fahrzeug::dTanken(double dMenge)
{
	return 0;
}


ostream& Fahrzeug::ostreamAusgabe(ostream& out)
{
	out << resetiosflags(ios::right) << setiosflags(ios::left)//zun‰chst rechts und dann linkb¸ndig
		<< setw(5) << p_iID
		<< setw(9) << p_sName
		<< setw(3) << ":"
		<< setw(9) << p_dMaxGeschwindigkeit
		<< setw(9) << dGeschwindigkeit()//Aufgabe2.3
		<< setw(9) << p_dGesamtStrecke
		<< setw(11) << p_dGesamtZeit;
	return out;
}


bool Fahrzeug::operator<( Fahrzeug& fahrzeug)
{
	if (p_dGesamtStrecke<fahrzeug.p_dGesamtStrecke)//Vergleich nach Gesamtstrecke
		return true;
	return false;
}


Fahrzeug& Fahrzeug::operator=( Fahrzeug& fahrzeug)//Zuweisung
{
	p_dGesamtStrecke = fahrzeug.p_dGesamtStrecke;
	p_dGesamtZeit = fahrzeug.p_dGesamtZeit;
	p_dMaxGeschwindigkeit = fahrzeug.p_dMaxGeschwindigkeit;
	p_dZeit = fahrzeug.p_dZeit;
	p_sName = fahrzeug.p_sName + "_KOPIE";// Zum Unterscheiden vom kopierten Objekt.
	return *this;
	//Die Identit‰tsnummer kann nicht einfach vom originalen Objekt kopiert werden
}


ostream& operator<<(ostream& out, Fahrzeug& fahrzeug)
{
	return fahrzeug.ostreamAusgabe(out);
}

//unten ,ansonten keine Kopie mehr
Fahrzeug::Fahrzeug( Fahrzeug& fahrzeug) :p_dGesamtStrecke(fahrzeug.p_dGesamtStrecke),
p_dGesamtZeit(fahrzeug.p_dGesamtZeit),
p_dMaxGeschwindigkeit(fahrzeug.p_dMaxGeschwindigkeit),
p_dZeit(fahrzeug.p_dZeit)
{
	p_sName = fahrzeug.p_sName + "_COPY";// Zum Unterscheiden vom kopierten Objekt.

	p_iID = p_iMaxID ;//Die ID wird aktualisiert.
	p_iMaxID++;//Die Anzahl von Fahrzeugen wird hochgez‰hlt.
	
}

