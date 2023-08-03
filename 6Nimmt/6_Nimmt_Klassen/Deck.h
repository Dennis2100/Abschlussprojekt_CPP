#pragma once
#include "Karte.h"
class Deck
{
	Karte deck[104];
	int deckLänge;

public:
	Deck();										//Standart-Konstruktor

	Karte Dealer();								//Gibt eine Zufällige Karte aus den noch vorhandenen Karten im Deck zurück
	//int ErmittlungStrafpunkte(int zahl);
	void KarteAusDeckLöschen(int index);		//Löscht eine Karte aus dem Deck
};

