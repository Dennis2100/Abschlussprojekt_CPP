#include "pch.h"
#include "UI.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "Spielfeld.h"

UI::UI()
{
}

void UI::AusgabeSpielfeld()			//Aktuelles Spielfeld ausgeben
{
	Spielfeld spielfeld;

	for (int i = 0; i < 4; i++)
	{
		for(int c = 0; c < 5; c++)
		{
			spielfeld.GetSpielfeld(i, c);
		}
	}
}

int UI::AbfrageBot()				//Frage welcher Bot verwendet werden soll
{
	int eingabe = 0;

	std::cout << "1 : Schlauer Bot\n2 : Zufalls Bot\n3 : Anderer Bot\n\n";
	std::cout << "Bitte geben Sie den gewählten Bot ein: ";
	std::cin >> eingabe;

	std::cout << "\n";

	return eingabe;
}

void UI::AusgabeHandkarten()		//Graphische Ausgabe der Handkarten des Menschspielers
{

}

int UI::EingabeKarte()				//Auswahl der zu legenden Karte für den Menschspieler
{
	int eingabe;

	std::cout << "Wählen Sie einen Index um die gewünschte Karte zu legen: ";
	std::cin >> eingabe;

	return eingabe;
}
