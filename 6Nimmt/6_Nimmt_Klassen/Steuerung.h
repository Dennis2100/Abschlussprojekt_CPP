#pragma once
#include "Spielfeld.h"
#include "Deck.h"
#include "Bot.h"
#include "Mensch.h"
#include "UI.h"

class Steuerung
{


public:

	Steuerung();																		//Standardkonstruktor für Steuerung

	void StarteSpiel();																	//Startet das Spiel 
	//void SechsNimmt(Spieler* spieler, Spielfeld* spielfeld);							//Falls 6 Karten in einer Reihe sind, nimmt derjenige der die 6. Karte gelegt hat
	void GebenHandkarten(Deck * deck, Spieler * bot, Spieler * mensch);					//Verteilen der Handkarten
	void ErstenVier(Spielfeld * spielfeld, Deck * deck);								//Einsetzen der ersten 4 Karten auf das Spielfeld
	//void AusgewaehlteReiheNehmen(Spieler* spieler, Spielfeld* spielfeld);
	//void ReiheNimmt(int reihe, Spieler * spieler, Spielfeld* spielfeld);
	void BotWahl(Spieler * bot, UI ui);
};

