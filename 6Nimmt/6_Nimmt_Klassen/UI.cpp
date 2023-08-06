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

const int UI::farben[] = { 15,03,06,4, 02, 5, 4 };

UI::UI()
{
}

UI::~UI()
{
}

void UI::ScreenVorbereiten()
{
	system("mode con COLS=200 LINES=300");
	//::ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	//::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	ScreenLoeschen();
}

//Aktuelle Ausgabe wird gelöscht
void UI::ScreenLoeschen()		
{
	system("cls");
}

//Aktuelles Spielfeld ausgeben
void UI::AusgabeSpielfeld(Spielfeld * spielfeld, const int activeReihe)			
{
	for (short i = 0; i < 4; i++)
	{
		for(short c = 0; c < spielfeld->GetKartenAnzahl(i); c++)
		{
			Karte_Zeichnen(spielfeld->GetSpielfeld(i, c), c * (KARTE_BREITE), i * (KARTE_HOEHE-1), (i == activeReihe));
		}
	}
}

//Ausgabe des aktuellen Spielerstands
void UI::SpielerStand(Spieler * spieler1, Spieler * spieler2)		
{
	SetCursorPosition(15+ KARTE_BREITE*5, 2);
	std::cout << spieler1->GetName() << " (" << spieler1->GetPunktestand() << ")  -  " << spieler2->GetName() << " (" << spieler2->GetPunktestand() << ")";

}

//Frage welcher Bot verwendet werden soll
int UI::AbfrageBot()				
{
	int eingabe = 0;

	do
	{
		std::cout << "1 : Schlauer Bot\n2 : Zufalls Bot\n3 : LowCardBot\n4 : HighCardBot\n\n";
		std::cout << "Bitte geben Sie den gewaehlten Bot ein: ";
		std::cin >> eingabe;
	} while (!(eingabe >= 1 && eingabe <= 4));

	std::cout << "\n";

	return eingabe;
}

//Graphische Ausgabe der Handkarten des Menschspielers
void UI::AusgabeHandkarten(Karte * handkarten, const int laengeHandkartenIndex, const int gewaehlteKarte)		
{
	for (short i = 0; i < laengeHandkartenIndex; i++)
	{
	 	Karte_Zeichnen(handkarten[i], 5 + (i+1) * KARTE_BREITE, 4*KARTE_HOEHE-1,(i == gewaehlteKarte));
	}

	for (short j = laengeHandkartenIndex; j < 10; j++)
	{
		Zeichnen_Linie( 5 + (j+1) * KARTE_BREITE, 4 * KARTE_HOEHE - 1,' ',' ',' ',KARTE_HOEHE);
	}

	std::cout << "\n";
}

//Auswahl der zu legenden Karte für den Menschspieler
int UI::EingabeKarte(Karte* handkarten, const int laengeHandkartenIndex)				
{
	int c;
	bool endlos = true;
	int gewaehlteKarte = 0;

	SetCursorPosition(1, 4 * KARTE_HOEHE - 3);
    std::cout << "                                 Waehlen Sie mit den Pfeiltasten eine Karte zum legen:                      ";
	
	while (endlos)
	{
		AusgabeHandkarten(handkarten, laengeHandkartenIndex, gewaehlteKarte);	//Gibt die Handkarten aus
		c = _getch();

		if (c == 0 or c == 224)
		{
			switch (_getch())
			{
				case LINKS:
					if (gewaehlteKarte > 0) gewaehlteKarte--;
					break;
				case RECHTS:
					if (gewaehlteKarte < laengeHandkartenIndex - 1) gewaehlteKarte++;
					break;
			}
		}
		else if (c == ENTER)
		{
			endlos = false;
		}

		AusgabeHandkarten(handkarten, laengeHandkartenIndex, laengeHandkartenIndex+1);
	}

	return gewaehlteKarte;
}

void UI::ZeigeZug(Spieler* spieler1, Spieler* spieler2)
{
	Karte_Zeichnen(spieler2->GetGesetzteKarte(), 18 + KARTE_BREITE * 5, 5);
	Karte_Zeichnen(spieler1->GetGesetzteKarte(), 22 + KARTE_BREITE * 5, 5 + KARTE_HOEHE);
	AusgabeHandkarten(spieler1->GetHandkarten(), spieler1->GetHandkartenIndexLaenge(), spieler1->GetHandkartenIndexLaenge() + 1);
	Sleep(1000);
}

//Ermittlung des Gewinners
void UI::SiegerEhrung(const int sieger, Spieler* spieler1, Spieler* spieler2)		
{
	SetCursorPosition(1, 4 * KARTE_HOEHE-3);
	switch (sieger)
	{
		 case 0:
			 std::cout << "Es ist ein unentschieden!";
			 break;
		 case 1:
			 std::cout << spieler1->GetName() << " hat Gewonnen!";
			 break;
		 case 2:
			 std::cout << spieler2->GetName() << " hat Gewonnen!";
			 break;
	}
}

