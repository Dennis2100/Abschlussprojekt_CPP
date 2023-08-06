 #include "pch.h"
#include "Spielfeld.h"
#include "Karte.h"

Spielfeld::Spielfeld()
{
}

Spielfeld::~Spielfeld()
{
}

Karte Spielfeld::GetSpielfeld(const int reihe, const int spalte)
{
	return spielfeld[reihe][spalte];
}

//Gibt die letzte Karte einer Reihe zurück
Karte Spielfeld::GetLetzteKarte(const int reihe)		
{
	return spielfeld[reihe][kartenzahl[reihe]];
}

void Spielfeld::SetSpielfeld(const int reihe, const int spalte, const Karte karte)
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

			if (karte.GetZahl() > tmp_karte.GetZahl())
			{
				tmp_diff = karte.GetZahl() - tmp_karte.GetZahl();
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

void Spielfeld::ReiheLeeren(const int reihe)
{
	kartenzahl[reihe] = 0;
}

//Gibt die Anzahl an Karten in einer Reihe zurück
int Spielfeld::GetKartenAnzahl(const int reihe)		
{
	return kartenzahl[reihe];
}

//Gibt die Strafpunkte einer Reihe zurück
int Spielfeld::GetStrafpunkte(const int reihe)		
{
	int summe = 0;
	for (int i = 0; i < kartenzahl[reihe]; i++)
	{
		summe += (spielfeld[reihe][i]).GetStrafpunkte();
	}

	return summe;
}
