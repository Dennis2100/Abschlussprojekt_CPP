#pragma once
#include "Spieler.h"
#include "Spielfeld.h"

class Mensch : public Spieler
{

public :
	Mensch();														//Standardkonstruktor

	Karte MachZug(Spielfeld * spielfeld) override;					//Macht einen Zug
	void AusgewaehlteReiheNehmen(Spielfeld* spielfeld) override;	//Nimmt die ausgewählte Reihe nehmen
};

