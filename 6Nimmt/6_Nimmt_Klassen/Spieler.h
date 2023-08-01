#pragma once
#include "Karte.h"

class Spieler
{
	int punktestand;
	Karte handkarten[];

public:
	Spieler();

	void SetPunktestand(int punktestand);
	int GetPunktestand();
	Karte SetzeKarte();
};

