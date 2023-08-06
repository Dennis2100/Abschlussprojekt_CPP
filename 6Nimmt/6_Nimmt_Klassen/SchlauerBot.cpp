#include "pch.h"
#include "SchlauerBot.h"
#include "Spielfeld.h"

SchlauerBot::SchlauerBot()
{
    name = "Schlauerbot";
}

//Zufallsbot macht einen Zug
Karte SchlauerBot::MachZug(Spielfeld * spielfeld)               
{
    Karte letztenKartenDerReihe[4];
    int karte = 0;
    
    Spielfeld* spielfeld2 = new Spielfeld();                    //Es wird ein zweites Spielfeld f�r einen Vergleich erstellt
    
    *spielfeld2 = *spielfeld;

    for (int c = 0; c < laengeHandkartenIndex; c++)             //Suche nach Karte, die man legen kann ohne Strafpunkte zu kassieren 
    {
        if (spielfeld2->KarteLegen(handkarten[c]) == 5)
        {
            karte = c;
            break;
        }
    }

    delete spielfeld2;                                          //Das zweite Spielfeld wird gel�scht

    //Falls man keine Handkarte hat die g��er ist als die Karten in der Reihe
    SetGesetzteKarte(handkarten[karte]);                        //Setzt die gesetzte Karte
    return LegeHandkarte(karte);                                //
}
