#pragma once
#include "Karte.h"
class Deck
{
	Karte deck[104];
	int deckL�nge;

public:
	Deck();

	Karte Dealer();
	int ErmittlungStrafpunkte(int zahl);
	void KarteAusDeckL�schen(int index);
};

