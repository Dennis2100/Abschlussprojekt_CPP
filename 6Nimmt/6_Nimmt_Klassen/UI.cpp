#include "pch.h"
#include "UI.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "Spielfeld.h"
#include "Mensch.h"

UI::UI()
{
}

void UI::AusgabeSpielfeld(Spielfeld * spielfeld)			//Aktuelles Spielfeld ausgeben
{
	system("MODE CON COLS=210 LINES=60");
	for (int i = 0; i < 4; i++)
	{
		for(int c = 0; c < 6; c++)
		{
			spielfeld->GetSpielfeld(i, c).zeigen(i*18,c*10);
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

void UI::AusgabeHandkarten(Mensch * mensch)		//Graphische Ausgabe der Handkarten des Menschspielers
{
	int platzhalter;

	for (int i = 0; i < 10; i++)
	{
		mensch->GetHandkarteBeiIndex(i);
	}
	std::cin >> platzhalter;
}

int UI::EingabeKarte()				//Auswahl der zu legenden Karte für den Menschspieler
{
	int eingabe;

	std::cout << "Wählen Sie einen Index um die gewünschte Karte zu legen: ";
	std::cin >> eingabe;

	return eingabe;
}

void UI::SiegerEhrung(Bot * bot, Mensch * mensch)		//Ermittlung des Gewinners
{
	if (mensch->GetPunktestand() < bot->GetPunktestand())
	{
		std::cout << "Sie haben Gewonnen!";
	}
	else if(mensch->GetPunktestand() > bot->GetPunktestand())
	{
		std::cout << "Der Bot hat Gewonnen!";
	}
	else
	{
		std::cout << "Es ist ein unentschieden!";
	}
}
