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
	L�scheGelegteHandkarte(index);

	SortierenHandkarten();

	return rueckgabe;
}

void Spieler::L�scheGelegteHandkarte(int index)
{
	Karte zwischenspeicher;

	zwischenspeicher = handkarten[index];
	handkarten[index] = handkarten[l�ngeHandkartenIndex - 1];
	handkarten[l�ngeHandkartenIndex - 1] = zwischenspeicher;

	l�ngeHandkartenIndex--;
}

int Spieler::GetHandkartenIndexLaenge()
{
	return l�ngeHandkartenIndex;
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

void Spieler::ReiheNimmt(int reihe, Spielfeld* spielfeld)
{
	Karte platzhalter;

	punktestand += spielfeld->getStrafpunkte(reihe);
	
	spielfeld->ReiheLeeren(reihe);
	spielfeld->KarteLegen(gesetzteKarte);
}

void Spieler::SortierenHandkarten()
{
	HeapSort();
}

void Spieler::HeapSort()
{
	//Heap bauen
	for (int i = l�ngeHandkartenIndex / 2 -1; i >= 0; i--)
	{
		Heapify(l�ngeHandkartenIndex, i);
	}

	//Elemente einzeln herausnehmen
	for (int i = l�ngeHandkartenIndex - 1; i >= 0; i--)
	{
		SwapHandkarten(0, i);	//Aktuellen root ans Ende bewegen

		Heapify(i, 0);			//Wieder Heapify auf den Unterbaum aufrufen
	}
}

void Spieler::Heapify(int index, int root)
{
	int largest = root;		//root ist das gr��te Element
	int l = 2 * root + 1;	//links = 2*root + 1
	int r = 2 * root + 2;	//rechts = 2*root + 2

	//Linkes Kindelement ist gr��er als root
	if (l < index && handkarten[l].getZahl() > handkarten[largest].getZahl())
	{
		largest = l;
	}

	//Rechtes Kindelement ist gr��er als root
	if (r < index && handkarten[r].getZahl() > handkarten[largest].getZahl())
	{
		largest = r;
	}

	//Gr��tes Element (largest) ist nicht root
	if (largest != root)
	{
		SwapHandkarten(root, largest);	//Vertauschen von root und dem gr��ten Element

		Heapify(index, largest);		//Heapify der Unterb�ume
	}
}

void Spieler::SwapHandkarten(int index1, int index2)
{
	Karte zwischenspeicher;

	zwischenspeicher = handkarten[index1];
	handkarten[index1] = handkarten[index2];
	handkarten[index2] = zwischenspeicher;
}
