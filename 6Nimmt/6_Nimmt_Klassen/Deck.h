#pragma once
#include "Karte.h"
class Deck
{
	Karte deck[104];
	int deckL�nge;
	int randomizer=0;

public:
	Deck();										//Standart-Konstruktor

	Karte Dealer();								//Gibt eine Zuf�llige Karte aus den noch vorhandenen Karten im Deck zur�ck
	void KarteAusDeckL�schen(int index);		//L�scht eine Karte aus dem Deck
	void SetRandomizer(int seek);				//Hilft eine Zufallszahl zu generieren
};

