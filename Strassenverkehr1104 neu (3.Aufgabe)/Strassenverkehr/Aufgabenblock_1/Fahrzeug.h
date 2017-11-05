#pragma once
#include <string>
#include <iostream>
#include <iomanip> //1.1.5
using namespace std;

class Fahrzeug
{
public:
	Fahrzeug();  //1.1.2 
	Fahrzeug(string);    //1.1.2
	Fahrzeug(string, double);//1.1.4
	Fahrzeug( Fahrzeug& fahrzeug);
	~Fahrzeug(); //1.1.2
	virtual double dTanken(double dMenge);
	virtual void vAusgabe(); //1.1.5     (virtual wegen 1.2.1)
	virtual void vAbfertigung();  //1.1.8  (virtual wegen 1.2.1)
	virtual double dGeschwindigkeit();//1.2.3 weil Fahrrader nicht immer mit maxspeed fahren können 

	 
	 //Operatoreb überladen
	virtual ostream& ostreamAusgabe(ostream& out);//Aufgabe 3.1,Zugriff auf die privaten Variablen für Ausgaeb-Operator
	bool operator<( Fahrzeug& fahrzeug);//Aufgabe 3.2,Vergleichoperator nach Gesamtstrecke
	virtual Fahrzeug& operator=( Fahrzeug& fahrzeug);//Aufgabe 3.3, Zuweisungsoperator 




protected:    //1.2.1
	string p_sName;         //1.1.2
	int p_iID;		 		//1.1.2
	static int p_iMaxID;   //1.1.2
	void vInitialisierung(); //1.1.4  (nicht virtual wegen 1.2.1)
	double p_dMaxGeschwindigkeit; //1.1.4
	double p_dGesamtStrecke;  //1.1.4
	double p_dGesamtZeit;	//1.1.4
	double p_dZeit;			//1.1.4

	


};



//Weil Operand vom Ausgabe-Operatoren kein Element der Klasse ist,muss der Operator außerhalb der Klasse definiert werden.
ostream& operator<<(ostream& out, Fahrzeug& fahrzeug);//Ausgabe-Operator mit einer einzigen Definiton für alle von Fahrzeug abgeleitenden Klassen


