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
	
	eingabe = ui.EingabeKarte(handkarten, l�ngeHandkartenIndex);	//Eingabe der zu legenen Karte
	
	SetGesetzteKarte(handkarten[eingabe]);							//
																	//Setzen der ausgew�hlten Karte
	return LegeHandkarte(eingabe);									//
}

void Mensch::AusgewaehlteReiheNehmen(Spielfeld* spielfeld)			//Mensch w�hlt eine Reihe zum nehmen aus
{
	int eingabe;
	UI ui;

	eingabe = ui.AuswahlReiheNehmen(spielfeld);						//Eingabe der zu w�hlenden Reihe
	
	ReiheNimmt(eingabe, spielfeld);									//Ausgew�hlte Reihe wird genommen
}
