#pragma once
#include "Spielfeld.h"
#include "Mensch.h"
#include "Bot.h"

class UI
{


public:

	UI();

	void AusgabeSpielfeld(Spielfeld * spielfeld);								//Aktuelles Spielfeld ausgeben
	int AbfrageBot();															//Frage welcher Bot verwendet werden soll
	void AusgabeHandkarten(Karte * handkarten, int l�ngeHandkartenIndex);		//Graphische Ausgabe der Handkarten des Menschspielers
	int EingabeKarte();															//Auswahl der zu legenden Karte f�r den Menschspieler
	void SiegerEhrung(Spieler * spieler1, Spieler * spieler2);					//Ermittlung des Gewinners
	int AuswahlReiheNehmen();													//Ausgabe f�r Mensch welche Reihe er nehmen m�chte
	int IstSpielerMensch();														//Abfrage ob man selber spielen m�chte

};

