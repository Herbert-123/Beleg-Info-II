#include "Header.h"


//Neuen Fahrer Anlegen

int fahrer(File_Path fp, global_var gv) {

	FILE* nf;

	//Setzen Speicherpfad
	//Adress reset; nötig, da Adressberechnung sonst nur dateiendung anhängt -> "...\\ordner\\datei.xtx\\text.txt"
	memset(fp.file_pathf, 0, sizeof(fp.file_pathf));			//beschreibt file_pathein mit nur nullen
	strcat(fp.file_pathf, fp.seed_path);					//beschreibt file_pathein mit seed_path

	//Deklaration struct
	Fahrer f;
		strcpy(f.Vorname, "Vn");
		strcpy(f.Nachname, "Nn");
		strcpy(f.Geburtstag, "0");
		f.Fahrernummer = 0;
		strcpy(f.datei_name, "Fahrerdatenbank");

		//Überschrift
		printf("                                     <<< Neuen Fahrer anlegen: >>>\n\n\n");
		

		// Hier evtl. öffnen fahrer datei und hochzählen der Nummer
		//Pfadberechnung:
		strcat(fp.file_pathf, "\\\\");
		strcat(fp.file_pathf, f.datei_name);
		strcat(fp.file_pathf, ".txt");
		printf("\nDateipfad: %s \n", fp.file_pathf);

		// Öffen Datei; Modus: append -> datei neu erstellt neu erstellt
		nf = fopen(fp.file_pathf, "a+");

		//get vorherige Fahrernummer 5
		fseek(nf, -5L, SEEK_END);
		fscanf(nf, "%u", &f.Fahrernummer);
		f.Fahrernummer++;									//Fahrernummer um eins hochzählen
		printf("Fahrernummer: %u\n\n", f.Fahrernummer);


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


		//Put eingelesene Größen
			//einfügen Leerzeilen zu besseren Lesbarkeit
			fputs("\n", nf);
			fputs("\n", nf);

			fputs("Nachname, Vorname: ", nf);
			fputs(f.Nachname,nf);
			fputs(", ", nf);
			fputs(f.Vorname, nf);
			fputs("\n", nf);

			fputs("Geburtstag: ", nf);
			fputs("\n", nf);
			
			fputs("Fahrernummer: 00000", nf);
			fprintf(nf, "%i", f.Fahrernummer);

			fclose(nf);

			system("color 2E");
			system("PAUSE");

	return 0;
}