#pragma once
#include "Karte.h"
class Deck
{
	Karte deck[104];
	int deckL�nge;

public:
	Deck();										//Standart-Konstruktor

	Karte Dealer();								//Gibt eine Zuf�llige Karte aus den noch vorhandenen Karten im Deck zur�ck
	//int ErmittlungStrafpunkte(int zahl);
	void KarteAusDeckL�schen(int index);		//L�scht eine Karte aus dem Deck
};

