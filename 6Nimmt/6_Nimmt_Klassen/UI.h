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
	void AusgabeHandkarten(Karte * handkarten, int längeHandkartenIndex);		//Graphische Ausgabe der Handkarten des Menschspielers
	int EingabeKarte();															//Auswahl der zu legenden Karte für den Menschspieler
	void SiegerEhrung(Spieler *bot, Spieler *mensch);							//Ermittlung des Gewinners
	int AuswahlReiheNehmen();
	int IstSpielerMensch();

};

