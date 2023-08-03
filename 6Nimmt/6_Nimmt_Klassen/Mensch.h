#pragma once
#include "Spieler.h"

class Mensch : public Spieler
{

public :
	Mensch();

	Karte MachZug() override;
	bool PruefeEingabe(int auswahl);
	void AusgewaehlteReiheNehmen(Spielfeld* spielfeld) override;
};

