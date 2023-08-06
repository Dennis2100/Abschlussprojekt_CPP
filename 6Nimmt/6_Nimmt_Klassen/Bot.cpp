#include "pch.h"
#include "Bot.h"

Bot::Bot()
{

}

/* Nimmt die ausgew�hlte Reihe */
void Bot::AusgewaehlteReiheNehmen(Spielfeld* spielfeld)
{
	int spalte = 0;

	spalte = ErmittlungMin(spielfeld);		//Ermittelt die zu Nehmende Reihe

	ReiheNimmt(spalte, spielfeld);			//Reihe wird genommen
}

/* findet Reihe mit minimalen Strafpunkten */
int Bot::ErmittlungMin(Spielfeld* spielfeld)
{
	int spalte = 0;
	int min = spielfeld->GetStrafpunkte(0);

	for (int i = 1; i < 4; i++)
	{
		if (min > spielfeld->GetStrafpunkte(i))
		{
			min = spielfeld->GetStrafpunkte(i);
			spalte = i;
		}
	}

	return spalte;							//R�ckgabe der Spalte mit den geringesten Strafpunkten
}