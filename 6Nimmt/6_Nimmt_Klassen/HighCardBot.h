#pragma once
#include "Bot.h"

class HighCardBot : public Bot
{

public:
	HighCardBot();

	Karte MachZug() override;
};

