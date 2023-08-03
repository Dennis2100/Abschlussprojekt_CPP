#pragma once
#include "Karte.h"
#include "Spielfeld.h"

class Spieler
{
	

public:
	Spieler();

	void SetPunktestand(int punktestand);										//Strafpunkte setzen
	int GetPunktestand();														//Strafpunkte ausgeben
	void SetHandkarteBeiIndex(int index, Karte karte);							//Eine Handkarte beim angegebenen Index setzen
	Karte LegeHandkarte(int index);												//Die gelegte karte wird ausgegeben und danach aus den Handkarten gel�scht
	void L�scheGelegteHandkarte(int index);										//Methode zum L�schen der gelegten Handkarte
	int GetHandkartenIndexLaenge();												//Ausgabe der Anzahl der noch Vorhandenen Handkarten 
	Karte GetHandkarteBeiIndex(int index);										//Gibt die Handkarte am angegebenen Index aus
	void SetGesetzteKarte(Karte karte);											//Setzt die vom Spieler geseztze Karte (Variable gesetzteKarte)
	Karte GetGesetzteKarte();													//Gibt die gesetzte Karte aus
	std::string GetName();														//Gibt den Namen des Spielers zur�ck

	void ReiheNimmt(int spalte, Spielfeld * spielfeld);							//Die Reihe wird genommen, die Strafpunkte f�r den Spieler werden berechnet, erste Karte wird zur gesetzten Karte des Spielers
	//void SechsNimmt(int spalte, Spielfeld * spielfeld);

	void SortierenHandkarten();													//Sortiert die Handkarten des Spielers
	void HeapSort();															//
	void Heapify(int index, int root);											//	Gew�hltes Sortierverfahren, da komplexit�t immer gleich
	void SwapHandkarten(int index1, int index2);								//

	virtual Karte MachZug() abstract;											//Spieler macht einen Zug	
	virtual void AusgewaehlteReiheNehmen(Spielfeld * spielfeld) abstract;		//Nimmt die Ausgew�hlte Reihe, berechnet Strafpunkte, Setzt ertse Karte der Spalte

protected:
	std::string name;
	Karte handkarten[10];
	int punktestand = 0;
	int l�ngeHandkartenIndex = 10;
	Karte gesetzteKarte;
};

