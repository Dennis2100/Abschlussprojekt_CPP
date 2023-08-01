#include "pch.h"
#include "Spielfeld.h"
#include "Karte.h"

Spielfeld::Spielfeld()
{
	Karte spielfeld[4][6]{};
}

Karte Spielfeld::GetSpielfeld(int reihe, int spalte)
{
	return spielfeld[spalte][reihe];
}

void Spielfeld::SetSpielfeld(int reihe, int spalte, Karte karte)
{
	spielfeld[spalte][reihe] = karte;
}
