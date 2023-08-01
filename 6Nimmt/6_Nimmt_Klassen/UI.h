#pragma once
class UI
{


public:

	UI();
	void AusgabeSpielfeld();		//Aktuelles Spielfeld ausgeben
	int AbfrageBot();				//Frage welcher Bot verwendet werden soll
	void AusgabeHandkarten();		//Graphische Ausgabe der Handkarten des Menschspielers
	int EingabeKarte();				//Auswahl der zu legenden Karte für den Menschspieler
};

