#include "Header.h"

/* -------------------------------------------------
		Neuen Eintrag in vorhandenes Fahrzeug
-------------------------------------------------- */

int eintrag(File_Path fp ,global_var gv) {

	FILE* ne;
	
	int fzz = gv.Nrierr;
	int i = 0;												//Laufvariable

	//Setzen Speicherpfad
	//Adress reset; nötig, da Adressberechnung sonst nur dateiendung anhängt -> "...\\ordner\\datei.xtx\\text.txt"
	memset(fp.file_pathein, 0, sizeof(fp.file_pathein));			//beschreibt file_pathein mit nur nullen
	strcat(fp.file_pathein, fp.seed_path);					//beschreibt file_pathein mit seed_path
	

	// Variablen Definition ursprünglich hier

	//Initialisierung struct
	struct Eintrag e = { "0", "0", "0", 0, 0, "0", 0, 0, 0, 0, 0 };
	

	//Überschrift
	printf("                                     <<< Neuer Fahrteintrag: >>>\n\n\n");

	
	//Kennzeicheneingabe und Fehlerprüfung

	/*
	printf("Bitte geben Sie das Kennzeichen ein:                              Beipiel Syntax: 'AA-BB-0000'\n");
	scanf_s("%19s", &e.Kennzeichen, 20);
	fflush(stdin);
	*/

	//Pfadberechnung:
	/*
	strcat(fp.file_pathein, "\\\\");
	strcat(fp.file_pathein, e.Kennzeichen);
	strcat(fp.file_pathein, ".txt");
	printf("\nDateipfad: %s \n", fp.file_pathein);
	*/

	//fflush(stdin);

	for (size_t i = 0; i < fzz; i++)
	{
		printf("Bitte geben Sie das Kennzeichen ein:                              Beipiel Syntax: 'AA-BB-0000'\n");
		scanf_s("%19s", &e.Kennzeichen, 20);
		fflush(stdin);

		strcat(fp.file_pathein, "\\\\");
		strcat(fp.file_pathein, e.Kennzeichen);
		strcat(fp.file_pathein, ".txt");

		struct stat buffer;
		int check=stat(fp.file_pathein, &buffer);

		if (check == 0) { 
			printf("\n aufgerufene Datei: %s \n", fp.file_pathein);
			break; 
		}
		
		//Beenden Funktion wenn Fehlereingabe zu hoch
		else if (i==fzz-1)
			{
			system("color 4A");
			printf("\n\n Zu viele Fehleingaben Programm wird beendet.\n");
			exit(0);
			}

		else{
			printf("\nUngueltige Datei: %s \n", fp.file_pathein);
			printf("Fahrzeug konnte nicht gefunden werden! Bitte ueberpruefen Sie Ihre Eingabe!\n\n");

			//Adress reset
			memset(fp.file_pathein, 0, sizeof(fp.file_pathein));
			strcat(fp.file_pathein, fp.seed_path);
			}

		
	}

	
	printf("Check complete");

	
	
	
	// Öffen Datei; Modus: read
		ne = fopen(fp.file_pathein, "r");

		//get und Anzeige vorheriger km Stand
		fseek(ne, -14L, SEEK_END);
		fscanf(ne, "%f", &e.km_Stand_alt);
		printf("\nDer letzte km Stand war: %f\n", e.km_Stand_alt);

		fclose(ne);

	fflush(stdin);
	// Öffen Datei; Modus: Append
	ne = fopen(fp.file_pathein, "a");

		//Fehlerüberprüfung
		if (ne == NULL){printf("Fahrzeug konnte nicht gefunden werden! Bitte ueberpruefen Sie das Kennzeichen!\n");}

		/*-------------------------------
		      Einlesen aller Größen
		--------------------------------*/
		// Eingabe Fahrername
		printf("Geben Sie bitte Ihren Namen ein:\n");
		while ((getchar()) != '\n');
		fgets(e.Fahrername, sizeof(e.Fahrername), stdin);
		

		// Eingabe Datum
		printf("Geben Sie bitte das Datum ein (tt.mm.jjjj):\n");
		//while ((getchar()) != '\n');
		fgets(e.datum, sizeof(e.datum), stdin);
		
	
		//Eingabe Liter
		printf("Bitte geben Sie die getankten Liter ein:	");
		scanf_s("%f", &e.Liter);
		
	
		//Eingabe Preis
		printf("Bitte geben Sie den bezahlten Preis ein:	");
		scanf_s("%f", &e.Preis);
		
	
		// Eingabe Name Tankstelle
		printf("Geben Sie bitte den Namen der Tankstelle ein:\n");
		while ((getchar()) != '\n');
		fgets(e.Name_Tankstelle, sizeof(e.Name_Tankstelle), stdin);
		
	
		//Eingabe jetziger km Stand
		printf("Bitte geben Sie den jetzigen km-Stand ein:	");
		for (i = 0; i < fzz; i++)
		{
			scanf_s("%f", &e.km_Stand_neu);
			if (e.km_Stand_neu > e.km_Stand_alt){break;}
			printf("Fehlerhafte Eingabe! Bitte wiederholen: ");
		}

			// Abbruch bei zu hoher Fehlerzahl(>Nrierr)
			if (i == fzz) {
				system("color 4A");
				printf("\n\n Zu viele Fehleingaben Programm wird beendet.\n");
				exit(0); 
			}
	
		//-------------Berechnng und Put Größen----------------
		printf("");
	
		//gefahrene km
		e.km_gefahren = e.km_Stand_neu - e.km_Stand_alt;
		printf("\n\ngefahrene km: %f\n", e.km_gefahren);
		
	
		// Durchnschnittsverbrauch
		e.d_verbr = e.Liter / e.km_gefahren *100;
		printf("Durchschnittsverbrauch l / 100km: % f\n", e.d_verbr);
		
	
		// Preis pro Liter
		e.p_l = e.Preis / e.Liter;
		printf("Preis pro Liter: %f\n\n", e.p_l);
		
		
		
		//Put aller Größen
			//einfügen Leerzeilen zu besseren Lesbarkeit
			fputs("\n", ne);
			fputs("\n", ne);

		fputs(e.Fahrername, ne);
		fputs(e.datum, ne);
		fprintf(ne, "%f", e.Liter);
		fputs("\n", ne);
		fprintf(ne, "%f", e.Preis);
		fputs("\n", ne);
		fputs(e.Name_Tankstelle, ne);
		fprintf(ne, "%f", e.km_gefahren);
		fputs("\n", ne);
		fprintf(ne, "%f", e.d_verbr);
		fputs("\n", ne);
		fprintf(ne, "%f", e.p_l);
		fputs("\n", ne);

		//Put jetziger km Stand
		fputs("\n", ne);
		fputs("\n", ne);
		fprintf(ne, "%f", e.km_Stand_neu);

		fclose(ne);

		system("color 2E");
		system("PAUSE");

	return 0;
}
