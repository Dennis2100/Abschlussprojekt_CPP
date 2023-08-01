#pragma once
#include "KonsolenOperation.h"
#include <iostream>
#include <string.h>

class Karte
{
	

public:
	Karte();
	Karte(int strfpnkt, int z);

	void zeigen(int x, int y, bool verdeckt = false);

	int myNum;
	std::string myString;

private:
	int strafpunkte;
	int zahl;

	static const int karte_breite = 16;
	static const int karte_hoehe = 11;

	const static int colors[];

	void zeigen_linie(int xl, int yl, char char1, char char2, char char3);
};

