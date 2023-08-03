#include "pch.h"
#include "Mensch.h"
#include "UI.h"

Mensch::Mensch()
{

}

Karte Mensch::MachZug()
{
	UI ui;
	int eingabe;

	ui.AusgabeHandkarten(handkarten, längeHandkartenIndex);

	do																//Abfangen von Falschen Einträgen
	{
		eingabe = ui.EingabeKarte();
	} while (PruefeEingabe(eingabe));

	SetGesetzteKarte(handkarten[eingabe-1]);

	return LegeHandkarte(eingabe-1);
}

bool Mensch::PruefeEingabe(int auswahl)
{
	if (auswahl > GetHandkartenIndexLaenge() || auswahl < 1) return true;
	return false;
}

void Mensch::AusgewaehlteReiheNehmen(Spielfeld* spielfeld)
{
	int eingabe;
	UI ui;

	do
	{
		eingabe = ui.AuswahlReiheNehmen();
	} while (eingabe < 1 && eingabe > 4);

	ReiheNimmt(eingabe, spielfeld);
}
