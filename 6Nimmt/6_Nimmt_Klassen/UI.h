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

	UI();																									//Standardkonstruktor
	~UI();																									//Standardkonstruktor

	void ScreenVorbereiten();																				//
	void ScreenLoeschen();																					//Löscht die aktuelle Ausgabe
	void SpielerStand(Spieler* spieler1, Spieler* spieler2);												//Gibt den aktuellen Spielstand aus
	void AusgabeSpielfeld(Spielfeld * spielfeld, const int activeReihe);									//Aktuelles Spielfeld ausgeben
	int AbfrageBot();																						//Frage welcher Bot verwendet werden soll
	void AusgabeHandkarten(Karte * handkarten, const int längeHandkartenIndex, const int gewahelteKarte);   //Graphische Ausgabe der Handkarten des Menschspielers
	void ZeigeZug(Spieler* spieler1, Spieler* spieler2);
	int EingabeKarte(Karte* handkarten, const int längeHandkartenIndex);									//Auswahl der zu legenden Karte für den Menschspieler
	void SiegerEhrung(const int sieger, Spieler* spieler1, Spieler* spieler2);								//Nennung des Gewinners
	int AuswahlReiheNehmen(Spielfeld* spielfeld);															//Ausgabe für Mensch welche Reihe er nehmen möchte
	int IstSpielerMensch();																					//Abfrage ob man selber spielen möchte
	
private:	

	const static int farben[];

	void Karte_Zeichnen(Karte karte, const short x, const short y, bool gewaehlt = false);
	void Zeichnen_Linie(const short xl, const short yl, char char1, char char2, char char3, const int wiederholen);
	void Zeichne_Kopf(const short xk, short yk);
	void Zeichnen_Kartennummer(short xm1, short ym1, const int zahl);
	void Zeichnen_Strafpunkte(const short x, const short y, const int punkte);
	void SetCursorPosition(const short x, const short y);													//Setzt den Cursor an eine ausgewählte Stelle
	void SetTextColor(const int col);																		//Setzt eine Farbe durch einen index
};

