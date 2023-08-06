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

	Steuerung();																														//Standardkonstruktor
	~Steuerung();

	int StarteSpiel(const int istSpielerMensch, const int botWahl1, const int botWahl2, bool konsolenausgabe=true, const int seek=0);	//Startet das Spiel																						//Startet das Spiel 
	void GebenHandkarten(Deck * deck, Spieler * spieler);																				//Verteilen der Handkarten
	void ErstenVier(Spielfeld * spielfeld, Deck * deck);																				//Einsetzen der ersten 4 Karten auf das Spielfeld
	void WerDarfAnfangen(Karte gewaelteKarte1, Karte gewaelteKarte2, Spielfeld * spielfeld, Spieler * spieler1, Spieler * spieler2);	//Abfrage wer Anfangen darf, Karte wird direkt gesetzt
	void spielerLegtKarten(Spielfeld* spielfeld, Spieler* spieler, Karte karte);														//Simuliert das Legen einer Karte auf das Spielfeld
	int SiegerBestimmung(Spieler* spieler1, Spieler* spieler2);																			//Bestimmt wer Gewonnen hat
	Spieler * BotWahl(const int nummer);																								//Bibt den Ausgewählten Bot zurück
};

