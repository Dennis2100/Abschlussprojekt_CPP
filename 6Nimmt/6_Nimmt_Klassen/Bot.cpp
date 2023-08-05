#include "pch.h"
#include "Bot.h"

Bot::Bot()
{

}

void Bot::AusgewaehlteReiheNehmen(Spielfeld* spielfeld)
{
	int spalte = 0;

	spalte = ErmittlungMin(spielfeld);

	ReiheNimmt(spalte, spielfeld);
}

/* findet Reihe mit minimalen Strafpunkten */
int Bot::ErmittlungMin(Spielfeld* spielfeld)
{
	int spalte = 0;
	int min = spielfeld->getStrafpunkte(0);

	for (int i = 1; i < 4; i++)
	{
		if (min > spielfeld->getStrafpunkte(i))
		{
			min = spielfeld->getStrafpunkte(i);
			spalte = i;
		}
	}

	return spalte;
}