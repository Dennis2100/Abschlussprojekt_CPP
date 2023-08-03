#pragma once
#include "Karte.h"
#include "Spielfeld.h"

class Spieler
{
	

public:
	Spieler();

	void SetPunktestand(int punktestand);
	int GetPunktestand();
	void SetHandkarteBeiIndex(int index, Karte karte);
	Karte LegeHandkarte(int index);
	void LöscheGelegteHandkarte(int index);
	int GetHandkartenIndexLaenge();
	Karte GetHandkarteBeiIndex(int index);
	void SetGesetzteKarte(Karte karte);
	Karte GetGesetzteKarte();

	void ReiheNimmt(int spalte, Spielfeld * spielfeld);
	//void SechsNimmt();

	virtual Karte MachZug() abstract;
	virtual void AusgewaehlteReiheNehmen(Spielfeld * spielfeld) abstract;

protected:
	Karte handkarten[10];
	int punktestand = 0;
	int längeHandkartenIndex = 10;
	Karte gesetzteKarte;
};

