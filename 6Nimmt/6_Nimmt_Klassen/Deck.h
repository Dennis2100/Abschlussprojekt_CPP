#pragma once
#include "Karte.h"
class Deck
{
	Karte deck[104];
	int deckLänge;
	int randomizer=0;

public:
	Deck();										//Standart-Konstruktor

	Karte Dealer();								//Gibt eine Zufällige Karte aus den noch vorhandenen Karten im Deck zurück
	void KarteAusDeckLöschen(int index);		//Löscht eine Karte aus dem Deck
	void SetRandomizer(int seek);				//Hilft eine Zufallszahl zu generieren
};

