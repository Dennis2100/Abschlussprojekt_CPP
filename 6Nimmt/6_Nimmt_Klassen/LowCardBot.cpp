#include "pch.h"
#include "LowCardBot.h"
#include "Spielfeld.h"

LowCardBot::LowCardBot()
{
    name = "LowCardBot";
}

Karte LowCardBot::MachZug(Spielfeld * spielfeld)    //LowCardBot macht einen Zug
{
    SetGesetzteKarte(handkarten[0]);                //
                                                    //Setzt die Niedrigste Karte auf der Hand
    return LegeHandkarte(0);                        //
}
