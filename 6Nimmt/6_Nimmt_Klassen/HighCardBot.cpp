#include "pch.h"
#include "HighCardBot.h"

HighCardBot::HighCardBot()
{
	name = "HighCardBot";
}

Karte HighCardBot::MachZug()
{
	int index = längeHandkartenIndex - 1;

	SetGesetzteKarte(handkarten[index]);

	return LegeHandkarte(index);
}
