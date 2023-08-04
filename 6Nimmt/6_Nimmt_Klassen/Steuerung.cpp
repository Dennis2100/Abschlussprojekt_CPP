#include "pch.h"
#include "Steuerung.h"
#include "UI.h"
#include "Spieler.h"
#include "Spielfeld.h"
#include "Karte.h"
#include "Bot.h"
#include "Deck.h"
#include "Mensch.h"
#include "SchlauerBot.h"
#include "ZufallsBot.h"
#include "LowCardBot.h"
#include "HighCardBot.h"
#include <cstdlib>

Steuerung::Steuerung()
{
}

void Steuerung::StarteSpiel()
{
	UI ui;
	Spielfeld * spielfeld = new Spielfeld();
	Deck * deck = new Deck();

	Spieler * spieler1 = NULL;
	Spieler * spieler2 = NULL;

	system("MODE CON COLS=200 LINES=200");
	
	if (ui.IstSpielerMensch() == 1)
	{
		spieler1 = new Mensch();

		spieler2 = BotWahl(ui);
		//BotWahl(spieler2, ui);
	}
	else
	{
		spieler1 = BotWahl(ui);
		spieler2 = BotWahl(ui);

		//BotWahl(spieler1, ui);
		//BotWahl(spieler2, ui);
	}
	
	//spieler1 = new Mensch();
	//spieler2 = new ZufallsBot();
	//spieler2 = new LowCardBot();
	//spieler2 = new HighCardBot();
	//spieler2 = new SchlauerBot();

	Karte gewaelteKarte1;												//Gewählte Karte von Spieler1
	Karte gewaelteKarte2;												//Gewählte Karte von Spieler2

	ErstenVier(spielfeld, deck);

	GebenHandkarten(deck, spieler1);
	GebenHandkarten(deck, spieler2);

	ui.ScreenVorbereiten();

	for (int i = 0; i < 10; i++)										//Ablauf des Spiels á 10 Runden
	{
		ui.ScreenLoeschen();
		ui.AusgabeSpielfeld(spielfeld,5);
		ui.SpielerStand(spieler1, spieler2);

		spieler1->MachZug(spielfeld);
		spieler2->MachZug(spielfeld);

		gewaelteKarte1 = spieler1->GetGesetzteKarte();
		gewaelteKarte2 = spieler2->GetGesetzteKarte();

		WerDarfAnfangen(gewaelteKarte1, gewaelteKarte2, spielfeld, spieler1, spieler2);
	}

	ui.ScreenLoeschen();
	ui.AusgabeSpielfeld(spielfeld,5);
	ui.SpielerStand(spieler1, spieler2);

	ui.SiegerEhrung(spieler1, spieler2);								//Gewinner wird ermittelt
	std::cin.get();
}

void Steuerung::GebenHandkarten(Deck * deck, Spieler * spieler)	//Verteilen der Handkarten
{
	for (int i = 0; i < 10; i++)
	{
		spieler->SetHandkarteBeiIndex(i, deck->Dealer());
	}
	spieler->SortierenHandkarten();
}

void Steuerung::ErstenVier(Spielfeld * spielfeld, Deck  * deck)							//Einsetzen der ersten 4 Karten auf das Spielfeld
{
	for(int i = 0; i < 4; i++)
	{
		spielfeld->KarteLegen(deck->Dealer());
	}
}

//void Steuerung::BotWahl(Spieler * spieler, UI ui)
//{
//	int botAbfrage;
//
//	do																					//Bot Auswahl
//	{
//		botAbfrage = ui.AbfrageBot();
//	} while (!(botAbfrage <= 4 && botAbfrage >= 1));
//
//	switch (botAbfrage)																	//Zuweisung des Ausgewählten Bots
//	{
//		case 1:
//			spieler = new SchlauerBot();
//			break;
//
//		case 2:
//			spieler = new ZufallsBot();
//			break;
//
//		case 3:
//			spieler = new LowCardBot();
//			break;
//
//		case 4:
//			spieler = new HighCardBot();
//			break;
//
//		default:
//			break;
//	}
//}

void Steuerung::WerDarfAnfangen(Karte gewaelteKarte1, Karte gewaelteKarte2, Spielfeld* spielfeld, Spieler* spieler1, Spieler* spieler2)
{
	if (gewaelteKarte1.getZahl() < gewaelteKarte2.getZahl())							//Wer darf als erster legen
	{
		spielerLegtKarten(spielfeld, spieler1, gewaelteKarte1);
		spielerLegtKarten(spielfeld, spieler2, gewaelteKarte2);
	}
	else
	{
		spielerLegtKarten(spielfeld, spieler2, gewaelteKarte2);
		spielerLegtKarten(spielfeld, spieler1, gewaelteKarte1);
	}
}

void Steuerung::spielerLegtKarten(Spielfeld * spielfeld,Spieler * spieler, Karte karte)
{
	int rueckgabe;
	
	rueckgabe = spielfeld->KarteLegen(karte);
	switch (rueckgabe)
	{
	case 4:
		//Reihe wählen
		spieler->AusgewaehlteReiheNehmen(spielfeld);
		break;

	case 5:
		//Kart angenommen, keine weitere Aktion erforderlich
		break;

	default:
		//Ganze Reihe nehmen, rueckgabe = 0..3
		spieler->ReiheNimmt(rueckgabe, spielfeld);
		break;
	}

}

Spieler* Steuerung::BotWahl(UI ui)
{
	int nummer;

	do																					//Bot Auswahl
	{
		nummer = ui.AbfrageBot();
	} while (!(nummer <= 4 && nummer >= 1));

	switch (nummer)																	//Zuweisung des Ausgewählten Bots
	{
		case 1:
			return new SchlauerBot();
			break;

		case 2:
			return new ZufallsBot();
			break;

		case 3:
			return new LowCardBot();
			break;

		case 4:
			return new HighCardBot();
			break;

		default:
			break;
	}
}
