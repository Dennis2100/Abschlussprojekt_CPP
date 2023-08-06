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

//Macht einen zuf�lligen Zug
Karte ZufallsBot::MachZug(Spielfeld * spielfeld)				
{
	srand((unsigned int)time(NULL));
	int random = rand() % laengeHandkartenIndex; //0 bis l�ngeHandkartenIndex-1

	SetGesetzteKarte(handkarten[random]);

	return LegeHandkarte(random);
}

//Nimmt eine zuf�llige Reihe
void ZufallsBot::AusgewaehlteReiheNehmen(Spielfeld* spielfeld)	
{
	srand((unsigned int)time(NULL));
	int random = rand() % 4; //0 bis 3

	ReiheNimmt(random, spielfeld);
}