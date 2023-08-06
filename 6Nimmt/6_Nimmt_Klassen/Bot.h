#pragma once
#include "Spieler.h"
#include "Spielfeld.h"

class Bot : public Spieler
{

public: 
	Bot();																	//Standardkonstuktor
	~Bot();

	virtual Karte MachZug(Spielfeld * spielfeld) abstract;					//Bot macht einen Zug
	virtual void AusgewaehlteReiheNehmen(Spielfeld* spielfeld) override;	//Nur override von Spieler, gleiche Funktionalität
	int ErmittlungMin(Spielfeld * spielfeld);								//Fasst die Strafpunkte in einer Reihe zusammen und übergibt sie an Minimal, gibt den index zurück
};

