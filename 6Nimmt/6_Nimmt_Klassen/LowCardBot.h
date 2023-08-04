#pragma once
#include "Bot.h"
#include "Spielfeld.h"

class LowCardBot : public Bot
{

public: 
	LowCardBot();

	Karte MachZug(Spielfeld * spielfeld) override;
};

