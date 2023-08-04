#include "pch.h"
#include "Karte.h"
#include "KonsolenOperation.h"

const int Karte::farben[] = { 15,03,06,4, 02, 5, 4 };

Karte::Karte(void)
{
    strafpunkte = 0;
    zahl = 0;
}

Karte::Karte(int z)
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

int Karte::getZahl()
{
    return zahl;
}

int Karte::getStrafpunkte()
{
    return strafpunkte;
}

/* die Methode zeichnet die Karte an der angegebenen Koordinaten */
void Karte::zeichnen(int x, int y, bool gewaehlt)
{
    /* Setzten die Basisfarbe */
    int basisfarbe = 0x0F;      //weiss auf schwarzem Hindergrund
    int straffarbe;

    if (gewaehlt) basisfarbe = 0xF0;  //schwarz auf weissem Hindergrund
    
    SetTextColor(basisfarbe);

    /* Zeichne die Umrisse von Karte */
    zeichnen_linie(x, y, 43, 45, 43, 1);
    zeichnen_linie(x, y + 1, 124, 32, 124, Karte_hoehe - 3);
    zeichnen_linie(x, y + Karte_hoehe - 2, 43, 45, 43, 1);

    /* Nummern aud der Karte in alle vier Ecken ausgeben */
    zeichnen_kartennummer(x, y);

    /* Strafpunkte auf der Karte ausgeben */
    straffarbe = farben[strafpunkte - 1];

    if (strafpunkte == 1)
    {
        straffarbe = basisfarbe;
    }
    else if(gewaehlt)
    {
        straffarbe += basisfarbe;   //Weisse hintergund
    }
    
    SetTextColor(straffarbe);
    zeichnen_strafpunkte(x, y, strafpunkte);
    SetTextColor(basisfarbe);

    /* zeichne den Ochsenkopf */
    zeichne_kopf(x + Karte_breite / 2 - 3, y + Karte_hoehe / 2 - 1);

    SetTextColor(farben[0]);
}

void Karte::zeichnen_linie(int xl, int yl, char char1, char char2, char char3, int wiederholen)
{
    for (int j = 0; j < wiederholen; j++)
    {
        SetCursorPosition(xl, yl + j);
        printf("%c", char1);
        for (int i = 0; i < Karte_breite - 2; i++) printf("%c", char2);
        printf("%c", char3);
    }
}

void Karte::zeichne_kopf(int xk, int yk)
{
    SetCursorPosition(xk, yk++); printf("/_  _\\");
    SetCursorPosition(xk, yk++); printf("  ||");
    SetCursorPosition(xk, yk);   printf(" (__)");
}

void Karte::zeichnen_kartennummer(int xm1, int ym1)
{
    int xm2;
    int ym2;

    xm1++;
    xm2 = xm1 + Karte_breite - 5;
    ym1++;
    ym2 = ym1 + Karte_hoehe - 4;

    SetCursorPosition(xm1, ym1);
    printf("%d", zahl);

    SetCursorPosition(xm2, ym1);
    printf("%3d", zahl);

    SetCursorPosition(xm1, ym2);
    printf("%d", zahl);

    SetCursorPosition(xm2, ym2);
    printf("%3d", zahl);
}

void Karte::zeichnen_strafpunkte(int xp, int yp, int punkte)
{
    int straf_linies;

    straf_linies = punkte / 4 + 1; //ab 4 Strafpunkte zeichnet man in zwei Zeilen
    for (int k = 0; k < straf_linies; k++)
    {
        /* Berechnung der Position, damit die Strafpunkte symmetrisch in der Mitte platziert sind */
        int l = punkte / straf_linies + (1 - k) * (straf_linies / 2) * (punkte % 2);
        int m = xp + Karte_breite / 2 - l + 1;
        for (int n = 0; n < l;n++)
        {
            SetCursorPosition(m, yp + 1 + k);
            printf("*");
            m += 2;
        }
    }
}
