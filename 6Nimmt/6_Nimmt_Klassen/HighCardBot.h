#pragma once
#include "Bot.h"
#include "Spielfeld.h"

class HighCardBot : public Bot
{

public:
	HighCardBot();									//Standardkonstruktor
	~HighCardBot();

	Karte MachZug(Spielfeld * spielfeld) override;	//Macht einen Zug
};

