#include "pch.h"
#include "Deck.h"

Deck::Deck()
{
	for (int i = 0; i < 104; i++)
	{
		Deck::deck[i] = Karte(ErmittlungStrafpunkte(i+1), i+1);
	}

	deckL�nge = 104;
}

Karte Deck::Dealer()
{
	srand((unsigned int)time(NULL));

	Karte rueckgabe;
	int random = rand() % deckL�nge; //0 bis 103
	rueckgabe = deck[random];

	KarteAusDeckL�schen(random);

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

void Deck::KarteAusDeckL�schen(int index)
{
	Karte zwischenspeicher;

	zwischenspeicher = deck[index];
	deck[index] = deck[deckL�nge - 1];
	deck[deckL�nge - 1] = zwischenspeicher;

	deckL�nge--;
}
