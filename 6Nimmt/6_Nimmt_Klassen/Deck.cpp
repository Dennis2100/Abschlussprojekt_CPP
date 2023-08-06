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

Deck::~Deck()
{
}

//Hilft dabei eine Zufällige Zahl zu generieren
void Deck::SetRandomizer(const int seek)		
{
	randomizer = seek;
}

//Gibt eine zufällige Karte aus dem Deck zurück
Karte Deck::Dealer()		
{
	Karte rueckgabe;

	
	srand((unsigned int)(time(NULL)*(randomizer++)));
	
	//std::srand(static_cast<unsigned int>(std::time(nullptr)));

	int random = rand() % deckLänge; //0 bis 103
	//int random = srand((unsigned int)time(NULL)) % deckLänge;	//0 bis 103

	rueckgabe = deck[random];

	KarteAusDeckLöschen(random);

	return rueckgabe;
}

//Eine Karte am angegebenen index wird gelöscht
void Deck::KarteAusDeckLöschen(const int index)		
{
	Karte zwischenspeicher;

	zwischenspeicher = deck[index];
	deck[index] = deck[deckLänge - 1];
	deck[deckLänge - 1] = zwischenspeicher;

	deckLänge--;
}