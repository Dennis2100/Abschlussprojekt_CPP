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
	void GebenHandkarten(Deck * deck, Spieler * bot, Spieler * mensch);					//Verteilen der Handkarten
	void ErstenVier(Spielfeld * spielfeld, Deck * deck);								//Einsetzen der ersten 4 Karten auf das Spielfeld
	void BotWahl(Spieler * bot, UI ui);													//Auswahl des Bots
};

