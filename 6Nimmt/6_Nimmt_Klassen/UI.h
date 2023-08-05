#pragma once
#include "Spielfeld.h"
#include "Mensch.h"
#include "Bot.h"

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

};

