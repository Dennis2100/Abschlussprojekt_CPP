#pragma once
#include "Bot.h"

class SchlauerBot : public Bot
{

public:
	SchlauerBot();

	Karte MachZug() override;
	void AusgewaehlteReiheNehmen(Spielfeld* spielfeld) override;
};

