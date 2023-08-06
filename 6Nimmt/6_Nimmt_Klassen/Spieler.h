#pragma once
#include "Karte.h"
#include "Spielfeld.h"

class Spieler
{
	

public:
	Spieler();																	//Standardkonstruktor
	~Spieler();

	void SetPunktestand(const int punktestand);									//Strafpunkte setzen
	int GetPunktestand();														//Strafpunkte ausgeben
	void SetHandkarteBeiIndex(const int index, Karte karte);					//Eine Handkarte beim angegebenen Index setzen
	Karte LegeHandkarte(const int index);										//Die gelegte karte wird ausgegeben und danach aus den Handkarten gelöscht
	void LoescheGelegteHandkarte(const int index);								//Methode zum Löschen der gelegten Handkarte
	int GetHandkartenIndexLaenge();												//Ausgabe der Anzahl der noch Vorhandenen Handkarten 
	Karte* GetHandkarten();														//Gibt die Handkarten des Spielers zurück
	Karte GetHandkarteBeiIndex(const int index);								//Gibt die Handkarte am angegebenen Index aus
	void SetGesetzteKarte(Karte karte);											//Setzt die vom Spieler geseztze Karte (Variable gesetzteKarte)
	Karte GetGesetzteKarte();													//Gibt die gesetzte Karte aus
	std::string GetName();														//Gibt den Namen des Spielers zurück

	void ReiheNimmt(const int spalte, Spielfeld * spielfeld);					//Die Reihe wird genommen, die Strafpunkte für den Spieler werden berechnet, erste Karte wird zur gesetzten Karte des Spielers

	void SortierenHandkarten();													//Sortiert die Handkarten des Spielers
	void HeapSort();															//
	void Heapify(const int index, const int root);								//	Gewähltes Sortierverfahren
	void SwapHandkarten(const int index1, const int index2);					//

	virtual Karte MachZug(Spielfeld * spielfeld) abstract;						//Spieler macht einen Zug	
	virtual void AusgewaehlteReiheNehmen(Spielfeld * spielfeld) abstract;		//Nimmt die Ausgewählte Reihe, berechnet Strafpunkte, Setzt ertse Karte der Spalte

protected:
	std::string name;
	Karte handkarten[10];
	int punktestand = 0;
	int laengeHandkartenIndex = 10;
	Karte gesetzteKarte;
};

