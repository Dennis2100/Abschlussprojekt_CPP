#pragma once
#include "Karte.h"
class Deck
{

public:
	Deck();										//Standart-Konstruktor

	Karte Dealer();								//Gibt eine Zufällige Karte aus den noch vorhandenen Karten im Deck zurück
	void KarteAusDeckLöschen(const int index);  //Löscht eine Karte aus dem Deck
	void SetRandomizer(const int seek);			//Hilft eine Zufallszahl zu generieren

private:
	Karte deck[104];
	int deckLänge;
	int randomizer = 0;
};

