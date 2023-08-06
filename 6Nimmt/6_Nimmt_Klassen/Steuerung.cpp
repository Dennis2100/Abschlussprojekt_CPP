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

Steuerung::~Steuerung()
{
}

int Steuerung::StarteSpiel(const int istSpielerMensch, const int botWahl1, const int botWahl2, bool konsolenausgabe, const int seek)
{
	UI ui;
	int sieger;
	Spielfeld* spielfeld = new Spielfeld();
	Deck* deck = new Deck();

	deck->SetRandomizer(seek);

	Spieler* spieler1 = NULL;
	Spieler* spieler2 = NULL;

	if (istSpielerMensch == 1)											//Initialisierung der Spieler 
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

	ErstenVier(spielfeld, deck);										//Zuweisung der ersten vier Karten 
				
	GebenHandkarten(deck, spieler1);									//Zuweisung der Handkarten
	GebenHandkarten(deck, spieler2);									//Zuweisung der Handkarten

	if (konsolenausgabe) ui.ScreenVorbereiten();						//Die Konsolenausgabe wird vorbereitet

	for (int i = 0; i < 10; i++)										//Ablauf des Spiels á 10 Runden
	{
		if (konsolenausgabe)											//Unterdrückung der Konsolenausgabe um die Tests zu beschleunigen
		{
			ui.ScreenLoeschen();										//Löschen der aktuellen Ausgabe
			ui.AusgabeSpielfeld(spielfeld, 5);							//Ausgabe des Spielfelds
			ui.SpielerStand(spieler1, spieler2);						//Ausgabe des Spielerstands
		}

		spieler1->MachZug(spielfeld);									//Spieler macht einen Zug
		spieler2->MachZug(spielfeld);									//

		gewaelteKarte1 = spieler1->GetGesetzteKarte();					//Gewählte Karte wird zugewiesen
		gewaelteKarte2 = spieler2->GetGesetzteKarte();					//

		if (konsolenausgabe) ui.ZeigeZug(spieler1, spieler2);

		WerDarfAnfangen(gewaelteKarte1, gewaelteKarte2, spielfeld, spieler1, spieler2);	//Ermittlung wer anfangen darf
	}

	sieger = SiegerBestimmung(spieler1, spieler2);						//Der Sieger wird bestimmt

	if (konsolenausgabe)												//Erneute Unterdrückung der Konsolenausgabe um die Tests zu beschleunigen
	{
	    ui.ScreenLoeschen();											//Löschen der aktuellen Ausgabe
	    ui.AusgabeSpielfeld(spielfeld, 5);								//Ausgabe des Spielfelds
	    ui.SpielerStand(spieler1, spieler2);							//Ausgabe des Spielerstands
    	ui.SiegerEhrung(sieger, spieler1, spieler2);					//Ausgabe des Siegers
		(void)getchar();
	}
	
	/* Loeschen von Objekten */
	delete (spieler1);
	delete (spieler2);
	delete (deck);
	delete (spielfeld);

	return sieger;														//Gewinner wird ermittelt
}

//Verteilen der Handkarten
void Steuerung::GebenHandkarten(Deck * deck, Spieler * spieler)								
{
	for (int i = 0; i < 10; i++)
	{
		spieler->SetHandkarteBeiIndex(i, deck->Dealer());
	}

	spieler->SortierenHandkarten();										//Handkarten werden Sortiert
}

//Einsetzen der ersten 4 Karten auf das Spielfeld
void Steuerung::ErstenVier(Spielfeld * spielfeld, Deck  * deck)								
{
	for(int i = 0; i < 4; i++)
	{
		spielfeld->KarteLegen(deck->Dealer());
	}
}

//Wer darf als erster legen
void Steuerung::WerDarfAnfangen(Karte gewaelteKarte1, Karte gewaelteKarte2, Spielfeld* spielfeld, Spieler* spieler1, Spieler* spieler2)
{
	if (gewaelteKarte1.GetZahl() < gewaelteKarte2.GetZahl())								
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

/* Spieler legt eine Karte auf das Spielfeld */
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

//Ermittlung des Gewinners
int Steuerung::SiegerBestimmung(Spieler* spieler1, Spieler* spieler2)						
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

//Zuweisung des Ausgewählten Bots
Spieler* Steuerung::BotWahl(const int nummer)														
{
	switch (nummer)
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
			return new ZufallsBot(); 
			break;
	}
}
