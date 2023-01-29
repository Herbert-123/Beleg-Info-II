#include "Header.h"

/* -------------------------------------------------
				Neus Fahrzeug anlegen
-------------------------------------------------- */
int nfz(File_Path fp, global_var gv)
{

	FILE* nfzp;

	Fahrzeug snfz;
		strcpy(snfz.Kennzeichen, "0");
		strcpy(snfz.Marke, "0");
		strcpy(snfz.Autotyp, "0");
		snfz.kmAusgang = 0;

	//Überschrift
	printf("                                     <<< Neues Fahrzeug anlegen: >>>\n\n\n");
	printf("Bitte beachten Sie, dass bereits vorhendene Fahrzeuge mit dem selben Kennzeichen ueberschrieben werden!\n\n");

	//Eingabe Kennzeichen
	printf("Bitte geben Sie das Kennzeichen ein:                              Beipiel Syntax: 'AA-BB-0000'\n");
	scanf_s("%19s", &snfz.Kennzeichen,20);

	//Pfadberechnung:
	strcat(fp.file_pathfz, "\\\\");
	strcat(fp.file_pathfz, snfz.Kennzeichen);
	strcat(fp.file_pathfz, ".txt");
	printf("Dateipfad: %s \n", fp.file_pathfz);

	fflush(stdin);

	//öffen neuer Datei oder überschreiben Datei mit gleichem Kennzeichen
	nfzp = fopen(fp.file_pathfz, "w");

	//Überprüfung ob Datei geöffnet wird bzw. Pfad
	if (nfzp == NULL) { printf("Fehler beim Oeffnen! Bitte ueberpruefe deinen Pfad!\n");}

	//Put Kennzeichen in Datei
	fputs("Kennzeichen:			", nfzp);									//Feldbezeichnung
	fputs(snfz.Kennzeichen, nfzp);
	fputs("\n", nfzp);
	
	//Eingabe und Put Marke
	printf("Bitte geben Sie die Marke ein:				");
	while ((getchar()) != '\n');
	fgets(snfz.Marke, sizeof(snfz.Marke), stdin);
	fputs("Marke:				", nfzp);										//Feldbezeichnung
	fputs(snfz.Marke, nfzp);
	//fputs("\n", nfzp);
	
	//Eingabe und Put Autotyp
	printf("Bitte geben Sie den Autotyp ein:			");
	scanf_s("%49s", snfz.Autotyp, 50);
	fputs("Autotyp:				", nfzp);									//Feldbezeichnung
	fputs(snfz.Autotyp, nfzp);
	fputs("\n", nfzp);

	//Eingabe und Put Ausgangs Kilometer Stand
	printf("Bitte geben Sie den Ausgangs Kilometer Stand ein:	");
	scanf_s("%f", &snfz.kmAusgang);
	fprintf(nfzp, "Ausgangskilometerstand:		");							//Feldbezeichnung
	fprintf(nfzp, "%f", snfz.kmAusgang);
	
	fclose(nfzp);
	system("PAUSE");
	return 0;
}