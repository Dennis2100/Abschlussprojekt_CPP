#pragma once
#include <iostream>
#include <string.h>

class Karte {

public:
	Karte(void);
	Karte(const int zahl);
	~Karte();

	int GetZahl();
	int GetStrafpunkte();

private:
	int strafpunkte;
	int zahl;

	static int karte_index;

};