#pragma once
#include "Bot.h"

class LowCardBot : public Bot
{

public: 
	LowCardBot();

	Karte MachZug() override;
};

