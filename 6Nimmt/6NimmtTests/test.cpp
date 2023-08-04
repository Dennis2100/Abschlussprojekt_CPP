#include "pch.h"
#include "Steuerung.h"

TEST(SchlauerBotVsZufallsBot, ZufallsBot) {

	Steuerung steuerung;
	int schlauerBotGewinnt = 0;
	double prozent;

	for (int i = 0; i < 1000; i++)
	{
		if (steuerung.StarteSpiel(0, 1, 2) == 1)
		{
			schlauerBotGewinnt++;
		}
	}

	prozent = schlauerBotGewinnt / 10.0;

	std::cout << "\n\n";

	EXPECT_GT(prozent, 80.0);
}

TEST(SchlauerbotVsLowCardBot, LowCardBot) {

	Steuerung steuerung;
	int schlauerBotGewinnt = 0;
	double prozent;

	for (int i = 0; i < 1000; i++)
	{
		if (steuerung.StarteSpiel(0, 1, 3) == 1)
		{
			schlauerBotGewinnt++;
		}
	}

	prozent = schlauerBotGewinnt / 10.0;

	std::cout << "\n\n";

	EXPECT_GT(prozent, 80.0);
}

TEST(SchlauerbotVsHighCardBot, HighCardBot) {

	Steuerung steuerung;
	int schlauerBotGewinnt = 0;
	double prozent;

	for (int i = 0; i < 1000; i++)
	{
		if (steuerung.StarteSpiel(0, 1, 4) == 1)
		{
			schlauerBotGewinnt++;
		}
	}

	prozent = schlauerBotGewinnt / 10.0;

	std::cout << "\n\n";

	EXPECT_GT(prozent, 80.0);
}