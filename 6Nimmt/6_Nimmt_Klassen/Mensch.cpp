#include "pch.h"
#include "Mensch.h"
#include "UI.h"
#include "Spielfeld.h"

Mensch::Mensch()
{
	name = "Mensch";
}

Karte Mensch::MachZug(Spielfeld * spielfeld)						//Mensch macht einen Zug
{
	UI ui;
	int eingabe;
	
	eingabe = ui.EingabeKarte(handkarten, längeHandkartenIndex);	//Eingabe der zu legenen Karte
	
	SetGesetzteKarte(handkarten[eingabe]);							//
																	//Setzen der ausgewählten Karte
	return LegeHandkarte(eingabe);									//
}

void Mensch::AusgewaehlteReiheNehmen(Spielfeld* spielfeld)			//Mensch wählt eine Reihe zum nehmen aus
{
	int eingabe;
	UI ui;

	eingabe = ui.AuswahlReiheNehmen(spielfeld);						//Eingabe der zu wählenden Reihe
	
	ReiheNimmt(eingabe, spielfeld);									//Ausgewählte Reihe wird genommen
}
