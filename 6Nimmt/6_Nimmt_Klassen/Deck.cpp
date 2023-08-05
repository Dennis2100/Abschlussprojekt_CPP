#include "pch.h"
#include "Deck.h"
#include "time.h"
#include <random>

Deck::Deck()
{
	for (int i = 0; i < 104; i++)
	{
		Deck::deck[i] = Karte(i+1);
	}

	deckLänge = 104;
}

void Deck::SetRandomizer(int seek)
{
	randomizer = seek;
}

Karte Deck::Dealer()
{
	Karte rueckgabe;

	
	srand((unsigned int)(time(NULL)*(randomizer+1)));
	
	//std::srand(static_cast<unsigned int>(std::time(nullptr)));

	int random = rand() % deckLänge; //0 bis 103
	//int random = srand((unsigned int)time(NULL)) % deckLänge;	//0 bis 103

	rueckgabe = deck[random];

	KarteAusDeckLöschen(random);

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