#include "pch.h"
#include "Karte.h"

Karte::Karte(void)          //Einfacher Standardkonstruktor
{
    strafpunkte = 0;
    zahl = 0;
}

Karte::Karte(int z)         //Standardkobstruktor mit direkter ermittlung der Strafpunkte
{
    if (z == 55)
    {
        strafpunkte = 7;
    }
    else if (z % 10 == 0)
    {
        strafpunkte = 3;
    }
    else if (z % 10 == 5)
    {
        strafpunkte = 2;
    }
    else if (z % 11 == 0)
    {
        strafpunkte = 5;
    }
    else
    {
        strafpunkte = 1;
    }

    zahl = z;
}

Karte::~Karte()
{
}

int Karte::getZahl()            //Gibt die Zahl einer Karte zurück
{
    return zahl;
}

int Karte::getStrafpunkte()     //Gibt die Strafpunkte einer Karte zurück
{
    return strafpunkte;
}