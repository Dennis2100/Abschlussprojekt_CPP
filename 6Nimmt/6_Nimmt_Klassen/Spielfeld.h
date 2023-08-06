#pragma once
#include "Karte.h"
#define max_diff 105; //initialer Wert fuer die Unterschied zwischen Karten auf dem Spielfeld 

class Spielfeld
{
public:

	Spielfeld();																	//Standard-Konstruktor
	~Spielfeld();																	//Standard-Destruktor

	Karte GetSpielfeld(const int reihe, const int spalte);							//Gibt die Karte an der angegebenen Reihe und Spalte zurück 
	Karte GetLetzteKarte(const int reihe);											//Gibt die letzte Karte einer Reihe an
	void SetSpielfeld(const int reihe, const int spalte, const Karte karte);		//Setzt das Spielfeld an der angegebenen Reihe und Spalte
	int KarteLegen(Karte karte);												//Karte wird gelegt mit einem int als Rückgabe, Beschreibung in der .cpp
	int GetKartenAnzahl(int reihe);													//Gibt die anzahl der Karten einer Reihe an
	int GetStrafpunkte(const int reihe);											//Gibt die Strafpunkte 
	void ReiheLeeren(const int reihe);												//

private:
	Karte spielfeld[4][6];
	int kartenzahl[4] = { 0,0,0,0 };
};

