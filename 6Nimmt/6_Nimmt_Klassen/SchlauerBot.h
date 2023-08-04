#pragma once
#include "Bot.h"
#include "Spielfeld.h"

class SchlauerBot : public Bot
{

public:
	SchlauerBot();

	Karte MachZug(Spielfeld * spielfeld) override;
};

