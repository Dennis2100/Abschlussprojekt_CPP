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
