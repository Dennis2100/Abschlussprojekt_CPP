#include "pch.h"
#include "SchlauerBot.h"
#include "Spielfeld.h"

SchlauerBot::SchlauerBot()
{
    name = "Schlauerbot";
}

Karte SchlauerBot::MachZug(Spielfeld * spielfeld)
{
    Karte letztenKartenDerReihe[4];
    int karte = 0;
    
    Spielfeld* spielfeld2 = new Spielfeld();
    
    *spielfeld2 = *spielfeld;

    for (int c = 0; c < längeHandkartenIndex; c++)
    {
        if (spielfeld2->KarteLegen(handkarten[c]) == 5)
        {
            karte = c;
            break;
        }
    }

    delete spielfeld2;

    SetGesetzteKarte(handkarten[karte]);
    return LegeHandkarte(karte);


    /* alter Code */
    for (int i = 0; i < 4; i++)
    {
        letztenKartenDerReihe[i] = spielfeld->GetSpielfeld(i, spielfeld->GetKartenAnzahl(i)-1);
    }

    for (int i = 0; i < 4; i++)
    {
        for (int c = 0; c < längeHandkartenIndex; c++)
        {
            if (handkarten[c].getZahl() > letztenKartenDerReihe[i].getZahl() && spielfeld->GetKartenAnzahl(i) != 5)
            {
                SetGesetzteKarte(handkarten[c]);
                return LegeHandkarte(c);
            }
        }
    }

    //Falls man keine Handkarte hat die gößer ist als die Karten in der Reihe
    SetGesetzteKarte(handkarten[0]);
    return LegeHandkarte(0);
}
