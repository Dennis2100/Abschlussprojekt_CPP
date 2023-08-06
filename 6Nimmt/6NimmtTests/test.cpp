#include "pch.h"
#include "Steuerung.h"
#include "Spielfeld.h"

/* mindestens 100 Testläufe definieren */
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

// 4 - die Karte ist kleiner als die letzten Karten in allen Reihen, es muss gewählt werden welche Reihe wird genommen
TEST(KarteLegenReiheZumNehmenWaehlen, SpielfeldRueckgabe4) {
	Spielfeld spielfeld;

	Karte kartenArray[4]{Karte(2), Karte(10), Karte(21), Karte(50)};

	for (int i = 0; i < 4; i++)
	{
		spielfeld.KarteLegen(kartenArray[i]);
	}

	EXPECT_EQ(spielfeld.KarteLegen(Karte(1)), 4);
}

// 5 - die Karte angenommen, keine Interaktion erforderlich
TEST(KarteLegenKarteAngenommen, SpielfeldRueckgabe5) {
	Spielfeld spielfeld;

	Karte kartenArray[4]{ Karte(2), Karte(10), Karte(21), Karte(50) };

	for (int i = 0; i < 4; i++)
	{
		spielfeld.KarteLegen(kartenArray[i]);
	}

	EXPECT_EQ(spielfeld.KarteLegen(Karte(3)), 5);
}

// 0 bis 3 - die Karte angenommen, die Reihe mit den angegebenen Index muss genommen werden, da die sechste Karte
TEST(KarteLegenReiheZumNehmenWaehlen, SpielfeldRueckgabe0123) {
	Spielfeld spielfeld;

	Karte kartenArray[4][5]{};

	for (int i = 0; i < 4; i++)
	{
		for (int c = 0; c < 5; c++)
		{
			kartenArray[i][c] = Karte((c + 1) + (i * 10));
		}
	}

	for (int i = 0; i < 4 ; i++)
	{
		for (int c = 0; c < 5; c++)
		{
			spielfeld.KarteLegen(kartenArray[i][c]);
		}
	}

	EXPECT_TRUE((spielfeld.KarteLegen(50)) >= 0 && (spielfeld.KarteLegen(50) <= 3));
}

// Werden die Strafpunkte einer Reihe richtig zurückgegeben
TEST(GetStrafpunkteRichtigeAusgabe, GetStrafpunkte) {
	Spielfeld spielfeld;

	Karte kartenArray[4]{ Karte(1), Karte(10), Karte(20), Karte(30) };

	for (int i = 0; i < 4; i++)
	{
		spielfeld.KarteLegen(kartenArray[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		for (int c = 1; c < 5; c++)
		{
			spielfeld.KarteLegen((c + 1) + (i * 10));
		}
	}

	EXPECT_EQ(spielfeld.GetStrafpunkte(0), 6);
}