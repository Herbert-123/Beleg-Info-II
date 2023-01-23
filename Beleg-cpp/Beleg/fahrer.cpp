#include "Header.h"


//Neuen Fahrer Anlegen

int fahrer(File_Path fp, global_var gv) {

	FILE* ne;

	//Setzen Speicherpfad
	//Adress reset; n�tig, da Adressberechnung sonst nur dateiendung anh�ngt -> "...\\ordner\\datei.xtx\\text.txt"
	memset(fp.file_pathf, 0, sizeof(fp.file_pathf));			//beschreibt file_pathein mit nur nullen
	strcat(fp.file_pathf, fp.seed_path);					//beschreibt file_pathein mit seed_path

	//Deklaration struct
	Fahrer f;
		strcpy(f.Vorname, "Vn");
		strcpy(f.Nachname, "Nn");
		strcpy(f.Geburtstag, "0");
		f.Fahrernummer = 0;

		//�berschrift
		printf("                                     <<< Neuen Fahrer anlegen: >>>\n\n\n");
		printf("Es muss bereits eine Datei zu den Fahrer*innen vorhanden sein.\n");

		// Hier evtl. �ffnen fahrer datei und hochz�hlen der Nummer


		//Eingabe Daten Fahrer
			//Vorname
			printf("Bitte geben Sie Ihren Vornamen ein:\n");
			scanf_s("%29s", &f.Vorname, 30);

			//Nachname
			printf("Bitte geben Sie Ihren Nachnamen ein:\n");
			scanf_s("%29s", &f.Nachname, 30);

			//Geburtstag
			printf("Bitte geben Sie Ihren Geburtstag ein (tt.mm.jjjj):\n");
			scanf_s("%11s", &f.Geburtstag, 11);

			//get vorherige Fahrernummer 5 stellig +\n\n
			fseek(ne, -7L, SEEK_END);
			fscanf(ne, "%i", &f.Fahrernummer);
			f.Fahrernummer++;						//Fahrernummer um eins hochz�hlen

	/*
			//Pfadberechnung:
			strcat(fp.file_pathf, "\\\\");
			strcat(fp.file_pathf, f.Fahrernummer);
			strcat(fp.file_pathf, ".txt");
			printf("\nDateipfad: %s \n", fp.file_pathf);

			// �ffen Datei; Modus: read
			ne = fopen(fp.file_pathf, "r");

	*/

	return 0;
}