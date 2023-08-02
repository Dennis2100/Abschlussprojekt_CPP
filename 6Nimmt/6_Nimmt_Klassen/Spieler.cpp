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
	LöscheGelegteHandkarte(index);

	return rueckgabe;
}

void Spieler::LöscheGelegteHandkarte(int index)
{
	Karte zwischenspeicher;

	zwischenspeicher = handkarten[index];
	handkarten[index] = handkarten[längeHandkartenIndex];
	handkarten[längeHandkartenIndex] = zwischenspeicher;

	längeHandkartenIndex--;
}

int Spieler::GetHandkartenIndexLaenge()
{
	return längeHandkartenIndex;
}