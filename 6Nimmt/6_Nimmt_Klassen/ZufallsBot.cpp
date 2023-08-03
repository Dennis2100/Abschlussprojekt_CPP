#include "pch.h"
#include "ZufallsBot.h"

ZufallsBot::ZufallsBot()
{
	name = "Zufallsbot";
}

Karte ZufallsBot::MachZug()
{
	srand((unsigned int)time(NULL));
	int random = rand() % lšngeHandkartenIndex; //0 bis lšngeHandkartenIndex-1

	SetGesetzteKarte(handkarten[random]);

	return LegeHandkarte(random);
}

void ZufallsBot::AusgewaehlteReiheNehmen(Spielfeld* spielfeld)
{
	srand((unsigned int)time(NULL));
	int random = rand() % 4; //0 bis 3

	ReiheNimmt(random, spielfeld);
}