#pragma once
#include "Spielfeld.h"
#include "Mensch.h"
#include "Bot.h"

#define LINKS 75
#define RECHTS 77
#define OBEN 72
#define UNTEN 80
#define ENTER 13
#define KARTE_BREITE 14
#define KARTE_HOEHE  10

class UI
{


public:

	UI();																					   //Standardkonstruktor

	void ScreenVorbereiten();																   //
	void ScreenLoeschen();																	   //Löscht die aktuelle Ausgabe
	void SpielerStand(Spieler* spieler1, Spieler* spieler2);								   //Gibt den aktuellen Spielstand aus
	void AusgabeSpielfeld(Spielfeld * spielfeld,int activeReihe);				               //Aktuelles Spielfeld ausgeben
	int AbfrageBot();															               //Frage welcher Bot verwendet werden soll
	void AusgabeHandkarten(Karte * handkarten, int längeHandkartenIndex, int gewahelteKarte);  //Graphische Ausgabe der Handkarten des Menschspielers
	int EingabeKarte(Karte* handkarten, int längeHandkartenIndex);				               //Auswahl der zu legenden Karte für den Menschspieler
	void SiegerEhrung(int sieger, Spieler* spieler1, Spieler* spieler2);					   //Nennung des Gewinners
	int AuswahlReiheNehmen(Spielfeld* spielfeld);											   //Ausgabe für Mensch welche Reihe er nehmen möchte
	int IstSpielerMensch();														               //Abfrage ob man selber spielen möchte
	
private:	

	const static int farben[];

	void karte_zeichnen(Karte karte, short x, short y, bool gewaehlt = false);
	void zeichnen_linie(short xl, short yl, char char1, char char2, char char3, int wiederholen);
	void zeichne_kopf(short xk, short yk);
	void zeichnen_kartennummer(short xm1, short ym1, int zahl);
	void zeichnen_strafpunkte(short x, short y, int punkte);
	void SetCursorPosition(short x, short y);	//Setzt den Cursor an eine ausgewählte Stelle
	void SetTextColor(int col);				//Setzt eine Farbe durch einen index
};

