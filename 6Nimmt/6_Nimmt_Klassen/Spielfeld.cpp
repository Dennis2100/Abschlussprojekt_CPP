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

Karte Spielfeld::GetLetzteKarte(int reihe)		//Gibt die letzte Karte einer Reihe zurück
{
	return spielfeld[reihe][kartenzahl[reihe]];
}

void Spielfeld::SetSpielfeld(int reihe, int spalte, Karte karte)
{
	spielfeld[reihe][spalte] = karte;
}

/* die Methode plaziert eine Karte auf dem Spielfeld
   Rueckgabe Werte:
	 0 bis 3 - die Karte angenommen, die Reihe mit den angegebenen Index muss genommen werden, da die sechste Karte
	 4 - die Karte ist kleiner als die letzten Karten in allen Reihen, es muss gewählt werden welche Reihe wird genommen
	 5 - die Karte angenommen, keine Interaktion erforderlich */

int Spielfeld::KarteLegen(Karte karte)		//Ermittelt ob eine Karte ohne weiteres gelegt werden kann
{
	int diff = max_diff;
	int retWert = 5;
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

			if (karte.getZahl() > tmp_karte.getZahl())
			{
				tmp_diff = karte.getZahl() - tmp_karte.getZahl();
				if (tmp_diff < diff)
				{
					diff = tmp_diff;
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

			retWert = idx;
		}
	}
	else
	{
		/*  */
		retWert = 4;
	}

	return retWert;
}

void Spielfeld::ReiheLeeren(int reihe)
{
	kartenzahl[reihe] = 0;
}

int Spielfeld::GetKartenAnzahl(int reihe)		//Gibt die Anzahl an Karten in einer Reihe zurück
{
	return kartenzahl[reihe];
}

int Spielfeld::getStrafpunkte(int reihe)		//Gibt die Strafpunkte einer Reihe zurück
{
	int summe = 0;
	for (int i = 0; i < kartenzahl[reihe]; i++)
	{
		summe += (spielfeld[reihe][i]).getStrafpunkte();
	}

	return summe;
}
