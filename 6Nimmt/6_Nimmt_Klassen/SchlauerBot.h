#pragma once
#include "Bot.h"
#include "Spielfeld.h"

class SchlauerBot : public Bot
{

public:
	SchlauerBot();									//Standardkonstruktor
	~SchlauerBot();

	Karte MachZug(Spielfeld * spielfeld) override;	//Macht einen Zug
};

