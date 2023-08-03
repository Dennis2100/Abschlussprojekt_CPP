#include "pch.h"
#include "Bot.h"

Bot::Bot()
{

}

Karte Bot::MachZug()
{
	return Karte();
}

void Bot::AusgewaehlteReiheNehmen(Spielfeld* spielfeld)
{
	int spalte = 0;

	spalte = ErmittlungMin(spielfeld);

	ReiheNimmt(spalte, spielfeld);
}

int Bot::ErmittlungMin(Spielfeld* spielfeld)
{
	int strafPunkteReihe[4]{0,0,0,0};

	for (int i = 0; i < 4; i++)
	{
		for (int c = 0; c < 6; c++)
		{
			strafPunkteReihe[i] += spielfeld->GetSpielfeld(c, i).getStrafpunkte();
		}
	}

	return Minimal(strafPunkteReihe);
}

int Bot::Minimal(int reihe[])
{
	int spalte = 0;
	int min = reihe[0];

	for (int i = 0; i < 4; i++)
	{
		if(reihe[i] < min)
		{
			spalte = i;
			min = reihe[i];
		}
	}

	return spalte;
}

//Karte Bot::MachZug()
//{
//	int index = 0;
//
//	return LegeHandkarte(index);
//}
