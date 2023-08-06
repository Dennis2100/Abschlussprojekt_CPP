#pragma once
#include <iostream>
#include <string.h>

class Karte {

public:
	Karte(void);
	Karte(int zahl);
	~Karte();

	int getZahl();
	int getStrafpunkte();

private:
	int strafpunkte;
	int zahl;

	static int karte_index;

};