#pragma once
#include "Spielfeld.h"
#include "Mensch.h"
#include "Bot.h"

class UI
{


public:

	UI();																					   //Standardkonstruktor

	void ScreenVorbereiten();																   //
	void ScreenLoeschen();																	   //L�scht die aktuelle Ausgabe
	void SpielerStand(Spieler* spieler1, Spieler* spieler2);								   //Gibt den aktuellen Spielstand aus
	void AusgabeSpielfeld(Spielfeld * spielfeld,int activeReihe);				               //Aktuelles Spielfeld ausgeben
	int AbfrageBot();															               //Frage welcher Bot verwendet werden soll
	void AusgabeHandkarten(Karte * handkarten, int l�ngeHandkartenIndex, int gewahelteKarte);  //Graphische Ausgabe der Handkarten des Menschspielers
	int EingabeKarte(Karte* handkarten, int l�ngeHandkartenIndex);				               //Auswahl der zu legenden Karte f�r den Menschspieler
	void SiegerEhrung(int sieger, Spieler* spieler1, Spieler* spieler2);					   //Nennung des Gewinners
	int AuswahlReiheNehmen(Spielfeld* spielfeld);											   //Ausgabe f�r Mensch welche Reihe er nehmen m�chte
	int IstSpielerMensch();														               //Abfrage ob man selber spielen m�chte

};

