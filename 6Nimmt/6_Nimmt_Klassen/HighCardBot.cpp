#include "pch.h"
#include "HighCardBot.h"
#include "Spielfeld.h"

HighCardBot::HighCardBot()
{
	name = "HighCardBot";
}

//HighCardBot macht einen Zug
Karte HighCardBot::MachZug(Spielfeld * spielfeld)		
{
	int index = laengeHandkartenIndex - 1;

	SetGesetzteKarte(handkarten[index]);				//
														//Setzt die Höchste Karte auf der Hand
	return LegeHandkarte(index);						//
}
