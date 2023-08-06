#include "pch.h"
#include "LowCardBot.h"
#include "Spielfeld.h"

LowCardBot::LowCardBot()
{
    name = "LowCardBot";
}

//LowCardBot macht einen Zug
Karte LowCardBot::MachZug(Spielfeld * spielfeld)    
{
    SetGesetzteKarte(handkarten[0]);                //
                                                    //Setzt die Niedrigste Karte auf der Hand
    return LegeHandkarte(0);                        //
}
