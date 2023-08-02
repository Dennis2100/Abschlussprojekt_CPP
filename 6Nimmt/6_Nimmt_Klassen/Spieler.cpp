#include "pch.h"
#include "Spieler.h"


Spieler::Spieler()
{
	
}

void Spieler::SetPunktestand(int punktestand)
{
	this->punktestand = punktestand;
}

int Spieler::GetPunktestand()
{
	return punktestand;
}

void Spieler::SetHandkarteBeiIndex(int index, Karte karte)
{
	handkarten[index] = karte;
}

Karte Spieler::LegeHandkarte(int index)
{
	Karte rueckgabe;

	rueckgabe = handkarten[index];
	L�scheGelegteHandkarte(index);

	return rueckgabe;
}

void Spieler::L�scheGelegteHandkarte(int index)
{
	Karte zwischenspeicher;

	zwischenspeicher = handkarten[index];
	handkarten[index] = handkarten[l�ngeHandkartenIndex];
	handkarten[l�ngeHandkartenIndex] = zwischenspeicher;

	l�ngeHandkartenIndex--;
}

int Spieler::GetHandkartenIndexLaenge()
{
	return l�ngeHandkartenIndex;
}