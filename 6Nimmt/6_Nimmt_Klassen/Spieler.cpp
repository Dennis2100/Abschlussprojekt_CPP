#include "pch.h"
#include "Spieler.h"
#include <iostream>

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
	Karte rueckgabe = handkarten[index];
	LöscheGelegteHandkarte(index);

	SortierenHandkarten();

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

Karte Spieler::GetHandkarteBeiIndex(int index)
{
	return handkarten[index];
}

void Spieler::SetGesetzteKarte(Karte karte)
{
	gesetzteKarte = karte;
}

Karte Spieler::GetGesetzteKarte()
{
	return gesetzteKarte;
}

std::string Spieler::GetName()
{
	return name;
}

void Spieler::ReiheNimmt(int spalte, Spielfeld* spielfeld)
{
	int strafpunkte = 0;
	Karte platzhalter;

	for (int i = 0; i < 5; i++)
	{
		strafpunkte += spielfeld->GetSpielfeld(i, spalte).getStrafpunkte();
		spielfeld->SetSpielfeld(i, spalte, platzhalter);
	}

	spielfeld->SetSpielfeld(5, spalte, platzhalter);

	spielfeld->SetSpielfeld(0, spalte, gesetzteKarte);

	punktestand = strafpunkte;
}

void Spieler::SortierenHandkarten()
{
	HeapSort();
}

void Spieler::HeapSort()
{
	for (int i = längeHandkartenIndex / 2 -1; i >= 0; i--)
	{
		Heapify(längeHandkartenIndex, i);
	}

	for (int i = längeHandkartenIndex - 1; i >= 0; i--)
	{
		SwapHandkarten(0, i);

		Heapify(i, 0);
	}
}

void Spieler::Heapify(int index, int root)
{
	int largest = root;
	int l = 2 * root + 1;
	int r = 2 * root + 2;

	if (l < index && handkarten[l].getZahl() > handkarten[largest].getZahl())
	{
		largest = l;
	}

	if (r < index && handkarten[r].getZahl() > handkarten[largest].getZahl())
	{
		largest = r;
	}

	if (largest != root)
	{
		SwapHandkarten(root, largest);

		Heapify(index, largest);
	}
}

void Spieler::SwapHandkarten(int index1, int index2)
{
	Karte zwischenspeicher;

	zwischenspeicher = handkarten[index1];
	handkarten[index1] = handkarten[index2];
	handkarten[index2] = zwischenspeicher;
}
