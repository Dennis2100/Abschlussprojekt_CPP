#include "pch.h"
#include "Steuerung.h"
#include "UI.h"
#include "Spieler.h"
#include "Spielfeld.h"
#include "Karte.h"
#include "Bot.h"
#include "Deck.h"
#include "Mensch.h"

Steuerung::Steuerung()
{

}

void Steuerung::StarteSpiel()
{
	UI ui;
	int botAbfrage;
	Spielfeld *spielfeld = new Spielfeld();
	Deck *deck = new Deck();

	Mensch *mensch = new Mensch();
	Bot *bot = new Bot();

	do
	{
		botAbfrage = ui.AbfrageBot();
	} while (botAbfrage != 1 && botAbfrage != 2 && botAbfrage != 3);

	switch (botAbfrage)
	{
		case 1:
			//bot = new ();
			break;

		case 2:
			//bot = new ();
			break;

		case 3:
			//bot = new ();
			break;
	}

	ErstenVier(*spielfeld, *deck);
	GebenHandkarten(*deck, *bot, *mensch);

	ui.AusgabeSpielfeld();

	for (int i = 0; i < 10; i++)
	{

	}

	/*if ()
	{

	}
	else
	{

	}*/
}

bool Steuerung::PrüfeEingabe()											//Prüfe ob der Eingegebene Index der Handkarten korrekt ist
{
	return false;
}

void Steuerung::EintragSpielfeld()										//Lege die gewählten karten
{

}

void Steuerung::SechsNimmt()											//Falls 6 Karten in einer Reihe sind, nimmt derjenige der die 6. Karte gelegt hat
{

}

void Steuerung::GebenHandkarten(Deck deck, Bot bot, Mensch mensch)		//Verteilen der Handkarten
{

}

void Steuerung::ErstenVier(Spielfeld spielfeld, Deck deck)				//Einsetzen der ersten 4 Karten auf das Spielfeld
{
	for(int i = 0; i < 4; i++)
	{
		spielfeld.SetSpielfeld(1, i, deck.Dealer());
	}
}

void Steuerung::PrüfenGelegteKarte()									//Prüfen der gelegten Karte ob sie kleiner ist als di Karten in der 4. Reihe
{

}
