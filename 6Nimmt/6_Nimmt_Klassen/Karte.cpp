#include "pch.h"
#include "Karte.h"

//Einfacher Standardkonstruktor
Karte::Karte(void)          
{
    strafpunkte = 0;
    zahl = 0;
}

//Standardkobstruktor mit direkter ermittlung der Strafpunkte
Karte::Karte(const int z)         
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

//Gibt die Zahl einer Karte zurück
int Karte::GetZahl()            
{
    return zahl;
}

//Gibt die Strafpunkte einer Karte zurück
int Karte::GetStrafpunkte()     
{
    return strafpunkte;
}