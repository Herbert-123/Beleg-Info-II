//#define _CRT_SECURE_NO_WARNINGS		
#include <stdio.h>
#include <stdlib.h>

//globale Variablen
int quit = 0;
int Nrierr=10;		//zulässige Fehlerzahl	- Nr input Error
int Auswahl=0;


/*Speicherordner Dateien (% Programm):
			>> Dateispeicher automatisch erstellen lassen in neuem automatisch erstellten Ordner (ca. line 30) bei :"C:\\temp\\Fahrtenbuch"
			
			>> alternativ individuell festlegen, folgendes ist zu beachten:
				- 4 mal backslash!! "\\\\"
				- darf keine Leerzeichen enthalten
				- "mkdir()" und folgende Zeile müssen auskommentiert werden
*/
//char seed_path[255] = "C:\\\\Users\\\\...";


//Funktionen

int eintrag(char file_patheintrag[255], int fzz);		//Neuen Eintrag in vorhandenes Fahrzeug
int nfz(char file_pathfz[255]);			//Neues Fahrzeug anlegen
	//int fahrer();		//Neuen Fahrer Anlegen
	//int reset();		//Reset

int main() {
	
	//neuen Ordner erstellen, beide folgende Zeilen evtl. auskommentieren
	mkdir("C:\\temp\\Fahrtenbuch");
	char seed_path[255] = "C:\\\\temp\\\\Fahrtenbuch";

	int i = 0;

	while (quit!=1)
	{
		printf("                                             +-------------+\n                                             | Fahrtenbuch |\n                                             +-------------+\n");
		
		for ( i = 0; i < Nrierr; i++)
		{
			printf("Bitte waehlen Sie Ihre Aktion:\n");
			printf("	1: Neuer Fahrtenbucheintrag (vorhandenes Fahrzeug)\n	2: Neues Fahrzeug anlegen\n	(3: Neuen Fahrer anlegen)\n	4 : Reset\n	5 : Ende\n");
			printf("Ihre Wahl : < >\b\b");
			scanf_s("%i", &Auswahl);

			if (Auswahl > 0 && Auswahl < 6) { break; }
			printf("\nFehlerhafte Eingabe, bitte Eingabe wiederholen!\n");
		}
		if (Auswahl == 5 || i==Nrierr) { quit = 1; }												// Abbruch bei Auswahl Ende(5) oder zu hoher Fehlerzahl(>Nrierr)

		printf("\n\n");

		switch (Auswahl)
		{
			//Neuer Fahrtenbucheintrag
			case 1:
				eintrag(seed_path,Nrierr);
				break;

			//Neues Fahrzeug anlegen
			case 2:
				nfz(seed_path);
				break;

			//Neuer Fahrereintrag
			case 3:
				fahrer();
				break;
		}
		
		//Bildschirm bereinigen
		system("cls");
	}
	system("color 1F");
	printf("\n\n\n\n\n\n\nEnde!\n--------------------------------------\n");
}

