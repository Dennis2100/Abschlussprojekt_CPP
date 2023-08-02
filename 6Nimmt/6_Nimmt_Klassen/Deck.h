#pragma once
#include "Karte.h"
class Deck
{
	Karte deck[104];
	int deckLänge;

public:
	Deck();

	Karte Dealer();
	int ErmittlungStrafpunkte(int zahl);
	void KarteAusDeckLöschen(int index);
};

