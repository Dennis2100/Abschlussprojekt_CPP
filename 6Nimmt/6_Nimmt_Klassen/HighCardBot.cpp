#include "pch.h"
#include "HighCardBot.h"

HighCardBot::HighCardBot()
{
	name = "HighCardBot";
}

Karte HighCardBot::MachZug()
{
	int index = lšngeHandkartenIndex - 1;

	SetGesetzteKarte(handkarten[index]);

	return LegeHandkarte(index);
}
