#include "pch.h"
#include "HighCardBot.h"
#include "Spielfeld.h"

HighCardBot::HighCardBot()
{
	name = "HighCardBot";
}

Karte HighCardBot::MachZug(Spielfeld * spielfeld)		//HighCardBot macht einen Zug
{
	int index = l�ngeHandkartenIndex - 1;

	SetGesetzteKarte(handkarten[index]);				//
														//Setzt die H�chste Karte auf der Hand
	return LegeHandkarte(index);						//
}
