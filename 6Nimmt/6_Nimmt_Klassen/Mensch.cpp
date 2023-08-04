#include "pch.h"
#include "Mensch.h"
#include "UI.h"

Mensch::Mensch()
{
	name = "Mensch";
}

Karte Mensch::MachZug()
{
	UI ui;
	int eingabe;
	
	eingabe = ui.EingabeKarte(handkarten, längeHandkartenIndex);
	
	SetGesetzteKarte(handkarten[eingabe]);

	return LegeHandkarte(eingabe);
}

void Mensch::AusgewaehlteReiheNehmen(Spielfeld* spielfeld)
{
	int eingabe;
	UI ui;

	eingabe = ui.AuswahlReiheNehmen(spielfeld);
	
	ReiheNimmt(eingabe, spielfeld);
}
