#include "pch.h"
#include "Mensch.h"
#include "UI.h"
#include "Spielfeld.h"

Mensch::Mensch()
{
	name = "Mensch";
}

Mensch::~Mensch()
{
}

//Mensch macht einen Zug
Karte Mensch::MachZug(Spielfeld * spielfeld)						
{
	UI ui;
	int eingabe;
	
	eingabe = ui.EingabeKarte(handkarten, laengeHandkartenIndex);	//Eingabe der zu legenen Karte
	
	SetGesetzteKarte(handkarten[eingabe]);							//
																	//Setzen der ausgewählten Karte
	return LegeHandkarte(eingabe);									//
}

//Mensch wählt eine Reihe zum nehmen aus
void Mensch::AusgewaehlteReiheNehmen(Spielfeld* spielfeld)			
{
	int eingabe;
	UI ui;

	eingabe = ui.AuswahlReiheNehmen(spielfeld);						//Eingabe der zu wählenden Reihe
	
	ReiheNimmt(eingabe, spielfeld);									//Ausgewählte Reihe wird genommen
}
