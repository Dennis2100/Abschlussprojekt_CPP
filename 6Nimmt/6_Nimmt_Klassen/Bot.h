#pragma once
#include "Spieler.h"

class Bot : public Spieler
{

public: 
	Bot();

	virtual Karte MachZug() override;
	virtual void AusgewaehlteReiheNehmen(Spielfeld* spielfeld) override;
};

