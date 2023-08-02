#include "pch.h"
#include "Spielfeld.h"
#include "Karte.h"

Spielfeld::Spielfeld()
{
	Karte spielfeld[4][6];
}

Karte Spielfeld::GetSpielfeld(int reihe, int spalte)
{
	return spielfeld[reihe][spalte];
}

void Spielfeld::SetSpielfeld(int reihe, int spalte, Karte karte)
{
	spielfeld[reihe][spalte] = karte;
}

int Spielfeld::KarteLegen(Karte karte)
{
	int diff = max_diff;
	int retWert = 0;
	int tmp_diff;
	int idx = 4;

	for (int i = 0; i < 4; i++)
	{
		if (kartenzahl[i] == 0)
		{
			/* Wenn wir eine Reihe ohne Karten haben. sollen wir sie gleich belegen - immer am Anfang des Spieles */
			idx = i; //stapel[i][kartenzahl[i]++] = karte;
			break;
		}
		else
		{
			Karte tmp_karte;
			tmp_karte = spielfeld[i][kartenzahl[i] - 1];

			if (karte.GetZahl() > tmp_karte.GetZahl())
			{
				tmp_diff = karte.GetZahl() - tmp_karte.GetZahl();
				if (tmp_diff < diff)
				{
					tmp_diff = diff;
					idx = i;
				}

			}
		}
	}

	if (idx < 4)
	{
		/* Reihe gefunden, wo die Karte reinpasst */
		if (kartenzahl[idx] < 5)
		{
			spielfeld[idx][kartenzahl[idx]++] = karte;
		}
		else
		{

			retWert = 2;
		}
	}
	else
	{
		/*  */
		retWert = 1;
	}

	return retWert;
}

int Spielfeld::GetKartenAnzahl(int reihe)
{
	return kartenzahl[reihe];
}
