#pragma once
#include "Bot.h"
#include "Spielfeld.h"

class SchlauerBot : public Bot
{

public:
	SchlauerBot();									//Standardkonstruktor

	Karte MachZug(Spielfeld * spielfeld) override;	//Macht einen Zug
};

