#pragma once
#include "Spielfeld.h"
#include "Deck.h"
#include "Bot.h"
#include "Mensch.h"
#include "UI.h"
#include "Karte.h"

class Steuerung
{


public:

	Steuerung();																														//Standardkonstruktor für Steuerung

	void StarteSpiel();																													//Startet das Spiel 
	void GebenHandkarten(Deck * deck, Spieler * spieler);																	//Verteilen der Handkarten
	void ErstenVier(Spielfeld * spielfeld, Deck * deck);																				//Einsetzen der ersten 4 Karten auf das Spielfeld
	void BotWahl(Spieler * bot, UI ui);																									//Auswahl des Bots
	void WerDarfAnfangen(Karte gewaelteKarte1, Karte gewaelteKarte2, Spielfeld * spielfeld, Spieler * spieler1, Spieler * spieler2);	//Abfrage wer Anfangen darf, Karte wird direkt gesetzt
	void spielerLegtKarten(Spielfeld* spielfeld, Spieler* spieler, Karte karte);
};

