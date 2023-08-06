#include "pch.h"
#include "Spieler.h"
#include <iostream>

Spieler::Spieler()
{
}

Spieler::~Spieler()
{
}

void Spieler::SetPunktestand(const int punktestand)
{
	this->punktestand = punktestand;
}

/* Gibt die Summe bis jetzt gesammelten Straffpunkten des Spielers zurueck */
int Spieler::GetPunktestand()
{
	return punktestand;
}

//Eine Handkarte beim angegebenen Index setzen
void Spieler::SetHandkarteBeiIndex(const int index, Karte karte)
{
	handkarten[index] = karte;
}

//Die gelegte karte wird ausgegeben und danach aus den Handkarten gelöscht
Karte Spieler::LegeHandkarte(const int index)
{
	Karte rueckgabe = handkarten[index];
	LoescheGelegteHandkarte(index);

	SortierenHandkarten();

	return rueckgabe;
}

//Methode zum Löschen der gelegten Handkarte
void Spieler::LoescheGelegteHandkarte(const int index)
{
	Karte zwischenspeicher;

	zwischenspeicher = handkarten[index];
	handkarten[index] = handkarten[laengeHandkartenIndex - 1];
	handkarten[laengeHandkartenIndex - 1] = zwischenspeicher;

	laengeHandkartenIndex--;
}

//Ausgabe der Anzahl der noch Vorhandenen Handkarten
int Spieler::GetHandkartenIndexLaenge()
{
	return laengeHandkartenIndex;
}

//Gibt die Handkarten des Spielers zurück
Karte * Spieler::GetHandkarten()
{
	return handkarten;
}

//Gibt die Handkarte am angegebenen Index aus
Karte Spieler::GetHandkarteBeiIndex(const int index)
{
	return handkarten[index];
}

//Setzt die vom Spieler geseztze Karte (Variable gesetzteKarte)
void Spieler::SetGesetzteKarte(Karte karte)
{
	gesetzteKarte = karte;
}

//Gibt die gesetzte Karte aus
Karte Spieler::GetGesetzteKarte()
{
	return gesetzteKarte;
}

//Gibt den Namen des Spielers zurück
std::string Spieler::GetName()
{
	return name;
}

//Die Reihe wird genommen, die Strafpunkte für den Spieler werden berechnet, erste Karte wird zur gesetzten Karte des Spielers
void Spieler::ReiheNimmt(const int reihe, Spielfeld* spielfeld)
{
	Karte platzhalter;

	punktestand += spielfeld->GetStrafpunkte(reihe);
	
	spielfeld->ReiheLeeren(reihe);
	spielfeld->KarteLegen(gesetzteKarte);
}

/* Die Karten werden nach Kartenzahl aufsteigend sortiert */
void Spieler::SortierenHandkarten()
{
	HeapSort();
}

void Spieler::HeapSort()
{
	//Heap bauen
	for (int i = laengeHandkartenIndex/2 - 1; i >= 0; i--)
	{
		Heapify(laengeHandkartenIndex, i);
	}

	//Elemente einzeln herausnehmen
	for (int i = laengeHandkartenIndex - 1; i >= 0; i--)
	{
		SwapHandkarten(0, i);	//Aktuellen root ans Ende bewegen

		Heapify(i, 0);			//Wieder Heapify auf den Unterbaum aufrufen
	}
}

void Spieler::Heapify(const int index, const int root)
{
	int largest = root;		//root ist das größte Element
	int l = 2 * root + 1;	//links = 2*root + 1
	int r = 2 * root + 2;	//rechts = 2*root + 2

	//Linkes Kindelement ist größer als root
	if (l < index && handkarten[l].GetZahl() > handkarten[largest].GetZahl())
	{
		largest = l;
	}

	//Rechtes Kindelement ist größer als root
	if (r < index && handkarten[r].GetZahl() > handkarten[largest].GetZahl())
	{
		largest = r;
	}

	//Größtes Element (largest) ist nicht root
	if (largest != root)
	{
		SwapHandkarten(root, largest);	//Vertauschen von root und dem größten Element

		Heapify(index, largest);		//Heapify der Unterbäume
	}
}

void Spieler::SwapHandkarten(const int index1, const int index2)
{
	Karte zwischenspeicher;

	zwischenspeicher = handkarten[index1];
	handkarten[index1] = handkarten[index2];
	handkarten[index2] = zwischenspeicher;
}
