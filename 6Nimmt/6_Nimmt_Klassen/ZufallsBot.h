#pragma once
#include "Bot.h"
#include "Spielfeld.h"

class ZufallsBot : public Bot
{

public: 
	ZufallsBot();													//Standardkonstruktor
	~ZufallsBot();

	Karte MachZug(Spielfeld * spielfeld) override;					//Macht einen Zug
	void AusgewaehlteReiheNehmen(Spielfeld* spielfeld) override;	//Nimmt die ausgewählte Reihe nehmen
};

