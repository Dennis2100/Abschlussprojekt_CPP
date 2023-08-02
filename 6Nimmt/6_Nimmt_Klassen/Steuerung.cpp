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
	int eingabeMensch;
	Spielfeld * spielfeld = new Spielfeld();
	Deck * deck = new Deck();

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

	ErstenVier(spielfeld, deck);
	GebenHandkarten(deck, bot, mensch);

	ui.AusgabeSpielfeld(spielfeld);

	for (int i = 0; i < 10; i++)										//Ablauf des Spiels � 10 Runden
	{
		ui.AusgabeHandkarten(mensch);

		do																//Abfangen von Falschen Eintr�gen
		{
			eingabeMensch = ui.EingabeKarte();
		} while (Pr�feEingabe(eingabeMensch, mensch));

		mensch->LegeHandkarte(eingabeMensch);							//Mensch legt eine Karte
		bot->MachZug();													//Bot legt eine Karte

	}

	ui.SiegerEhrung(bot, mensch);										//Gewinner wird ermittelt
}

bool Steuerung::Pr�feEingabe(int auswahl, Mensch * mensch)				//Pr�fe ob der Eingegebene Index der Handkarten korrekt ist
{
	bool rueckgabe = false;

	if (auswahl > mensch->GetHandkartenIndexLaenge() || auswahl < 0) return true;

	return false;
}

void Steuerung::EintragSpielfeld()										//Lege die gew�hlten karten
{

}

void Steuerung::SechsNimmt()											//Falls 6 Karten in einer Reihe sind, nimmt derjenige der die 6. Karte gelegt hat
{

}

void Steuerung::GebenHandkarten(Deck * deck, Bot * bot, Mensch * mensch)		//Verteilen der Handkarten
{
	for (int i = 0; i < 10; i++)
	{
		bot->SetHandkarteBeiIndex(i, deck->Dealer());
		mensch->SetHandkarteBeiIndex(i, deck->Dealer());
	}
}

void Steuerung::ErstenVier(Spielfeld * spielfeld, Deck  * deck)				//Einsetzen der ersten 4 Karten auf das Spielfeld
{
	for(int i = 0; i < 4; i++)
	{
		spielfeld->SetSpielfeld(0, i, deck->Dealer());
	}
}

//bool Steuerung::PruefenAusgewaehlteKarte(int auswahl)					//Pr�fen der gelegten Karte ob sie kleiner ist als die Karten in der 4 Reihen
//{
//
//}
