#pragma once
#include "Spieler.h"

class Mensch : public Spieler
{

public :
	Mensch();

	Karte MachZug() override;
	void AusgewaehlteReiheNehmen(Spielfeld* spielfeld) override;
};

