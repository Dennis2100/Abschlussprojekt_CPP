#pragma once
#include "Bot.h"

class SchlauerBot : public Bot
{

public:
	SchlauerBot();

	Karte MachZug() override;
};

