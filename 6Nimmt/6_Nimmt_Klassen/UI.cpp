#include "pch.h"
#include "UI.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "Spielfeld.h"
#include "Mensch.h"

#define LINKS 75
#define RECHTS 77
#define OBEN 72
#define UNTEN 80
#define ENTER 13

UI::UI()
{
}

void UI::ScreenVorbereiten()
{
	system("mode con COLS=200 LINES=60");
	::ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	ScreenLoeschen();
}

void UI::ScreenLoeschen()
{
	system("cls");
}

void UI::AusgabeSpielfeld(Spielfeld * spielfeld, int activeReihe)			//Aktuelles Spielfeld ausgeben
{
	for (int i = 0; i < 4; i++)
	{
		for(int c = 0; c < spielfeld->GetKartenAnzahl(i); c++)
		{
			spielfeld->GetSpielfeld(i, c).zeichnen(c * 12, i*8,(i == activeReihe));
		}
	}
}

void UI::SpielerStand(Spieler * spieler1, Spieler * spieler2)
{
	SetCursorPosition(85, 2);
	std::cout << spieler1->GetName() << " (" << spieler1->GetPunktestand() << ")  -  " << spieler2->GetName() << " (" << spieler2->GetPunktestand() << ")";

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

void UI::AusgabeHandkarten(Karte * handkarten, int längeHandkartenIndex, int gewaehlteKarte)		//Graphische Ausgabe der Handkarten des Menschspielers
{
	for (int i = 0; i < längeHandkartenIndex; i++)
	{
		handkarten[i].zeichnen(15 + i * 14, 34,(i == gewaehlteKarte));
	}
}

int UI::EingabeKarte(Karte* handkarten, int längeHandkartenIndex)				//Auswahl der zu legenden Karte für den Menschspieler
{
	int c;
	bool endlos = true;
	int gewaehlteKarte = 0;

	SetCursorPosition(1, 32);
    std::cout << "                                 Waehlen Sie eine Zahl um die gewuenschte Karte zu legen:                      ";
	
	while (endlos)
	{
		AusgabeHandkarten(handkarten, längeHandkartenIndex, gewaehlteKarte);
		c = _getch();
		if (c == 0 or c == 224)
		{
			switch (_getch())
			{
			case LINKS:
				if (gewaehlteKarte > 0) gewaehlteKarte--;
				break;
			case RECHTS:
				if (gewaehlteKarte < längeHandkartenIndex - 1) gewaehlteKarte++;
				break;
			}
		}
		else if (c == ENTER)
		{
			endlos = false;
		}
		AusgabeHandkarten(handkarten, längeHandkartenIndex, längeHandkartenIndex+1);
	}
	return gewaehlteKarte;
}

void UI::SiegerEhrung(Spieler * spieler1, Spieler * spieler2)		//Ermittlung des Gewinners
{
	SetCursorPosition(1, 32);
	if (spieler1->GetPunktestand() < spieler2->GetPunktestand())
	{
		std::cout << spieler1->GetName() << " hat Gewonnen!";
	}
	else if(spieler1->GetPunktestand() > spieler2->GetPunktestand())
	{
		std::cout << spieler2->GetName() << " hat Gewonnen!";
	}
	else
	{
		std::cout << "Es ist ein unentschieden!";
	}
}

int UI::AuswahlReiheNehmen(Spielfeld * spielfeld)
{
	int c;
	bool endlos = true;
	int gewaehlteReihe = 0;
	

	SetCursorPosition(1, 32);
	std::cout << "                                 Welche Reihe soll genommen werden:                                  ";

	while (endlos)
	{
		AusgabeSpielfeld(spielfeld, gewaehlteReihe);
		c = _getch();
		if (c == 0 or c == 224)
		{
			switch (_getch())
			{
			case OBEN:
				if (gewaehlteReihe > 0) gewaehlteReihe--;
				break;
			case UNTEN:
				if (gewaehlteReihe < 3) gewaehlteReihe++;
				break;
			}
		}
		else if (c == ENTER)
		{
			endlos = false;
		}
		AusgabeSpielfeld(spielfeld, 5);
	}

	return gewaehlteReihe;
}

int UI::IstSpielerMensch()
{
	int rueckgabe = 0;

	std::cout << "Soll einer der Spieler ein Mensch sein? (1/Ja | 0/Nein):";
	std::cin >> rueckgabe;

	std::cout << "\n";

	return rueckgabe;
}
