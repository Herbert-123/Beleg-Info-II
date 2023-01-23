# Beleg-Info-II

Beleg Vorarbeit vom letzten Jahr weiterentwickelt
mit struct
  -Problem: Speicherpfad "struct File_Path" muss in jedem .c - file neu Deklariert werden
  
 ausmodularisiert in 
  - header.h: Variablen in struct, Funktionsdeklrationen
  - eintrag.c: Neuer Eintrag in vorhandenes Fahrzeug, Aufruf .txt - Datei und beschreiben mit neuer Fahrt
  - nfz.c: Erstellung neues Fahrzeug mit Grundinfos
  - fahrer.c:  soll neuen Fahrer anlegen, Dateioperationen fehlen, Muss noch entschieden werden

to-Do:
  -input Fehler abfangen (for schleife mit "Nrierr oder mit advaced input Funktion")
  -eintrag.c:
      - überprüfen wie letzter km stand ausgelesen wird
      - Überprüfung ob beim Anlegen eines neuen Fahrzeuges ob km-Stand Kommazahl ist
  -fahrer.c weiterschreiben:
      -eine Datei mit allen Fahrern? ->automatisch laufende Nummer vergeben?
      - Dateioperationen
