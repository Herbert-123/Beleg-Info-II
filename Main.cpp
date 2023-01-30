#include "Header.h"


int main() {

	//Deklaration Globale Variablen
	global_var gv;
	gv.quit = 0;
	gv.Nrierr = 10;							//zulässige Fehlerzahl	- Nr input Error
	gv.Auswahl = 0;

	//Deklaration Filepath
	File_Path fp;
		strcpy(fp.seed_path, "C:\\\\temp\\\\Fahrtenbuch");
		strcpy(fp.file_pathein, "0");
		strcpy(fp.file_pathfz, "0");
		strcpy(fp.file_pathf, "0");
	
	//neuen Ordner erstellen, beide folgende Zeilen evtl. auskommentieren
	char mkdir(*fp.seed_path);
	//char seed_path[255] = "C:\\\\temp\\\\Fahrtenbuch";

	//Laufvariable
	int i = 0;

	while (gv.quit!=1)
	{		
		printf("                                             +-------------+\n                                             | Fahrtenbuch |\n                                             +-------------+\n");

		//Ausgabe seed_path
		printf("Der festgelegte Speicherpfad ist: %s\\\\* \n\n", fp.seed_path);

		printf("Bitte waehlen Sie Ihre Aktion:\n\n");
		printf("		1: Neuer Fahrtenbucheintrag (vorhandenes Fahrzeug)\n		2: Neues Fahrzeug anlegen\n		3: Neuen Fahrer anlegen\n		5: Ende\n\n");
		
		for ( i = 0; i < gv.Nrierr; i++)
		{
			printf("Ihre Wahl : < >\b\b");
			int p=scanf_s("%i", &gv.Auswahl);
			fflush(stdin);

			//Richtige Eingabe
			if (gv.Auswahl > 0 && gv.Auswahl < 6) { break; }

			printf("\nFehlerhafte Eingabe, bitte Eingabe wiederholen!\n");

			printf("Anzahl Runde: %i\n", i);
		}
		if (gv.Auswahl == 5 || i== gv.Nrierr) { gv.quit = 1; }												// Abbruch bei Auswahl Ende(5) oder zu hoher Fehlerzahl(>Nrierr)

		printf("\n\n");

		switch (gv.Auswahl)
		{
			//Neuer Fahrtenbucheintrag
			case 1:
				eintrag(fp, gv);
				break;

			//Neues Fahrzeug anlegen
			case 2:
				nfz(fp,gv);
				break;

			//Neuer Fahrereintrag
			case 3:
				fahrer(fp,gv);
				break;

		}
		
		system("pause");
		//Bildschirm bereinigen
		system("cls");
	}
	system("color 1F");
	printf("\n\n\n\n\n\n\nEnde!\n--------------------------------------\n");
}

