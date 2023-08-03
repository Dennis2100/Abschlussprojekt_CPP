#include "pch.h"
#include "Deck.h"

Deck::Deck()
{
	for (int i = 0; i < 104; i++)
	{
		Deck::deck[i] = Karte(i+1);
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

void Deck::KarteAusDeckL�schen(int index)
{
	Karte zwischenspeicher;

	zwischenspeicher = deck[index];
	deck[index] = deck[deckL�nge - 1];
	deck[deckL�nge - 1] = zwischenspeicher;

	deckL�nge--;
}
