#include "pch.h"
#include "Steuerung.h"
#include "Spielfeld.h"

/* mindestens 100 Testl�ufe definieren */
const int AnzahlTests = 1000;

TEST(SchlauerBotVsZufallsBot, ZufallsBot) {

	Steuerung steuerung;
	int schlauerBotGewinnt = 0;
	double prozent;

	for (int i = 0; i < AnzahlTests; i++)
	{
		if (steuerung.StarteSpiel(0, 1, 2,false,i) == 1)
		{
			schlauerBotGewinnt++;
		}
	}

	prozent = schlauerBotGewinnt / (AnzahlTests/100);

	//std::cout << "Schlaubot hat " << schlauerBotGewinnt << " Mal von " << AnzahlTests << " gewonnen" << "\n\n";

	EXPECT_GE(prozent, 80.0);
}

TEST(SchlauerbotVsLowCardBot, LowCardBot) {

	Steuerung steuerung;
	int schlauerBotGewinnt = 0;
	double prozent;

	for (int i = 0; i < AnzahlTests; i++)
	{
		if (steuerung.StarteSpiel(0, 1, 3,false,i) == 1)
		{
			schlauerBotGewinnt++;
		}
	}

	prozent = schlauerBotGewinnt / (AnzahlTests / 100);

	//std::cout << schlauerBotGewinnt << "\n\n";

	EXPECT_GE(prozent, 80.0);
}

TEST(SchlauerbotVsHighCardBot, HighCardBot) {

	Steuerung steuerung;
	int schlauerBotGewinnt = 0;
	double prozent;

	for (int i = 0; i < AnzahlTests; i++)
	{
		if (steuerung.StarteSpiel(0, 1, 4,false,i) == 1)
		{
			schlauerBotGewinnt++;
		}
	}

	prozent = schlauerBotGewinnt / (AnzahlTests / 100);

	//std::cout << schlauerBotGewinnt << "\n\n";

	EXPECT_GE(prozent, 80.0);
}

TEST(KarteLegenReiheZumNehmenWaehlen, SpielfeldRueckgabe4) {
	Spielfeld spielfeld;

	Karte kartenArray[4]{Karte(2), Karte(10), Karte(21), Karte(50)};

	for (int i = 0; i < 4; i++)
	{
		spielfeld.KarteLegen(kartenArray[i]);
	}

	EXPECT_EQ(spielfeld.KarteLegen(Karte(1)), 4);
}

TEST(KarteLegenReiheZumNehmenWaehlen, SpielfeldRueckgabe5) {
	Spielfeld spielfeld;

	Karte kartenArray[4]{ Karte(2), Karte(10), Karte(21), Karte(50) };

	for (int i = 0; i < 4; i++)
	{
		spielfeld.KarteLegen(kartenArray[i]);
	}

	EXPECT_EQ(spielfeld.KarteLegen(Karte(3)), 5);
}