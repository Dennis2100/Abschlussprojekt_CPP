#pragma once
#include "Spieler.h"
#include "Spielfeld.h"

class Bot : public Spieler
{

public: 
	Bot();

	virtual Karte MachZug(Spielfeld * spielfeld) abstract;					//Bot macht einen Zug
	virtual void AusgewaehlteReiheNehmen(Spielfeld* spielfeld) override;	//Nur override von Spieler, gleiche Funktionalit�t
	int ErmittlungMin(Spielfeld * spielfeld);								//Fasst die Strafpunkte in einer Reihe zusammen und �bergibt sie an Minimal, gibt den index zur�ck
	int Minimal(int reihe[]);												//Unterst�tzt ErmittlungMin, ermittelt den Index und gibt ihn an ErmittlungMin zur�ck
};

