#include "pch.h"
#include "ZufallsBot.h"
#include "Spielfeld.h"

ZufallsBot::ZufallsBot()
{
	name = "Zufallsbot";
}

ZufallsBot::~ZufallsBot()
{
}

//Macht einen zufälligen Zug
Karte ZufallsBot::MachZug(Spielfeld * spielfeld)				
{
	srand((unsigned int)time(NULL));
	int random = rand() % laengeHandkartenIndex; //0 bis längeHandkartenIndex-1

	SetGesetzteKarte(handkarten[random]);

	return LegeHandkarte(random);
}

//Nimmt eine zufällige Reihe
void ZufallsBot::AusgewaehlteReiheNehmen(Spielfeld* spielfeld)	
{
	srand((unsigned int)time(NULL));
	int random = rand() % 4; //0 bis 3

	ReiheNimmt(random, spielfeld);
}