#include "pch.h"
#include "LowCardBot.h"

LowCardBot::LowCardBot()
{
    name = "LowCardBot";
}

Karte LowCardBot::MachZug()
{
    SetGesetzteKarte(handkarten[0]);

    return LegeHandkarte(0);
}
