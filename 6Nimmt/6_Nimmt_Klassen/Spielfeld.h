#pragma once
#include "Karte.h"
#define max_diff 105; //initialer Wert fuer die Unterschied zwischen Karten auf dem Spielfeld 

class Spielfeld
{

	Karte spielfeld[4][6];
	int kartenzahl[4] = { 0,0,0,0 };

public:

	Spielfeld();

	Karte GetSpielfeld(int reihe, int spalte);
	void SetSpielfeld(int reihe, int spalte, Karte karte);
	int KarteLegen(Karte karte);
	int GetKartenAnzahl(int reihe);
};

