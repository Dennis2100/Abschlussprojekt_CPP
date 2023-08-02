#include "pch.h"
#include "Deck.h"

Deck::Deck()
{
	for (int i = 0; i < 104; i++)
	{
		Deck::deck[i] = Karte(ErmittlungStrafpunkte(i+1), i+1);
	}

	deckLänge = 104;
}

Karte Deck::Dealer()
{
	srand((unsigned int)time(NULL));

	Karte rueckgabe;
	int random = rand() % deckLänge; //0 bis 103
	rueckgabe = deck[random];

	KarteAusDeckLöschen(random);

	return rueckgabe;
}

int Deck::ErmittlungStrafpunkte(int zahl)
{
	int rueckgabe = 1;

	if (zahl == 55)
	{
		rueckgabe = 7;
	}
	else if (zahl % 11 == 0)
	{
		rueckgabe = 5;
	}
	else if (zahl % 10 == 5)
	{
		rueckgabe = 2;
	}
	else if (zahl % 10 == 0)
	{
		rueckgabe = 3;
	}

	return rueckgabe;
}

void Deck::KarteAusDeckLöschen(int index)
{
	Karte zwischenspeicher;

	zwischenspeicher = deck[index];
	deck[index] = deck[deckLänge - 1];
	deck[deckLänge - 1] = zwischenspeicher;

	deckLänge--;
}
