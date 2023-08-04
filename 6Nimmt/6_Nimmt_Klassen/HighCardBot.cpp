#include "pch.h"
#include "HighCardBot.h"
#include "Spielfeld.h"

HighCardBot::HighCardBot()
{
	name = "HighCardBot";
}

Karte HighCardBot::MachZug(Spielfeld * spielfeld)
{
	int index = längeHandkartenIndex - 1;

	SetGesetzteKarte(handkarten[index]);

	return LegeHandkarte(index);
}
