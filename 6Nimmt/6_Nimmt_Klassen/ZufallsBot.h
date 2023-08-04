#pragma once
#include "Bot.h"
#include "Spielfeld.h"

class ZufallsBot : public Bot
{

public: 
	ZufallsBot();

	Karte MachZug(Spielfeld * spielfeld) override;
	void AusgewaehlteReiheNehmen(Spielfeld* spielfeld) override;
};

