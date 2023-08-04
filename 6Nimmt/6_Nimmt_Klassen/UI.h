#pragma once
#include "Spielfeld.h"
#include "Mensch.h"
#include "Bot.h"

class UI
{


public:

	UI();

	void ScreenVorbereiten();
	void ScreenLoeschen();
	void SpielerStand(Spieler* spieler1, Spieler* spieler2);
	void AusgabeSpielfeld(Spielfeld * spielfeld,int activeReihe);				               //Aktuelles Spielfeld ausgeben
	int AbfrageBot();															               //Frage welcher Bot verwendet werden soll
	void AusgabeHandkarten(Karte * handkarten, int längeHandkartenIndex, int gewahelteKarte);  //Graphische Ausgabe der Handkarten des Menschspielers
	int EingabeKarte(Karte* handkarten, int längeHandkartenIndex);															               //Auswahl der zu legenden Karte für den Menschspieler
	void SiegerEhrung(Spieler * spieler1, Spieler * spieler2);					               //Ermittlung des Gewinners
	int AuswahlReiheNehmen(Spielfeld* spielfeld);												                   //Ausgabe für Mensch welche Reihe er nehmen möchte
	int IstSpielerMensch();														               //Abfrage ob man selber spielen möchte

};

