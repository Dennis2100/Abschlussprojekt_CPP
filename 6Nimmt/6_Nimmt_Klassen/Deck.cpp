#include "pch.h"
#include "Deck.h"

Deck::Deck()
{
	Karte deck[104]{};

	for (int i = 0; i < 104; i++)
	{
		deck[i] = Karte(ErmittlungStrafpunkte(i), i);
	}
}

Karte Deck::Dealer()
{
	int random = rand() % 104; //0 bis 103


	return deck[random];
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
	else if (zahl % 5 == 0)
	{
		
	}
	else if (zahl % 10 == 0)
	{

	}

	return rueckgabe;
}
