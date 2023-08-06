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

	deckL�nge = 104;
}

Deck::~Deck()
{
}

//Hilft dabei eine Zuf�llige Zahl zu generieren
void Deck::SetRandomizer(const int seek)		
{
	randomizer = seek;
}

//Gibt eine zuf�llige Karte aus dem Deck zur�ck
Karte Deck::Dealer()		
{
	Karte rueckgabe;

	
	srand((unsigned int)(time(NULL)*(randomizer++)));
	
	//std::srand(static_cast<unsigned int>(std::time(nullptr)));

	int random = rand() % deckL�nge; //0 bis 103
	//int random = srand((unsigned int)time(NULL)) % deckL�nge;	//0 bis 103

	rueckgabe = deck[random];

	KarteAusDeckL�schen(random);

	return rueckgabe;
}

//Eine Karte am angegebenen index wird gel�scht
void Deck::KarteAusDeckL�schen(const int index)		
{
	Karte zwischenspeicher;

	zwischenspeicher = deck[index];
	deck[index] = deck[deckL�nge - 1];
	deck[deckL�nge - 1] = zwischenspeicher;

	deckL�nge--;
}