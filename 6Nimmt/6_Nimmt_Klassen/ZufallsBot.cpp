#include "pch.h"
#include "ZufallsBot.h"
#include "Spielfeld.h"

ZufallsBot::ZufallsBot()
{
	name = "Zufallsbot";
}

Karte ZufallsBot::MachZug(Spielfeld * spielfeld)				//Macht einen zufälligen Zug
{
	srand((unsigned int)time(NULL));
	int random = rand() % längeHandkartenIndex; //0 bis längeHandkartenIndex-1

	SetGesetzteKarte(handkarten[random]);

	return LegeHandkarte(random);
}

void ZufallsBot::AusgewaehlteReiheNehmen(Spielfeld* spielfeld)	//Nimmt eine zufällige Reihe
{
	srand((unsigned int)time(NULL));
	int random = rand() % 4; //0 bis 3

	ReiheNimmt(random, spielfeld);
}