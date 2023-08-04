#include "pch.h"
#include "LowCardBot.h"
#include "Spielfeld.h"

LowCardBot::LowCardBot()
{
    name = "LowCardBot";
}

Karte LowCardBot::MachZug(Spielfeld * spielfeld)
{
    SetGesetzteKarte(handkarten[0]);

    return LegeHandkarte(0);
}
