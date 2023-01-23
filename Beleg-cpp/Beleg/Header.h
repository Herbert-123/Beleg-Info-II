#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

using namespace std;

//Deklarierung struct

	//globale Variablen			
	// 	
	//(spezifische Initialisierung in "main.c" line 4)

	struct global_var
	{
		int quit;
		int Nrierr;		//zulässige Fehlerzahl	- Nr input Error
		int Auswahl;
	};

	//File Path/ Speicherpfad
		/*Speicherordner Dateien (% Programm):
				>> Dateispeicher automatisch erstellen lassen in neuem automatisch erstellten Ordner (main.cpp line 14) bei :"C:\\temp\\Fahrtenbuch"
					-es muss Schreibberechtigung auf den vorhandenen Pfad "C:\\temp" vorhanden sein

				>> alternativ individuell festlegen, folgendes ist zu beachten:
					- 4 mal backslash!! "\\\\"
					- darf keine Leerzeichen enthalten
					
		*/
		//Bsp anderer Pfad: "C:\\\\Users\\\\..."

	struct File_Path
	{
		char seed_path[255];
		char file_pathein[255];
		char file_pathfz[255];
		char file_pathf[255];
		char name_datei_fahrer[20];
	};

	//Fahrteneintrag
	// 
	//(unspezifische Initialisierung in "eintrag.c" line 23)

	struct Eintrag {

		//eingelesene Größen
		char Kennzeichen[20];
		char Fahrername[50];
		char datum[11];
		float Liter;
		float Preis;
		char Name_Tankstelle[50];
		float km_Stand_alt;
		float km_Stand_neu;							//wenn nicht funktioniert, gefahrene km

		//berechnete Größen
		float km_gefahren;
		float d_verbr;								//Durchnittsverbrauch
		float p_l;									// Preis Pro liter

	};

	//Neues Fahrzeug
	// 
	//(spezifische Initialisierung in "nfz.c" line 19)

	struct Fahrzeug
	{
		char Kennzeichen[20];
		char Marke[50];
		char Autotyp[50];
		float kmAusgang;
	};

	//Neuer Fahrer
	// 
	//(spezifische Initialisierung in Fahrer.c
	struct Fahrer 
	{
		char Vorname[30];
		char Nachname[30];
		char Geburtstag[11];
		int Fahrernummer;
	};


//Deklarierung Funktionen
	
	int eintrag(struct File_Path, struct global_var);		//Neuen Eintrag in vorhandenes Fahrzeug
	int nfz(struct File_Path, struct global_var);			//Neues Fahrzeug anlegen
	int fahrer(struct File_Path, struct global_var);		//Neuen Fahrer Anlegen
	//int reset();		//Reset