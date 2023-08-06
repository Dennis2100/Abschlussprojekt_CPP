/* Name: Dennis Melnychuk, Matrikelnummer: 4240524 */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Steuerung.h"
#include "Karte.h"
#include "UI.h"

int main()
{
    Steuerung steuerung;
    UI ui;

    int istSpielerMensch = ui.IstSpielerMensch();
    int botWahl1 = ui.AbfrageBot();
    int botWahl2 = 0;

    if (istSpielerMensch == 0)
    {
        botWahl2 = ui.AbfrageBot();
    }

    steuerung.StarteSpiel(istSpielerMensch, botWahl1, botWahl2);

    return 0;
}