#pragma once
#include "Spielfeld.h"
#include "Deck.h"
#include "Bot.h"
#include "Mensch.h"
class Steuerung
{


public:

	Steuerung();												//Standardkonstruktor für Steuerung

	void StarteSpiel();											//Startet das Spiel 
	bool PrüfeEingabe();										//Prüfe ob der Eingegebene Index der Handkarten korrekt ist
	void EintragSpielfeld();									//Lege die gewählten karten
	void SechsNimmt();											//Falls 6 Karten in einer Reihe sind, nimmt derjenige der die 6. Karte gelegt hat
	void GebenHandkarten(Deck deck, Bot bot, Mensch mensch);	//Verteilen der Handkarten
	void ErstenVier(Spielfeld spielfeld, Deck deck);			//Einsetzen der ersten 4 Karten auf das Spielfeld
	void PrüfenGelegteKarte();									//Prüfen der gelegten Karte ob sie kleiner ist als di Karten in der 4. Reihe
};

