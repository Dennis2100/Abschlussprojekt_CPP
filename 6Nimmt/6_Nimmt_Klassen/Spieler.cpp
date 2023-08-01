#include "pch.h"
#include "Spieler.h"


Spieler::Spieler()
{
	int punktestand = 0;
	Karte handkarten[10]{};
}

void Spieler::SetPunktestand(int punktestand)
{
	this->punktestand = punktestand;
}

int Spieler::GetPunktestand()
{
	return punktestand;
}
