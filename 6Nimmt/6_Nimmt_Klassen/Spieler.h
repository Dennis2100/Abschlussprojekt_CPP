#pragma once
#include "Karte.h"

class Spieler
{
	int punktestand = 0;
	int längeHandkartenIndex = 9;

public:
	Spieler();

	void SetPunktestand(int punktestand);
	int GetPunktestand();
	void SetHandkarteBeiIndex(int index, Karte karte);
	Karte LegeHandkarte(int index);
	void LöscheGelegteHandkarte(int index);
	int GetHandkartenIndexLaenge();

protected:
	Karte handkarten[10];
};

