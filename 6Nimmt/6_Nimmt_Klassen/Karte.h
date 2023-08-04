#pragma once
#include "KonsolenOperation.h"
#include <iostream>
#include <string.h>

class Karte {

public:
	Karte(void);
	Karte(int zahl);
	~Karte();

	void zeichnen(int x, int y, bool gewaehlt = false);
	int getZahl();
	int getStrafpunkte();

private:
	int strafpunkte;
	int zahl;

	static int karte_index;

	static const int Karte_breite = 12;
	static const int Karte_hoehe = 9;

	const static int farben[];

	void zeichnen_linie(int xl, int yl, char char1, char char2, char char3, int wiederholen);
	void zeichne_kopf(int xk, int yk);
	void zeichnen_kartennummer(int xm1, int ym1);
	void zeichnen_strafpunkte(int x, int y, int punkte);
};