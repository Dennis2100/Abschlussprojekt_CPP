#include "pch.h"
#include "HighCardBot.h"
#include "Spielfeld.h"

HighCardBot::HighCardBot()
{
	name = "HighCardBot";
}

Karte HighCardBot::MachZug(Spielfeld * spielfeld)		//HighCardBot macht einen Zug
{
	int index = längeHandkartenIndex - 1;

	SetGesetzteKarte(handkarten[index]);				//
														//Setzt die Höchste Karte auf der Hand
	return LegeHandkarte(index);						//
}
