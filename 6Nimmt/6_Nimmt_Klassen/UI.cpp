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
}

int UI::AbfrageBot()				//Frage welcher Bot verwendet werden soll
{
	int eingabe = 0;

	std::cout << "1 : Schlauer Bot\n2 : Zufalls Bot\n3 : LowCardBot\n4 : HighCardBot\n\n";
	std::cout << "Bitte geben Sie den gewaehlten Bot ein: ";
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

	std::cout << "Waehlen Sie eine Zahl um die gewuenschte Karte zu legen: ";
	std::cin >> eingabe;

	return eingabe;
}

void UI::SiegerEhrung(Spieler * spieler1, Spieler * spieler2)		//Ermittlung des Gewinners
{
	if (spieler1->GetPunktestand() < spieler2->GetPunktestand())
	{
		std::cout << spieler1->GetName() << "hat Gewonnen!";
	}
	else if(spieler1->GetPunktestand() > spieler2->GetPunktestand())
	{
		std::cout << spieler2->GetName() << "hat Gewonnen!";
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
