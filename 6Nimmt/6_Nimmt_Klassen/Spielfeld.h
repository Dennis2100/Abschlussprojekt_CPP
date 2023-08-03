#pragma once
#include "Karte.h"
#define max_diff 105; //initialer Wert fuer die Unterschied zwischen Karten auf dem Spielfeld 

class Spielfeld
{

	Karte spielfeld[4][6];
	int kartenzahl[4] = { 0,0,0,0 };

public:

	Spielfeld();												//Standart-Konstruktor

	Karte GetSpielfeld(int reihe, int spalte);					//Gibt die Karte an der angegebenen Reihe und Spalte zurück 
	void SetSpielfeld(int reihe, int spalte, Karte karte);		//Setzt das Spielfeld an der angegebenen Reihe und Spalte
	int KarteLegen(Karte karte);								//Karte wird gelegt mit einem int als Rückgabe, Beschreibung in der .cpp
	int GetKartenAnzahl(int reihe);								//Gibt die anzahl der Karten einer Reihe an
};

