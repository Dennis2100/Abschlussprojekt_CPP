#pragma once
#include "Bot.h"

class ZufallsBot : public Bot
{

public: 
	ZufallsBot();

	Karte MachZug() override;
	void AusgewaehlteReiheNehmen(Spielfeld* spielfeld) override;
};

