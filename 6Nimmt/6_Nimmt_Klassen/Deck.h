#pragma once
#include "Karte.h"
class Deck
{

	Karte deck[104];

public:
	Deck();

	Karte Dealer();
	int ErmittlungStrafpunkte(int zahl);
};

