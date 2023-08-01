#include "pch.h"
#include "Karte.h"
#include "KonsolenOperation.h"

Karte::Karte()
{
	strafpunkte = 0;
	zahl = 0;
}

Karte::Karte(int strfpnkt, int z)
{
	strafpunkte = strfpnkt;
	zahl = z;
}

const int Karte::colors[] = {15, 03, 06, 4, 02, 5, 4};

void Karte::zeigen(int x, int y, bool verdeckt)
{
    int straf_linies;
    int x_kopf;
    int y_kopf;


    zeigen_linie(x, y, 43, 45, 43);

    for (int j = 1; j < karte_hoehe - 2; j++)
    {
        zeigen_linie(x, y + j, 124, 32, 124);
    }

    zeigen_linie(x, y + karte_hoehe - 2, 43, 45, 43);

    /* druck die Karte. Falls sie verdeckt ist, werden die Nummern und die Strafpunkte nicht ausgegeben */
    if (/*not*/!verdeckt)
    {
        SetCursorPosition(x + 1, y + 1);
        printf("%d", zahl);

        SetCursorPosition(x + karte_breite - 4, y + 1);
        printf("%3d", zahl);

        SetCursorPosition(x + 1, y + karte_hoehe - 3);
        printf("%d", zahl);

        SetCursorPosition(x + karte_breite - 4, y + karte_hoehe - 3);
        printf("%3d", zahl);

        SetTextColor(colors[strafpunkte - 1]);
        straf_linies = strafpunkte / 4 + 1; //ab 4 Strafpunkte zeichnet man in zwei Zeilen
        for (int k = 0; k < straf_linies; k++)
        {
            int l = strafpunkte / straf_linies + (1 - k) * (straf_linies / 2) * (strafpunkte % 2);
            int m = x + karte_breite / 2 - l + 1;
            for (int n = 0; n < l;n++)
            {
                SetCursorPosition(m, y + 1 + k);
                printf("*");
                m += 2;
            }
        }
        SetTextColor(15);
    }

    x_kopf = x + karte_breite / 2 - 3;
    y_kopf = y + karte_hoehe / 2 - 1;

    /* druck den Ochsenkopf */
    SetCursorPosition(x_kopf, y_kopf++); printf("/_  _\\");
    SetCursorPosition(x_kopf, y_kopf++); printf("  ||");
    SetCursorPosition(x_kopf, y_kopf);   printf(" (__)");
}

void Karte::zeigen_linie(int xl, int yl, char char1, char char2, char char3)
{
    SetCursorPosition(xl, yl);
    printf("%c", char1);
    for (int i = 0; i < karte_breite - 2; i++) printf("%c", char2);
    printf("%c", char3);
}
