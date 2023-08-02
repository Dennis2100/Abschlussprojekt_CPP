#pragma once
#include "Spieler.h"

class Bot : public Spieler
{

public: 
	Bot();

	Karte MachZug();
};

