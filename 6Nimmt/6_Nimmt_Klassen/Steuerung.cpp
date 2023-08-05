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

int Steuerung::StarteSpiel(int istSpielerMensch, int botWahl1, int botWahl2, bool konsolenausgabe,int seek)
{
	UI ui;
	int sieger;
	Spielfeld* spielfeld = new Spielfeld();
	Deck* deck = new Deck();

	deck->SetRandomizer(seek);

	Spieler* spieler1 = NULL;
	Spieler* spieler2 = NULL;

	if (istSpielerMensch == 1)
	{
		spieler1 = new Mensch();

		spieler2 = BotWahl(botWahl1);
	}
	else
	{
		spieler1 = BotWahl(botWahl1);
		spieler2 = BotWahl(botWahl2);
	}

	Karte gewaelteKarte1;												//Gewählte Karte von Spieler1
	Karte gewaelteKarte2;												//Gewählte Karte von Spieler2

	ErstenVier(spielfeld, deck);

	GebenHandkarten(deck, spieler1);
	GebenHandkarten(deck, spieler2);

	if (konsolenausgabe) ui.ScreenVorbereiten();

	for (int i = 0; i < 10; i++)										//Ablauf des Spiels á 10 Runden
	{
		if (konsolenausgabe)   //Unterdrückung der Konsolenausgabe um die Tests zu beschleunigen
		{
			ui.ScreenLoeschen();
			ui.AusgabeSpielfeld(spielfeld, 5);
			ui.SpielerStand(spieler1, spieler2);
		}

		spieler1->MachZug(spielfeld);
		spieler2->MachZug(spielfeld);

		gewaelteKarte1 = spieler1->GetGesetzteKarte();
		gewaelteKarte2 = spieler2->GetGesetzteKarte();

		WerDarfAnfangen(gewaelteKarte1, gewaelteKarte2, spielfeld, spieler1, spieler2);
	}

	if (konsolenausgabe)
	{
	    ui.ScreenLoeschen();
	    ui.AusgabeSpielfeld(spielfeld, 5);
	    ui.SpielerStand(spieler1, spieler2);
    }

	sieger = SiegerBestimmung(spieler1, spieler2);
	if (konsolenausgabe)
	{
		ui.SiegerEhrung(sieger, spieler1, spieler2);
		std::cin.get();
	}
	return sieger;								//Gewinner wird ermittelt

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

int Steuerung::SiegerBestimmung(Spieler* spieler1, Spieler* spieler2)		//Ermittlung des Gewinners
{
	if (spieler1->GetPunktestand() < spieler2->GetPunktestand())
	{
		return 1;
	}
	else if (spieler1->GetPunktestand() > spieler2->GetPunktestand())
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

Spieler* Steuerung::BotWahl(int nummer)
{
	switch (nummer)																		//Zuweisung des Ausgewählten Bots
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