//Auswahl der Reihe die genommen werden soll
int UI::AuswahlReiheNehmen(Spielfeld * spielfeld)			
{
	int c;
	bool endlos = true;
	int gewaehlteReihe = 0;
	

	SetCursorPosition(1, 4 * KARTE_HOEHE - 3);
	std::cout << "                                 Welche Reihe soll genommen werden:                                  ";

	while (endlos)
	{
		AusgabeSpielfeld(spielfeld, gewaehlteReihe);		//Spielfeld wird ausgegeben
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

//Abfrage ob man selber als Spieler agieren will
int UI::IstSpielerMensch()			
{
	int rueckgabe = 0;

	do
	{
		std::cout << "Soll einer der Spieler ein Mensch sein? (1/Ja | 0/Nein):";
		std::cin >> rueckgabe;
	} while (!(rueckgabe == 0 || rueckgabe == 1));

	std::cout << "\n";

	return rueckgabe;
}

/* die Methode zeichnet die Karte an der angegebenen Koordinaten */
void UI::Karte_Zeichnen(Karte karte, const short x, const short y, bool gewaehlt)
{
	/* Setzten die Basisfarbe */
	int basisfarbe = 0x0F;      //weiss auf schwarzem Hindergrund
	int straffarbe;

	int strafpunkte = karte.GetStrafpunkte();

	if (gewaehlt) basisfarbe = 0xF0;  //schwarz auf weissem Hindergrund

	SetTextColor(basisfarbe);

	/* Zeichne die Umrisse von Karte */
	Zeichnen_Linie(x, y, '+', '-', '+', 1);
	Zeichnen_Linie(x, y + 1, '|' , ' ', '|', KARTE_HOEHE - 3);
	Zeichnen_Linie(x, y + KARTE_HOEHE - 2, '+', '-', '+', 1);

	/* Nummern aud der Karte in alle vier Ecken ausgeben */
	Zeichnen_Kartennummer(x, y, karte.GetZahl());

	/* Strafpunkte auf der Karte ausgeben */
	straffarbe = farben[strafpunkte - 1];

	if (strafpunkte == 1)
	{
		straffarbe = basisfarbe;
	}
	else if (gewaehlt)
	{
		straffarbe += basisfarbe;   //Weisse hintergund
	}

	SetTextColor(straffarbe);
	Zeichnen_Strafpunkte(x, y, strafpunkte);
	SetTextColor(basisfarbe);

	/* zeichne den Ochsenkopf */
	Zeichne_Kopf(x + KARTE_BREITE / 2 - 3, y + KARTE_HOEHE / 2 - 1);

	SetTextColor(farben[0]);
}

void UI::Zeichnen_Linie(const short xl, const short yl, char char1, char char2, char char3, const int wiederholen)
{
	for (int j = 0; j < wiederholen; j++)
	{
		SetCursorPosition(xl, yl + j);
		printf("%c", char1);
		for (int i = 0; i < KARTE_BREITE - 2; i++) printf("%c", char2);
		printf("%c", char3);
	}
}

void UI::Zeichne_Kopf(const short xk, short yk)
{
	SetCursorPosition(xk, yk++); printf("/_  _\\");
	SetCursorPosition(xk, yk++); printf("  ||");
	SetCursorPosition(xk, yk);   printf(" (__)");
}

void UI::Zeichnen_Kartennummer(short xm1, short ym1, const int zahl)
{
	short xm2;
	short ym2;

	xm1++;
	xm2 = xm1 + KARTE_BREITE - 5;
	ym1++;
	ym2 = ym1 + KARTE_HOEHE - 4;

	SetCursorPosition(xm1, ym1);
	printf("%d", zahl);

	SetCursorPosition(xm2, ym1);
	printf("%3d", zahl);

	SetCursorPosition(xm1, ym2);
	printf("%d", zahl);

	SetCursorPosition(xm2, ym2);
	printf("%3d", zahl);
}

void UI::Zeichnen_Strafpunkte(const short xp, const short yp, const int punkte)
{
	int straf_linies;

	straf_linies = punkte / 4 + 1; //ab 4 Strafpunkte zeichnet man in zwei Zeilen
	for (int k = 0; k < straf_linies; k++)
	{
		/* Berechnung der Position, damit die Strafpunkte symmetrisch in der Mitte platziert sind */
		int l = punkte / straf_linies + (1 - k) * (straf_linies / 2) * (punkte % 2);
		int m = xp + KARTE_BREITE/2 - l + 1;
		for (int n = 0; n < l;n++)
		{
			SetCursorPosition(m, yp + 1 + k);
			printf("*");
			m +=2;
		}
	}
}

void UI::SetCursorPosition(const short x, const short y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { x, y };
	SetConsoleCursorPosition(hOut, coord);
}

void UI::SetTextColor(const int col)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	FlushConsoleInputBuffer(hOut);
	SetConsoleTextAttribute(hOut, col);
}