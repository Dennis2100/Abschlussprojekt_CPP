#pragma once
#include "Spieler.h"
#include "Spielfeld.h"

class Mensch : public Spieler
{

public :
	Mensch();

	Karte MachZug(Spielfeld * spielfeld) override;
	void AusgewaehlteReiheNehmen(Spielfeld* spielfeld) override;
};

