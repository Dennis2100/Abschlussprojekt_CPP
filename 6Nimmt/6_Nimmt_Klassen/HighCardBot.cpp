#include "pch.h"
#include "HighCardBot.h"

HighCardBot::HighCardBot()
{
	name = "HighCardBot";
}

Karte HighCardBot::MachZug()
{
	int index = l�ngeHandkartenIndex - 1;

	SetGesetzteKarte(handkarten[index]);

	return LegeHandkarte(index);
}
