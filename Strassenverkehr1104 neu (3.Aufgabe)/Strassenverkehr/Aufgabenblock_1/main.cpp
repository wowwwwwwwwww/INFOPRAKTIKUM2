#include <iostream>
#include <sstream>
#include <vector>   //1.2.4
#include "Fahrzeug.h"
#include "Fahrrad.h"
#include "PKW.h"


void vAufgabe1();
void vAufgabe1_deb();
void Tabellekopf();
void vAufgabe2();
void vAufgabe3();



double dGlobaleZeit;
int main()
{
	vAufgabe3();
	//vAufgabe2();
	//vAufgabe1_deb();
}

void vAufgabe1()
{

	//PKW auto1("asdfasdfadfa");  //mit Name 
	Fahrzeug auto2("A");
	Fahrzeug auto3("B");
	Fahrzeug auto4;					//ohne Name 
	Fahrzeug auto5;
	Fahrzeug auto6; 
	Fahrzeug auto7;
	//die oben sind statisch 
	//die unten sind dynamisch ,weil mit new 
	Fahrrad *aaa = new Fahrrad("yuyang", 15);  //1.1.3    
	Fahrzeug *bbb = new Fahrzeug ("Francesso",99);//1.1.3
	double dTakt;
	cin >> dTakt;
	for (dGlobaleZeit = 0; dGlobaleZeit < 5.0; dGlobaleZeit += 0.1)
	{


		aaa->vAbfertigung();
		Tabellekopf();
		aaa->vAusgabe();
	}
	}

	/*cout << endl;  //Zeilenwechsel
	bbb->vAusgabe();
	cout << endl;  //Zeilenwechsel
	delete bbb;
	delete aaa;  //1.1.3
*/


void vAufgabe1_deb()
{
	Fahrzeug* asdfgh[4] ;
	    asdfgh[0] = new Fahrzeug("dab", 121);
		asdfgh[1] = new Fahrzeug("dac", 131);
		asdfgh[2] = 0;
		asdfgh[3] = new Fahrzeug("dabf", 111);

}
void Tabellekopf()
{
	cout << setiosflags(ios::left) << setw(3) << "ID"
		<< setw(6) <<"Name   :  "
		<<setw(10) << "MaxKmh"
		<< setw(12)<<"sumStecke" 
		<< setw(14) << "nowspeed"
		<< setw(16) << "sumverbrauch"
		<< setw(18) << "nowtank"
		<< endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}

void vAufgabe2()
{

	int AnzahlPKW, Anzahlbike;
	cin >> AnzahlPKW;
	cin >> Anzahlbike;
	vector<PKW*>Car;
	vector<Fahrrad*>Bike;
	
	for (int i = 0; i < AnzahlPKW; i++)
	{
		stringstream s;
		s << "Auto" << i + 1;
		Car.push_back(new PKW(s.str(), 60 + 5 * i, 10 + i));

	}
	
	
	for (int j = 0; j < Anzahlbike; j++)
	{
		stringstream t;
		t << "Fahrrad" << j + 1;
		Bike.push_back(new	Fahrrad(t.str(), 30+2*j));

	}

	for (dGlobaleZeit = 0; dGlobaleZeit < 10.0; dGlobaleZeit += 0.5)
	{
		cout << "Zeit:" << dGlobaleZeit << "std" << endl;
		Tabellekopf();
		for (int i = 0; i < AnzahlPKW; i++)
		{
			Car[i]->vAbfertigung();
			Car[i]->vAusgabe();

		}
		

		for (int j = 0; j < Anzahlbike; j++)
		{
			Bike[j]->vAbfertigung();
			Bike[j]->vAusgabe();


			if (fabs(dGlobaleZeit - 3) < 0.1)
			{
				for (int i = 0; i < AnzahlPKW; i++)
					Car[i]->dTanken(-1);
			}
			if (fabs(dGlobaleZeit - 6) < 0.1)
			{
				for (int i = 0; i < AnzahlPKW; i++)
					Car[i]->dTanken(-1);
			}
			if (fabs(dGlobaleZeit - 9) < 0.1)
			{
				for (int i = 0; i < AnzahlPKW; i++)
					Car[i]->dTanken(-1);
			}

		}
	}
	
		

		

	}



void vAufgabe3()
{
	PKW* Car = new PKW("Auto", 70.0, 15.0);
	Fahrrad* Bike = new Fahrrad("Fahrrad", 30.0);
	for (dGlobaleZeit = 0.0; dGlobaleZeit <= 2.0; dGlobaleZeit = dGlobaleZeit + 0.1)
		//die Fahrzeuge mehrmaks abfertigen
	{
		cout << "\nGlobale Zeit: " << dGlobaleZeit << " h" << endl;//Zeit ausgeben
		Tabellekopf();
		Car->vAbfertigung();
		Bike->vAbfertigung();
		//Zum Test bei der Unteraufgabe_1
		//Ausgabe dierekt mit "cout"
		//cout << (*Car) << endl;
		//cout << (*Bike) << endl;
	}

/*
	//Zum Test bei der Unteraufgabe_2
	if ((*Bike)<(*Car))
		cout << "Car faehrt weiter als Bike\n" << endl;
	else if ((*Car)<(*Bike))
		cout << "Bike faehrt weiter als Car\n" << endl;
	else
		cout << "Bike und Car fahren gleichweit.\n" << endl;
		
		
		*/

	//Zum Test bei der Unteraufgabe_3
	PKW* Car_1 = new PKW();
	PKW* Car_2 = new PKW(*Car);//Anwendung des Copy-Konstruktors zum Vergleich mit Car_1, der vom Car zugewiesen wird.
//	PKW* Car_3 = new PKW(*Car);
	(*Car_1) = (*Car);//Anwendung des Zuweisungsoperators
//	(*Car_3) = (*Car);
	Tabellekopf();
	cout << (*Car) << endl;
	cout << (*Car_1) << endl;
	cout << (*Car_2) << endl;
	//cout << (*Car_3) << endl;
}
