#include "pch.h"
#include "UI.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Spielfeld.h"
#include "Mensch.h"

UI::UI()
{
}

void UI::AusgabeSpielfeld(Spielfeld * spielfeld)			//Aktuelles Spielfeld ausgeben
{
	//int platzhalter;

	//system("MODE CON COLS=210 LINES=60");
	system("mode con COLS=700");
	system("cls");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

	for (int i = 0; i < 4; i++)
	{
		for(int c = 0; c < spielfeld->GetKartenAnzahl(i); c++)
		{
			spielfeld->GetSpielfeld(i, c).zeichnen(c * 18, i*9);
		}
	}

	//std::cin >> platzhalter;
}

int UI::AbfrageBot()				//Frage welcher Bot verwendet werden soll
{
	int eingabe = 0;

	std::cout << "1 : Schlauer Bot\n2 : Zufalls Bot\n3 : LowCardBot\n\n";
	std::cout << "Bitte geben Sie den gewählten Bot ein: ";
	std::cin >> eingabe;

	std::cout << "\n";

	return eingabe;
}

void UI::AusgabeHandkarten(Karte * handkarten, int längeHandkartenIndex)		//Graphische Ausgabe der Handkarten des Menschspielers
{
	for (int i = 0; i < längeHandkartenIndex; i++)
	{
		handkarten[i].zeichnen(20 + i * 18, 40);
	}
}

int UI::EingabeKarte()				//Auswahl der zu legenden Karte für den Menschspieler
{
	int eingabe;

	SetCursorPosition(1, 53);

	std::cout << "Wählen Sie einen Index um die gewünschte Karte zu legen: ";
	std::cin >> eingabe;

	return eingabe;
}

void UI::SiegerEhrung(Spieler * bot, Spieler * mensch)		//Ermittlung des Gewinners
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

int UI::AuswahlReiheNehmen()
{
	int eingabe;

	SetCursorPosition(1, 53);
	std::cout << "Welche Reihe soll genommen werden: ";
	std::cin >> eingabe;

	std::cout << "\n";

	return eingabe;
}

int UI::IstSpielerMensch()
{
	int rueckgabe = 0;

	std::cout << "Soll einer der Spieler ein Mensch sein? (1/Ja | 0/Nein):";
	std::cin >> rueckgabe;

	std::cout << "\n";

	return rueckgabe;
}
