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

#include <cstdlib>

Steuerung::Steuerung()
{
}

void Steuerung::StarteSpiel()
{
	UI ui;
	Spielfeld * spielfeld = new Spielfeld();
	Deck * deck = new Deck();

	Spieler * spieler1;
	Spieler * spieler2;

	system("MODE CON COLS=200 LINES=200");

	if (ui.IstSpielerMensch() == 1)
	{
		spieler1 = new Mensch();

		spieler2 = new Bot();
		BotWahl(spieler2, ui);
	}
	else
	{
		spieler1 = new Bot();
		spieler2 = new Bot();

		BotWahl(spieler1, ui);
		BotWahl(spieler2, ui);
	}

	Karte gewaelteKarte1;												//vom Spieler gewaehlet Karte
	Karte gewaelteKarte2;

	ErstenVier(spielfeld, deck);
	GebenHandkarten(deck, spieler1, spieler2);

	for (int i = 0; i < 10; i++)										//Ablauf des Spiels á 10 Runden
	{
		ui.AusgabeSpielfeld(spielfeld);

		spieler1->MachZug();
		spieler2->MachZug();

		gewaelteKarte1 = spieler1->GetGesetzteKarte();
		gewaelteKarte2 = spieler2->GetGesetzteKarte();

		if (gewaelteKarte1.getZahl() < gewaelteKarte2.getZahl())	//Wer darf als erster legen
		{
			switch (spielfeld->KarteLegen(gewaelteKarte1))
			{
				case 1:
					//Reihe wählen
					spieler1->AusgewaehlteReiheNehmen(spielfeld);
					break;

				case 2:
					//Ganze Reihe nehmen
					//SechsNimmt(mensch, spielfeld);
					break;

				default:
					break;
			}

			switch (spielfeld->KarteLegen(gewaelteKarte2))
			{
			case 1:
				//Reihe wählen
				//AusgewaehlteReiheNehmen(mensch, spielfeld);
				spieler2->AusgewaehlteReiheNehmen(spielfeld);
				break;

			case 2:
				//Ganze Reihe nehmen
				//SechsNimmt(mensch, spielfeld);
				break;

			default:
				break;
			}
		}
		else
		{
			switch (spielfeld->KarteLegen(gewaelteKarte2))
			{
			case 1:
				//Reihe wählen
				//AusgewaehlteReiheNehmen(mensch, spielfeld);
				spieler2->AusgewaehlteReiheNehmen(spielfeld);
				break;

			case 2:
				//Ganze Reihe nehmen
				//SechsNimmt(mensch, spielfeld);
				break;

			default:
				break;
			}

			switch (spielfeld->KarteLegen(gewaelteKarte1))
			{
			case 1:
				//Reihe wählen
				//AusgewaehlteReiheNehmen(mensch, spielfeld);
				spieler1->AusgewaehlteReiheNehmen(spielfeld);
				break;

			case 2:
				//Ganze Reihe nehmen
				//SechsNimmt(mensch, spielfeld);
				break;

			default:
				break;
			}
		}
	}

	//ui.SiegerEhrung(bot, mensch);										//Gewinner wird ermittelt
}

//void Steuerung::SechsNimmt(Spieler * spieler, Spielfeld* spielfeld)			//Falls 6 Karten in einer Reihe sind, nimmt derjenige der die 6. Karte gelegt hat
//{
//	int index = 0;
//
//
//
//	ReiheNimmt(index, spieler, spielfeld);
//}

void Steuerung::GebenHandkarten(Deck * deck, Spieler * spieler1, Spieler * spieler2)	//Verteilen der Handkarten
{
	for (int i = 0; i < 10; i++)
	{
		spieler1->SetHandkarteBeiIndex(i, deck->Dealer());
		spieler2->SetHandkarteBeiIndex(i, deck->Dealer());
	}
}

void Steuerung::ErstenVier(Spielfeld * spielfeld, Deck  * deck)			//Einsetzen der ersten 4 Karten auf das Spielfeld
{
	for(int i = 0; i < 4; i++)
	{
		spielfeld->KarteLegen(deck->Dealer());
	}
}

//void Steuerung::AusgewaehlteReiheNehmen(Spieler* spieler, Spielfeld* spielfeld)
//{
//	int eingabe;
//	UI ui;
//
//	do
//	{
//		eingabe = ui.AuswahlReiheNehmen();
//	} while (eingabe < 1 && eingabe > 4);
//
//	ReiheNimmt(eingabe, spieler, spielfeld);
//}
//
//void Steuerung::ReiheNimmt(int spalte, Spieler * spieler, Spielfeld * spielfeld)
//{
//	int strafpunkte = 0;
//	Karte platzhalter;
//
//	for (int i = 0; i < 5; i++)
//	{
//		strafpunkte += spielfeld->GetSpielfeld(i, spalte).getStrafpunkte();
//		spielfeld->SetSpielfeld(i, spalte, platzhalter);
//	}
//
//	spielfeld->SetSpielfeld(5, spalte, platzhalter);
//
//	spielfeld->SetSpielfeld(0, spalte, spieler->GetGesetzteKarte());
//
//	spieler->SetPunktestand(strafpunkte);
//}

void Steuerung::BotWahl(Spieler * bot, UI ui)
{
	int botAbfrage;

	do																	//Bot Auswahl
	{
		botAbfrage = ui.AbfrageBot();
	} while (botAbfrage != 1 && botAbfrage != 2 && botAbfrage != 3);

	switch (botAbfrage)
	{
	case 1:
		bot = new SchlauerBot();
		break;

	case 2:
		bot = new ZufallsBot();
		break;

	case 3:
		bot = new LowCardBot();
		break;
	}
}
