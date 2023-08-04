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
	void AusgabeHandkarten(Karte * handkarten, int l�ngeHandkartenIndex, int gewahelteKarte);  //Graphische Ausgabe der Handkarten des Menschspielers
	int EingabeKarte(Karte* handkarten, int l�ngeHandkartenIndex);															               //Auswahl der zu legenden Karte f�r den Menschspieler
	void SiegerEhrung(Spieler * spieler1, Spieler * spieler2);					               //Ermittlung des Gewinners
	int AuswahlReiheNehmen(Spielfeld* spielfeld);												                   //Ausgabe f�r Mensch welche Reihe er nehmen m�chte
	int IstSpielerMensch();														               //Abfrage ob man selber spielen m�chte

};

