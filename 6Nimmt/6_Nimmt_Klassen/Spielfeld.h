#pragma once
#include "Karte.h"
class Spielfeld
{

	Karte spielfeld[4][6];

public:

	Spielfeld();

	Karte GetSpielfeld(int reihe, int spalte);
	void SetSpielfeld(int reihe, int spalte, Karte karte);
};

