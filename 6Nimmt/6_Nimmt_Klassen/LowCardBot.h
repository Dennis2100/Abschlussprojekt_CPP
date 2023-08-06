#pragma once
#include "Bot.h"
#include "Spielfeld.h"

class LowCardBot : public Bot
{

public:		
	LowCardBot();									//Standardkonstruktor
	~LowCardBot();

	Karte MachZug(Spielfeld * spielfeld) override;	//Macht einen Zug
};

