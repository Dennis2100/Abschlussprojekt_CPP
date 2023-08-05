#include "pch.h"
#include "Steuerung.h"

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

	EXPECT_GT(prozent, 80.0);
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

	EXPECT_GT(prozent, 80.0);
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

	EXPECT_GT(prozent, 80.0);
}