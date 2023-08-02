#pragma once
#include "Spieler.h"

class Mensch : public Spieler
{

public :
	Mensch();

	Karte GetHandkarteBeiIndex(int index);
};

